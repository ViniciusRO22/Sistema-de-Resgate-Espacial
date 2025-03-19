#include "Astronauta.hpp"

Astronauta::Astronauta() : nome(""), nivelSaude(0), atendimentoUrgente(false), x(0), y(0), resgatado(false) {}

Astronauta::Astronauta(const std::string& nome, int nivelSaude, bool atendimentoUrgente, int x, int y) : nome(nome), nivelSaude(nivelSaude), atendimentoUrgente(atendimentoUrgente), x(x), y(y), resgatado(false) {}

std::string Astronauta::getNome() const 
{
    return nome;
}

int Astronauta::getNivelSaude() const 
{
    return nivelSaude;
}

bool Astronauta::isAtendimentoUrgente() const 
{
    return atendimentoUrgente;
}

std::pair<int,int> Astronauta::getPosicao() const 
{
    return {x, y};
}

void Astronauta::setPosicao(int x, int y) 
{
    this->x = x;
    this->y = y;
}

bool Astronauta::isResgatado() const 
{
    return resgatado;
}

void Astronauta::setResgatado(bool r) 
{
    resgatado = r;
}

