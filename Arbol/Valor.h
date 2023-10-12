#ifndef RISK_ESTDATOS_VALOR_H
#define RISK_ESTDATOS_VALOR_H


class Valor {
    public:
        void setValor(char c);
        void setFrecuencia(int f);
        void setAscii(int a);

        char getValor();
        int getFrecuencia();
        int getAscii();

    protected:
        char valor;
        int frecuencia;
        int ascii;
};


#endif //RISK_ESTDATOS_VALOR_H
