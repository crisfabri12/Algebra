#include <iostream>
#include <NTL/ZZ.h>
#include <string>
#include <Cesar.h>
#include <Afin.h>
#include "RSA.h"
#include <fstream>
#include "GA.h"
#include "gramal.h"
#include <time.h>
#include "Funciones Matematicas.h"
using namespace std;
using namespace NTL;

main()
{
//    srand(time(NULL));
//    ifstream ficheroEntrada;
//    string mensaje;
//    ficheroEntrada.open ("entrada.txt",ios::out | ios::binary);
//    getline(ficheroEntrada,mensaje);
//    ficheroEntrada.close();
//    RSA s(1024);
//    string encriptado = s.cifrar(mensaje);
//    string original = s.descifrar(encriptado);
//    cout<<original;
//    ofstream ficherosalida;
//    ficherosalida.open ("salida.txt");
//    ficherosalida << original;
//    ficherosalida.close();
    gramal r(512);
    ZZ e_1,e_2,p,c;
    e_1 = stringTozz(zzToString(r.get_e1()));
    e_2 = stringTozz(zzToString(r.get_e2()));
    p = stringTozz(zzToString(r.get_P()));
    gramal s(e_1,e_2,p,512);
    string cifrado = s.cifrar("hola que tal");
    cout<<cifrado<<endl;
    c = stringTozz(zzToString(s.get_C1()));
    r.set_c(c);
    string original = r.descifrar(cifrado);
    cout<<original;


};
