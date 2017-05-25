#include "Afin.h"
#include <stdlib.h>
int modulo_(int x,int y)
{
    int q=x/y;
    int r=x-(y*q);
    if(r<0)
        r=y+r;
    return r;
}
int MCD(int x , int y){
    int r;
	while(r!=0)
	{
		r=modulo_(x,y);
		x=y;
		y=r;
	}
	return(x);
}
int inversomod(int a,int b){

    int r1 = a, r2 = b;
    int x1 = 1, x2 = 0;
    int y1 = 0, y2 = 1;

    int q , r , x , y;

    while(r2>0){
        q = r1/r2;

        r = r1 - q*r2;
        r1 = r2;
        r2 = r;

        x = x1 -q*x2;
        x1 = x2;
        x2 = x;

        y = y1 - q*y2;
        y1 = y2;
        y2 = y;
    }
    return x1;

}

Afin::Afin()
{
    alfab = {"abcdefghijklmnopqrstuvwxyz"};
    Generar_clave();


}

Afin::~Afin()
{
    //dtor
}

Afin::Generar_clave()
{
    int clave;
    int s = alfab.size();
    srand(time(NULL));
    clave = rand()%s;
    while(MCD(clave,s)!= 1)
    {
        int nuevo;
        nuevo = rand()%s;
        clave = nuevo;
    }
    this->a = clave;
    this->b = rand()%s;
}

string Afin::Emitir(string palabra)
{
    int x,s = alfab.size();
    int aux;
    string encrip;
    for(int i = 0;i<palabra.size();i++)
    {
        x = alfab.find(palabra[i]);
        aux = (x*a)+b;
        encrip += alfab[modulo_(aux,s)];
    }
    return encrip;
}

string Afin::Recibir(string encrip)
{
    int s= alfab.size(),x,aux,j;
    string original;
    for(int i =0;i<encrip.size();i++)
    {
        j = alfab.find(encrip[i]);
        cout<<j<<endl;
        x = inversomod(a,s);
        if(x < 0)
        {
            x = modulo_(x,s);
        }
        aux = (j-b)*x;
        original += alfab[modulo_(aux,s)];
    }
    return original;
}
