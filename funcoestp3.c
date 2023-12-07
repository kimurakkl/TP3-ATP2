/*Arquivo que possui a implementação de todas as funções presentes na
 * *biblioteca*/

// Colocar todas as funções nesse arquivo!!!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int quantidade_de_jogadores(){

  FILE *file;
  file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\TP3\\jogadores.dat", "rb");
  fseek(file, 0*sizeof(JOGADOR),SEEK_END);
  int tam = (ftell(file)/sizeof(JOGADOR));

  fclose(file);
  return(tam); 
}

/*1*/void CadastrarJogador() {

  JOGADOR jogadores;

    printf("\nCADASTRO DO NOVO JOGADOR");
    printf("\nDigite o nome do jogador: ");
    fflush(stdin);
    gets(jogadores.nome_do_jogador); 
    fflush(stdin);

    printf("\nDigite a data de nascimento do jogador: ");
    printf("\nInsira o dia: ");
    scanf("%d", &jogadores.data_de_nascimento.dia);
    printf("\nInsira o mes: ");
    scanf("%d", &jogadores.data_de_nascimento.mes);
    printf("\nInsira o ano: ");
    scanf("%d", &jogadores.data_de_nascimento.ano);

    printf("\nDigite o CPF: ");
    scanf("%ld", &jogadores.cpf);

    fflush(stdin);
    printf("\nDigite o genero: ");
    gets(jogadores.genero);
    fflush(stdin);

    printf("\nDigite o estado civil: ");
    gets(jogadores.estadoCivil);
    fflush(stdin);

    printf("\nDigite o nome da equipe: ");
    gets(jogadores.equipe.nome_da_equipe);
    fflush(stdin);
    printf("\nDigite o nick de rede social da equipe: ");
    gets(jogadores.equipe.nick_rede_social_equipe);
    fflush(stdin);
    printf("\nDigite a quantidade de seguidores da equipe nas redes sociais: ");
    scanf("%ld", &jogadores.equipe.seguidores_equipe);

    fflush(stdin);
    printf("\nDigite o nome da patrocinadora principal: ");
    gets(jogadores.patrocinadora_principal);
    fflush(stdin);

    fflush(stdin);
    printf("\nDigite o nick do jogador nas redes sociais: ");
    gets(jogadores.nick_rede_jogador);
    fflush(stdin);

    printf(
        "\nDigite a quantidade de seguidores do jogador nas redes sociais: ");
    scanf("%ld", &jogadores.seguidores_jogador);

    fflush(stdin);
    printf(
        "\nDigite o modelo do computador ou notebook utilizado pelo jogador: ");
    gets(jogadores.hardware.modelo_do_pc);
    fflush(stdin);
    printf("\nDigite o modelo do processador: ");
    gets(jogadores.hardware.processador);
    fflush(stdin);
    printf("\nDigite o modelo da placa de video: ");
    gets(jogadores.hardware.placa_de_video);
    fflush(stdin);
    printf("\nDigite a quantidade de memoria RAM da maquina: ");
    scanf("%d", &jogadores.hardware.qnt_ram);

    printf("\nDigite a quantidade de vitorias: ");
    scanf("%d", &jogadores.pontuacao.vitorias);
    printf("\nDigite a quantidade de derrotas: ");
    scanf("%d", &jogadores.pontuacao.derrotas);
    printf("\nDigite a quantidade de empates: ");
    scanf("%d", &jogadores.pontuacao.empates);

    printf("\nDigite a quantidade de titulos do jogador: ");
    scanf("%d", &jogadores.qnt_titulos);

    printf("\nDigite a posicao no rank mundial: ");
    scanf("%d", &jogadores.posicao_rank_mundial);

    FILE *file;
    file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\TP3\\jogadores.dat", "ab");

    if(file != NULL) {

        int qtsRegEscritos = fwrite(&jogadores, sizeof(JOGADOR), 1, file);
        printf ("A quantidade de registros escritos e: %d", qtsRegEscritos);
        fclose(file);
    }
    else printf("O ARQUIVO NÃO FOI ABERTO!\n\n");
    return;

}

/*2*/ void LerCadastroJogador() {

  FILE *file;
  file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\TP3\\jogadores.dat", "rb");

  int tam = quantidade_de_jogadores();
  JOGADOR jogadoresLidos[tam];

  if (file != NULL) {
    int qtdRegLidos = fread(jogadoresLidos, sizeof(JOGADOR), tam, file);
    printf("\nForam lidos %d registro(s) de aluno(s)!\n", qtdRegLidos);

    fclose(file);
  } else
    printf("O ARQUIVO NÃO FOI ABERTO!\n\n");
  return;
}

