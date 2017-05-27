#include <iostream>
#include <NTL/ZZ.h>
#include <string>
#include <Cesar.h>
#include <Afin.h>
#include "RSA.h"
#include <fstream>
#include "GA.h"
#include <time.h>
#include "Funciones Matematicas.h"
using namespace std;
using namespace NTL;

main()
{
    srand(time(NULL));
    ifstream ficheroEntrada;
    string mensaje;
    ficheroEntrada.open("entrada.txt",ios::out | ios::binary);
    getline(ficheroEntrada,mensaje);
    ficheroEntrada.close();
    RSA emisor(512);
    string encriptado = emisor.cifrar(mensaje);
    ofstream encrip;
    encrip.open ("encriptado.txt");
    encrip << encriptado;
    encrip.close();
    ofstream e;
    e.open("clave_e.txt");
    e<<emisor.get_clave_publica();
    e.close();
    ofstream n;
    n.open("clave_n.txt");
    n<<emisor.get_N();
    n.close();
//    ZZ e = to_ZZ();
//    ZZ d = to_ZZ();
//    ZZ p = to_ZZ();
//    ZZ q = to_ZZ();
//    ZZ N = to_ZZ();
//    RSA receptor(e,N);
//    receptor.set_p(p);
//    receptor.set_q(q);
//    receptor.set_d(d);
//    string original = receptor.descifrar(encriptado);
//    cout<<original;
//    ofstream ficherosalida;
//    ficherosalida.open ("salida.txt");
//    ficherosalida << original;
//    ficherosalida.close();

};
