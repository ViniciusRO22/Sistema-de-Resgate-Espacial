#ifndef MODULO_OBSTACULO_HPP
#define MODULO_OBSTACULO_HPP

#include "Modulo.hpp"

class ModuloObstaculo : public Modulo 
{
    public:
        ModuloObstaculo();
        bool podeAcessar() const override;
};

#endif

