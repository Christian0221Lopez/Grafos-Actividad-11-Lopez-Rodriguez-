#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <set>
#include <cstring>
#include <cstdio>
#include "Prototipo.h"

void Graph::Show()
{
    Nodo* Pnn = new Nodo;
    Pnn = Grafo->pSig;

    while(Pnn != NULL)
    {
        std::cout <<"Data-------------------------"<< Pnn->Data << std::endl;
        std::cout <<"ID-------------------------"<< Pnn->id << std::endl;
        Pnn = Pnn->pSig;
    }
}

void Graph::Insertar(string var)
{
    ifstream File(var);
    ofstream Matriz("Matriz de Adyacencia.txt");
    ofstream MatrizInd("Matriz de Incidencia.txt");
    string oracion;
    int MatrizAdj[300][300];
    int i = 0;
    int ID;
    string Entero;
    string Limpio;
    int vectors;

    for(int i = 0;i<=200;i++)
    {
        for(int j = 0;j<=200;j++)
        {
            MatrizAdj[i][j] = 0;
        }
    }

    if (!File)
    {
        cout <<"Error al abrir el archivo"<<endl;
    }

        for(i = 0;i <= 331;i++)
        {
            if(i<=193)
            {
            if (!std::getline(File, oracion, '\n'))
            {
                cout << "Error: el archivo no tiene suficientes líneas" << endl;
                return;
            }
            if(i<100)
            {
                Entero = oracion.substr(0, 2);
                int Id = std::stoi(Entero);
                Limpio = oracion.substr(2, 30);
                Grafo->InsertarAdelanteChar(Id,Limpio);
                //Grafo = Grafo->pSig;
            }
            else
            {
                Entero = oracion.substr(0, 3);
                int Id = std::stoi(Entero);
                Limpio = oracion.substr(3, 30);
                Grafo->InsertarAdelanteChar(Id,Limpio);
                //Grafo = Grafo->pSig;
            }
            }
            else
            {
                   while (std::getline(File, oracion, ','))
                   {
                    try
                    {
                        ID = std::stoi(oracion);
                    }
                            catch(const std::invalid_argument& e) {
                            cout << "Error: el valor de código no es un entero válido" << endl;
                            return;
                        }
                    cout << ID <<",";
                    if (!std::getline(File, oracion, '\n'))
                    {
                        cout << "Error: el archivo no tiene suficientes líneas" << endl;
                        return;
                    }

                    try
                    {
                        vectors = std::stoi(oracion);
                    }
                            catch(const std::invalid_argument& e) {
                            cout << "Error: el valor de código no es un entero válido" << endl;
                            return;
                        }
                    //int vectors = std::atoi(oracion.c_str());
                    cout << vectors << endl;

                    MatrizAdj[ID][vectors] = 1;


                   }

            }
        }

// Imprimir encabezado
cout << "  ";
for (int i = 0; i < 193; i++) {
    cout << i << " ";
}
cout << endl;

// Imprimir matriz de adyacencia
for (int i = 0; i < 193; i++) {
    cout << i << " ";
    for (int j = 0; j < 193; j++) {
        cout << MatrizAdj[i][j] << " ";
    }
    cout << endl;
}

if (!Matriz)
    {
        cout <<"Error al abrir el archivo"<<endl;
    }

    Matriz << "  ";
    for (int i = 0; i < 193; i++) {
        Matriz << i << " ";
    }
    Matriz << endl;

    // Imprimir matriz de adyacencia
    for (int i = 0; i < 193; i++) {
        Matriz << i << " ";
        for (int j = 0; j < 193; j++) {
            Matriz << MatrizAdj[i][j] << " ";
        }
        Matriz << endl;
    }

// Contar el número de aristas
int numAristas = 0;
for (int i = 0; i < 193; i++) {
    for (int j = i; j < 193; j++) {
        if (MatrizAdj[i][j] == 1) {
            numAristas++;
        }
    }
}
// Crear la matriz de incidencia
int matrizIncidencia[193][numAristas];
for (int i = 0; i < 193; i++) {
    for (int j = 0; j < numAristas; j++) {
        matrizIncidencia[i][j] = 0;
    }
}
// Llenar la matriz de incidencia
int arista = 0;
for (int i = 0; i < 193; i++) {
    for (int j = i; j < 193; j++) {
        if (MatrizAdj[i][j] == 1) {
            matrizIncidencia[i][arista] = 1;
            matrizIncidencia[j][arista] = 1;
            arista++;
        }
    }
}


if (!MatrizInd)
    {
        cout <<"Error al abrir el archivo"<<endl;
    }

    MatrizInd << "  ";
    for (int i = 0; i < 193; i++) {
        MatrizInd << i << " ";
    }
    MatrizInd << endl;

    // Imprimir matriz de adyacencia
    for (int i = 0; i < 193; i++) {
        MatrizInd << i << " ";
        for (int j = 0; j < 193; j++) {
            MatrizInd << matrizIncidencia[i][j] << " ";
        }
        MatrizInd << endl;
    }

    File.close();
    Matriz.close();
    MatrizInd.close();
    cout << "Matriz guardada en archivo" << endl;
}


