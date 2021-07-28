#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _ARVORE_H
#define _ARVORE_H

typedef struct No{
	int info;
	int altura;
	struct No* esquerda;
	struct No* direita;	
}No;

typedef struct No* ArvoreAVL;

ArvoreAVL* criarArvoreAVL();
void liberarNo(No* no);
void liberarArvoreAVL(ArvoreAVL* raiz);
int estaVazia(ArvoreAVL* raiz);
int alturaArvoreAVL(ArvoreAVL *raiz);
int totalNosArvoreAVL(ArvoreAVL *raiz);
void preOrdemArvoreAVL(ArvoreAVL *raiz);
void emOrdemArvoreAVL(ArvoreAVL *raiz);
void posOrdemArvoreAVL(ArvoreAVL *raiz);
int alturaNo(struct No* no);
int fatorBalanceamentoNo(struct No* no);
void rotacaoLL(ArvoreAVL *raiz);
void rotacaoRR(ArvoreAVL *raiz);
void rotacaoLR(ArvoreAVL *raiz);
void rotacaoRL(ArvoreAVL *raiz);
int inserirArvoreAVL(ArvoreAVL *raiz, int valor);


#endif