void imprimirJogadorVetor() {

  FILE *file;
  file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\TP3\\jogadores.dat", "rb");

  int tam = quantidade_de_jogadores(file);
  JOGADOR jogadores[tam];
  fread(jogadores, sizeof(JOGADOR), tam, file);

  printf("\n\n===== JOGADORES ====\n\n");

  for (int i = 0; i < tam; i++) {

    printf("\n\n==============================================================================\n\n");
    printf("\nNome: %s\n", jogadores[i].nome_do_jogador);
    printf("\nData de nascimento: %d/%d/%d\n",
           jogadores[i].data_de_nascimento.dia,
           jogadores[i].data_de_nascimento.mes,
           jogadores[i].data_de_nascimento.ano);
    printf("\nCPF: %ld\n", jogadores[i].cpf);
    printf("\nGenero: %s\n", jogadores[i].genero);
    printf("\nEstado Civil: %s\n", jogadores[i].estadoCivil);
    printf("\nNome da equipe: %s\n", jogadores[i].equipe.nome_da_equipe);
    printf("\nNick da rede social da equipe: %s\n",
           jogadores[i].equipe.nick_rede_social_equipe);
    printf(
        "\nQuantidade de seguidores da rede social da equipe: %ld seguidores\n",
        jogadores[i].equipe.seguidores_equipe);
    printf("\nPatrocinadora principal: %s\n",
           jogadores[i].patrocinadora_principal);
    printf("\nNick da rede social do jogador: %s\n",
           jogadores[i].nick_rede_jogador);
    printf(
        "\nQuantidade de seguidores da rede social do jogador: %ld jogadores\n",
        jogadores[i].seguidores_jogador);
    printf("\nModelo do pc: %s\n", jogadores[i].hardware.modelo_do_pc);
    printf("\nModelo do procesador: %s\n", jogadores[i].hardware.processador);
    printf("\nModelo da placa de video: %s\n",
           jogadores[i].hardware.placa_de_video);
    printf("\nQuantidade de memoria RAM: %dGB\n",
           jogadores[i].hardware.qnt_ram);
    printf("\nQuantidade de vitorias: %d vitorias\n",
           jogadores[i].pontuacao.vitorias);
    printf("\nQuantidade de derrotas: %d derrotas\n",
           jogadores[i].pontuacao.derrotas);
    printf("\nQuantidade de empates: %d empates\n",
           jogadores[i].pontuacao.empates);
    int pontuacao_total = (3 * jogadores[i].pontuacao.vitorias) +
                          (jogadores[i].pontuacao.empates);
    printf("\nPontuacao total: %d\n", pontuacao_total);
    printf("\nQuantidade de titulos do jogador: %d titulos\n",
           jogadores[i].qnt_titulos);
    printf("Posicao no rank mundial: %d lugar\n",
           jogadores[i].posicao_rank_mundial);
  }

  fclose(file);
}

/*3*/ int buscaJogador(JOGADOR jogadores[], int quant, int *posicao,char nome[30]) {
  FILE *file;

  file = fopen("jogadores.dat", "rb");
  if (file == NULL) {
    printf("O arquivo nao foi aberto\n");
    return (1);
  } else {
    for (int i = 0; i < quant; i++) {
      fseek(file, i * sizeof(JOGADOR), SEEK_SET);
      if (strcmp(nome, jogadores->nome_do_jogador) == 0) {
        *posicao = i;
        return *posicao;
      }
    }
    return 0;
  }
}

