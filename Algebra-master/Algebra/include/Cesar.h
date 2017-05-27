#ifndef CESAR_H
#define CESAR_H
#include <stdlib.h>
#include <iostream>
using namespace std;

class Cesar
{
        string alfab;
        int clave;
    public:
        Cesar(int clave);
        virtual ~Cesar();
        string encriptar(string palabra);
        string desencriptar(string palabra);
};

#endif // CESAR_H
