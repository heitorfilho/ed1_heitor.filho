// tad

typedef struct TMat2D TMat2D;

TMat2D *mat2D_create(int nrow, int ncol);
int mat2d_free(TMat2D *mat);
double acessar(int nrow, int ncolums, TMat2D *mat);
int escrever(int nrow, int ncolums, TMat2D *mat, double n );
int preencher(double n1, double n2, TMat2D *mat);
int somar(TMat2D *mat1, TMat2D *mat2);
int multiplicar(TMat2D *mat1, TMat2D *mat2);
int multiplicar_escalar(TMat2D *mat1, double escalar);
double traco(TMat2D *mat);
int getnrows(TMat2D *mat);
int getncolumns(TMat2D *mat);
int soma_linha(TMat2D *mat, double *v);
int soma_coluna(TMat2D *mat, double *v);