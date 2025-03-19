#ifndef MODULO_COM_FOGO_HPP
#define MODULO_COM_FOGO_HPP

#include "Modulo.hpp"

class ModuloComFogo : public Modulo 
{
    public:
        ModuloComFogo();
        bool podeAcessar() const override;
};

#endif
