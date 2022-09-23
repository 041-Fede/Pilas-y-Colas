#include <iostream>
#include <string.h>

using namespace std;

struct Pasajeros
{
    int DNI;
    string Nombre,Destino;
};

struct NodoCola
{
    Pasajeros Info;
    NodoCola*Sig;
};

void CargaDeDatos(NodoCola*&PrimeroMar,NodoCola*&UltimoMar,NodoCola*&PrimeroPunta,NodoCola*&UltimoPunta,NodoCola*&PrimeroMonte,NodoCola*&UltimoMonte);
void Encolar(NodoCola*&Primero,NodoCola*&Ultimo,Pasajeros Dato);
void Punto2 (NodoCola*&PrimeroMar,NodoCola*&UltimoMar,NodoCola*&PrimeroPunta,NodoCola*&UltimoPunta,NodoCola*&PrimeroMonte,NodoCola*&UltimoMonte,string Destino,int Nro);
void Desencolar(NodoCola*&Primero,NodoCola*&Ultimo,Pasajeros &Dato);

int main()
{
    int Nro;
    string Destino;
    NodoCola*PrimeroMar = NULL,NodoCola*UltimoMar = NULL;
    NodoCola*PrimeroPunta = NULL,NodoCola*UltimoPunta = NULL;
    NodoCola*PrimerMonte = NULL,NodoCola*UltimoMonte = NULL;

    CargaDeDatos(PrimeroMar,UltimoMar,PrimeroPunta,UltimoPunta,PrimerMonte,UltimoMonte);

    cout << "---------------------------------" << endl;
    cout << "Seleccione un destino (MarDelPlata,PuntaDelEste,Montevideo): ";
    cin >> Destino;

    cout << "INFORME cantidad de asientos libres para el destino: ";
    cin >>  Nro;

    cout << "---------------------------------" << endl;
    cout << "Listado de los pasajeros que viajaran: " << endl;

    Punto2(PrimeroMar,UltimoMar,PrimeroPunta,UltimoPunta,PrimerMonte,UltimoMonte,Destino,Nro);

    cout << "---------------------------------" << endl;

    return 0;
}

void CargaDeDatos(NodoCola*&PrimeroMar,NodoCola*&UltimoMar,NodoCola*&PrimeroPunta,NodoCola*&UltimoPunta,NodoCola*&PrimeroMonte,NodoCola*&UltimoMonte)
{
    Pasajeros P;

    cout << "INFORME dni del pasajero: ";
    cin >> P.DNI;

    while(P.DNI != 0)
    {
        cout << "INFORME nombre del pasajero: ";
        cin >> P.Nombre;

        cout << "INFORME lugar de destino (MarDelPlata, PuntaDelEste, Montevideo): ";
        cin >> P.Destino;

        if(P.Destino == "MarDelPlata")
        {
            Encolar(PrimeroMar,UltimoMar,P);
        }
        else
        {
            if(P.Destino == "PuntaDelEste")
            {
                Encolar(PrimeroPunta,UltimoPunta,P);
            }
            else
            {
                if(P.Destino == "Montevideo")
                {
                    Encolar(PrimeroMonte,UltimoMonte,P);
                }
                else
                {
                    cout << "Destino no encontrado" << endl;
                }
            }
        }

        cout << "---------------------------------" << endl;
        cout << "INFORME dni del siguiente pasajero: ";
        cin >> P.DNI;
    }
}

void Encolar(NodoCola*&Primero,NodoCola*&Ultimo,Pasajeros Dato)
{
    NodoCola*Aux = new NodoCola;
    Aux->Info = Dato;
    Aux->Sig = NULL;

    if(Ultimo != NULL)
    {
        Ultimo->Sig = Aux;
    }
    else
    {
        Primero = Aux;
    }

    Ultimo = Aux;
}

void Punto2(NodoCola*&PrimeroMar,NodoCola*&UltimoMar,NodoCola*&PrimeroPunta,NodoCola*&UltimoPunta,NodoCola*&PrimeroMonte,NodoCola*&UltimoMonte,string Destino,int Nro)
{
    int i = 0;
    Pasajeros P;

    if(Destino == "MarDelPlata")
    {
        while(PrimeroMar != NULL && i < Nro)
        {
            Desencolar(PrimeroMar,UltimoMar,P);

            cout << "Nro de dni: " << P.DNI << " - " << "Nombre del pasajero: " << P.Nombre << " - " << "Destino del pasajero: " << P.Destino << endl;

            i++;
        }
    }
    else
    {
        if(Destino == "PuntaDelEste")
        {
            while(PrimeroPunta != NULL && i < Nro)
            {
                Desencolar(PrimeroPunta,UltimoPunta,P);

                cout << "Nro de dni: " << P.DNI << " - " << "Nombre del pasajero: " << P.Nombre << " - " << "Destino del pasajero: " << P.Destino << endl;

                i++;
            }
        }
        else
        {
            if(Destino == "Montevideo")
            {
                while(PrimeroMonte != NULL && i < Nro)
                {
                    Desencolar(PrimeroMonte,UltimoMonte,P);

                    cout << "Nro de dni: " << P.DNI << " - " << "Nombre del pasajero: " << P.Nombre << " - " << "Destino del pasajero: " << P.Destino << endl;

                    i++;
                }
            }
            else
            {
                cout << "Destino no encontrado" << endl;
            }
        }
    }
}

void Desencolar(NodoCola*&Primero,NodoCola*&Ultimo,Pasajeros &Dato)
{
    NodoCola*Aux;
    Aux = Primero;
    Dato = Aux->Info;
    Primero = Aux->Sig;

    delete Aux;

    if(Primero == NULL)
    {
        Ultimo = NULL;
    }
}