/*3*/ int AtualizarCadastro(JOGADOR jogadores[], int quant) {
  char nome[30];
  int dado, posicao;
  FILE *file;
  printf("\nDigite o nome do jogador: ");
  gets(nome);
  printf("\nDADOS:\n1 - Nome\n2 - Data de nascimento\n3 - CPF\n4 - Genero\n5 - "
         "Estado civil\n6 - Nome da equipe\n7 - Nick da equipe\n8 - Quantidade "
         "de seguidores da equipe\n9 - Patrocinadora principal\n10 - Nickname "
         "na rede social\n11 - Quantidade de seguidores\n12 - Modelo do pc\n13 "
         "- Processador\n14 - Placa de video\n15 - Quantidade de memoria "
         "RAM\n16 - Quantidade de titulos\n17 - Posicao "
         "no rank mundial\n ");
  printf("Digite 0 caso tenha acabado a atualização\n");
  while (1) {
    printf(
        "\nDigite o numero correspondente ao dado que se deseja atualizar: ");
    scanf("%d", &dado);
    printf("Digite o nome atual do jogador cujo cadastro deseja atualizar: ");
    gets(nome);
    buscaJogador(jogadores, quant, &posicao, nome);
    if (buscaJogador(jogadores, quant, &posicao, nome) == 0) {
      printf("Jogador nao encontrado\n");
      return 0;
    }
    switch (dado) {
    case 1:
      fflush(stdin);
      printf("Digite o novo nome do jogador: ");
      gets(jogadores[posicao].nome_do_jogador);
      file = fopen("jogadores.dat", "wb");
      fseek(file, posicao * sizeof(JOGADOR), SEEK_SET);
      printf("%s", jogadores[posicao].nome_do_jogador);
      fclose(file);
      break;
    case 2:
      fflush(stdin);
      printf("Digite o dia da nova data de nascimento: ");
      scanf("%d", &jogadores[posicao].data_de_nascimento.dia);
      printf("Digite o mes da nova data de nascimento: ");
      scanf("%d", &jogadores[posicao].data_de_nascimento.mes);
      printf("Digite o ano da nova data de nascimento: ");
      scanf("%d", &jogadores[posicao].data_de_nascimento.ano);
      file = fopen("jogadores.dat", "wb");
      fseek(file, (posicao * sizeof(JOGADOR)) + sizeof(nome[30]), SEEK_SET);
      printf("%d\n", jogadores[posicao].data_de_nascimento.dia);
      printf("%d\n", jogadores[posicao].data_de_nascimento.mes);
      printf("%d\n", jogadores[posicao].data_de_nascimento.ano);
      fclose(file);
      break;
    case 3:
      fflush(stdin);
      printf("Digite o novo cpf do jogador: ");
      scanf("%ld", &jogadores[posicao].cpf);
      file = fopen("jogadores.dat", "wb");
      fseek(file,
            (posicao * sizeof(JOGADOR)) + sizeof(nome[30]) +
                sizeof(DATANASCIMENTO),
            SEEK_SET);
      printf("%ld", jogadores[posicao].cpf);
      fclose(file);
      break;
    case 4:
      fflush(stdin);
      printf("Digite o novo genero do jogador: ");
      gets(jogadores[posicao].genero);
      file = fopen("jogadores.dat", "wb");
      fseek(file,
            (posicao * sizeof(JOGADOR)) + sizeof(nome[30]) +
                sizeof(DATANASCIMENTO) + sizeof(int),
            SEEK_SET);
      printf("%s", jogadores[posicao].genero);
      fclose(file);
      break;
    case 5:
      fflush(stdin);
      printf("Digite o novo estado civil do jogador: ");
      gets(jogadores[posicao].estadoCivil);
      file = fopen("jogadores.dat", "wb");
      fseek(file,
            (posicao * sizeof(JOGADOR)) + sizeof(nome[30]) +
                sizeof(DATANASCIMENTO) + sizeof(int) + sizeof(char[10]),
            SEEK_SET);
      printf("%s", jogadores[posicao].estadoCivil);
      fclose(file);
      break;
    case 6:
      fflush(stdin);
      printf("Digite o novo nome da equipe do jogador: ");
      gets(jogadores[posicao].equipe.nome_da_equipe);
      file = fopen("jogadores.dat", "wb");
      fseek(file,
            (posicao * sizeof(JOGADOR)) + sizeof(nome[30]) +
                sizeof(DATANASCIMENTO) + sizeof(int) + sizeof(char[10]) +
                sizeof(char[15]),
            SEEK_SET);
      printf("%s", jogadores[posicao].equipe.nome_da_equipe);
      fclose(file);
      break;
    case 7:
      fflush(stdin);
      printf("Digite o novo nick da equipe do jogador: ");
      gets(jogadores[posicao].equipe.nick_rede_social_equipe);
      file = fopen("jogadores.dat", "wb");
      fseek(file,
            (posicao * sizeof(JOGADOR)) + sizeof(nome[30]) +
                sizeof(DATANASCIMENTO) + sizeof(int) + sizeof(char[10]) +
                sizeof(char[15]) + sizeof(char[30]),
            SEEK_SET);
      printf("%s", jogadores[posicao].equipe.nick_rede_social_equipe);
      fclose(file);
      break;
    case 8:
      fflush(stdin);
      printf("Digite a nova quantidade de seguidores da equipe do jogador: ");
      scanf("%ld", &jogadores[posicao].equipe.seguidores_equipe);
      file = fopen("jogadores.dat", "wb");
      fseek(file,
            (posicao * sizeof(JOGADOR)) + sizeof(nome[30]) +
                sizeof(DATANASCIMENTO) + sizeof(int) + sizeof(char[10]) +
                sizeof(char[15]) + (2 * sizeof(char[30])),
            SEEK_SET);
      printf("%ld", jogadores[posicao].equipe.seguidores_equipe);
      fclose(file);
      break;
    case 9:
      fflush(stdin);
      printf("Digite o novo nome da patrocinadora principal do jogador: ");
      gets(jogadores[posicao].patrocinadora_principal);
      file = fopen("jogadores.dat", "wb");
      fseek(file,
            (posicao * sizeof(JOGADOR)) + sizeof(nome[30]) +
                sizeof(DATANASCIMENTO) + sizeof(int) + sizeof(char[10]) +
                sizeof(char[15]) + sizeof(EQUIPE),
            SEEK_SET);
      printf("%s", jogadores[posicao].patrocinadora_principal);
      fclose(file);
      break;
    case 10:
      fflush(stdin);
      printf("Digite o novo nick do jogador: ");
      gets(jogadores[posicao].nick_rede_jogador);
      file = fopen("jogadores.dat", "wb");
      fseek(file,
            (posicao * sizeof(JOGADOR)) + (2 * sizeof(nome[30])) +
                sizeof(DATANASCIMENTO) + sizeof(int) + sizeof(char[10]) +
                sizeof(char[15]) + sizeof(EQUIPE),
            SEEK_SET);
      printf("%s", jogadores[posicao].nick_rede_jogador);
      fclose(file);
      break;
    case 11:
      fflush(stdin);
      printf("Digite a nova quantidade de seguidores do jogador: ");
      scanf("%ld", &jogadores[posicao].seguidores_jogador);
      file = fopen("jogadores.dat", "wb");
      fseek(file,
            (posicao * sizeof(JOGADOR)) + (3 * sizeof(nome[30])) +
                sizeof(DATANASCIMENTO) + sizeof(int) + sizeof(char[10]) +
                sizeof(char[15]) + sizeof(EQUIPE),
            SEEK_SET);
      printf("%ld", jogadores[posicao].seguidores_jogador);
      fclose(file);
      break;
    case 12:
      fflush(stdin);
      printf("Digite o novo modelo do pc do jogador: ");
      gets(jogadores[posicao].hardware.modelo_do_pc);
      file = fopen("jogadores.dat", "wb");
      fseek(file,
            (posicao * sizeof(JOGADOR)) + (3 * sizeof(nome[30])) +
                sizeof(DATANASCIMENTO) + (2 * sizeof(int)) + sizeof(char[10]) +
                sizeof(char[15]) + sizeof(EQUIPE),
            SEEK_SET);
      printf("%s", jogadores[posicao].hardware.modelo_do_pc);
      fclose(file);
      break;
    case 13:
      fflush(stdin);
      printf("Digite o novo processador do jogador: ");
      gets(jogadores[posicao].hardware.processador);
      file = fopen("jogadores.dat", "wb");
      fseek(file,
            (posicao * sizeof(JOGADOR)) + (4 * sizeof(nome[30])) +
                sizeof(DATANASCIMENTO) + (2 * sizeof(int)) + sizeof(char[10]) +
                sizeof(char[15]) + sizeof(EQUIPE),
            SEEK_SET);
      printf("%s", jogadores[posicao].hardware.processador);
      fclose(file);
      break;
    case 14:
      fflush(stdin);
      printf("Digite a nova placa de video do jogador: ");
      gets(jogadores[posicao].hardware.placa_de_video);
      file = fopen("jogadores.dat", "wb");
      fseek(file,
            (posicao * sizeof(JOGADOR)) + (5 * sizeof(nome[30])) +
                sizeof(DATANASCIMENTO) + (2 * sizeof(int)) + sizeof(char[10]) +
                sizeof(char[15]) + sizeof(EQUIPE),
            SEEK_SET);
      printf("%s", jogadores[posicao].hardware.placa_de_video);
      fclose(file);
      break;
    case 15:
      fflush(stdin);
      printf("Digite a nova quantidade de memoria RAM do jogador: ");
      scanf("%d", &jogadores[posicao].hardware.qnt_ram);
      file = fopen("jogadores.dat", "wb");
      fseek(file,
            (posicao * sizeof(JOGADOR)) + (6 * sizeof(nome[30])) +
                sizeof(DATANASCIMENTO) + (2 * sizeof(int)) + sizeof(char[10]) +
                sizeof(char[15]) + sizeof(EQUIPE),
            SEEK_SET);
      printf("%d", jogadores[posicao].hardware.qnt_ram);
      fclose(file);
      break;
    case 16:
      fflush(stdin);
      printf("Digite a nova quantidade de titulos do jogador: ");
      scanf("%d", &jogadores[posicao].qnt_titulos);
      file = fopen("jogadores.dat", "wb");
      fseek(file,
            (posicao * sizeof(JOGADOR)) + (3 * sizeof(nome[30])) +
                sizeof(DATANASCIMENTO) + (2 * sizeof(int)) + sizeof(char[10]) +
                sizeof(char[15]) + sizeof(EQUIPE) + sizeof(HARDWARE) +
                sizeof(PONTUACAO),
            SEEK_SET);
      printf("%d", jogadores[posicao].qnt_titulos);
      fclose(file);
      break;
    case 17:
      fflush(stdin);
      printf("Digite a nova posicao do jogador no rank mundial: ");
      scanf("%d", &jogadores[posicao].posicao_rank_mundial);
      file = fopen("jogadores.dat", "wb");
      fseek(file,
            (posicao * sizeof(JOGADOR)) + (3 * sizeof(nome[30])) +
                sizeof(DATANASCIMENTO) + (3 * sizeof(int)) + sizeof(char[10]) +
                sizeof(char[15]) + sizeof(EQUIPE) + sizeof(HARDWARE),
            SEEK_SET);
      printf("%d", jogadores[posicao].posicao_rank_mundial);
      fclose(file);
      break;
    default:
      printf("Atualizacao Cancelada\n");
      return 0;
    }
  }
  // Busca exata no arquivo
}

