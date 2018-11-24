#ifndef BHEAP_H
#define BHEAP_H

#include <cstdlib>
#include <iostream>
#include <list>
#include <string>
#include <queue>
#include <stack>
#include <fstream>
using namespace std;
template<class T>
class Nodo
{
public:
    T Dato;
    int Grado;
    list<Nodo<T> *> hijos;
    Nodo<T> *Sig;
public:
    Nodo(T d){
        Dato=d;
        Grado=0;
        Sig=NULL;
    }
};
template<class T>
class Bheap
{
public:
    Nodo<T> *Min;
    Nodo<T> *Root;
public:
    Bheap(){Min=Root=NULL;}
    void printBH(list<Nodo<T>*> A,Nodo<T>*a, ostream &file);
    void Agregar(T d);
    void generarDot();
    void Merge();
    void MergeB();
    Nodo<T> *SearchMin();
    void swap(Nodo<T> *&,Nodo<T>*&);
    void deletemin();
    Nodo<T> *GetMin();
    Nodo<T> *Rootp();
    void Ordenar();
    void muero(Nodo<T>*a){
        Nodo<T>*aux=Root;
        cout<<"entro al if"<<endl;
        if(a==Root){Root=a->Sig;}
        else{
            cout<<"entro al while 1"<<endl;
            while(aux->Sig!=a && aux->Sig){
                cout<<"entro al while"<<endl;
                aux=aux->Sig;
            }
        }
        aux->Sig=a->Sig;
        delete a;
    }
};

#endif // BHEAP_H
