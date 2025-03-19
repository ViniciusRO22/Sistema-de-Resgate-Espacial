#include "ModuloSeguranca.hpp"

ModuloSeguranca::ModuloSeguranca() : Modulo('S') {}

bool ModuloSeguranca::podeAcessar() const 
{ 
    return true; 
}

