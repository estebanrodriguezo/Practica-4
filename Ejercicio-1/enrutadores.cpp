#include "enrutadores.h"

Enrutador::Enrutador()
{

}


Enrutador::Enrutador(string nombre)
{
    cout << "Enrutador " << nombre << " creado." << endl;
    this->nombreNodo = nombre;
}
