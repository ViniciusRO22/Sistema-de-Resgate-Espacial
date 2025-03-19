#ifndef MODULO_SEGURANCA_HPP
#define MODULO_SEGURANCA_HPP

#include "Modulo.hpp"

class ModuloSeguranca : public Modulo 
{
    public:
        ModuloSeguranca();
        bool podeAcessar() const override;
};

#endif

