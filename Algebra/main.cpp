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
    ficheroEntrada.open ("entrada.txt",ios::out | ios::binary);
    getline(ficheroEntrada,mensaje);
    ficheroEntrada.close();
    RSA s(1024);
    string encriptado = s.cifrar(mensaje);
    string original = s.descifrar(encriptado);
    cout<<original;
    ofstream ficherosalida;
    ficherosalida.open ("salida.txt");
    ficherosalida << original;
    ficherosalida.close();

};
