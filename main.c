/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
INCLUDES
*/

//#include "empresa.c"
#include "arvore.c"

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
MAIN
*/

int main(){
    
    ArvoreAVL* raiz = criarArvoreAVL();
	int quantidadeElementos = 0;
	int elemento = 0;
	printf("Quantidade de elementos: ");
	scanf("%d",&quantidadeElementos);
	int i = 0;
	for(i = 0; i < quantidadeElementos; i++){
		printf("\nElemento %d: ",i+1);
		scanf("%d",&elemento);
		inserirArvoreAVL(raiz, elemento);
	}
	printf("\nPre ordem\n");
	preOrdemArvoreAVL(raiz);
	printf("\nEm ordem\n");
	emOrdemArvoreAVL(raiz);
	printf("\nPos ordem\n");
	posOrdemArvoreAVL(raiz);
	liberarArvoreAVL(raiz);
	return 0;
}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=