/*4*/ int AtualizarPontuacao(JOGADOR jogadores[], int quant) {
  char nome[30];
  int dado, posicao;
  FILE *file;
  printf("\nDigite o nome do jogador: ");
  gets(nome);
  printf("\nPONTUACAO:\n1 - Vitorias\n2 - Derrotas\n3 - Empates\n");
  printf("Digite 0 caso tenha acabado a atualização\n");
  while (1) {
    printf(
        "\nDigite o numero correspondente ao dado que se deseja atualizar: ");
    scanf("%d", &dado);
    printf("Digite o nome atual do jogador cuja pontuacao deseja atualizar: ");
    gets(nome);
    buscaJogador(jogadores, quant, &posicao, nome);
    if (buscaJogador(jogadores, quant, &posicao, nome) == 0) {
      printf("Jogador nao encontrado\n");
      return 0;
    }
    switch (dado) {
    case 1:
      fflush(stdin);
      printf("Digite a quantidade de vitorias do jogador: ");
      scanf("%d", &jogadores[posicao].pontuacao.vitorias);
      file = fopen("jogadores.dat", "wb");
      fseek(file,
            (posicao * sizeof(JOGADOR)) + (3 * sizeof(nome[30])) +
                sizeof(DATANASCIMENTO) + (2 * sizeof(int)) + sizeof(char[10]) +
                sizeof(char[15]) + sizeof(EQUIPE) + sizeof(HARDWARE),
            SEEK_SET);
      printf("%d", jogadores[posicao].pontuacao.vitorias);
      fclose(file);
      break;
    case 2:
      fflush(stdin);
      printf("Digite a quantidade de derrotas do jogador: ");
      scanf("%d", &jogadores[posicao].pontuacao.derrotas);
      file = fopen("jogadores.dat", "wb");
      fseek(file,
            (posicao * sizeof(JOGADOR)) + (3 * sizeof(nome[30])) +
                sizeof(DATANASCIMENTO) + (3 * sizeof(int)) + sizeof(char[10]) +
                sizeof(char[15]) + sizeof(EQUIPE) + sizeof(HARDWARE),
            SEEK_SET);
      printf("%d", jogadores[posicao].pontuacao.derrotas);
      fclose(file);
      break;
    case 3:
      fflush(stdin);
      printf("Digite a quantidade de empates do jogador: ");
      scanf("%d", &jogadores[posicao].pontuacao.empates);
      file = fopen("jogadores.dat", "wb");
      fseek(file,
            (posicao * sizeof(JOGADOR)) + (3 * sizeof(nome[30])) +
                sizeof(DATANASCIMENTO) + (4 * sizeof(int)) + sizeof(char[10]) +
                sizeof(char[15]) + sizeof(EQUIPE) + sizeof(HARDWARE),
            SEEK_SET);
      printf("%d", jogadores[posicao].pontuacao.empates);
      fclose(file);
      break;
    default:
      printf("Atualizacao Cancelada\n");
      return 0;
    }
  }
}

