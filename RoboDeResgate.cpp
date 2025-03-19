#include "RoboDeResgate.hpp"
#include "Modulo.hpp"
#include "ModuloComFogo.hpp"
#include "ModuloObstaculo.hpp"
#include "ModuloVazio.hpp"
#include "ModuloNormal.hpp"
#include <queue>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

RoboDeResgate::RoboDeResgate(int x, int y, EstacaoEspacial* estacao) : posX(x), posY(y), estacao(estacao), totalPassos(0) { }

bool RoboDeResgate::isDoLadoFogo(int x, int y) const 
{
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    const auto& matriz = estacao->getMatriz();
    int linhas = estacao->getLinhas();
    int colunas = estacao->getColunas();
    
    for (int i = 0; i < 4; i++) 
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < linhas && ny >= 0 && ny < colunas) 
        {
            if (matriz[nx][ny]->getTipo() == 'F')
            {
                return true;
            }
        }
    }
    
    return false;
}

bool RoboDeResgate::isValido(int x, int y, const vector<vector<bool>>& visitado) const 
{
    int linhas = estacao->getLinhas();
    int colunas = estacao->getColunas();
    
    if (x < 0 || x >= linhas || y < 0 || y >= colunas)
    {
        return false;
    }
    
    if (visitado[x][y])
    {
        return false;
    }
    
    const auto& matriz = estacao->getMatriz();
    
    if (!matriz[x][y]->podeAcessar())
    {
        return false;
    }
    
    if (isDoLadoFogo(x, y))
    {
        return false;
    }
    
    return true;
}

int RoboDeResgate::bfs(int inicioX, int inicioY, int alvoX, int alvoY, vector<pair<int,int>>& caminho) const 
{
    int linhas = estacao->getLinhas();
    int colunas = estacao->getColunas();
    
    vector<vector<bool>> visited(linhas, vector<bool>(colunas, false));
    vector<vector<pair<int,int>>> parent(linhas, vector<pair<int,int>>(colunas, {-1,-1}));
    queue<pair<int,int>> q;
    q.push({inicioX, inicioY});
    
    visited[inicioX][inicioY] = true;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    bool found = false;
    
    while (!q.empty()) 
    {
        auto [x, y] = q.front();
        q.pop();
        
        if (x == alvoX && y == alvoY) 
        {
            found = true;
            
            break;
        }
        
        for (int i = 0; i < 4; i++) 
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (isValido(nx, ny, visited)) 
            {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }
    
    if (!found)
    {
        return -1;
    }
    
    vector<pair<int,int>> revPath;
    int x = alvoX, y = alvoY;
    
    while (!(x == inicioX && y == inicioY)) 
    {
        revPath.push_back({x, y});
        auto p = parent[x][y];
        x = p.first;
        y = p.second;
    }
    
    revPath.push_back({inicioX, inicioY});
    caminho.assign(revPath.rbegin(), revPath.rend());
    
    return caminho.size() - 1;
}

void RoboDeResgate::printMatriz(ostream& os) const 
{
    const auto& matriz = estacao->getMatriz();
    int linhas = estacao->getLinhas();
    int colunas = estacao->getColunas();

    const auto& astron = estacao->getAstronautas();
    
    for (int i = 0; i < linhas; i++) 
    {
        for (int j = 0; j < colunas; j++) 
        {
            if (i == posX && j == posY) 
            {
                os << "R"; // posição do robô
            } 
            else 
            {
                bool printed = false;
                
                for (const auto& astro : astron) 
                {
                    if (!astro.isResgatado()) 
                    {
                        auto pos = astro.getPosicao();
                        
                        if (pos.first == i && pos.second == j) 
                        {
                            os << "A";
                            printed = true;
                            
                            break;
                        }
                    }
                }
                
                if (!printed)
                {
                    os << matriz[i][j]->getTipo();
                }
            }
        }
        
        os << "\n";
    }
    
    os << "Passos totais: " << totalPassos;
    os << " | Astronautas resgatados: " << resgatados.size() << "\n";
    os << "-------------------\n";
}

void RoboDeResgate::iniciarResgate(ostream& os) 
{
    std::vector<Astronauta>& listaAstros = estacao->getAstronautas();
    std::vector<bool> jaResgatados(listaAstros.size(), false);

    os << "Estado inicial:\n";
    printMatriz(os);

    while (true) 
    {
        int minDist = INT_MAX;
        int alvoIdx = -1;
        vector<pair<int,int>> melhorCaminho;
        
        for (size_t i = 0; i < listaAstros.size(); i++) 
        {
            if (jaResgatados[i]) continue;
            
            auto posAstro = listaAstros[i].getPosicao();
            vector<pair<int,int>> caminho;
            int dist = bfs(posX, posY, posAstro.first, posAstro.second, caminho);
            
            if (dist != -1 && dist < minDist) 
            {
                minDist = dist;
                alvoIdx = i;
                melhorCaminho = caminho;
            }
        }
        
        if (alvoIdx == -1)
        {
            break;
        }
        
        for (size_t i = 1; i < melhorCaminho.size(); i++) 
        {
            posX = melhorCaminho[i].first;
            posY = melhorCaminho[i].second;
            totalPassos++;
            printMatriz(os);
        }
        
        resgatados.push_back(listaAstros[alvoIdx]);
        jaResgatados[alvoIdx] = true;
        listaAstros[alvoIdx].setResgatado(true);
    }
    
    auto seg = estacao->getPosicaoSeguranca();
    vector<pair<int,int>> caminhoVolta;
    int distVolta = bfs(posX, posY, seg.first, seg.second, caminhoVolta);
    
    if (distVolta != -1) 
    {
        for (size_t i = 1; i < caminhoVolta.size(); i++) 
        {
            posX = caminhoVolta[i].first;
            posY = caminhoVolta[i].second;
            totalPassos++;
            printMatriz(os);
        }
    }
    
    for (size_t i = 0; i < listaAstros.size(); i++) 
    {
        if (!jaResgatados[i])
        {
            naoResgatados.push_back(listaAstros[i]);
        }
    }
}

void RoboDeResgate::gerarRelatorio(ostream& os) const 
{
    os << "\n===== Relatório de Resgate =====\n";
    os << "- Número total de passos: " << totalPassos << "\n";
    os << "- Número de astronautas resgatados: " << resgatados.size() << "\n";
    
    for (const auto &a : resgatados) 
    {
        auto pos = a.getPosicao();
        
        os << "  - " << a.getNome() << ": Saúde " << a.getNivelSaude() << ", Atendimento Médico Urgente: " << (a.isAtendimentoUrgente() ? "Sim" : "Não") << ", Posição: (" << pos.first << ", " << pos.second << ")\n";
    }
    
    os << "- Lista de astronautas não resgatados:\n";
    
    for (const auto &a : naoResgatados) 
    {
        auto pos = a.getPosicao();
        
        os << "  - " << a.getNome() << ": Saúde " << a.getNivelSaude() << ", Atendimento Médico Urgente: " << (a.isAtendimentoUrgente() ? "Sim" : "Não") << ", Posição: (" << pos.first << ", " << pos.second << ")\n";
    }
    
    os << "================================\n";
}


