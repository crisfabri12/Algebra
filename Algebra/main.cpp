#include <iostream>
#include <NTL/ZZ.h>
#include <string>
#include <Cesar.h>
#include <Afin.h>
#include "RSA.h"
#include <fstream>
#include "GA.h"
#include <sstream>
#include <time.h>
#include "Funciones Matematicas.h"
using namespace std;
using namespace NTL;
string zzToString(ZZ z) {
    stringstream buffer;
    buffer << z;
    return buffer.str();
}
ZZ stringTozz(string str){
    ZZ number(INIT_VAL, str.c_str());
    return number;
}
main()
{
    srand(time(NULL));
    ifstream ficheroEntrada;
    string mensaje;
    ficheroEntrada.open ("entrada.txt",ios::out | ios::binary);
    getline(ficheroEntrada,mensaje);
    ficheroEntrada.close();
    RSA emisor(512);
    emisor.set_p(stringTozz("6262628098190764497111100751110739700487221461908733893521244404139801415321068177697604809930334598515815847894652125287889555682490848912990593222347761"));
    emisor.set_q(stringTozz("9060464282949476286438060144741035082299673908446487765196008397830100513123796974203369301040936203721862857878869698693729344799746914467300771300419389"));
    emisor.set_N(stringTozz(" 56742318201053227418361638706512654116629903397700379461728039904834464522225753921831752883086105737129871796783477845159065741049931203103870947228057347477662438347050363870907185010077218622813438409301456928739666437415687259898196394800484367892196362341812306575452134101116651641985324028986505138029"));
    emisor.set_d(stringTozz("48700714418644682078752014685690970653323179086129359139207152394551129052028704498077817161714707885406013344569622826600371617435610756541728718374028303745590586289523972442138928898433579165145013070739748018390617165954704246864508954537450320282205260311812688691864296654667448090450283551982119110659"));
    emisor.set_e(stringTozz("12125676050909829925939214189821235281948924508780040649337300009927211492585213929681910958554779911776724686901192984004146226873500093599887644436542699"));
    string original = emisor.descifrar(mensaje);
    cout<<original;
    ofstream ficherosalida;
    ficherosalida.open ("salida.txt");
    ficherosalida << original;
    ficherosalida.close();
    //    ZZ e;
//    e = stringTozz("");
//    ZZ n;
//    n = stringTozz("");
//    RSA receptor(e,n);
////    string encriptado = receptor.cifrar(mensaje);
////    ofstream salida;
////    salida.open ("encriptado.txt");
////    salida << encriptado;
////    salida.close();

};