/*5*/
void ListarJogadoresAlfabetico() {

  FILE *file;
  file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\TP3\\jogadores.dat", "rb");

  int tam = quantidade_de_jogadores();
  JOGADOR jogadores[tam];

  if (file != NULL) {
    int qtdRegLidos = fread(jogadores, sizeof(JOGADOR), tam, file);
    printf("\nForam lidos %d registro(s) de aluno(s)!\n", qtdRegLidos);
    int i, j;
    JOGADOR aux;

    for (i=1; i<tam; i++){
    for (j=0; j<tam-1; j++){
      int flag = strcasecmp(jogadores[j].nome_do_jogador,jogadores[j+1].nome_do_jogador);
      if(flag>0){
          aux = jogadores[j];
          jogadores[j] = jogadores[j+1];
          jogadores[j+1] = aux;
      }
    }
  }

  printf("\n\n===== JOGADORES ====\n\n");

  for (int i = 0; i < tam; i++) {

    printf("\n\n==============================================================================\n\n");
    printf("\nNome: %s\n", jogadores[i].nome_do_jogador);
    printf("\nData de nascimento: %d/%d/%d\n",
           jogadores[i].data_de_nascimento.dia,
           jogadores[i].data_de_nascimento.mes,
           jogadores[i].data_de_nascimento.ano);
    printf("\nCPF: %ld\n", jogadores[i].cpf);
    printf("\nGenero: %s\n", jogadores[i].genero);
    printf("\nEstado Civil: %s\n", jogadores[i].estadoCivil);
    printf("\nNome da equipe: %s\n", jogadores[i].equipe.nome_da_equipe);
    printf("\nNick da rede social da equipe: %s\n",
           jogadores[i].equipe.nick_rede_social_equipe);
    printf(
        "\nQuantidade de seguidores da rede social da equipe: %ld seguidores\n",
        jogadores[i].equipe.seguidores_equipe);
    printf("\nPatrocinadora principal: %s\n",
           jogadores[i].patrocinadora_principal);
    printf("\nNick da rede social do jogador: %s\n",
           jogadores[i].nick_rede_jogador);
    printf(
        "\nQuantidade de seguidores da rede social do jogador: %ld jogadores\n",
        jogadores[i].seguidores_jogador);
    printf("\nModelo do pc: %s\n", jogadores[i].hardware.modelo_do_pc);
    printf("\nModelo do procesador: %s\n", jogadores[i].hardware.processador);
    printf("\nModelo da placa de video: %s\n",
           jogadores[i].hardware.placa_de_video);
    printf("\nQuantidade de memoria RAM: %dGB\n",
           jogadores[i].hardware.qnt_ram);
    printf("\nQuantidade de vitorias: %d vitorias\n",
           jogadores[i].pontuacao.vitorias);
    printf("\nQuantidade de derrotas: %d derrotas\n",
           jogadores[i].pontuacao.derrotas);
    printf("\nQuantidade de empates: %d empates\n",
           jogadores[i].pontuacao.empates);
    int pontuacao_total = (3 * jogadores[i].pontuacao.vitorias) +
                          (jogadores[i].pontuacao.empates);
    printf("\nPontuacao total: %d\n", pontuacao_total);
    printf("\nQuantidade de titulos do jogador: %d titulos\n",
           jogadores[i].qnt_titulos);
    printf("Posicao no rank mundial: %d lugar\n",
           jogadores[i].posicao_rank_mundial);
  }

    fclose(file);
  } else {
    printf("O ARQUIVO NÃO FOI ABERTO!\n\n");
  }

  return;
}

