#include "EstacaoEspacial.hpp"
#include "ModuloSeguranca.hpp"
#include "ModuloComFogo.hpp"
#include "ModuloObstaculo.hpp"
#include "ModuloVazio.hpp"
#include "ModuloNormal.hpp"
#include <stdexcept>

EstacaoEspacial::EstacaoEspacial(int linhas, int colunas) : linhas(linhas), colunas(colunas) 
{
    matriz.resize(linhas, std::vector<Modulo*>(colunas, nullptr));
}

EstacaoEspacial::~EstacaoEspacial() 
{
    for (int i = 0; i < linhas; i++) 
    {
        for (int j = 0; j < colunas; j++) 
        {
            delete matriz[i][j];
        }
    }
}

void EstacaoEspacial::adicionarModulo(int x, int y, char tipo) 
{
    Modulo* mod = nullptr;
    
    switch(tipo) 
    {
        case 'S':
            mod = new ModuloSeguranca();
            posicaoSeguranca = {x, y};
            break;
        
        case 'A':
            mod = new ModuloNormal();
            break;
        
        case '#':
            mod = new ModuloObstaculo();
            break;
        
        case '~':
            mod = new ModuloVazio(); 
            break;
        
        case 'F':
            mod = new ModuloComFogo();
            break;
        
        case '.':
            mod = new ModuloNormal();
            break;
        
        default:
            mod = new ModuloNormal();
            break;
    }
    
    matriz[x][y] = mod;
}

void EstacaoEspacial::adicionarAstronauta(const Astronauta& astronauta) 
{
    astronautas.push_back(astronauta);
}

const std::vector<std::vector<Modulo*>>& EstacaoEspacial::getMatriz() const 
{
    return matriz;
}

const std::vector<Astronauta>& EstacaoEspacial::getAstronautas() const 
{
    return astronautas;
}

std::vector<Astronauta>& EstacaoEspacial::getAstronautas() 
{
    return astronautas;
}

int EstacaoEspacial::getLinhas() const 
{
    return linhas;
}

int EstacaoEspacial::getColunas() const 
{
    return colunas;
}

std::pair<int,int> EstacaoEspacial::getPosicaoSeguranca() const 
{
    return posicaoSeguranca;
}
