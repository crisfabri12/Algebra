#ifndef AFIN_H
#define AFIN_H
#include <iostream>
#include <time.h>
using namespace std;

class Afin
{
    int a;
    int b;
    string alfab;
    public:
        Afin();
        virtual ~Afin();
        int Generar_clave();
        string Emitir(string Palabra);
        string Recibir(string encrip);

};


#endif // AFIN_H