/*6*/
void ListarJogadoresPosicaoRanking() {

  FILE *file;
  file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\TP3\\jogadores.dat", "rb");

  int tam = quantidade_de_jogadores();
  JOGADOR jogadores[tam];

  if (file != NULL) {
    fread(jogadores, sizeof(JOGADOR), tam, file);
    int i, j;
    JOGADOR aux;

    for (i=1; i<tam; i++){
    for (j=0; j<tam-1; j++){
      if(jogadores[j].posicao_rank_mundial>jogadores[j+1].posicao_rank_mundial){
          aux = jogadores[j];
          jogadores[j] = jogadores[j+1];
          jogadores[j+1] = aux;
      }
    }
  }

  printf("\n\n===== JOGADORES ====\n\n");

  for (int i = 0; i < tam; i++) {

    printf("\n\n==============================================================================\n\n");
    printf("\nNome: %s\n", jogadores[i].nome_do_jogador);
    printf("\nData de nascimento: %d/%d/%d\n",jogadores[i].data_de_nascimento.dia,jogadores[i].data_de_nascimento.mes,jogadores[i].data_de_nascimento.ano);
    printf("\nCPF: %ld\n", jogadores[i].cpf);
    printf("\nGenero: %s\n", jogadores[i].genero);
    printf("\nEstado Civil: %s\n", jogadores[i].estadoCivil);
    printf("\nNome da equipe: %s\n", jogadores[i].equipe.nome_da_equipe);
    printf("\nNick da rede social da equipe: %s\n",jogadores[i].equipe.nick_rede_social_equipe);
    printf("\nQuantidade de seguidores da rede social da equipe: %ld seguidores\n",jogadores[i].equipe.seguidores_equipe);
    printf("\nPatrocinadora principal: %s\n",jogadores[i].patrocinadora_principal);
    printf("\nNick da rede social do jogador: %s\n",jogadores[i].nick_rede_jogador);
    printf("\nQuantidade de seguidores da rede social do jogador: %ld jogadores\n",jogadores[i].seguidores_jogador);
    printf("\nModelo do pc: %s\n", jogadores[i].hardware.modelo_do_pc);
    printf("\nModelo do procesador: %s\n", jogadores[i].hardware.processador);
    printf("\nModelo da placa de video: %s\n",jogadores[i].hardware.placa_de_video);
    printf("\nQuantidade de memoria RAM: %dGB\n",jogadores[i].hardware.qnt_ram);
    printf("\nQuantidade de vitorias: %d vitorias\n",jogadores[i].pontuacao.vitorias);
    printf("\nQuantidade de derrotas: %d derrotas\n",jogadores[i].pontuacao.derrotas);
    printf("\nQuantidade de empates: %d empates\n",jogadores[i].pontuacao.empates);int pontuacao_total = (3 * jogadores[i].pontuacao.vitorias) +(jogadores[i].pontuacao.empates);
    printf("\nPontuacao total: %d\n", pontuacao_total);
    printf("\nQuantidade de titulos do jogador: %d titulos\n",jogadores[i].qnt_titulos);
    printf("Posicao no rank mundial: %d lugar\n",jogadores[i].posicao_rank_mundial);
    }

    fclose(file);
  } else {
    printf("O ARQUIVO NÃO FOI ABERTO!\n\n");
  }

  return;
}


