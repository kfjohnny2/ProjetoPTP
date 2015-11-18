#include "utils.h"
#include "headers.h"
#include "funcoes.h"

void verificaPPM(char file[]){

    /*Copia a string do parametro 'file[]'*/
    strcpy(file_name, file);

    //DEFINE O NOME FINAL DO ARQUIVO, CONCATENANDO O FORMATO DO MESMO.
    img_file = fopen(strcat(file,".ppm"), "r");
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
    fscanf(img_file, "%i ", &alt);
    fscanf(img_file, "%i ", &maxRGB);
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
    for (i = 0; i < alt; i++)
        for (j = 0; j < lar; j++) {
            fscanf(img_file, "%i ", &img[i][j].red);
            //verificaComentarios();
            fscanf(img_file, "%i ", &img[i][j].green);
            //verificaComentarios();
            fscanf(img_file, "%i ", &img[i][j].blue);
            //verificaComentarios();
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