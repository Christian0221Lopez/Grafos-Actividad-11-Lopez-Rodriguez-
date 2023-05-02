#ifndef PROTOTIPO_H_INCLUDED
#define PROTOTIPO_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include "Prototipo.h"

using namespace std;

class Nodo
{
private:
	Nodo* Vector = NULL;
	Nodo* pSig = NULL;
	int id;
	string Data;
	int arista[300][300];
	friend class Graph;
public:
	void InsertarAdelanteChar(int,string);
	void AddEdge(int);
	float EliminarSiguiente();
};

class Graph
{
private:
    Nodo* Grafo;
    friend class Nodo;
public:
    Graph();
    void Insertar(string);
    void Show();
    void AddEdges(string);
};

class CD
{
private:
    string Titulo;
    string Artista;
    string Genero;
    string FechaL;
    int Codigo;
    int cont;
public:
    void Agregar();
    void Mostrar();
    void Consulta();
    void Eliminar();
    void Recuperar(string);
    void Escribir(string);
};

class Lista
{
private:
    CD Inicio[50];
    	friend class Graph;
public:
    int Menu(string var);
    //void Recuperar(string var);
};



#endif // PROTOTIPO_H_INCLUDED
