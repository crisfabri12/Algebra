#include "gramal.h"
#include "GA.h"
#include <iostream>
#include <stdlib.h>
#include <NTL/ZZ.h>
#include <sstream>
#include "Funciones Matematicas.h"
using namespace NTL;
using namespace std;

Elgamal::Elgamal(ZZ e_1,ZZ e_2,ZZ p,int bits)
{
    r = ga(bits/4, bits, 20, 3);
    while((r < 2) && (r > p - 2))
    {
        r = ga(bits/4, bits, 20, 3);;
    }
    c  = potencia(e_1, r, p);
    k = potencia(e_2, r, p);
    this->p = p;
    cout<<"c:  "<<c<<endl;
    cout<<"k:  "<<k<<endl;
}


Elgamal::Elgamal(int bits)
{
    generar_claves(bits);
}
ZZ Elgamal::raiz_primitiva(ZZ p)
{
    ZZ q, g;
    q = (p - 1)/2;
    for(int i = 1; i < p - 1; i++)
    {
        g = p - i;
        if((potencia(g, to_ZZ(2), p) != 1) && (potencia(g, q, p) != 1))
        {
            break;
        }
    }
    return q;
}

void Elgamal::generar_claves(int bits)
{
    p = ga(bits/2,bits,sqrt(bits),11);
    while(ProbPrime(p,10)!=1)
    {
        p = ga(bits/2,bits,sqrt(bits),11);
    }
    e_1 = raiz_primitiva(p);
    d = ga(bits/4, bits, 20, 3);
    while((d > (p - 2)) && (d < 2))
    {
        d = ga(bits/4, bits, 20, 3);
    }
    e_2 = potencia(e_1, d, p);
    cout<<"p:  "<<p<<endl;
    cout<<"e_1:  "<<e_1<<endl;
    cout<<"d:  "<<d<<endl;
    cout<<"e_2:  "<<e_2<<endl;


}

string Elgamal::cifrar(string mensaje)
{
    string mensaje_cifrado;
    string digito;
    string temp;
    string aux;
    int pos;
    ZZ aux_2;
    for(int i = 0;i<mensaje.size();i++)
    {
        pos = alfabeto.find(mensaje[i]);
        if(pos<10)
            digito+="0";
        digito+= zzToString(to_ZZ(pos));
    }

    ZZ tam = to_ZZ(digito.size());
    ZZ part = to_ZZ((zzToString(p).size())-1);
    while(modulo(tam,part)!=0){
        pos = alfabeto.find("w");
        digito+= zzToString(to_ZZ(pos));
        tam = to_ZZ(digito.size());
    }
    for(int i=0;i<digito.size();i+=to_int(part))
    {
        int j=0;
        while(j<to_int(part))
        {
            aux+=digito[i+j];
            ++j;
        }
        aux_2 = stringTozz(aux);
        aux = zzToString(modulo((aux_2*k),p));
        int a = aux.size();
        while(to_ZZ(a)<part+1)
        {
            a++;
            temp+="0";

        }
        temp+= aux;
        mensaje_cifrado+=temp;
        aux = "";
        temp = "";
     }

    return mensaje_cifrado;

}


 string Elgamal::descifrar(string cifrado)
{
    k = potencia(c, d, p);
    string original;
    ZZ aux_2;
    string aux;
    ZZ InversaK = inversa(k, p);
    string digitos;
    int pos = 0;
    ZZ part = to_ZZ((zzToString(p).size()));
    for(int i=0;i<cifrado.size();i+=to_int(part))
    {
        int j=0;
        while(j<to_int(part))
        {
            aux+=cifrado[i+j];
            ++j;
        }

        aux_2 = modulo((stringTozz(aux)*InversaK), p);
        aux = zzToString(aux_2);
        int a = aux.size();
        while(to_ZZ(a)<part-1)
        {
            a++;
            digitos+="0";

        }
        digitos+= aux;
        aux = "";
     }
    aux= "";
    for(int i = 0;i<digitos.size();i+=2)
    {
        int j=0;
        while(j<2)
        {
            aux+=digitos[i+j];
            ++j;
        }
        aux_2 = stringTozz(aux);
        pos = to_int(aux_2);
        original+= alfabeto[pos];
        aux = "";
    }
    return original;
}
ZZ Elgamal::get_e1()
{
    return e_1;
}
ZZ Elgamal::get_e2()
{
    return e_2;
}
ZZ Elgamal::get_P()
{
    return p;
}
ZZ Elgamal::get_C1()
{
    return c;
}
void Elgamal::set_d(ZZ d)
{
    this->d = d;
}
void Elgamal::set_P(ZZ P)
{
    this->p = p;
}
void Elgamal::set_c(ZZ c)
{
    this->c = c;
}



void Elgamal::set_e1(ZZ e1)
{
    this->e_1 = e1;
}

void Elgamal::set_e2(ZZ e2)
{
    this->e_2 = e2;
}
void Elgamal::set_k(ZZ k)
{
    this->k = k;
}
