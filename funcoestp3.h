/*Arquivo que define a biblioteca e contém o cabeçalho/protótipo/referência de
 * todas as funções presentes na biblioteca*/

#ifndef FUNCOESTP3_
#define FUNCOESTP3_

/* Estrutura obrigatória do jogador*/
typedef enum meses {
  janeiro = 1,
  fevereiro,
  marco,
  abril,
  maio,
  junho,
  julho,
  agosto,
  setembro,
  outubro,
  novembro,
  dezembro
} MESES;

typedef struct dataNascimento {
  int dia;
  int mes;
  int ano;
} DATANASCIMENTO;

typedef struct equipe {
  char nome_da_equipe[30];
  char nick_rede_social_equipe[30];
  long int seguidores_equipe;
} EQUIPE;

typedef struct hardware {
  char modelo_do_pc[30];
  char processador[30];
  char placa_de_video[30];
  int qnt_ram;
} HARDWARE;

typedef struct pontuacao {
  int pontuacao_total;
  int vitorias; // 3 pontos por vitórias
  int derrotas; // 0 pontos por derrota
  int empates;  // 1 ponto por empate
} PONTUACAO;

typedef struct jogador {
  char nome_do_jogador[30];
  DATANASCIMENTO data_de_nascimento;
  long int cpf;
  char genero[10];
  char estadoCivil[15];
  EQUIPE equipe;
  char patrocinadora_principal[30];
  char nick_rede_jogador[30];
  long int seguidores_jogador;
  HARDWARE hardware;
  PONTUACAO pontuacao;
  int qnt_titulos;
  int posicao_rank_mundial;
} JOGADOR;

/*Funções presentes no TP3*/
/*1*/ void CadastrarJogador();

/*2*/ void imprimirJogadoresVetor();

/*3*/ // int AtualizarCadastro(JOGADOR jogadores[], int quant);

/*4*/ // int AtualizarPontuacao(JOGADOR jogadores[], int quant);

/*5*/ void ListarJogadoresAlfabetico();

/*6*/ void ListarJogadoresPosicaoRanking();

/*7*/ void ListarJogadoresPorVitorias();

/*8*/ //void ClassificacaoCampeonato();

/*9*/ //void ListaJogadoresPontuacaoMaior();

/*10*/ //void ListaJogadoresPontuacaoMenor();

/*11*/ void buscaJogadorNome ();

/*12*/ void buscaPosicaoRankMundial();

/*13*/ void MediaSeguidores();

#include "funcoestp3.c"
#endif //FUNCOESTP3_

