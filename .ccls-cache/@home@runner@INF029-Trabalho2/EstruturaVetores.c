#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#include "EstruturaVetores.h"

typedef struct ele {
  int quantidade;
  int tamanho;
  int *aux;
} Elemento;

Elemento vetorPrincipal[TAM];
/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/

/*
  Objetivo: inicializa o programa. deve ser chamado ao inicio do programa
  */
  void inicializar() {
    for (int i = 0; i < 10; i++) {
      vetorPrincipal[i].quantidade = 0;
      vetorPrincipal[i].tamanho = 0;
      vetorPrincipal[i].aux = NULL;
    }
  }

  /*
  Objetivo: finaliza o programa. deve ser chamado ao final do programa
  para poder liberar todos os espaços de memória das estruturas auxiliares.
  */
  void finalizar() {
    for (int i = 0; i < 10; i++) {
      if (vetorPrincipal[i].aux != NULL)
        free(vetorPrincipal[i].aux);
    }
  }

int criarEstruturaAuxiliar(int posicao, int tamanho) {
  if (vetorPrincipal[posicao].aux != NULL) {
    return JA_TEM_ESTRUTURA_AUXILIAR;
  }

  if (posicao > 10 || posicao < 1) {
    return POSICAO_INVALIDA;
  }

  if (tamanho < 1) {
    return TAMANHO_INVALIDO;
  }

  vetorPrincipal[posicao].aux = (int *)malloc(tamanho * sizeof(int));
  vetorPrincipal[posicao].tamanho = tamanho;
  vetorPrincipal[posicao].quantidade = 0;
  return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor) {
  int retorno = 0;
  int existeEstruturaAuxiliar = 0;
  int temEspaco = 0;
  int posicao_invalida = 0;

  if (posicao > 10 || posicao < 1)
    retorno = POSICAO_INVALIDA;
  else {
    // testar se existe a estrutura auxiliar
    if (vetorPrincipal[posicao].aux != NULL) {
      if (vetorPrincipal[posicao].quantidade <
          vetorPrincipal[posicao].tamanho) {
        vetorPrincipal[posicao].aux[vetorPrincipal[posicao].quantidade] = valor;
        vetorPrincipal[posicao].quantidade++;
        retorno = SUCESSO;
      } else {
        retorno = SEM_ESPACO;
      }
    } else {
      retorno = SEM_ESTRUTURA_AUXILIAR;
    }
  }

  return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar
da seguinte forma [3, 8, 7,  ,  ,  ]. Obs. Esta é uma exclusão lógica Rertono
(int) SUCESSO - excluido com sucesso ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao) {
  int retorno;

  if (posicao > 10 || posicao < 1)
    retorno = POSICAO_INVALIDA;

  else {
    if (vetorPrincipal[posicao].aux != NULL) {
      if (vetorPrincipal[posicao].quantidade > 0) {
        // Simula ter uma posição a menos, efetivamente substituindo em outra
        // iteração.//
        vetorPrincipal[posicao].quantidade--;
        retorno = SUCESSO;
      } else
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    } else
      retorno = SEM_ESTRUTURA_AUXILIAR;
  }
  return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições
anteriores ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o
valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ] Obs. Esta é
uma exclusão lógica Rertono (int) SUCESSO - excluido com sucesso 'valor' da
estrutura na posição 'posicao' ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor) {
  int retorno, status = 0, i;

  // if (ehPosicaoValida(posicao) != SUCESSO){}
  if (posicao > 10 || posicao < 1)
    retorno = POSICAO_INVALIDA;

  else {
    if (vetorPrincipal[posicao].aux != NULL) {
      if (vetorPrincipal[posicao].quantidade > 0) {
        for (i = 0; i < vetorPrincipal[posicao].quantidade && status == 0;
             i++) {
          if (valor == vetorPrincipal[posicao].aux[i])
            status = 1;
        }
        if (status == 1) {
          for (i = i - 1; i < vetorPrincipal[posicao].quantidade; i++) {
            vetorPrincipal[posicao].aux[i] = vetorPrincipal[posicao].aux[i + 1];
          }
          vetorPrincipal[posicao].quantidade--;
          retorno = SUCESSO;
        } else {
          retorno = NUMERO_INEXISTENTE;
        }
      } else {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
      }
    } else {
      retorno = SEM_ESTRUTURA_AUXILIAR;
    }
  }

  return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao) {
  int retorno = 0;
  if (posicao < 1 || posicao > 10) {
    retorno = POSICAO_INVALIDA;
  } else
    retorno = SUCESSO;

  return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar POSICAO_INVALIDA -
Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {

  int retorno;
  if (posicao > 10 || posicao < 1)
    retorno = POSICAO_INVALIDA;
  else {
    if (vetorPrincipal[posicao].aux != NULL) {
      if (vetorPrincipal[posicao].quantidade > 0) {
        for (int i = 0; i < vetorPrincipal[posicao].quantidade; i++) {
          vetorAux[i] = vetorPrincipal[posicao].aux[i];
        }
        retorno = SUCESSO;
      } else {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
      }
    } else {
      retorno = SEM_ESTRUTURA_AUXILIAR;
    }
  }

  return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao
(1..10)'. os números devem ser armazenados em vetorAux Rertono (int) SUCESSO -
recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {

  int retorno, i, j, aux;

  if (posicao > 10 || posicao < 1)
    retorno = POSICAO_INVALIDA;
  else {
    if (vetorPrincipal[posicao].aux != NULL) {
      if (vetorPrincipal[posicao].quantidade > 0) {
        for (i = 0; i < vetorPrincipal[posicao].quantidade; i++) {
          vetorAux[i] = vetorPrincipal[posicao].aux[i];
        }
        for (i = 0; i < vetorPrincipal[posicao].quantidade; i++) {
          for (j = i + 1; j < vetorPrincipal[posicao].quantidade; j++) {
            if (vetorAux[i] > vetorAux[j]) {
              aux = vetorAux[i];
              vetorAux[i] = vetorAux[j];
              vetorAux[j] = aux;
            }
          }
        }
        retorno = SUCESSO;
      } else {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
      }
    } else {
      retorno = SEM_ESTRUTURA_AUXILIAR;
    }
  }

  return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares
estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {

  int retorno, k = 0;

  for (int i = 0; i < TAM; i++) {
    if (vetorPrincipal[i].aux != NULL) {
      if (vetorPrincipal[i].quantidade > 0) {
        for (int j = 0; j < vetorPrincipal[i].quantidade; j++) {
          vetorAux[k] = vetorPrincipal[i].aux[j];
          k++;
        }
      }
    }
  }

  if (k > 0)
    retorno = SUCESSO;
  else
    retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

  return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares
estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]) {

  int retorno, aux, k = 0, i, j;

  for (i = 0; i < TAM; i++) {
    if (vetorPrincipal[i].aux != NULL) {
      if (vetorPrincipal[i].quantidade > 0) {
        for (j = 0; j < vetorPrincipal[i].quantidade; j++) {
          vetorAux[k] = vetorPrincipal[i].aux[j];
          k++;
        }
      }
    }
  }

  if (k > 0) {
    for (i = 0; i < k; i++) {
      for (j = i + 1; j < k; j++) {
        if (vetorAux[i] > vetorAux[j]) {
          aux = vetorAux[i];
          vetorAux[i] = vetorAux[j];
          vetorAux[j] = aux;
        }
      }
    }
    retorno = SUCESSO;
  } else
    retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

  return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o
novo tamanho 'novoTamanho' + tamanho atual Suponha o tamanho inicial = x, e novo
tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser
sempre >= 1 Rertono (int) SUCESSO - foi modificado corretamente o tamanho da
estrutura auxiliar SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {

  int retorno;
  novoTamanho = novoTamanho + vetorPrincipal[posicao].tamanho;

  if (posicao > 10 || posicao < 1)
    retorno = POSICAO_INVALIDA;
  else {
    if (novoTamanho < 1) {
      retorno = NOVO_TAMANHO_INVALIDO;
      return retorno;
    }
    if (vetorPrincipal[posicao].aux != NULL) {
      vetorPrincipal[posicao].aux =
          realloc(vetorPrincipal[posicao].aux, (novoTamanho * sizeof(int)));
      if (!vetorPrincipal[posicao].aux)
        retorno = SEM_ESPACO_DE_MEMORIA;
      else {
        vetorPrincipal[posicao].tamanho = novoTamanho;
        if (vetorPrincipal[posicao].tamanho <
            vetorPrincipal[posicao].quantidade)
          vetorPrincipal[posicao].quantidade = vetorPrincipal[posicao].tamanho;
        retorno = SUCESSO;
      }
      }
      else {
        retorno = SEM_ESTRUTURA_AUXILIAR;
      }
    }

    return retorno;
  }

  /*
  Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar
  da posição 'posicao'. Retorno (int) POSICAO_INVALIDA - posição inválida
      SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
      ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
      Um número int > 0 correpondente a quantidade de elementos preenchidos da
  estrutura
  */
  int getQuantidadeElementosEstruturaAuxiliar(int posicao) {

    int retorno;

    if (posicao > 10 || posicao < 1)
      retorno = POSICAO_INVALIDA;
    else {
      if (vetorPrincipal[posicao].aux != NULL) {
        if (vetorPrincipal[posicao].quantidade > 0) {
          if (vetorPrincipal[posicao].tamanho <
              vetorPrincipal[posicao].quantidade)
            vetorPrincipal[posicao].quantidade =
                vetorPrincipal[posicao].tamanho;
          retorno = vetorPrincipal[posicao].quantidade;
        } else {
          retorno = ESTRUTURA_AUXILIAR_VAZIA;
        }
      } else {
        retorno = SEM_ESTRUTURA_AUXILIAR;
      }
    }

    return retorno;
  }