#include "Modulo.hpp"

Modulo::Modulo(char tipo) : tipo(tipo) {}

Modulo::~Modulo() {}

char Modulo::getTipo() const 
{
    return tipo;
}

