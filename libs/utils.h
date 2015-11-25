//Declarações de variáveis globais.
FILE *img_file;
char file_name[50];
int lar, alt, MAX, maxRGB;
int i,j;

//Criacao de registro para armazenamento da escala RGBfuncoes
typedef struct{
    int r;
    int g;
    int b;
} PPMRgb;