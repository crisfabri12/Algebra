#include "RSA.h"
#include "GA.h"
#include <iostream>
#include <stdlib.h>
#include <NTL/ZZ.h>
#include <sstream>
#include "Funciones Matematicas.h"
using namespace NTL;
using namespace std;

string zzToString(ZZ z) {
    stringstream buffer;
    buffer << z;
    return buffer.str();
}
ZZ stringTozz(string str){
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
    cout <<"e: " << e << endl;
    this->e = e;
    this->d = inversa(e, phi_N);
    cout <<"d: " << d << endl;
    cout <<"p: " << p << endl;
    cout <<"q: " << q << endl;
    cout <<"N: " << N << endl;
}
RSA::RSA(ZZ e, ZZ n) //EMISOR
{
    e = e;
    N = n;
    alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .,;# *";
}
RSA::RSA(int bits) //RECEPTOR
{
    generar_claves(bits);
    alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .,;# *";
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
        string message;
        string temp="";
        string letra;
        string aux;
        ZZ num;
        int tam = zzToString(to_ZZ(alfabeto.length()-1)).length();
        int tamN= zzToString(N).length();
        for(int i=0;i<mensaje.length();i++){
                letra=zzToString(to_ZZ(alfabeto.find(mensaje[i])));
                while(letra.length()<tam){
                    aux=letra;
                    letra="0";
                    letra+=aux;
                }
                temp+=letra;
        }
        while(temp.length()%(tamN-1)!=0){
                temp+=zzToString(to_ZZ(alfabeto.find("#")));
        }
        for(int i=0;i<temp.length();i+=tamN-1){
            letra="";
            for(int j=0;j<tamN-1;j++){
                letra+=temp[j+i];
            }
            num=potenciaMod(stringTozz(letra),e,N);
            letra=zzToString(num);
            while(letra.length()<tamN){
                aux=letra;
                letra="0";
                letra+=aux;
            }
            message+=letra;
        }
        return message;

}


 string RSA::descifrar(string cifrado)
{
        string message;
        string letra;
        string temp;
        string aux;
        ZZ num;
        int tam = zzToString(to_ZZ(alfabeto.length()-1)).length();
        int tamN= zzToString(N).length();
        for(int i=0;i<cifrado.length();i+=tamN){
            letra="";
            for(int j=0;j<tamN;j++){
                letra+=cifrado[j+i];
            }
            num=stringTozz(letra);
            letra=zzToString(resto_chino(num));
            while(letra.length()<tamN-1){
                aux=letra;
                letra="0";
                letra+=aux;
            }
            temp+=letra;
        }
        for(int i=0;i<temp.length();i+=tam){
            letra="";
            for(int j=0;j<tam;j++){
                letra+=temp[j+i];
            }
            message+=alfabeto[to_int(stringTozz(letra))];
        }
//        while(message[message.length()-1]=='#'){
//            aux="";
//            for(int i=0;i<message.length()-1;i++)
//                aux+=message[i];
//            message=aux;
//        }
        return message;
}

void RSA::set_e(ZZ x)
{
    this->e = x;
}
void RSA::set_d(ZZ x){
    this->d = x;
}
void RSA::set_N(ZZ x){
    this->N = x;
}
 void RSA::set_p(ZZ x)
 {
     this->p = x;
 }
void RSA::set_q(ZZ x)
{
    this->q = x;
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

