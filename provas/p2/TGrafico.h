#define MAX 100

struct ponto {
    float x;
    float y;
};
 
typedef struct TGrafico TGrafico ;

TGrafico* cria_grafico();
void apaga_grafico(TGrafico* li);
int definir_nomes_eixos(TGrafico* li, char *eixo_x, char *eixo_y);
int definir_titulo(TGrafico* li, char *titulo);
int insere_ponto_inicio(TGrafico* li, struct ponto pto);
int insere_ponto_fim(TGrafico* li, struct ponto pto);
int mostrar_grafico(TGrafico* li);
int busca_maior(TGrafico* li);
int inserir(TGrafico* li, int pos, float pontox, float pontoy);