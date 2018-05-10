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


