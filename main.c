#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/ProcessadorDeImagem.h"

int main(){
    char filtro[3];
    char file[50];

    //Recebe e armazena nome do arquivo em uma variavel do tipo char.
    printf("Nome do arquivo: ");
    scanf("%s", file);
    
    //Joga o arquivo no metodo de verificacao.
    verificaPPM(file);

    //Instancia novamento o registro de pixels, 'PPMRgb' com os valores redefinidos.
    PPMRgb img[MAX][MAX];

    printf("Qual filtro voce deseja aplicar na sua imagem?\n'thr'\n'blu'\n'sha'\n'rot'\n'amp'\n'red'\n");
    scanf("%s", filtro);
    if (!strcmp(filtro, "thr")){
        binarizacao(img); 
        imprimir(file, img);
    } else if (!strcmp(filtro, "amp")){
        ampliar(img, file);
    }  else if(!strcmp(filtro, "rot")){
        rotate(img, file);
    }
        
    printf("Pronto\n");
    return 0;
}