#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/ProcessadorDeImagem.h"

int main(){
    char filtro[4];
    char arquivo[50];
    //Recebe e armazena nome do arquivo em uma variavel do tipo char.
    printf("Nome do arquivo: ");
    scanf("%s", arquivo);
    
    //Joga o arquivo no metodo de verificacao.
    verificaPPM(arquivo);

    //Instancia novamento o registro de pixels, 'PPMRgb' com os valores redefinidos.
    PPMRgb img[MAX][MAX];

    menu(filtro, arquivo, img);
    /*
    printf("Qual filtro voce deseja aplicar na sua imagem?\n'thr'\n'blu'\n'sha'\n'rot'\n'amp'\n'red'\n'sair'\n");
    scanf("%s", filtro);
    if (!strcmp(filtro, "thr")){
        binarizacao(img, arquivo); 
        //imprimir(file_name, img);
    } else if (!strcmp(filtro, "amp")){
        ampliar(img, arquivo);
    }  else if(!strcmp(filtro, "rot")){
        rotate(img, arquivo);
    }  else if(!strcmp(filtro, "red")){
        reduce(img, arquivo);
    } else if(!strcmp(filtro, "blu")){
        blurring(img, arquivo);
    } else if(!strcmp(filtro, "sha")){
        sharpening(img, arquivo);
    }
        
    printf("Pronto\n");*/
    return 0;
}