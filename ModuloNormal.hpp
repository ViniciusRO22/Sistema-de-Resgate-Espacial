#ifndef MODULO_NORMAL_HPP
#define MODULO_NORMAL_HPP

#include "Modulo.hpp"

class ModuloNormal : public Modulo 
{
    public:
        ModuloNormal();
        bool podeAcessar() const override;
};

#endif

