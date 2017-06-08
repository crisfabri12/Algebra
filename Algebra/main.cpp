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
//    ficheroEntrada.open("entrada.txt",ios::out | ios::binary);
//    getline(ficheroEntrada,mensaje);
//    ficheroEntrada.close();
//    RSA emisor(512);
//    string encriptado = emisor.cifrar(mensaje);
//    ofstream encrip;
//    encrip.open ("encriptado.txt");
//    encrip << encriptado;
//    encrip.close();
//    ofstream e;
//    e.open("clave_e.txt");
//    e<<emisor.get_clave_publica();
//    e.close();
//    ofstream n;
//    n.open("clave_n.txt");
//    n<<emisor.get_N();
//    n.close();
////    ZZ e = to_ZZ();
////    ZZ d = to_ZZ();
////    ZZ p = to_ZZ();
////    ZZ q = to_ZZ();
////    ZZ N = to_ZZ();
////    RSA receptor(e,N);
////    receptor.set_p(p);
////    receptor.set_q(q);
////    receptor.set_d(d);
////    string original = receptor.descifrar(encriptado);
////    cout<<original;
////    ofstream ficherosalida;
////    ficherosalida.open ("salida.txt");
////    ficherosalida << original;
////    ficherosalida.close();



//    Elgamal r(512);
//    ZZ e_1,e_2,p,c;
//    e_1 = stringTozz("5162954591453389165598544172431244981515303983012685238851121718334532700671678690237907162774041236372239289482979868708368705015144711109190579808391260");
//    e_2 = stringTozz("6976040546996372950497327444112067979262336627261554444627586054408551438053946730633366918964810812906999361900436984705437574779717821988645440258238713");
//    p = stringTozz("10325909182906778331197088344862489963030607966025370477702243436669065401343357380475814325548082472744478578965959737416737410030289422218381159616782521");
//    r.set_e1(e_1);
//    r.set_e2(e_2);
//    r.set_P(stringTozz("10325909182906778331197088344862489963030607966025370477702243436669065401343357380475814325548082472744478578965959737416737410030289422218381159616782521"));
//    r.set_d(stringTozz("2166124225646099103457058145847597278053528241729525493682239271446240139106500112124700886814481697855239807206945356263035899355484791505556959564074958"));
//    Elgamal s(e_1,e_2,p,512);
//    string cifrado = s.cifrar("hola que tal");
//    cout<<cifrado<<endl;
//    c = stringTozz(zzToString(s.get_C1()));
//    r.set_c(stringTozz("673143501351586795674843607345005867473317849332132037645190702000138600211717383863637153008358328448619424805197370845071352598242904981442772615688384"));
//    string original = r.descifrar(cifrado);
//    cout<<original;

    vector<int > r =criba_Eratostenes(50,3);
    for(int i=0;i<r.size();i++)
    {
        cout<<r[i]<<endl;
    }








};
