#ifndef MODULO_VAZIO_HPP
#define MODULO_VAZIO_HPP

#include "Modulo.hpp"

class ModuloVazio : public Modulo 
{
    public:
        ModuloVazio();
        bool podeAcessar() const override;
};

#endif
