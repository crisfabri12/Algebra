#include "Funciones Matematicas.h"
#include <NTL/ZZ.h>
#include "GA.h"
#include <vector>
using namespace NTL;
using namespace std;
ZZ modulo(ZZ a, ZZ n)
{
    ZZ q, r;
	q = a / n;
	r = a - (q*n);
	if (r < 0)
		r += n;
	return r;
}

ZZ euclides(ZZ a, ZZ b)
{
     ZZ residuo = modulo(a,b);
     while(residuo!=0)
     {
         a = b;
         b = residuo;
         residuo = modulo(a,b);
     }
     return b;
}
ZZ mcd(ZZ a, ZZ b)
{
    ZZ resultado;
    resultado = 1;
    ZZ i;
    for(i=1;i<=a;i++)
    {
        if((modulo(a,i)==0)&&(modulo(b,i)==0))
        {
            resultado = i;
        }
    }
    return resultado;
}
std::vector <ZZ> euclides_extendido(ZZ a, ZZ b)
{
    std::vector <ZZ> resultados;
    ZZ r1,s1,t1,r2,s2,t2,q,r;
    r1 = a;
    r2 = b;
    s1 = 1;
    s2 = 0;
    t1 = 0;
    t2 = 1;
    while(r2>0)
    {
        q = r1/r2;

        ZZ r = r1 - q * r2;
        r1 = r2;
        r2 = r;

        ZZ s = s1 - q * s2;
        s1 = s2;
        s2 = s;

        ZZ t = t1 - q * t2;
        t1 = t2;
        t2 = t;

    }
    resultados.push_back(r1);
    resultados.push_back(s1);
    resultados.push_back(t1);
    return resultados;
}
ZZ inversa(ZZ a, ZZ alfabeto)
{
    ZZ x = euclides_extendido(a,alfabeto)[1];
    if(x<0)
    {
        return modulo(x,alfabeto);
    }
    return x;
}

ZZ potencia(ZZ a, ZZ b, ZZ modu)
{
    ZZ result = to_ZZ(1);
    ZZ n = to_ZZ(2);
    while(b != 0){
        if(modulo(b,n)==1){
            result = modulo((result * a),modu);
        }
        a = modulo((a * a),modu);
        b = b/2;
    }
    return result;
}


bool fermat(ZZ p){
    ZZ a;
    a=to_ZZ(3);
    while(true){
        a=ga(4,1024,2,3);
        if(mcd(p,a)==1){
            break;
        }
    }
    if(potencia(a,p-1,p)==1){
        return 1;
    }
    return 0;
}
int moduloo(int a, int n)
{
    int q, r;
	q = a / n;
	r = a - (q*n);
	if (r < 0)
		r += n;
	return r;
}
std::vector<int> criba_Eratostenes(int intervalo_mayor, int intervalo_menor)
{
    std::vector<int>lista(intervalo_mayor,1);
    int j=0,k=0,pivote;//j[0]=2,j[1]=3,...

    while(j<intervalo_mayor){
        while(lista[j]==0){//0 es falso
            j++;
        }
        pivote=j+2;
        k=j+3;j++;
        while(k<intervalo_mayor){
            if(lista[k]==1&&moduloo(k,pivote)==0){
                lista[k]=0;//cout<<k<<endl;
            }
            k++;
        }
    }
    std::vector<int>res;
    for(int i=intervalo_menor;i<intervalo_mayor;i++)
    {
        if(lista[i]==1)
        {
            res.push_back(i);
        }
    }
    return res;
}
int PHI_euler(int num){
    int factorPrimo=2, exp=0,resultado=1;/////////////////////////CALCULAMOS LOS FACTORES
    std::vector<int>exp_factores;
    while(factorPrimo<=num){
        if(moduloo(num,factorPrimo)==0){
            num=num/factorPrimo;
            exp++;
        }
        else{
            factorPrimo++;
            exp_factores.push_back(exp);
            exp=0;
        }
    }
    exp_factores.push_back(exp);
    for(int i=0;i<exp_factores.size();i++){//////////////////////////EMPEZAMOS A CALCULAR EL PHI DE EULER
        if(exp_factores[i]==0)//i[0]=2;i[1]=3... i[n]=n+2
            continue;
        if(exp_factores[i]==1){
            resultado*=i+1;
        }
        else {
            resultado*=(pow((i+2),exp_factores[i])- pow((i+2),exp_factores[i]-1));
        }
    }
    return resultado;
}





