#ifndef MODULO_HPP
#define MODULO_HPP

class Modulo 
{
    protected:
        char tipo;
    
    
    public:
        Modulo(char tipo);
        virtual ~Modulo();
        char getTipo() const;
        virtual bool podeAcessar() const = 0;
};

#endif

