void binarizacao(PPMRgb img[MAX][MAX], char filename[]){
    /*Neste metodo, e passado um parametro 'img' do tipo PPMRgb, onde estao localizadas as variaveis dos RGBs dos pixels.
      O metodo percorrera cada pixel e fara a media entre os RGBs de cada. Em seguida, definido o valor obtido das medias em cada valor do RGB.
    */

    //Variaveis de controle.
    int i, j, mediaRGB, base;
    printf("Digite um valor base para a binarizacao\n");
    scanf("%i", &base);
       //Concatena os caracteres do nome do arquivo com o formato do mesmo para a saida.
    strcat(strcat(filename, "_bin"), ".ppm");
    
    //Abre o arquivo para manipulacao.
    img_file = fopen(filename, "w");

    /*Reescreve o cabeçalho do arquivo*/
    fprintf(img_file, "P3\n");
    fprintf(img_file, "%i %i\n", lar, alt);
    fprintf(img_file, "%i\n",maxRGB);
    for (i = 0; i < lar; i++){
        for (j = 0; j < alt; j++){
                //CALCULO DA MEDIA DOS RGBs seguida da redefinicao dos valores.
                mediaRGB = (img[i][j].r + img[i][j].g + img[i][j].b)/3;
                if(mediaRGB<base){
                    mediaRGB = 0;
                } else {
                    mediaRGB = maxRGB;
                }    
                       
                img[i][j].r = mediaRGB;
                img[i][j].g = mediaRGB;
                img[i][j].b = mediaRGB;
                fprintf(img_file, "%i %i %i\n", img[i][j].r, img[i][j].g, img[i][j].b);                
        }
    }
    fclose(img_file);
}

void ampliar(PPMRgb img[alt][lar], char filename[]){
    int amp, k, l;

    strcat(strcat(filename, "_amp"), ".ppm");
    
    //Abre o arquivo para manipulacao.
    img_file = fopen(filename, "w");
    
    printf("Em quantas vezes deseja ampliar a foto?\n");
    scanf("%i", &amp);

    fprintf(img_file, "P3\n");
    fprintf(img_file, "%i %i\n", lar*amp, alt*amp);
    fprintf(img_file, "%i\n",maxRGB);
    for (i = 0; i < alt; i++){
        for ( k = 0; k < amp; k++){        
            for (j = 0; j < lar; j++){
                for (l = 0; l < amp; l++){
                  fprintf(img_file, "%i %i %i\n", img[i][j].r, img[i][j].g, img[i][j].b);
                }
            }
        }
    }
    fclose(img_file);
}

void rotate(PPMRgb img[MAX][MAX], char filename[]){
    int i, j;
    //strcat(strcat(filename, "-rot"), ".ppm");
     strcat(filename, "_rot.ppm");  
    //Abre o arquivo para manipulacao.
    img_file = fopen(filename, "w");

    //cria matriz temporaria para fazer a manipulacao
    PPMRgb img_aux[MAX][MAX];
    for (i = 0; i < alt; i++){
        for (j = 0; j < lar; j++){
            //clona a matriz
            img_aux[i][j] = img[i][j];
        }
    }
    fprintf(img_file, "P3\n");
    fprintf(img_file, "%i %i\n", alt, lar);
    fprintf(img_file, "%i\n",maxRGB);

    //copia a matriz auxiliar para dentro da matriz de origem deitada (transposta)
    for (i = 0; i < alt; i++){
        for (j = 0; j < lar; j++){
            img[lar-j-1][i] = img_aux[i][j];
        }
    }
    for (i = 0; i < alt; i++){
        for (j = 0; j < lar; j++){
            //repete o processo de copia de matriz
            fprintf(img_file, "%i %i %i\n", img[i][j].r, img[i][j].g, img[i][j].b);
        }
    }
    fclose(img_file);

}

void reduce(PPMRgb img[MAX][MAX], char filename[]){

    int red, k, l;
    
    strcat(strcat(strcat(filename, "_"), "red"), ".ppm");
    
    //Abre o arquivo para manipulacao.
    img_file = fopen(filename, "w");
    
    printf("Em quantas vezes deseja reduzir a foto?\n");
    scanf("%i", &red);
    
    int area_img=red*red;
    PPMRgb img_aux = {0,0,0};

    fprintf(img_file, "P3\n");
    fprintf(img_file, "%i %i\n", lar/red, alt/red);
    fprintf(img_file, "%i\n",maxRGB);
    for (i = 0; i <= alt-red; i += red){
        for (j = 0; j <= lar-red; j += red, 
                    img_aux.r = 0, img_aux.g = 0, img_aux.b = 0) {
            for (k = 0; k < red; k++){
                for (l = 0; l < red; l++){
                    img_aux.r += img[i+k][j+l].r,
                    img_aux.g += img[i+k][j+l].g,
                    img_aux.b += img[i+k][j+l].b;
                }
            }
            fprintf(img_file, "%i %i %i\n",img_aux.r/area_img, img_aux.g/area_img, img_aux.b/area_img);
        } 
    }
    fclose(img_file);
}

void imprimir(char filename[], PPMRgb img[MAX][MAX]){

    //Concatena os caracteres do nome do arquivo com o formato do mesmo para a saida.
    strcat(strcat(filename, "_"), ".ppm");
    
    //Abre o arquivo para manipulacao.
    img_file = fopen(filename, "w");

    /*Reescreve o cabeçalho do arquivo*/
    fprintf(img_file, "P3\n");
    fprintf(img_file, "%i %i\n", lar, alt);
    fprintf(img_file, "%i\n",maxRGB);
    /*Escreve o RGB de cada pixel do arquivo, utilizando os novos valores definidos no registro 'PPMRgb'*/
    for (i = 0; i < lar; i++){
        for (j = 0; j < alt; j++){
            fprintf(img_file, "%i %i %i\n", img[i][j].r, img[i][j].g, img[i][j].b);
        }            
    }
        
    //Fecha o buffer para evitar erros na memoria.
    fclose(img_file);
}
