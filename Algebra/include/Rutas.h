#ifndef RUTAS_H
#define RUTAS_H
#include <iostream>
#include <time.h>
using namespace std;
class Rutas
{
    int clave;
    public:
        Rutas(int clave);
        virtual ~Rutas();
        string desencriptar(string palabra);
        string encriptar(string palabra);

};

#endif // RUTAS_H
