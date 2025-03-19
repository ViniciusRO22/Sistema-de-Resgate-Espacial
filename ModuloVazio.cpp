#include "ModuloVazio.hpp"

ModuloVazio::ModuloVazio() : Modulo('~') {}

bool ModuloVazio::podeAcessar() const 
{ 
    return false; 
}

