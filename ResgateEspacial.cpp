#include "ResgateEspacial.hpp"
#include "EstacaoEspacial.hpp"
#include "RoboDeResgate.hpp"
#include "Astronauta.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <tuple>
#include <stdexcept>

using namespace std;

void ResgateEspacial::executar() 
{
    for (int arquivo = 1; arquivo <= 10; arquivo++) 
    {
        string inputFile = "entrada" + to_string(arquivo) + ".txt";
        ifstream fin(inputFile);
        
        if (!fin.is_open()) 
        {
            cerr << "Arquivo " << inputFile << " não encontrado. Pulando...\n";
            
            continue;
        }
    
        cout << "Processando " << inputFile << "...\n";

        int N, M;
        fin >> N >> M;
        fin.ignore(); 

        EstacaoEspacial estacao(N, M);

        vector<string> linhasMatriz;
        
        for (int i = 0; i < N; i++) 
        {
            string linha;
            getline(fin, linha);
            
            if (linha.empty()) 
            { 
                i--; 
                
                continue; 
            }
            
            linhasMatriz.push_back(linha);
        }

        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < M; j++) 
            {
                char ch = linhasMatriz[i][j];
                estacao.adicionarModulo(i, j, ch);
            }
        }

        string token;
        
        while(getline(fin, token)) 
        {
            if(token.find("Astronautas:") != string::npos)
            {
                break;
            }
        }

        vector<tuple<string,int,bool>> dadosAstronautas;
        
        while(getline(fin, token)) 
        {
            if(token.find("Posições dos astronautas") != string::npos)
            {
                break;
            }
            
            if(token.empty()) continue;
            
            stringstream ss(token);
            string nome, nivelAstr, urgenciaAstr;
            
            if(!getline(ss, nome, ',')) continue;
            if(!getline(ss, nivelAstr, ',')) continue;
            if(!getline(ss, urgenciaAstr, ',')) continue;
            
            int nivel = stoi(nivelAstr);
            bool urgencia = (stoi(urgenciaAstr) == 1);
            dadosAstronautas.push_back(make_tuple(nome, nivel, urgencia));
        }

        vector<pair<int,int>> posicoes;
        vector<string> nomesPos;
        
        while(getline(fin, token)) 
        {
            if(token.empty()) continue;
            
            size_t posDoisPontos = token.find(':');
            
            if(posDoisPontos == string::npos) continue;
            
            string nome = token.substr(0, posDoisPontos);
            nomesPos.push_back(nome);
            
            size_t posParenOpen = token.find('(', posDoisPontos);
            size_t posVirgula = token.find(',', posParenOpen);
            size_t posParenClose = token.find(')', posVirgula);
            
            int x = stoi(token.substr(posParenOpen + 1, posVirgula - posParenOpen - 1));
            int y = stoi(token.substr(posVirgula + 1, posParenClose - posVirgula - 1));
            posicoes.push_back({x, y});
        }

        if(dadosAstronautas.size() != posicoes.size())
        {
            cerr << "Número de astronautas e posições não correspondem no arquivo " << inputFile << endl;
            continue;
        }

        for (size_t i = 0; i < dadosAstronautas.size(); i++) 
        {
            string nome;
            int nivel;
            bool urgencia;
            
            tie(nome, nivel, urgencia) = dadosAstronautas[i];
            
            int x = posicoes[i].first;
            int y = posicoes[i].second;
            
            Astronauta astro(nome, nivel, urgencia, x, y);
            estacao.adicionarAstronauta(astro);
        }

        pair<int,int> inicio = estacao.getPosicaoSeguranca();
    
        RoboDeResgate robo(inicio.first, inicio.second, &estacao);
        
        string outputFile = "saida" + to_string(arquivo) + ".txt";
        ofstream fout(outputFile);
        
        if (!fout.is_open())
        {
            cerr << "Não foi possível abrir " << outputFile << " para escrita.\n";
            
            continue;
        }
        
        robo.iniciarResgate(fout);

        robo.gerarRelatorio(fout);
        fout.close();
    }
}

int main() 
{
    ResgateEspacial::executar();
    return 0;
}

