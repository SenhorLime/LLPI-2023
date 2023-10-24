/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   estruturado.cpp
 * Author: contagem
 *
 * Created on 19 de Setembro de 2018, 11:22
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "bolha.hpp"

using namespace std;

typedef long TChave;

struct TItem {
    TChave chave;
    /* outros componentes */


    bool operator==(TItem a) const{
        if(a.chave==chave)return true;
        return false;
    }

    bool operator>(TItem a) const{
        if(chave>a.chave)return true;
        return false;
    }

    bool operator<(TItem a) const{
        if(chave<a.chave)return true;
        return false;
    }

};

struct TDicionario{
    TItem *v;
    int n, max;
} ;

/* inicializa um dicionário */
void TDicionario_Inicio(TDicionario *t) {
    t->n = 0;
    t->max = 10;
    t->v = (TItem*) malloc(sizeof (TItem) * t->max);
}

/* encontra e retorna o índice da chave x no dicionário */
int TDicionario_Find(TDicionario *t, TChave c) {
    int i;
    for (i = t->n - 1; i >= 0; i--)
        if (t->v[i].chave == c)
            return i;
    return -1; // retorna -1 caso a chave não seja encontrada
}

/* insere um registro no dicionário */
void TDicionario_Insere(TDicionario *t, TItem x) {
    if (t->n == t->max) {
        t->max *= 2;
        t->v = (TItem*) realloc(t->v, sizeof (TItem) * t->max);
    }
    // n é o tamanho
    t->v[t->n++] = x;
}

/* encontra o índice da chave x no dicionário entre esq e dir */
int TDicionario_Binaria(TDicionario *t, int esq,
        int dir, TChave x) {
    int meio = (esq + dir) / 2;
    if (t->v[meio].chave != x && esq >= dir)
        return -1;
    else if (x > t->v[meio].chave)
        return TDicionario_Binaria(t, meio + 1, dir, x);
    else if (x < t->v[meio].chave)
        return TDicionario_Binaria(t, esq, meio - 1, x);
    else
        return meio;
}

void TDicionario_Imprimir(TDicionario *t) {

    for (int i = 0; i < t->n; i++)
        cout << t->v[i].chave << ";";
    cout << endl;
    
}

/* encontra o índice da chave x no dicionário */
int TDicionario_Find_Binary(TDicionario *t, TChave x) {
    return TDicionario_Binaria(t, 0, t->n - 1, x); // t->n é o   tamanho
}


void TDicionario_Delete(TDicionario *t){
	cout<< "Deletando dicionario" << endl;
	delete[]  t->v;
}



int main2(int argc, char** argv) {
    TDicionario dic;
    int tamanho = 10;
    int vetor[] = {6,28,29,37,43,46,62,82,92,96};
    TItem item;


    TDicionario_Inicio(&dic);
    for (int i = 0; i < tamanho; i++) {
        item.chave = i;
        //item.chave = rand() % 100 + 1;
        item.chave = vetor[i];
        TDicionario_Insere(&dic, item);
    }

    cout << "Nao ordenado" <<endl;
    TDicionario_Imprimir(&dic);


    Bolha<TItem>(dic.v, dic.n);

    cout << "Ordenado" <<endl;
    TDicionario_Imprimir(&dic);

    TChave chave = 29;

    int resultado = TDicionario_Find_Binary(&dic, chave);
    cout << "Chave " << chave << " encontrado na posicao: " << resultado << endl;


    TDicionario_Delete(&dic);
    return 0;
}

