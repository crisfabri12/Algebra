#include "Cesar.h"

int modulo3(int x)
{
    int q=x/26;
    int r=x-(q*26);
    if(r<0)
        r=26+r;
    return r;
}

Cesar::Cesar(int clave)
{
    alfab = {"abcdefghijklmnopqrstuvwxyz"};
    this->clave = clave;
}

Cesar::~Cesar()
{
    //dtor
}

string Cesar::encriptar(string palabra)
{
    for(int i=0; i<palabra.size();i++)
    {
    palabra[i]=alfab[modulo3(alfab.find(palabra[i])+clave)];
    }
    return palabra;
}

string Cesar::desencriptar(string palabra)
{
    for(int i=0; i<palabra.size();i++)
    {
        palabra[i]=alfab[modulo3(alfab.find(palabra[i])-clave)];
    }
    return palabra;
}
