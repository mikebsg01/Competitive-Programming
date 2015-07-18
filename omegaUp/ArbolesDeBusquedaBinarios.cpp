#include <stdio.h>

int N, raiz;
int clave[1005];
int izq[1005];
int der[1005];
int nodos = 0;

int crear_nodo(int dato){
    clave[nodos] = dato;
    izq[nodos] = -1;
    der[nodos] = -1;
    return nodos++;
}

void insertar(int nodo, int dato){
    if(clave[nodo]>dato){
        if(izq[nodo] == -1){
            izq[nodo] = crear_nodo(dato);
        } else {
            insertar(izq[nodo], dato);
        }
    } else {
        if(der[nodo] == -1){
            der[nodo] = crear_nodo(dato);
        } else {
            insertar(der[nodo], dato);
        }
    }
}

void visita(int nodo){
    printf("%d ",clave[nodo]);
}

void preorden(int nodo){
    if(nodo == -1){
        return;
    }
    visita(nodo);
    preorden(izq[nodo]);
    preorden(der[nodo]);
}

int main(){
    int i,num;
    int array[1005];
    scanf("%d",&N);
    for(i=0; i<N; ++i){
        scanf("%d",&array[i]);
    }
    for(i=N-1; i>=0; --i){
        if(i==(N-1)){
            raiz = crear_nodo(array[i]);
        } else {
            insertar(raiz, array[i]);
        }
    }
    preorden(raiz);
    return 0;
}
