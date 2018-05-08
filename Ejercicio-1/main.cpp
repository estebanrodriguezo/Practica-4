#include <iostream>
#include "enrutadores.h"
#include<conio.h>
using namespace std;

int  main()
{
    Enrutador nodoA("Nodo A");
    Enrutador nodoB("Nodo B");
    Enrutador nodoC("Nodo C");
    Enrutador nodoD("Nodo D");
    Enrutador nodoE("Nodo E");
    Enrutador nodoF("Nodo F");

    nodoA.agregarNodo(&nodoB,4);
    nodoA.agregarNodo(&nodoC,10);
    nodoA.agregarNodo(&nodoF,4);
    nodoA.imprimirNodos();

    nodoB.agregarNodo(&nodoA,4);
    nodoB.agregarNodo(&nodoD,1);
    nodoB.agregarNodo(&nodoE,5);
    nodoB.imprimirNodos();

    nodoC.agregarNodo(&nodoA,10);
    nodoC.agregarNodo(&nodoD,2);
    nodoC.agregarNodo(&nodoE,8);
    nodoC.imprimirNodos();

    nodoD.agregarNodo(&nodoB,1);
    nodoD.agregarNodo(&nodoC,2);
    nodoD.agregarNodo(&nodoF,6);
    nodoD.imprimirNodos();

    nodoE.agregarNodo(&nodoB,5);
    nodoE.agregarNodo(&nodoC,8);
    nodoE.imprimirNodos();

    nodoF.agregarNodo(&nodoA,4);
    nodoF.agregarNodo(&nodoD,6);
    nodoF.imprimirNodos();





    nodoF.crearTabla();

    nodoF.imprimirNodosAccesibles();

    floyd E;
    E.ingresar();
    E.nodointer();
    E.floid();
    E.mostrar1();
    E.mostrar2();
    E.preguntar();
    getch();


    return 0;
}



//// Declaraciones en el archivo .h
//int cn=6; //cantidad de nodos
//vector< vector<int> > ady;

//// Devuelve una matriz con las distancias mínimas de cada nodo al resto de los vértices.
//vector< vector<int> > Grafo :: floydWarshall(){
//    vector< vector<int> > path = this->ady;

//    /* No tendría porqué ser necesario si ya hay ceros en las diagonales de ady */
//    for(int i = 0; i < cn; i++)
//        path[i][i] = 0;

//    for(int k = 0; k < cn; k++)
//        for(int i = 0; i < cn; i++)
//            for(int j = 0; j < cn; j++){
//                int dt = path[i][k] + path[k][j];
//                if(path[i][j] > dt)
//                    path[i][j] = dt;
//            }

//    return path;
//}

