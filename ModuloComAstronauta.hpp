#ifndef MODULO_COM_ASTRONAUTA_HPP
#define MODULO_COM_ASTRONAUTA_HPP

#include "Modulo.hpp"

class ModuloComAstronauta : public Modulo 
{
    public:
        ModuloComAstronauta();
        bool podeAcessar() const override;
};

#endif
