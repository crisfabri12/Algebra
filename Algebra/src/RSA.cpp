#include "RSA.h"
#include "GA.h"
#include <iostream>
#include <stdlib.h>
#include <NTL/ZZ.h>
#include <sstream>
#include "Funciones Matematicas.h"
using namespace NTL;
using namespace std;

string RSA::zzToString(ZZ z) {
    stringstream buffer;
    buffer << z;
    return buffer.str();
}
ZZ RSA::stringTozz(string str){
    ZZ number(INIT_VAL, str.c_str());
    return number;
}
vector<bool> ZZtoBinary(ZZ num){
    vector<bool> binario;
    while(num>0){
        binario.push_back(to_int(modulo(num,to_ZZ(2))));
        num=num>>1;
    }
    return binario;
}

ZZ potenciaMod(ZZ n, ZZ m, ZZ mod){
    if(n>mod)
        n=modulo(n,mod);
    vector<bool> b=ZZtoBinary(m);
    ZZ d=to_ZZ(1);
	for(int i=b.size();i>0;i--){
        d=modulo(d*d,mod);
        if(b[i-1]==1)
            d=modulo(d*n,mod);
	}
	return d;
}

void RSA::generar_claves(int bits)
{
    ZZ p = ga(bits/2,bits,sqrt(bits),11);
    ZZ q = ga(bits/2,bits,sqrt(bits),11);
    while(ProbPrime(p,10)!=1)
    {
        p = ga(bits/2,bits,sqrt(bits),11);
    }
    while(ProbPrime(q,10)!=1)
    {
        q = ga(bits/2,bits,sqrt(bits),1);
    }
    N = p * q;
    this->p = p;
    this->q = q;
    this->N = N;
    ZZ phi_N =(p-1)*(q-1);
    ZZ e = ga(bits/2,bits,sqrt(bits),11);
    while(e > phi_N || euclides(e, phi_N) != 1)
    {
        e = ga(bits/2,bits,sqrt(bits),11);
    }
    cout <<"Clave publica: " << e << endl;
    this->e = e;
    this->d = inversa(e, phi_N);
    cout << "Clave privada: " << d << endl;
    cout <<"N: " << N << endl;
}
RSA::RSA(ZZ e, ZZ n) //EMISOR
{
    e = e;
    N = n;
    alfabeto = "abcdefghijklmnñopqrstuvwxyz ABCDEFGHIJKLMNÑOPQRSTUVWXYZ0123456789.,;:-_()@{}+/";
}
RSA::RSA(int bits) //RECEPTOR
{
    generar_claves(bits);
    alfabeto = "abcdefghijklmnñopqrstuvwxyz ABCDEFGHIJKLMNÑOPQRSTUVWXYZ0123456789.,;:-_()@{}+/";
}
ZZ RSA::get_N()
{
    return N;
}
ZZ RSA::get_clave_publica()
{
    return e;
}
string RSA::cifrar(string mensaje)
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
    ZZ part = to_ZZ((zzToString(N).size())-1);
    while(modulo(tam,part)!=0){
        pos = alfabeto.find("*");
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
        aux_2 = potenciaMod(aux_2,e,N);
        aux = zzToString(aux_2);
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


 string RSA::descifrar(string cifrado)
{
    string original;
    ZZ aux_2;
    string aux;
    string digitos;
    int pos = 0;
    ZZ part = to_ZZ((zzToString(N).size()));
    for(int i=0;i<cifrado.size();i+=to_int(part))
    {
        int j=0;
        while(j<to_int(part))
        {
            aux+=cifrado[i+j];
            ++j;
        }

        aux_2 = stringTozz(aux);
        aux_2 = resto_chino(aux_2);
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
void RSA::set_p(ZZ a){
    this -> p = a;
}

void RSA::set_q(ZZ b){
    this -> q = b;
}

void RSA::set_N(ZZ c){
    this -> N = c;
}

void RSA::set_d(ZZ x){
    this -> d = x;
}

void RSA::set_e(ZZ y){
    this -> e = y;
}

ZZ RSA::resto_chino(ZZ c){
    ZZ x;
    ZZ d_1 = modulo(this->d,this->p -1);
    ZZ d_2 = modulo(this->d,this->q -1);
    ZZ a_1 = potenciaMod(c,d_1,p);
    ZZ a_2 = potenciaMod(c,d_2,q);
    ZZ q_1 = inversa(q,p);
    ZZ q_2 = inversa(p,q);
    x = modulo(a_1 * q * q_1,this->N);
    x+= modulo(a_2 * p * q_2,this->N);
    return modulo(x,this->N);
}

