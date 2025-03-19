#ifndef ASTRONAUTA_HPP
#define ASTRONAUTA_HPP

#include <string>
#include <utility>

class Astronauta 
{
    private:
        std::string nome;
        int nivelSaude;
        bool atendimentoUrgente;
        int x, y;  
        bool resgatado; 
    
    public:
        Astronauta();
        Astronauta(const std::string& nome, int nivelSaude, bool atendimentoUrgente, int x, int y);
        
        std::string getNome() const;
        int getNivelSaude() const;
        bool isAtendimentoUrgente() const;
        std::pair<int,int> getPosicao() const;
        void setPosicao(int x, int y);
        
        bool isResgatado() const;
        void setResgatado(bool r);
};

#endif