void Nodo::InsertarAdelanteChar(int ID, string data)
{
    // Si el nodo actual ya tiene un nodo siguiente, avanzamos hasta el último nodo en la lista
    Nodo* nodoActual = this;
    while (nodoActual->pSig != nullptr) {
        nodoActual = nodoActual->pSig;
    }

    // Creamos un nuevo nodo y lo agregamos al final de la lista
    Nodo* Pnn = new Nodo;
    Pnn->Data = data;
    Pnn->id = ID;
    Pnn->pSig = nullptr;
    Pnn->Vector = nullptr;

    nodoActual->pSig = Pnn;

    std::cout <<"Data-------------------------"<< Pnn->Data << std::endl;
    std::cout <<"ID-------------------------"<< Pnn->id << std::endl;
}

Graph::Graph()
{
    Grafo->pSig = NULL;
    Grafo->Vector = NULL;
}

void CD::Escribir(string var)
{
    ofstream File(var, ios::trunc);

    if (!File)
    {
        cout <<"Error al abrir el archivo"<<endl;
    }
    else
    {
        for (int i=0; i<cont; i++)
        {
            File << this[i].Artista << ',';
            File << this[i].Titulo << ',';
            File << this[i].Genero << ',';
            File << this[i].FechaL << ',';
            File << this[i].Codigo;

            // Agrega un salto de línea si no es el último registro
            if (i != cont-1) {
                File << '\n';
            }
        }

        cout << "Datos guardados en archivo " << var << endl;
    }

    File.close();
}

void CD::Recuperar(string var)
{
    ifstream File(var);

    if(!File)
    {
        cout <<"Archivo no encontrado "<<endl;
        return;
    }

    string Titulo;
    string Artista;
    string Genero;
    string FechaL;
    int Codigo;
    string oracion;

    while(std::getline(File, oracion, '\n'))
    {
        Artista = oracion;
        if (!std::getline(File, oracion, '\n'))
        {
            cout << "Error: el archivo no tiene suficientes líneas" << endl;
            return;
        }
        Titulo = oracion;
        if (!std::getline(File, oracion, '\n'))
        {
            cout << "Error: el archivo no tiene suficientes líneas" << endl;
            return;
        }
        Genero = oracion;
        if (!std::getline(File, oracion, '\n'))
        {
            cout << "Error: el archivo no tiene suficientes líneas" << endl;
            return;
        }
        FechaL = oracion;
        if (!std::getline(File, oracion, '\n'))
        {
            cout << "Error: el archivo no tiene suficientes líneas" << endl;
            return;
        }
        try {
            Codigo = std::stoi(oracion);
        }
        catch(const std::invalid_argument& e) {
            cout << "Error: el valor de código no es un entero válido" << endl;
            return;
        }

        this[cont].Artista = Artista;
        this[cont].Titulo = Titulo;
        this[cont].Genero = Genero;
        this[cont].FechaL = FechaL;
        this[cont].Codigo = Codigo;
        cont++;
    }

    cout <<"argv2 :"<<var<<endl;

    File.close();
}

