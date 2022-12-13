#include <stdio.h>
#include <stdlib.h>

void inserirElemento(int *principal[10]){
  int pos, size, number;
  
  printf("Em qual posição deseja inserir o elemento? [1-10]\n");
  scanf("%d", &pos);

  if (!principal[pos]){
    printf("Estrutura auxiliar inexistente!\n");
    printf("Qual o tamanho da nova estrutura aux. desejada?");
    scanf("%d", &size);

    int estruturaAux[size];
    printf("Insira o número na nova estrutura: ");
    scanf("%d", &number);
    estruturaAux[0] = number;
    
    principal[pos] = estruturaAux;
  } else {

    int tamanho = sizeof(principal[pos])/sizeof(principal[pos][0]);
    for (int i = 0; i <= tamanho; i++){
      if (!principal[pos][i]){
        printf("Qual o número a ser inserido? ");
        scanf("%d", &principal[pos][i]);
      } else if (i == tamanho){
        printf("Estrutura cheia! Aumente o tamanho ou selecione outra.\n\n");
      }
    }
  }
    
  return principal;
}

int mainAntigo(void) {
  int opc, *principal[10];
  
  do {
   printf("Insira a opção: \n");
   printf("1 - Inserir elemento\n");
   printf("7 - Sair\n");
   scanf("%d", &opc);

  switch (opc) {
    case 1:
      inserirElemento(principal); 
    break;
    
    case 7:
    break;
    }
  }

  while(opc != 7);

  printf("%i", principal);
  return 0;
}