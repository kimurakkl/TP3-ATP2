/* Implementação de um sistema de Campeonato de eSports com equipes porém que
 * jogam individualmente (1x1). O sistema implementado consiste em um simples
 * cadastro de registros de jogadores de eSports, na qual é possível aplicar
 * manipulações como inserção, remoção, atualização e consulta de jogadores
 * utilizando arquivos.*/

#include "funcoestp3.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
  int n=1;

  while (n != 0) {

    printf("\n\n ~ MENU ~ ");
    printf("\n\n0 - SAIR\n1 - Cadastrar um novo jogador\n2 - Ler cadastro de "
           "todos os jogadores\n3 - Atualizar cadastro de um jogador\n4 - "
           "Inserir vitoria, derrota ou empate (Atualizar pontuacao)");
    printf("\n5 - Listar todos os jogadores em ordem alfabetica\n6 - Listar "
           "todos os jogadores por ordem da posição do rank mundial\n7 - "
           "Listar todos os jogadores com maior numero de vitorias");
    printf("\n8 - Mostrar a classificacao do campeonato\n9 - Listar jogadores "
           "com pontuacao maior que um dado valor\n10 - Listar jogadores com "
           "pontuacao menor que um dado valor");
    printf("\n11 - Buscar um jogador por nome\n12 - Buscar um jogador por "
           "posicao no rank mundial\n13 - Mostrar a quantidade media de "
           "seguidores de um jogador do campeonato");
    printf("\n\nDigite o numero que corresponde ao que voce deseja fazer: ");
    scanf("%d", &n);

    switch (n) {
    case 1:
      printf ("\ncaso 1\n");
      CadastrarJogador();
      break;

    case 2:
      printf ("caso 2");
      imprimirJogadoresVetor();
      break;

    case 3:
      printf ("caso 3");
      //AtualizarCadastro();
      break;

    case 4:
      printf ("caso 4");
      //AtualizarPontuacao();
      break;

    case 5:
      printf ("caso 5");
      ListarJogadoresAlfabetico();
      break;

    case 6:
      printf ("caso 6");
      ListarJogadoresPosicaoRanking();
      break;

    case 7:
      printf ("caso 7");
      ListarJogadoresPorVitorias();
      break;

    case 8:
      printf ("caso 8");
      //ClassificacaoCampeonato();
      break;

    case 9:
      printf ("caso 9");
      //ListaJogadoresPontuacaoMaior();
      break;

    case 10:
      printf ("caso 10");
      //ListaJogadoresPontuacaoMenor();
      break;

    case 11:
      printf ("caso 11");
      buscaJogadorNome ();
      break;

    case 12:
      printf ("caso 12");
      buscaPosicaoRankMundial();
      break;

    case 13:
      printf ("caso 13");
      MediaSeguidores();
      break;

    default:
      break;
    }
  }
  return 0;
}

