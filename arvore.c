#include "arvore.h"

ArvoreAVL* criarArvoreAVL(){
	ArvoreAVL* raiz = (ArvoreAVL*)malloc(sizeof(ArvoreAVL));
	if(raiz != NULL){
		*raiz = NULL;
	}
	return raiz;
}

void liberarNo(No* no){
	if(no == NULL){
		return;
	}
	liberarNo(no->esquerda);
	liberarNo(no->direita);
	free(no);
	no = NULL;
}

void liberarArvoreAVL(ArvoreAVL* raiz){
	if(raiz == NULL){
		return;
	}
	liberarNo(*raiz);
	free(raiz);
}

int estaVazia(ArvoreAVL* raiz){
	if(raiz == NULL){
		return 1; // Est� vazia
	}
	if(*raiz == NULL){
		return 1; // Est� vazia
	}
	return 0; // N�o est� vazia
}

int alturaArvoreAVL(ArvoreAVL *raiz){
	if(raiz == NULL){
		return 0;
	}
	if(*raiz == NULL){
		return 0;
	}
	int alturaEsquerda = alturaArvoreAVL(&((*raiz)->esquerda));
	int alturaDireita = alturaArvoreAVL(&((*raiz)->direita));
	if(alturaEsquerda > alturaDireita){
		return (alturaEsquerda + 1);
	}
	else{
		return (alturaDireita + 1);
	}
}

int totalNosArvoreAVL(ArvoreAVL *raiz){
	if(raiz == NULL){
		return 0;
	}
	if(*raiz == NULL){
		return 0;
	}
	int alturaEsquerda = totalNosArvoreAVL(&((*raiz)->esquerda));
	int alturaDireita = totalNosArvoreAVL(&((*raiz)->direita));
	return (alturaEsquerda + alturaDireita + 1);
}

void preOrdemArvoreAVL(ArvoreAVL *raiz){
	if(raiz == NULL){
		return;
	}
	if(*raiz != NULL){
		printf("%d\n",(*raiz)->info);
		preOrdemArvoreAVL(&((*raiz)->esquerda));
		preOrdemArvoreAVL(&((*raiz)->direita));
	}
}

void emOrdemArvoreAVL(ArvoreAVL *raiz){
	if(raiz == NULL){
		return;
	}
	if(*raiz != NULL){
		emOrdemArvoreAVL(&((*raiz)->esquerda));
		printf("%d\n",(*raiz)->info);
		emOrdemArvoreAVL(&((*raiz)->direita));
	}
}

void posOrdemArvoreAVL(ArvoreAVL *raiz){
	if(raiz == NULL){
		return;
	}
	if(*raiz != NULL){
		posOrdemArvoreAVL(&((*raiz)->esquerda));
		posOrdemArvoreAVL(&((*raiz)->direita));
		printf("%d\n",(*raiz)->info);
	}
}

/* Fun��es auxiliar para a implementa��o da inser��o */
int alturaNo(struct No* no){ /* Calcula a altura de um n� */
	if(no == NULL){
		return -1;
	}
	else{
		return no->altura;
	}
}

int fatorBalanceamentoNo(struct No* no){ /* Calcular fator de balanceamento de um n� */
	return labs(alturaNo(no->esquerda) - alturaNo(no->direita));
}

int maior(int x, int y){
	if(x > y){
		return x;
	}
	else{
		return y;
	}
}
/* Fim da implementa��o das fun��es auxiliares */

/* Implementa��o das rota��es */
void rotacaoLL(ArvoreAVL *raiz){
	struct No *no;
	no = (*raiz)->esquerda;
	(*raiz)->esquerda = no->direita;
	no->direita = *raiz;
	(*raiz)->altura = maior(alturaNo((*raiz)->esquerda),alturaNo((*raiz)->direita)) + 1;
	no->altura = maior(alturaNo(no->esquerda),(*raiz)->altura) + 1;
	(*raiz) = no;
}

void rotacaoRR(ArvoreAVL *raiz){
	struct No *no;
	no = (*raiz)->direita;
	(*raiz)->direita = no->esquerda;
	no->esquerda = (*raiz);
	(*raiz)->altura = maior(alturaNo((*raiz)->esquerda),alturaNo((*raiz)->direita)) + 1;
	no->altura = maior(alturaNo(no->direita),(*raiz)->altura) + 1;
	(*raiz) = no;
}

void rotacaoLR(ArvoreAVL *raiz){
	rotacaoRR(&(*raiz)->esquerda);
	rotacaoLL(raiz);
}

void rotacaoRL(ArvoreAVL *raiz){
	rotacaoLL(&(*raiz)->direita);
	rotacaoRR(raiz);
}
/* Fim da implementa��o das rota��es */

int inserirArvoreAVL(ArvoreAVL *raiz, int valor){
	int res;
	if(*raiz == NULL){
		struct No *novo;
		novo = (struct No*)malloc(sizeof(struct No));
		if(novo == NULL){
			return 0;
		}
		novo->info = valor;
		novo->altura = 0;
		novo->esquerda = NULL;
		novo->direita = NULL;
		*raiz = novo;
		return 1;
	}
	struct No *atual = *raiz;
	if(valor < atual->info){
		if((res = inserirArvoreAVL(&(atual->esquerda),valor)) == 1){
			if(fatorBalanceamentoNo(atual) >= 2){
				if(valor < (*raiz)->esquerda->info){
					rotacaoLL(raiz);
				} else{
					rotacaoLR(raiz);
				}
			}
		}
	}
	else{
		if(valor > atual->info){
			if((res=inserirArvoreAVL(&(atual->direita),valor)) == 1){
				if(fatorBalanceamentoNo(atual) >= 2){
					if((*raiz)->direita->info < valor){
						rotacaoRR(raiz);
					} else{
						rotacaoRL(raiz);
					}
				}
			}
		} else{
			printf("Valor duplicado\n");
			return 0;
		}
	}
	atual->altura = maior(alturaNo(atual->esquerda),alturaNo(atual->direita)) + 1;
	return res;
}