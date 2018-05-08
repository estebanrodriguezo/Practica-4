#ifndef ENRRUTADORES_H
#define ENRRUTADORES_H

#include <iostream>
#include <vector>
#include<conio.h>

using namespace std;

class Enrutador
{
public:
    Enrutador();
    Enrutador(string nombre);
    string nombreNodo;
    vector<Enrutador*> listaDeNodos;
    vector<int> listaCostos;
    vector<int> tablaEnrutamiento;
    vector<Enrutador*> headerTabla;

    // Métodos
    void agregarNodo(Enrutador* nodo, int costo);
    void imprimirNodos();
    void crearTabla();

    void MirarVecinos(Enrutador* nodo, int costo);
    bool nodoYaEstaAgregado(Enrutador* nodo);

    void imprimirNodosAccesibles();
    void camino_corto(Enrutador* nodo);
    void inicializacion();
    void relajar();
};

class floyd{
    int n;
int A[10][10];
int vect1[10];
int vect2[10];
int B[10][10];
public:

void ingresar();
void nodointer();
void floid();
void mostrar1();
void mostrar2();
void preguntar();

};




#endif // ENRUTADORES_H
