#include "funciones.h"
#include <iostream>
using namespace std;

int pedirCandidatos(int* &vCandidatos){
    int numCandidatos;
    cout << "Digite el numero de candidatos: ";
    cin >> numCandidatos;
    vCandidatos = new int [numCandidatos]();
    if (vCandidatos != nullptr){
        cout << "Hay memoria" << endl << endl;
    }
    else{
        cout << "No hay memoria" << endl << endl;
    }
    for (int i=0; i<numCandidatos; i++){
        vCandidatos[i]=0;
    }
    return numCandidatos;
}

void cargarDatos(int *vCandidatos, int *vMunicipios, int numCandidatos){
    int candidato, municipio, cantidad;
    cout << "Municipio: ";
    cin >> municipio;

    while (municipio >= 0){
        cout << "Candidato: ";
        cin >> candidato;
        while (candidato > numCandidatos || candidato < 1){
            cout << "Numero de candidato invalido. Intente de nuevo" << endl;
            cout << "Candidato: ";
            cin >> candidato;
        }

        cout << "Votos: ";
        cin >> cantidad;

        // A
        vCandidatos[candidato-1] += cantidad;
        // B
        vMunicipios[municipio-1] += cantidad;

        cout << "Municipio: ";
        cin >> municipio;
    }
}
void puntoA(int *vCandidatos, int cantidadCandidatos){
    int candidatoMasVotado = buscarIndiceMaximo(vCandidatos, cantidadCandidatos);
    cout << "Cantidato más votado: " << candidatoMasVotado + 1;
    cout << " con " << vCandidatos[candidatoMasVotado] << " votos" << endl;
}
void puntoB(int vMunicipios[], int cantidadMunicipios){
    int cantMunicipios = contarMayoresAReferencia(vMunicipios, cantidadMunicipios, 5000);
    cout << "Cantidad de municipios con más de 5000 votos: " << cantMunicipios << endl;
}

int contarMayoresAReferencia(int vectorBusqueda[], int cantidad, int valorReferencia){
    int cont = 0;
    for (int i=0; i<cantidad; i++){
        if (vectorBusqueda[i] > valorReferencia){
            cont++;
        }
    }
    return cont;
}

int buscarIndiceMaximo(int vectorBusqueda[], int cantidad){
    int posicionMaximo = 0;
    for(int i=1; i<cantidad; i++){
        if (vectorBusqueda[i] > vectorBusqueda[posicionMaximo]){
            posicionMaximo = i;
        }
    }
    return posicionMaximo;
}