void CD::Agregar()
{
    system("cls");


        cout << "Dime el nombre del artista: " << cont << endl;
        std::getline(cin,this[cont].Artista);
        cout << "Titulo del disco: " << cont << endl;
        std::getline(cin,this[cont].Titulo);
        cout << "Genero del artista: " << cont << endl;
        std::getline(cin,this[cont].Genero);
        cout << "Fecha de lanzamiento: " << cont << endl;
        std::getline(cin,this[cont].FechaL);
        cout << "Codigo: " << cont << endl;
        cin >>this[cont].Codigo;
        cont++;

}

void CD::Mostrar()
{
    int i = 0;
    system("cls");

    for (i=0; i<cont; i++)
    {
         cout << "Nombre: " << this[i].Artista<<endl;
         cout << "Titulo: " << this[i].Titulo<<endl;
         cout << "Genero: " << this[i].Genero<<endl;
         cout << "Fecha de Lanzamiento: " << this[i].FechaL<<endl;
         cout << "Codigo: " << this[i].Codigo<<endl;
    }

}

void CD::Consulta()
{
    int i = 0;
    int reg = 0;
    int bandera = 0;
    CD aux;

    cout<<"Que registro deseas buscar: "<<endl;
    cin >>aux.Codigo;

    if(cont > 0)
    {
        for(i=0; i<cont; i++)
        {
            if(this[i].Codigo == aux.Codigo)
            {
                cout << "Nombre: " << this[i].Artista<<endl;
                cout << "Titulo: " << this[i].Titulo<<endl;
                cout << "Genero: " << this[i].Genero<<endl;
                cout << "Fecha de Lanzamiento: " << this[i].FechaL<<endl;
                cout << "Codigo: " << this[i].Codigo<<endl;
                bandera = 1 ;
                break;
            }
        }
    }

    else
    {
        cout<<"\n\tRegistro vacio..!";
    }

    if(bandera==0)
    {
        cout<<"\n\n\tEl Disco no fue encontrado..! :S"<<endl;

    }

}

void CD::Eliminar()
{
    int codigo;
    int indice_a_eliminar = -1;

    system("cls");
    cout << "Ingresa el codigo del registro a eliminar: " << endl;
    cin >> codigo;

    for (int i = 0; i < cont; i++) {
        if (this[i].Codigo == codigo) {
            indice_a_eliminar = i;
            break;
        }
    }

    if (indice_a_eliminar != -1) {
        for (int i = indice_a_eliminar; i < cont - 1; i++) {
            this[i] = this[i + 1];
        }
        cont--;
        cout << "Registro eliminado" << endl;
    } else {
        cout << "Registro no encontrado" << endl;
    }
}

int Lista::Menu(string var)
{
    int op = 0;
    int salir = 0;
    Graph G;

    do
       {
            system("cls");
    cout <<"\tSOFTWARE REGISTRO DE CD´S"<<endl;

    cout <<"Menu de Opciones"<<endl;
    cout <<"1.- Agregar"<<endl;
    cout <<"2.- Mostrar"<<endl;
    cout <<"3.- Add Edge"<<endl;
    cout <<"4.- Eliminar"<<endl;
    cout <<"5.- Escribir"<<endl;
    cout <<"6.- Recuperar"<<endl;
    cout <<"7.- Salir"<<endl;
    cout <<"Ingresa opcion: ";
    cin >>op;
    getchar();

    switch(op)
    {
    case 1:
        G.Insertar(var);
        break;
    case 2:
        G.Show();
        break;
    case 3:
        //G.AddEdges(var);
        //G.AddEdges(var);
        break;
    case 4:
        Inicio->Eliminar();
        break;
    case 5:
        Inicio->Escribir(var);
        break;
    case 6:
        Inicio->Recuperar(var);
        break;
    case 7:
        exit(-1);
        break;
    }

    cout <<"Deseas Salir?... 1.-Si/2.-No: "<<endl;
    cin >>salir;
system("pause");
   }while(salir != 1);

    return salir;
}
