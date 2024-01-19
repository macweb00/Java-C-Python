//Criador: Maciel F.  Cadeira relacionado: ARQ. de Comp.  II
#include <stdio.h>
#include <stdlib.h>
#include<omp.h>
#include <stdalign.h> //para usar o recurso de alinhar cache
#include <inttypes.h> //uso para imprimir a soma sem gerar aviso

#define ARRAY_SIZE 1024 //constante tamanho max. do array
#define MAX_THREADS 4 //constante tamanho max. de threds, uso para separar bloco de valores

//Uso 'alignas' para alinhar os arrays inteiros ao tamanho da linha de cache
//Eses dois devem ser global, pois o alinhamento depende do compilador e da base do sistema
alignas(64) int array_entrada[ARRAY_SIZE];
alignas(64) int array_saida[ARRAY_SIZE];

int main( int argc, char** argv){
    int valor_inicial, chunk_size; //guarda os valores das etapas ;
    //guarda a thread master ; guarda a base de tamanho/posicoes de cada thread

   printf("\n Digite o valor INICIAL para ver as 1024 posicoes seguintes: ");
   scanf("%d", &valor_inicial);

    if (valor_inicial <= 0){//testa se o valor eh inteiro positivo
        printf("\n ERRO: O valor inicial precisa ser um inteiro positivo.\n");
        return 1; //indica um erro e sai do programa
    }

     //por ser declarado fora, todas as threads usam a mesma instancia de tamanho, facilita o loop para percorrer a thread
    chunk_size = ARRAY_SIZE/ MAX_THREADS; //definindo o tamanho max. do bloco de cada thread

    omp_set_num_threads(MAX_THREADS);//limita o pragma abaixo a ter 4 threads
    #pragma omp parallel
    {
      int id_thread, local_start, local_end;

      //ID pega a thread atual, a partir do 0,1,2 e depois o 3 , ou seja, pode usaar para ordenar sequencial
      id_thread = omp_get_thread_num(); //omp_get_num_thread() -retorna o nº de thread dentro de pragma

      local_start = id_thread * chunk_size; //defino o inicio de cada thread
      local_end = (id_thread == MAX_THREADS - 1) ? ARRAY_SIZE : local_start + chunk_size; //defino o fim de cada thread


         for(int i = local_start; i < local_end; i++){//preencher o array de entrada a partir de zero
              array_entrada[i] = valor_inicial + i;
            }
         //nao uso a diretica atomic, pois cada thread executa apenas dentro de seu bloco size
         for(int i = local_start; i < local_end; i++){//preencher o array de saida a partir de zero
              array_saida[i] = array_entrada[i] + 1;
            }
     }//fim do pragma parallel

     int64_t soma = 0; //guarda o resultado da soma, nao uso o long long int
     #pragma omp parallel for reduction(+:soma)
     for(int i = 0; i <ARRAY_SIZE; i++){// neste bloco faz a soma com reducao
        soma += array_saida[i];
     }

    printf("\n ------------ Veja o valor de SAIDA ------------ \n\n");
    for(int i = 0; i <ARRAY_SIZE; i++){
        printf(" %d ", array_saida[i]);
    }
    printf("\n Soma total das posicoes de SAIDA: %" PRId64 "\n", soma);

    return 0;
}
