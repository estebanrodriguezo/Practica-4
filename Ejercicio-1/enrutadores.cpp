#include "enrutadores.h"
#include<conio.h>
Enrutador::Enrutador()
{

}

Enrutador::Enrutador(string nombre)
{
    cout << "Enrutador " << nombre << " creado." << endl;
    this->nombreNodo = nombre;
}

void Enrutador::agregarNodo(Enrutador* nodo, int costo)
{
    this->listaDeNodos.push_back(nodo);
    this->listaCostos.push_back(costo);
}

void Enrutador::imprimirNodos()
{
    cout << "A " << this->nombreNodo << " esta conectados los nodos"<< endl;
    for(int i=0; i < this->listaDeNodos.size() ; i++){
        cout << "  - " << this->listaDeNodos[i]->nombreNodo << " con costo: " << this->listaCostos[i] << endl;
    }
}

void Enrutador::crearTabla()
{
    this->MirarVecinos(this, 0);
}

void Enrutador::MirarVecinos(Enrutador* nodo, int costo)
{
    for(int i=0; i < nodo->listaDeNodos.size() ; i++){
        if(!nodoYaEstaAgregado(nodo->listaDeNodos[i]) && !(nodo->listaDeNodos[i] == this)){
            this->headerTabla.push_back(nodo->listaDeNodos[i]);
            this->tablaEnrutamiento.push_back(costo + nodo->listaCostos[i]);
            MirarVecinos(listaDeNodos[i], nodo->listaCostos[i]);
        }
    }
}

bool Enrutador::nodoYaEstaAgregado(Enrutador *nodo)
{
    bool flag = false;
    for(int i=0; i < this->headerTabla.size() ; i++){
        if(this->headerTabla[i] == nodo){
            flag = true;
        }
    }
    return flag;
}

void Enrutador::imprimirNodosAccesibles()
{
    cout << "A " << this->nombreNodo << " esta asociados los nodos"<< endl;
    for(int i=0; i < this->headerTabla.size() ; i++){
        cout << "  - " << this->headerTabla[i]->nombreNodo << " costo: "<< this->tablaEnrutamiento[i] << endl;
    }
}

///////////////////////////////////////////////////////////////////////////////
void floyd::ingresar(){
    cout<<"ingrese numero de nodos: ";
    cin>>n;
    int i,j;
 for(i=1;i<=n;i++)
    for(j=1;j<=n;j++){
    cout<<"ingrese matriz de ["<<i<<"]["<<j<<"] ";
    cin>>A[i][j];    }
}

void floyd::nodointer()
{int i,j;
    for(i=1;i<=6;i++)
    for(j=1;j<=6;j++)
    {if(i==j)
    B[i][j]=0;
    else B[i][j]=j;}
}

void floyd::floid()
{int bucle,i,j,suma;
    for(bucle=1;bucle<=n;bucle++){
for(i=1;i<=n;i++){
vect1[i]=A[bucle][i];
vect2[i]=A[i][bucle];
}

for(i=1;i<=n;i++)
for(j=1;j<=n;j++){
if(vect2[i]==999 || vect1[j]==999) suma=999;
else suma=vect2[i]+vect1[j];
if(suma<A[i][j]){
A[i][j]=suma;
B[i][j]=bucle;}

}}}

void floyd:: mostrar1()
{int i,j;
    cout<<"imprime distancias o pesos optimo "<<endl;
      for(i=1;i<=n;i++){
    for(j=1;j<=n;j++)
    {cout<<A[i][j]<<"\t";}
cout<<endl;}
}

void floyd:: mostrar2()
{int i,j;
    cout<<"imprime matriz intermedios "<<endl;
      for(i=1;i<=n;i++){
    for(j=1;j<=n;j++)
    {cout<<B[i][j]<<"\t";}
cout<<endl;}
}

void floyd:: preguntar()
{int i,j;
    cout<<"de que vertice a que vertice desea ir : "<<endl;
cin>>i>>j;
if(i==0 || j==0 || i==j)
cout<<"distancia minima es 0 "<<endl;
else{
cout<<"distancia minima "<<endl;
cout<<A[i][j]<<endl;
cout<<"pasa por el "<<B[i][j]<<" y despues por el "<<j<<endl;}
getch();
}

