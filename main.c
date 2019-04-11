#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *a, int left, int right) {
    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}

void bubleSort(int *vet, int tam){
    int aux, trocou = 1, i;

    while(trocou){
        trocou = 0;
        i = 0;
        while(i+1 < tam){
            if(vet[i]>vet[i+1]){
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                trocou = 1;
            }
            i++;
        }
      }
}

void bubleSort_Arq(char *nomeArq){

    FILE *arq = fopen(nomeArq, "rb+");
    fseek(arq,0,SEEK_END);
    int tam = ftell(arq);
    //printf("\nTamanho = %d\n", tam);
    rewind(arq);
    int trocou = 1, a, b;

    while(trocou){
        trocou = 0;
        rewind(arq);
        while(ftell(arq) < tam - sizeof(int)){
            //printf("posição: %d\n", ftell(arq));

            fread(&a, sizeof(int), 1, arq);
            fread(&b, sizeof(int), 1, arq);
            //printf("posição2: %d  a = %d, b = %d\n", ftell(arq), a, b);
            if(a>b){
                fseek(arq, ftell(arq) - 2*sizeof(int), SEEK_SET);
                fwrite(&b, sizeof(int), 1, arq);
                fwrite(&a, sizeof(int), 1, arq);
                trocou = 1;
            }

            fseek(arq, ftell(arq) - sizeof(int), SEEK_SET);
            //printf("posição3: %d  a = %d, b = %d\n", ftell(arq), a, b);
        }
    }
    fclose(arq);
}

int main()
{
    int vet [] = {2, 4, 7, -1, 32 , 11};
    //bubleSort(vet, 6);
    //quick_sort(vet,vet[0], vet[2]);
    for(int i = 0; i<6; i++)
        printf("%d ", vet[i]);


    FILE *arq = fopen("vetor", "wb");
    if(!arq) exit(1);

    int i = 0;
    while(i < (sizeof(vet)/sizeof(int))){
        fwrite(&vet[i],sizeof(int), 1, arq);
        i++;
    }

    fclose(arq);

    bubleSort_Arq("vetor");

    fopen("vetor", "r");
        if(!arq) exit(1);
    printf("\n\n\n");
    i = 0;
    int aux;
    while(i < (sizeof(vet)/sizeof(int))){
        fread(&aux,sizeof(int), 1, arq);
        printf("%d ", aux);
        i++;
    }
    fclose(arq);

    return 0;
}

