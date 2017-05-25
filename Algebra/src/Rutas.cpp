#include "Rutas.h"

Rutas::Rutas(int clave)
{
    this->clave = clave;
}

Rutas::~Rutas()
{
    //dtor
}

string Rutas::encriptar(string palabra)
{
    int avanza;
    string encriptado;

    for(int i=0;i<clave;i++)
    {
        encriptado += palabra[i];
        avanza = ((2*(clave-i))-2);
        while(avanza+i < palabra.size())
        {
            if(i== 0){
                encriptado += palabra[avanza];
                avanza += ((2*(clave))-2);
            }else if(i == clave-1)
            {
                avanza += (i*2);
                if(avanza+i > palabra.size())
                    break;
                encriptado += palabra[avanza+i];
            }else if(avanza+i != palabra.size()-1){
                encriptado += palabra[avanza+i];
                if(avanza+(i*2)+i < palabra.size()){
                    avanza += i*2;
                    encriptado += palabra[avanza+i];
                }
                avanza += ((2*(clave-i))-2);
            }
            else{
                avanza += ((2*(clave-i))-2);
            }
        }
    }
    return encriptado;
}

string Rutas::desencriptar(string palabra)
{
    string encriptado;
    int avanza = 0;
    for(int i=0;i < palabra.size();i++){
        encriptado += "*";
    }
    int i=0;
    int cont= palabra.size()/clave;
    while(avanza <= palabra.size()){
        int temp = i;
        encriptado[avanza] = palabra[i];
        int pos = avanza;
        avanza += ((2*(clave))-2);
        int avanza2 = avanza;
        while(pos+cont < palabra.size()){
            encriptado[pos+1] = palabra[pos+cont];
            ++cont;
            if((avanza2-1-pos) != pos+1){
                encriptado[avanza2-1-temp] = palabra[pos+cont];
            }
            cont += 2;
            ++pos;
        }
//        if(cont+temp < palabra.size()){
//            encriptado[palabra.size()-i-2] = palabra[temp+cont];
//        }
        i++;
        cont = palabra.size()/clave+i;




    }
//    while (i < palabra.size())
//    {
//        encriptado.insert(0+pos,palabra[i]);
//        ++pos;
//        ++i;
//    }

    return encriptado;

}
