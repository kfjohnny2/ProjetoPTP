#include "utils.h"
#include "headers.h"
#include "funcoes.h"

void verificaPPM(char file[]){

    /*Copia a string do parametro 'file[]'*/
    strcpy(file_name, file);

    //DEFINE O NOME FINAL DO ARQUIVO, CONCATENANDO O FORMATO DO MESMO.
    img_file = fopen(strcat(file_name,".ppm"), "r");
    if (img_file == NULL) {
        fprintf(stderr, "ARQUIVO NULO\n");
        return;
    }

    //verificaComentarios();

    /*Escaneia o cabeçalho do arquivo e preenche as variaveis de altura e largura de acordo com o que esta no arquivo a ser manipulado*/
    fscanf(img_file, "P3 ");
    //verificaComentarios();
    fscanf(img_file, "%i ", &lar);
    //verificaComentarios();
    fscanf(img_file, "%i \n", &alt);
    fscanf(img_file, "%i \n", &maxRGB);
    //verificaComentarios();

    /*Verifica se os valores sao diferentes de nulo*/
    if(!lar || !alt || !maxRGB){
        fprintf(stderr, "ERRO AO LER ARQUIVO\n");
        return;
    }

    //verifica qual a maior dimensao para preencher a variavel MAX com o maior valor a ser manipulado
    if(lar>alt){
        MAX = lar;
    } else{
        MAX = alt;
    }

    /*Instancia o registro com seus valores determinados*/
    PPMRgb image[MAX][MAX];

    //Joga o registro no metodo de leitura do arquivo.
    lerPPM(image);

    //Fecha o buffer para evitar erros na memoria.
    fclose(img_file);
}

void lerPPM(PPMRgb img[MAX][MAX]){

    /*Percorre o arquivo 'img_file' preenchendo cada item do registro 'PPMRgb' com o seu devido valor vindo do arquivo*/
    for (i = 0; i < alt; i++){
        for (j = 0; j < lar; j++) {
            //fscanf(img_file, "%i %i %i", &img[i][j].r, &img[i][j].g, &img[i][j].b);
            fscanf(img_file, "%i ", &img[i][j].g);
            //verificaComentarios();
            fscanf(img_file, "%i ", &img[i][j].b);
            //verificaComentarios();
            fscanf(img_file, "%i ", &img[i][j].r);
            //verificaComentarios();
        }
    }
        
}

void verificaComentarios(){
    char c;
    //Prepara a leitura de   caracteres do arquivo.
    c = fgetc(img_file);
    //Verifica se existem '#' no arquivo, ou seja, se existem cometarios. Enquanto houver, o sistema ira quebrar uma linha para ignorar o comentario. 
    while(c=='#'){  
        while(fgetc(img_file) != '\n');
        c=fgetc(img_file);
    }
    //Limpa o getc para reutilizaçao futura 
    ungetc(c, img_file);
}

void menu(char filtro[], char arquivo[], PPMRgb img[MAX][MAX]){
    char sair[1];
    printf("Qual filtro voce deseja aplicar na sua imagem?\nBinarizar imagem --- > 'thr'\nEmbaçar imagem --- > 'blu'\nAplicar sharpening --- > 'sha'\nRotacionar imagem --- >'rot'\nAmpliar imagem --- > 'amp'\nReduzir imagem --- > 'red'\nFinalizar aplicação --- > 'sair'\n");
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
    } else if(!strcmp(filtro, "sair")){
        printf("Concluido\n");
        exit(0);
    } 
    
    printf("Deseja finalizar o sistema? s/n \n");
    scanf("%s", sair);
    if(!strcmp(sair, "s")){
        printf("Concluido\n");
        exit(0);
    } else if(!strcmp(sair, "n")){
        menu(filtro, arquivo, img);
    }
}