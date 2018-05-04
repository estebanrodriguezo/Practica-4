#include "enrutadores.h"

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
    cout << "A " << this->nombreNodo << " está asociados los nodos"<< endl;
    for(int i=0; i < this->headerTabla.size() ; i++){
        cout << "  - " << this->headerTabla[i]->nombreNodo << " costo: "<< this->tablaEnrutamiento[i] << endl;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Declarando variables
#define MAX_NODOS 1024 /* número máximo de nodos */
#define INFINITO 1000000000 /* un número mayor que cualquier ruta máxima */
int n,i,k,minimo, dist[MAX_NODOS][MAX_NODOS]; /* dist[i][j] es la distancia de i a j */

struct nodo { /* Indica eL estado del nodo,la ruta y quien lo precede a dicho nodo */
    int predecesor; /* nodo previo */
    int longitud; /* longitud del origen a este nodo */
    bool etiqueta;	/*verdadero para un nodo permanente y falso para nodo tentativo*/
} nodo[MAX_NODOS];

void Enrutador :: inicializacion(){
    int p;
    for (p = &listaDeNodos[0]; p < &listaDeNodos[6]; p++) { /* estado de inicialización*/
            p->predecesor = -1;
            p->longitud = INFINITO;
            p->etiqueta = false;
        }
}
void Enrutador ::relajar(){
    for (int i = 0; i <6; i++){ /* este grafo tiene n nodos */
            if (dist[k][i] != 0 && listaDeNodos[i].etiqueta == false) {
                if (nodo[k].longitud + dist[k][i] < nodo[i].longitud) {
                    nodo[i].predecesor = k;
                        nodo[i].longitud = nodo[k].longitud + dist[k][i];
                }
                }
        }
}
void extraer_minimo(){ 	/* Encuentra los nodo etiquetados tentativamente y determina el menor entre estos nodos tentativos. */
    k = 0;
    minimo = INFINITO;
    for (i = 0; i < n; i++){
        if (nodo[i].etiqueta == false && nodo[i].longitud < minimo) {
            minimo = nodo[i].longitud;
            k = i;
        }
    }
}

void camino_corto(int s, int t, int camino[]) {
    inicializacion();
    nodo[t].longitud = 0; nodo[t].etiqueta = true;
    k = t; /* k es el nodo de trabajo inicial */
    do{ /* ¿hay una ruta mejor desde k? */
        relajar();
        extraer_minimo();
        nodo[k].etiqueta = true;
    } while (k != s);
    /* Copia la ruta en el arreglo de salida y procede a ir imprimiendolo. */
    i = 0; k = s;
    cout<< "La ruta es: ";
    do {
        cout<< k<< " ";
        camino[i] = k;
        k = nodo[k].predecesor;
        i++;
    } while (k >= 0);
    cout <<"La ruta minima es: "<<minimo<<endl ;
}























