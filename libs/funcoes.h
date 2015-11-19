void binarizacao(PPMRgb img[MAX][MAX]){
    /*Neste metodo, e passado um parametro 'img' do tipo PPMRgb, onde estao localizadas as variaveis dos RGBs dos pixels.
      O metodo percorrera cada pixel e fara a media entre os RGBs de cada. Em seguida, definido o valor obtido das medias em cada valor do RGB.
    */

    //Variaveis de controle.
    int i, j, mediaRGB, base;
    printf("Digite um valor base para a binarizacao\n");
    scanf("%i", &base);
    for (i = 0; i < lar; i++){
        for (j = 0; j < alt; j++){
                //CALCULO DA MEDIA DOS RGBs seguida da redefinicao dos valores.
                mediaRGB = (img[i][j].red + img[i][j].green + img[i][j].blue)/3;
                if(mediaRGB<base){
                    mediaRGB = 0;
                } else {
                    mediaRGB = maxRGB;
                }    
                       
                img[i][j].red = mediaRGB;
                img[i][j].green = mediaRGB;
                img[i][j].blue = mediaRGB;
                
        }
    }
}

void ampliar(PPMRgb img[alt][lar], char filename[]){
    int amp, k, l;

    strcat(strcat(filename, "_"), ".ppm");
    
    //Abre o arquivo para manipulacao.
    img_file = fopen(filename, "w");
    
    printf("Em quantas vezes deseja ampliar a foto\n");
    scanf("%i", &amp);

    fprintf(img_file, "P3\n");
    fprintf(img_file, "%i %i\n", lar*amp, alt*amp);
    fprintf(img_file, "%i\n",maxRGB);
    for (i = 0; i < alt; i++){
        for ( k = 0; k < amp; k++){        
            for (j = 0; j < lar; j++){
                for (l = 0; l < amp; l++){
                  fprintf(img_file, "%i %i %i\n", img[i][j].red, img[i][j].green, img[i][j].blue);
                }
            }
        }
    }
    fclose(img_file);
}

void rotate(PPMRgb img[MAX][MAX], char filename[]){
    int i, j;
    strcat(strcat(filename, "-rot"), ".ppm");
        
    //Abre o arquivo para manipulacao.
    img_file = fopen(filename, "w");

    PPMRgb img_aux[MAX][MAX];
    for (i = 0; i < alt; i++)
        for (j = 0; j < lar; j++)
            //cria matriz temporaria para fazer a manipulacao
            img_aux[i][j] = img[i][j];

    fprintf(img_file, "P3\n");
    fprintf(img_file, "%i %i\n", alt, lar);
    fprintf(img_file, "%i\n",maxRGB);

    //copia a matriz auxiliar para dentro da matriz de origem deitada (transposta)
    for (i = 0; i < alt; i++)
        for (j = 0; j < lar; j++)
            img[lar-j-1][i] = img_aux[i][j]; 

    for (i = 0; i < alt; i++)
        for (j = 0; j < lar; j++)
            //repete o processo de copia de matri
            fprintf(img_file, "%i %i %i\n", img[i][j].red, img[i][j].green, img[i][j].blue);
    fclose(img_file);

}

void imprimir(char filename[], PPMRgb img[MAX][MAX]){
    int i, j;
    //Concatena os caracteres do nome do arquivo com o formato do mesmo para a saida.
    strcat(strcat(filename, "_"), ".ppm");
    
    //Abre o arquivo para manipulacao.
    img_file = fopen(filename, "w");

    /*Reescreve o cabeçalho do arquivo*/
    fprintf(img_file, "P3\n");
    fprintf(img_file, "%i %i\n", lar, alt);
    fprintf(img_file, "%i\n",maxRGB);
    /*Escreve o RGB de cada pixel do arquivo, utilizando os novos valores definidos no registro 'PPMRgb'*/
    for (i = 0; i < lar; i++)
        for (j = 0; j < alt; j++)
            fprintf(img_file, "%i %i %i\n", img[i][j].red,img[i][j].green, img[i][j].blue);

    //Fecha o buffer para evitar erros na memoria.
    fclose(img_file);
}
