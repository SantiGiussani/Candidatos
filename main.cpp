#include <iostream>
#include <stdlib.h>
using namespace std;
#include "funciones.h"

int main(){
    int* vCandidatos, numCandidatos;
    int vMunicipios[280] = {};

    numCandidatos = pedirCandidatos(vCandidatos);
    cargarDatos(vCandidatos, vMunicipios, numCandidatos);
    puntoA(vCandidatos, numCandidatos);
    puntoB(vMunicipios, 280);

    delete[] vCandidatos;
    return 0;
}