/*7*/
void ListarJogadoresPorVitorias() {

  FILE *file;
  file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\TP3\\jogadores.dat", "rb");

  int tam = quantidade_de_jogadores();
  JOGADOR jogadores[tam];

  if (file != NULL) {
    fread(jogadores, sizeof(JOGADOR), tam, file);
    int i, j;
    JOGADOR aux;

    for (i=1; i<tam; i++){
    for (j=0; j<tam-1; j++){
      if(jogadores[j].pontuacao.vitorias<jogadores[j+1].pontuacao.vitorias){
          aux = jogadores[j];
          jogadores[j] = jogadores[j+1];
          jogadores[j+1] = aux;
      }
    }
  }

  printf("\n\n===== JOGADORES ====\n\n");

  for (int i = 0; i < tam; i++) {

    printf("\n\n==============================================================================\n\n");
    printf("\nNome: %s\n", jogadores[i].nome_do_jogador);
    printf("\nData de nascimento: %d/%d/%d\n",jogadores[i].data_de_nascimento.dia,jogadores[i].data_de_nascimento.mes,jogadores[i].data_de_nascimento.ano);
    printf("\nCPF: %ld\n", jogadores[i].cpf);
    printf("\nGenero: %s\n", jogadores[i].genero);
    printf("\nEstado Civil: %s\n", jogadores[i].estadoCivil);
    printf("\nNome da equipe: %s\n", jogadores[i].equipe.nome_da_equipe);
    printf("\nNick da rede social da equipe: %s\n",jogadores[i].equipe.nick_rede_social_equipe);
    printf("\nQuantidade de seguidores da rede social da equipe: %ld seguidores\n",jogadores[i].equipe.seguidores_equipe);
    printf("\nPatrocinadora principal: %s\n",jogadores[i].patrocinadora_principal);
    printf("\nNick da rede social do jogador: %s\n",jogadores[i].nick_rede_jogador);
    printf("\nQuantidade de seguidores da rede social do jogador: %ld jogadores\n",jogadores[i].seguidores_jogador);
    printf("\nModelo do pc: %s\n", jogadores[i].hardware.modelo_do_pc);
    printf("\nModelo do procesador: %s\n", jogadores[i].hardware.processador);
    printf("\nModelo da placa de video: %s\n",jogadores[i].hardware.placa_de_video);
    printf("\nQuantidade de memoria RAM: %dGB\n",jogadores[i].hardware.qnt_ram);
    printf("\nQuantidade de vitorias: %d vitorias\n",jogadores[i].pontuacao.vitorias);
    printf("\nQuantidade de derrotas: %d derrotas\n",jogadores[i].pontuacao.derrotas);
    printf("\nQuantidade de empates: %d empates\n",jogadores[i].pontuacao.empates);int pontuacao_total = (3 * jogadores[i].pontuacao.vitorias) +(jogadores[i].pontuacao.empates);
    printf("\nPontuacao total: %d\n", pontuacao_total);
    printf("\nQuantidade de titulos do jogador: %d titulos\n",jogadores[i].qnt_titulos);
    printf("Posicao no rank mundial: %d lugar\n",jogadores[i].posicao_rank_mundial);
  }

    fclose(file);
  } else {
    printf("O ARQUIVO NÃO FOI ABERTO!\n\n");
  }

  return;
}

/*8*/
/*9*/
/*10*/

/*11*/
void buscaJogadorNome (){

       FILE *file;
       file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\TP3\\jogadores.dat", "rb");

       int tam = quantidade_de_jogadores();
       JOGADOR jogadores[tam];

       char chave[30];
       printf ("\nDigite o nome do jogador que deseja buscar: ");
       fflush(stdin);
       gets(chave);
       fflush(stdin);

       if (file != NULL) {
       fread(jogadores, sizeof(JOGADOR), tam, file);

       int i;

       for (i=0; i<tam; i++){
              int flag = strcasecmp(jogadores[i].nome_do_jogador, chave);
              if(flag == 0){
              printf("\nNome: %s\n", jogadores[i].nome_do_jogador);
              printf("\nData de nascimento: %d/%d/%d\n",jogadores[i].data_de_nascimento.dia,jogadores[i].data_de_nascimento.mes,jogadores[i].data_de_nascimento.ano);
              printf("\nCPF: %ld\n", jogadores[i].cpf);
              printf("\nGenero: %s\n", jogadores[i].genero);
              printf("\nEstado Civil: %s\n", jogadores[i].estadoCivil);
              printf("\nNome da equipe: %s\n", jogadores[i].equipe.nome_da_equipe);
              printf("\nNick da rede social da equipe: %s\n",jogadores[i].equipe.nick_rede_social_equipe);
              printf("\nQuantidade de seguidores da rede social da equipe: %ld seguidores\n",jogadores[i].equipe.seguidores_equipe);
              printf("\nPatrocinadora principal: %s\n",jogadores[i].patrocinadora_principal);
              printf("\nNick da rede social do jogador: %s\n",jogadores[i].nick_rede_jogador);
              printf("\nQuantidade de seguidores da rede social do jogador: %ld jogadores\n",jogadores[i].seguidores_jogador);
              printf("\nModelo do pc: %s\n", jogadores[i].hardware.modelo_do_pc);
              printf("\nModelo do procesador: %s\n", jogadores[i].hardware.processador);
              printf("\nModelo da placa de video: %s\n",jogadores[i].hardware.placa_de_video);
              printf("\nQuantidade de memoria RAM: %dGB\n",jogadores[i].hardware.qnt_ram);
              printf("\nQuantidade de vitorias: %d vitorias\n",jogadores[i].pontuacao.vitorias);
              printf("\nQuantidade de derrotas: %d derrotas\n",jogadores[i].pontuacao.derrotas);printf("\nQuantidade de empates: %d empates\n",jogadores[i].pontuacao.empates);int pontuacao_total = (3 * jogadores[i].pontuacao.vitorias) +(jogadores[i].pontuacao.empates);
              printf("\nPontuacao total: %d\n", pontuacao_total);
              printf("\nQuantidade de titulos do jogador: %d titulos\n",jogadores[i].qnt_titulos);printf("Posicao no rank mundial: %d lugar\n",jogadores[i].posicao_rank_mundial);
              } 
       }

       fclose(file);
       } else {
       printf("O ARQUIVO NÃO FOI ABERTO!\n\n");
       }
}

