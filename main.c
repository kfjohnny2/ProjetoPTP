#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/ProcessadorDeImagem.h"

int main(){
    char filtro[3];

    //Recebe e armazena nome do arquivo em uma variavel do tipo char.
    printf("Nome do arquivo: ");
    scanf("%s", file_name);
    
    //Joga o arquivo no metodo de verificacao.
    verificaPPM(file_name);

    //Instancia novamento o registro de pixels, 'PPMRgb' com os valores redefinidos.
    PPMRgb img[MAX][MAX];

    printf("Qual filtro voce deseja aplicar na sua imagem?\n'thr'\n'blu'\n'sha'\n'rot'\n'amp'\n'red'\n");
    scanf("%s", filtro);
    if (!strcmp(filtro, "thr")){
        binarizacao(img, file_name); 
        //imprimir(file_name, img);
    } else if (!strcmp(filtro, "amp")){
        ampliar(img, file_name);
    }  else if(!strcmp(filtro, "rot")){
        rotate(img, file_name);
    }  else if(!strcmp(filtro, "red")){
        reduce(img, file_name);
    } 
        
    printf("Pronto\n");
    return 0;
}