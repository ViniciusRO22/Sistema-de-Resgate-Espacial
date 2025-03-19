#ifndef ESTACAO_ESPACIAL_HPP
#define ESTACAO_ESPACIAL_HPP

#include "Modulo.hpp"
#include "Astronauta.hpp"
#include <vector>
#include <string>
#include <utility>

class EstacaoEspacial 
{
    private:
        int linhas, colunas;
        std::vector<std::vector<Modulo*>> matriz;
        std::vector<Astronauta> astronautas;
        std::pair<int,int> posicaoSeguranca; 
    
   public:
        EstacaoEspacial(int linhas, int colunas);
        ~EstacaoEspacial();
        
        void adicionarModulo(int x, int y, char tipo);
        void adicionarAstronauta(const Astronauta& astronauta);
        
        const std::vector<std::vector<Modulo*>>& getMatriz() const;
        const std::vector<Astronauta>& getAstronautas() const;
        std::vector<Astronauta>& getAstronautas();
        
        int getLinhas() const;
        int getColunas() const;
        std::pair<int,int> getPosicaoSeguranca() const;
};

#endif

