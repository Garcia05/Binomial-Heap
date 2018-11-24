#include "bheap.h"

template<typename T>
void Bheap<T>::Agregar(T d)
{
    Nodo<T> *Nuevo=new Nodo<T>(d);
    Nodo<T> *temp=Root;
    if(!temp){
        Min=Nuevo;
        Root=Nuevo;
        return;
    }else{
        if(Min->Dato>d){
            Min=Nuevo;
        }
        Nuevo->Sig=Root;
        Root=Nuevo;
        Merge();
    }

}
template<typename T>
void Bheap<T>::MergeB()
{
    Nodo<T> *aux=Root;
    Nodo<T> *aux1=aux->Sig;
    Nodo<T> *temp=NULL;
    while(aux!=NULL && aux1!=NULL){
        if(aux->Grado<aux1->Grado){
            temp= aux;
            aux=aux->Sig;
            aux1=aux1->Sig;
        }
        else if(aux->Grado==aux1->Grado){
            cout<<"entre aca "<<endl;
            if(aux->Dato<=aux1->Dato){
                aux->hijos.push_back(aux1);
                aux->Grado++;
                aux->Sig=aux1->Sig;
            }
            else{
                if(aux==Root){
                    aux1->hijos.push_back(aux);
                    aux1->Grado++;
                    Root=aux1;
                    aux=Root;
                }else{
                    aux1->hijos.push_back(aux);
                    aux1->Grado++;
                    temp->Sig=aux1;
                }

            }
            aux=aux->Sig;
            aux1=aux1->Sig;
        }
    }
}

template<typename T>
void Bheap<T>::Merge()
{
    Nodo<T> *aux=Root;
    Nodo<T> *temp=aux->Sig;
    Nodo<T>*ant=NULL;
    while(temp){
        Nodo<T> *tmp=temp->Sig;
        if(aux==Root){
            if(aux->Grado==temp->Grado){
                cout<<"hola 1"<<endl;
                if(aux->Dato<=temp->Dato){
                    cout<<"hola 2 "<<endl;
                    aux->hijos.push_back(temp);
                    aux->Grado++;
                    aux->Sig=tmp;
                    temp->Sig=NULL;
                }else{
                    temp->hijos.push_back(aux);
                    temp->Grado++;
                    aux->Sig=NULL;
                    Root=temp;
                }

            }
            ant=aux;
            aux=temp;
            temp=tmp;
        }else{
            if(aux->Grado==temp->Grado){
                cout<<"hola ENTRO AL SIGUIENTE"<<endl;
                if(aux->Dato<=temp->Dato){
                    cout<<"hola AGREGO A HIJOS DE AUX "<<endl;
                    aux->hijos.push_back(temp);
                    aux->Grado++;
                    aux->Sig=tmp;

                    temp->Sig=NULL;

                }else{cout<<"hola AGREGO TEMP "<<endl;
                    temp->hijos.push_back(aux);
                    temp->Grado++;
                    aux->Sig=NULL;
                    ant->Sig=temp;
                }
            }
            ant=aux;
            aux=temp;
            temp=tmp;
        }
    }
    cout<<Root->Grado<<endl;
}
/*
template<typename T>
void Bheap<T>::Merge()
{
    Nodo<T> *aux=Root;
    Nodo<T> *ant=NULL;
    Nodo<T> *temp=aux->Sig;
    while(temp){
        cout<<"hola "<<endl;
        Nodo<T> *tmp=temp->Sig;
        if(aux->Grado==temp->Grado){
            cout<<"hola 1"<<endl;
            if(aux==Root){
                cout<<"aux al inicio :"<<aux->Dato<<endl;
                if(aux->Dato<=temp->Dato){
                    cout<<"hola 2 "<<endl;
                    aux->hijos.push_back(temp);
                    aux->Grado++;
                    aux->Sig=tmp;
                }else{
                    temp->hijos.push_back(aux);
                    temp->Grado++;
                    Root=temp;
                }
                ant=aux;
                aux=aux->Sig;
                cout<<"aux al fin :"<<aux->Dato<<endl;
            }else{
                if(aux->Dato<=temp->Dato){
                    cout<<"hola 7 "<<endl;
                    aux->hijos.push_back(temp);
                    aux->Grado++;
                    aux->Sig=tmp;
                }else{
                    temp->hijos.push_back(aux);
                    temp->Grado++;
                    ant->Sig=temp;
                }
                ant=aux;
                aux=temp;
            }
        }else{
            aux=aux->Sig;
        }
        temp=tmp;
    }
    cout<<Root->Grado<<endl;
}
*/
/*
template<typename T>
void Bheap<T>::Merge()
{
    Nodo<T> *aux=Root;
    Nodo<T> *ant=Root;
    Nodo<T> *temp=aux->Sig;
    Nodo<T>*tmp=temp->Sig;
    if(aux->Grado==temp->Grado ){
        if(aux->Dato<=temp->Dato){
            aux->hijos.push_back(temp);
            aux->Grado++;
            aux->Sig=tmp;
        }else{
            temp->hijos.push_back(aux);
            temp->Grado++;
            Root=temp;
        }
        aux=aux->Sig;
    }else{
        aux=aux->Sig;
    }
    while(aux->Sig){
        if(aux->Grado==temp->Grado){
            if(aux->Dato<=temp->Dato){
                aux->hijos.push_back(temp);
                aux->Grado++;
                aux->Sig=tmp;
            }else{
                temp->hijos.push_back(aux);
                temp->Grado++;
                aux=temp;
            }
            aux=aux->Sig;
        }else{
            aux=aux->Sig;
        }
    }
}*/
template<typename T>
void Bheap<T>::swap(Nodo<T>*&a,Nodo<T>*&b)
{
    Nodo<T> *aux=a;
    list<Nodo<T>*> temp=a->hijos;
    a=b;
    a->hijos=b->hijos;
    b=aux;
    b->hijos=temp;
}