/*11*/
/*12*/
void buscaPosicaoRankMundial(){

       FILE *file;
       file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\TP3\\jogadores.dat", "rb");

       int tam = quantidade_de_jogadores();
       JOGADOR jogadores[tam];

       int chave;
       printf ("\nDigite a posicao do ranking mundial que deseja buscar: ");
       scanf("%d", &chave);

       if (file != NULL) {
       fread(jogadores, sizeof(JOGADOR), tam, file);

       int i;

       for (i=0; i<tam; i++){

              if(jogadores[i].posicao_rank_mundial == chave){
              printf("\nNome: %s\n", jogadores[i].nome_do_jogador);
              printf("\nData de nascimento: %d/%d/%d\n",jogadores[i].data_de_nascimento.dia,jogadores[i].data_de_nascimento.mes,jogadores[i].data_de_nascimento.ano);
              printf("\nCPF: %ld\n", jogadores[i].cpf);
              printf("\nGenero: %s\n", jogadores[i].genero);
              printf("\nEstado Civil: %s\n", jogadores[i].estadoCivil);
              printf("\nNome da equipe: %s\n", jogadores[i].equipe.nome_da_equipe);
              printf("\nNick da rede social da equipe: %s\n",jogadores[i].equipe.nick_rede_social_equipe);
              printf("\nQuantidade de seguidores da rede social da equipe: %ld seguidores\n",jogadores[i].equipe.seguidores_equipe);
              printf("\nPatrocinadora principal: %s\n",jogadores[i].patrocinadora_principal);
              printf("\nNick da rede social do jogador: %s\n",jogadores[i].nick_rede_jogador);
              printf("\nQuantidade de seguidores da rede social do jogador: %ld jogadores\n",jogadores[i].seguidores_jogador);
              printf("\nModelo do pc: %s\n", jogadores[i].hardware.modelo_do_pc);
              printf("\nModelo do procesador: %s\n", jogadores[i].hardware.processador);
              printf("\nModelo da placa de video: %s\n",jogadores[i].hardware.placa_de_video);
              printf("\nQuantidade de memoria RAM: %dGB\n",jogadores[i].hardware.qnt_ram);
              printf("\nQuantidade de vitorias: %d vitorias\n",jogadores[i].pontuacao.vitorias);
              printf("\nQuantidade de derrotas: %d derrotas\n",jogadores[i].pontuacao.derrotas);printf("\nQuantidade de empates: %d empates\n",jogadores[i].pontuacao.empates);int pontuacao_total = (3 * jogadores[i].pontuacao.vitorias) +(jogadores[i].pontuacao.empates);
              printf("\nPontuacao total: %d\n", pontuacao_total);
              printf("\nQuantidade de titulos do jogador: %d titulos\n",jogadores[i].qnt_titulos);printf("Posicao no rank mundial: %d lugar\n",jogadores[i].posicao_rank_mundial);
              } 
       }

       fclose(file);
       } else {
       printf("O ARQUIVO NÃO FOI ABERTO!\n\n");
       }
}

/*13*/
void MediaSeguidores() {

  FILE *file;
  file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\TP3\\jogadores.dat", "rb");

  int tam = quantidade_de_jogadores();
  JOGADOR jogadores[tam];
  double soma = 0;
  double media = 0;

  if (file != NULL) {
    fseek(file, 0*sizeof(JOGADOR), SEEK_SET);
    fread(jogadores, sizeof(JOGADOR), tam, file);
    for(int i=0; i < tam; i++){
        soma = soma + jogadores[i].seguidores_jogador;

    }
    media = (soma/tam);

    printf("\n\nA media de seguidores de um jogador do campeonato e de: %.0lf seguidores\n\n", media);
    fclose(file);
  } else {
    printf("O ARQUIVO NÃO FOI ABERTO!\n\n");
  }

  return;
}
  