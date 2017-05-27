//#include "Funciones int.h"
//#include <math.h>
//#include <iostream>
//using namespace std;
//int moduloulo(int a, int n)
//{
//    int q, r;
//	q = a / n;
//	r = a - (q*n);
//	if (r < 0)
//		r += n;
//	return r;
//}
//int euclides(int a, int b)
//{
//     int residuo = moduloulo(a,b);
//     while(residuo!=0)
//     {
//         a = b;
//         b = residuo;
//         residuo = moduloulo(a,b);
//     }
//     return b;
//}
//int mcd(int a, int b)
//{
//    int resultado;
//    resultado = 1;
//    int i;
//    for(i=1;i<=a;i++)
//    {
//        if((moduloulo(a,i)==0)&&(moduloulo(b,i)==0))
//        {
//            resultado = i;
//        }
//    }
//    return resultado;
//}
//std::vector <int> euclides_extendido(int a, int b)
//{
//    std::vector <int> resultados;
//    int r1,s1,t1,r2,s2,t2,q,r;
//    r1 = a;
//    r2 = b;
//    s1 = 1;
//    s2 = 0;
//    t1 = 0;
//    t2 = 1;
//    while(r2>0)
//    {
//        q = r1/r2;
//
//        int r = r1 - q * r2;
//        r1 = r2;
//        r2 = r;
//
//        int s = s1 - q * s2;
//        s1 = s2;
//        s2 = s;
//
//        int t = t1 - q * t2;
//        t1 = t2;
//        t2 = t;
//
//    }
//    resultados.push_back(r1);
//    resultados.push_back(s1);
//    resultados.push_back(t1);
//    return resultados;
//}
//int inversa(int a, int alfabeto)
//{
//    int x = euclides_extendido(a,alfabeto)[1];
//    if(x<0)
//    {
//        return moduloulo(x,alfabeto);
//    }
//    return x;
//}
//
//int potencia(int a, int b, int modulou)
//{
//    int result = 1;
//    int n = 2;
//    while(b != 0){
//        if(moduloulo(b,n)==1){
//            result = moduloulo((result * a),modulou);
//        }
//        a = moduloulo((a * a),modulou);
//        b = b/2;
//    }
//    return result;
//}
//void resto_chino(int a[],int b[],int tam)
//{
//    int p=1;
//    int p_i[tam];
//    int q_i[tam];
//    for(int i=0;i<tam;i++)
//    {
//        p *= b[i];
//    }
//    for(int i=0;i<tam;i++)
//    {
//        p_i[i] = p/b[i];
//    }
//    for(int i=0;i<tam;i++)
//    {
//        q_i[i] = inversa(p_i[i],b[i]);
//    }
//    int x_0 = 0;
//    for(int i=0;i<tam;i++)
//    {
//        x_0 += a[i]*p_i[i]*q_i[i];
//    }
//    x_0 = moduloulo(x_0,p);
//    cout<<x_0<<"+"<<p<<"k"<<endl;
//}
//
//void Teorema_resto()
//{
//        int t;
//    cout<<"ingrese la cantidad de ecuaciones: ";
//    cin>>t;
//    int p[t];
//    int q[t];
//    for(int i=0;i<t;i++)
//    {
//        cout<<"Ingrese a"<<i<<": ";
//        cin>>p[i];
//        cout<<"Ingrese su moduloulo"<<i<<": ";
//        cin>>q[i];
//    }
//    for(int i=0;i<t;i++)
//    {
//        cout<<"x="<<p[i]<<"(modulo "<<q[i]<<")"<<endl;
//    }
//    resto_chino(p,q,t);
//}
//int exponenciacion_1(int a,int p, int n)
//{
//    int r = 1;
//    for(int i=0;i<p;i++)
//    {
//        r = modulo(r*a,n);
//    }
//    return r;
//}
//
//int exponenciacion_2(int a,int p,int n)
//{
//    int r;
//    if(p == 0)
//    {
//        return 1;
//    }
//    if(modulo(p,2)==0)
//    {
//        r = exponenciacion_2(a,p/2,n);
//        r = r*r;
//        return modulo(r,n);
//    }
//    r =exponenciacion_2(a,(p-1)/2,n);
//    return modulo(a*modulo(r*r,n),n);
//}
//int PHI_euler(int num){
//    int factorPrimo=2, exp=0,resultado=1;/////////////////////////CALCULAMOS LOS FACTORES
//    vector<int>exp_factores;
//    while(factorPrimo<=num){
//        if(moduloulo(num,factorPrimo)==0){
//            num=num/factorPrimo;
//            exp++;
//        }
//        else{
//            factorPrimo++;
//            exp_factores.push_back(exp);
//            exp=0;
//        }
//    }
//    exp_factores.push_back(exp);
//    for(int i=0;i<exp_factores.size();i++)
//        cout<<exp_factores[i]<<endl;
//
//    for(int i=0;i<exp_factores.size();i++){//////////////////////////EMPEZAMOS A CALCULAR EL PHI DE EULER
//        if(exp_factores[i]==0)//i[0]=2;i[1]=3... i[n]=n+2
//            continue;
//        if(exp_factores[i]==1){
//            resultado*=i+1;
//        }
//        else {
//            resultado*=(pow((i+2),exp_factores[i])- pow((i+2),exp_factores[i]-1));
//        }
//        cout<<"adfss"<<endl;
//    }
//    return resultado;
//}
//int modulo(int a,int b){
//    int q,r;
//	q = a/b;
//	r = a - (q*b);
//	if (r<0)
//		r=r+b;
//	return r;
//}
//
//void random(int seed,int a, int b, int n){
//    int aux;
//    int x = seed;
//    aux = (a*x) + b;
//    x = modulo(aux,n);
//    cout<<x<<endl;
//    while(x!= seed){
//        aux = (a*x) + b;
//        x = modulo(aux,n);
//        cout<<x<<endl;
//        }
//}
//
//int euclides_(int a, int b){
//    if(b == 0)
//        return a;
//    return euclides(b, modulo(a,b));
//}
//
//vector<int> mcd_(int a, int b){
//    int u=1,g=a,x=0,y=b,r,s,q,v;
//    while (y!=0){
//        r = modulo(g,y);
//        q = g/y;
//        s = u-q*x;
//        u=x;g=y;
//        x=s;y=r;
//    }
//    if(b==0){
//        g=a;u=1,v=0;
//    }
//    else
//        v=(g-a*u)/b;
//    if(u<0)u=u+b;
//    vector<int> resultado;
//    resultado.push_back(g);
//    resultado.push_back(u);
//    resultado.push_back(v);
//    return resultado;
//}
//
//int abs(int x){
//    if(x<0)return -1*x;
//    return x;
//}
//
//int xx(int a,int b)
//{
//    if(a==0)
//        return b;
//    else if (b==0)
//        return a;
//    else if ((modulo(a,2) == 0) and (modulo(b,2)==0))
//        return 2 * xx(a/2,b/2);
//    else if ((modulo(a,2) == 0) and (modulo(b,2)==1))
//        return xx(a/2,b);
//    else if ((modulo(a,2) == 1) and (modulo(b,2)==0))
//        return xx(a,b/2);
//    else
//        return xx(abs(a-b)/2,a);
//}
//
//int gcd(int a, int b){
//    if(a<b){
//        int temp=a;
//        a=b;
//        b=temp;
//    }
//    int g=1,t;
//    while(modulo(a,2)==0 and modulo(b,2)==0){
//        a/=2; b/=2; g*=2;
//    }
//    while(a!=0){
//        cout<<a<<b<<endl;
//        while(modulo(a,2)==0)
//            a/=2;
//        while(modulo(b,2)==0)
//            b/=2;
//        t=abs(a-b)/2;
//        if(a>=b)
//            a=t;
//    }
//    return g*b;
//}
//
//int ejercicio8(int N,int g,int A)
//{
//    int a = g;
//    int b = 1;
//    while(A > 0)
//    {
//        if(modulo(A,2) == 1)
//           {
//               b = modulo((b*a),N);
//           }
//        a = exponenciacion_1(a,2,N);
//        A = A/2;
//    }
//    return b;
//}
//
//vector<int> ejercicio9(int a,int b)
//{
//    vector<int> res(3,0);
//    vector<int> t(3,0);
//    if(b == 0)
//    {
//        res[0] = a;
//        res[1] = 1;
//        res[2] = 0;
//        return res;
//    }
//    int q = modulo(a,b);
//    int r = (a-q)/b;
//    t = ejercicio9(b,q);
//    res[0] = t[0];
//    res[1] = t[2];
//    res[2] = t[2]-t[1]*r;
//    return res;
//}
//
//int* primos(int n)
//{
//    int s[n/2+1];
//    bool es_primo;
//    int pos=0;
//    for(int j = 2;j<n;j++)
//    {
//        es_primo = true;
//        for(int i=0;i<pos;i++)
//        {
//            if (modulo(j,s[i]) == 0)
//            {
//                es_primo= false;
//                break;
//            }
//        }
//        if(es_primo == true)
//        {
//            s[pos] = j;cout<<s[pos]<<endl;
//            pos++;
//        }
//    }
//    s[pos]=-1;
//    return &s[0];
//}
//
//vector<int> criba_Eratostenes(int n){
//    vector<int>lista(n-1,1);
//    int j=0,k=0,pivote;//j[0]=2,j[1]=3,...
//
//    while(j<n-2){
//        while(lista[j]==0){//0 es falso
//            j++;
//        }
//        pivote=j+2;
//        k=j+3;j++;
//        while(k<n){
//            if(lista[k]==1&&modulo(k,pivote)==0){
//                lista[k]=0;//cout<<k<<endl;
//            }
//            k++;
//        }
//    }
//    vector<int>res;
//    for(int i=0;i<n-2;i++)
//    {
//        if(lista[i]==1)
//        {
//            res.push_back(i);
//        }
//    }
//    return res;
//}



//
//int inverse(int a, int n){
//    vector<int>res(3,0);
//    res=mcd(a,n);
//    if(res[0]==1)return res[1];
//    cout<< "No inverse";
//    return -1;
//}