/*
template<typename T>
void Bheap<T>::deletemin()
{
    Nodo<T>*minimo=Min->hijos.front();

    Nodo<T>*aux=Root;
    Nodo<T>*temp=aux->Sig;
    while(!Min->hijos.empty()){
        cout<<"entro deletemnin"<<endl;
      Nodo<T>*tp=Min->hijos.front();
      aux->Sig=tp;
      cout<<Min->hijos.front()->Dato<<endl;
      tp->Sig=temp;
      Min->hijos.pop_front();
      if(Min->hijos.front()<minimo && !Min->hijos.empty() ){
          minimo=Min->hijos.front();
          aux=temp;
          temp=temp->Sig;
      }
      cout<<" :v "<<temp->Dato<<endl;
    }
    aux->Sig=temp;
    Nodo<T>*ELIM=Min;
    cout<<minimo->Dato<<endl;
    Min=minimo;
    ELIM->Dato=700;
    muero(ELIM);
   // Merge();
    //cout<<Min->Dato<<endl;
}*/
/*
 *version 2
template<typename T>
void Bheap<T>::deletemin()
{
    Nodo<T> *aux=Root;
    Nodo<T>*temp=aux->Sig;
    list<Nodo<T>*> lista=Min->hijos;
    if(!lista.front()->hijos.empty() ){
        lista.front()->Sig=aux;
        Root=lista.front();
        lista.pop_front();}
    while(!lista.empty()){
        cout<<"entre al while "<<endl;
        aux->Sig=lista.front();
        lista.front()->Sig=temp;
        aux=lista.front();
        lista.pop_front();
        if(temp){
            temp=temp->Sig;}
    }

    Nodo<T>*ELIM=Min;
    muero(ELIM);
    cout<<"entro el search"<<endl;
    Min=SearchMin();
    cout<<"pasoo el search"<<endl;
    //Merge();
}*/
/* ////POSIBLE SOLUCION
template<typename T>
void Bheap<T>::deletemin()
{
    Nodo<T> *alm=Root;
    if(Min==Root){
        alm=alm->Sig;
    }
    list<Nodo<T>*> lista=Min->hijos;
    muero(Min);
    if(lista.empty()){return;}
    Nodo<T>*aux=lista.front();
    Root=aux;
    lista.pop_front();
    while(!lista.empty()){
        if(alm->Grado<=aux->Grado && alm->Sig){
            aux->Sig=alm;
            alm=alm->Sig;
        }
        else{
            aux->Sig=lista.front();
            lista.pop_front();
        }
        aux=aux->Sig;
    }
    aux->Sig=alm;
    Merge();
    Min=SearchMin();
    cout<<"Root :"<<Root->Dato<<endl;
    cout<<"este es el minimo :"<<Min->Dato<<endl;
}*/

template<typename T>
void Bheap<T>::deletemin()
{
    Nodo<T> *New;
    Nodo<T> *aux=Min;
    Nodo<T> *alm=Root;
    Nodo<T> *temp=alm->Sig;
    list<Nodo<T>*> lista=Min->hijos;
    //muero(aux);
    if(lista.empty()){ return;}
    else{
        New=lista.front();
        lista.pop_front();
        Root=New;
        if(lista.empty()){return;}
        while(!lista.empty()){
            if(alm->Grado>=lista.front()->Grado){
                New->Sig=lista.front();
                lista.pop_front();
                New=New->Sig;
            }
            else if(alm->Grado<lista.front()->Grado && !lista.empty()){
                New->Sig=alm;
                New=alm;
                alm=alm->Sig;
            }
            else{
                New->Sig=alm;
            }
        }
    }
    New->Sig=alm;
    //Merge();
    Min=SearchMin();
    muero(aux);

}
template<typename T>
Nodo<T> *Bheap<T>::GetMin()
{
    return Min;
}
template<typename T>
Nodo<T> *Bheap<T>::Rootp()
{
    return Root;
}
template<typename T>
Nodo<T> *Bheap<T>::SearchMin()
{
    Nodo<T> *aux=Root;
    Nodo<T> *minimo=aux;
    while(aux->Sig){
        if(minimo->Dato>aux->Sig->Dato){
            minimo=aux;
        }
        aux=aux->Sig;
    }
    return minimo;
}
template<typename T>
void Bheap<T>::printBH(list<Nodo<T>*> t,Nodo<T>*temp, ostream &file )
{
    if(temp->hijos.empty()){return;}
    while(!t.empty()){
        file<<temp->Dato<<"->"<<t.front()->Dato<<";"<<endl;
        list<Nodo<T>*> a=t.front()->hijos;
        printBH(a,t.front(),file);
        a.pop_front();
        t.pop_front();
    }

}
template <typename T>
void Bheap<T>::generarDot()
{

    string b="bheap.txt";
    string t;
    ofstream file;
    file.open(b.c_str(),ios::out);

    string aux="digraph g {";
    string aux2="graph [ordering=\"out\"];";
    file<<aux<<endl;
    if(!file.is_open()){
        cout<<"No se puede guardar"<<endl;
    }else{
        Nodo<T>*temp=Root;
        while(temp){
            file<<aux2<<endl;
            file<<temp->Dato<<";"<<endl;
            list<Nodo<T>*> t=temp->hijos;
            printBH(t,temp,file);
            temp=temp->Sig;
        }
    }
    t="} ";
    file<<t<<endl;
    file.close();
    system("dot -Tpng bheap.txt -o bheap.png");
    //system("chrome dato.pdf");
}
