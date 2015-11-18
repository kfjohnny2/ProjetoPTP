FILE *img_file;
char file_name[50], op[3];
int lar, alt, MAX, maxRGB;
int i,j;

//Criacao de registro para armazenamento da escala RGBfuncoes.h
typedef struct{
    int red;
    int green;
    int blue;
} PPMRgb;