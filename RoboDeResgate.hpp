#ifndef ROBO_DE_RESGATE_HPP
#define ROBO_DE_RESGATE_HPP

#include "EstacaoEspacial.hpp"
#include "Astronauta.hpp"
#include <vector>
#include <utility>
#include <ostream>

class RoboDeResgate 
{
    private:
        int posX, posY; 
        EstacaoEspacial* estacao;
        std::vector<Astronauta> resgatados;
        std::vector<Astronauta> naoResgatados;
        int totalPassos;
        
        bool isDoLadoFogo(int x, int y) const;
        bool isValido(int x, int y, const std::vector<std::vector<bool>>& visitado) const;
        int bfs(int inicioX, int inicioY, int alvoX, int alvoY, std::vector<std::pair<int,int>>& caminho) const;
        
        void printMatriz(std::ostream& os) const;
    
    public:
        RoboDeResgate(int x, int y, EstacaoEspacial* estacao);
      
        void iniciarResgate(std::ostream& os);
        
        void gerarRelatorio(std::ostream& os) const;
};

#endif

