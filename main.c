#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Definições *****************************************************************/

#define LARGURA_TELA 79
#define ALTURA_TELA  23

typedef struct{         //Estrutura dos tiles do mapa
    char c;             //c          -> Caracter que representa o tile
    bool passavel;     //passavel   -> Determina se entidades podem andar por cima do tile
}TILE_STRUCT;
const TILE_STRUCT TILE[] = {  //Dicionário com todas as informações sobre tiles
    {'.', true},        //TILE[0] -> Chão
    {'#', false},       //TILE[1] -> Parede
};

/* Variáveis Globais **********************************************************/

char TELA[LARGURA_TELA*ALTURA_TELA];        //Matriz com o que será impresso na saída padrão
short MAPA_ATUAL[LARGURA_TELA*ALTURA_TELA]; //Matriz com ids dos tiles do mapa atual. Por convenção o mapa sempre é do tamanho da tela -2

/* Funções de Mapa ************************************************************/
void renderizaMapa(){
    /* Renderiza o mapa atual na tela */
    short i;
    
    for(i=0;i<LARGURA_TELA*ALTURA_TELA;i++){
        TELA[i] = TILE[MAPA_ATUAL[i]].c;
    }
}

void inicializaMapa(){
    /* Inicializa o mapa com paredes em volta */
    short x, y;
    for(y=0;y<ALTURA_TELA;y++){
        for(x=0;x<LARGURA_TELA;x++){
            if(0==x || LARGURA_TELA-1==x || 0==y || ALTURA_TELA-1==y){
                MAPA_ATUAL[y*LARGURA_TELA+x] = 1;
            }else{
                MAPA_ATUAL[y*LARGURA_TELA+x] = 0;
            }
        }
    }
}

/* Funções de Tela ************************************************************/
void imprimeTela(){
    /* Mostra a tela na saída padrão */
    short x, y;
    for(y=0;y<ALTURA_TELA;y++){
        for(x=0;x<LARGURA_TELA;x++){
            printf("%c",TELA[y*LARGURA_TELA + x]);
        }
        printf("\n");
    }
}

/* Outras Funções *************************************************************/
int esperaTecla(){
    /* Espera até que o usuário aperte uma tecla e retorna o código da tecla pressionada */
    char in;
    scanf("%c",&in);
    return in;
}

/* Main ***********************************************************************/
int main(int argc, char** argv) {
    inicializaMapa(); //TODO: Excluir esta função e fazer a geração procedural dos mapas do jogo

	while(true){
		renderizaMapa();
		imprimeTela();
		esperaTecla();
	}
    return (EXIT_SUCCESS);
}
