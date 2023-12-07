
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

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

int quantidade_de_jogadores(){

  FILE *file;
  file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\copia\\jogadores.dat", "rb");
  fseek(file, 0*sizeof(JOGADOR),SEEK_END);
  int tam = (ftell(file)/sizeof(JOGADOR));

  fclose(file);
  return(tam); 
}

void AtualizarCadastro() {
  FILE *file;
  file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\copia\\jogadores.dat", "rb");

  int tam = quantidade_de_jogadores();
  JOGADOR jogadores[tam];
  int i, dado, posicao=0;

  char chave[30];
  printf ("\nDigite o nome do jogador que deseja editar o cadastro: ");
  fflush(stdin);
  gets(chave);
  fflush(stdin);
  fread(jogadores, sizeof(JOGADOR), tam, file);
  for (i=0; i<tam; i++){
    int flag = strcasecmp(jogadores[i].nome_do_jogador, chave);
    if (flag==0){
      posicao = i;
    }
  }
  
  printf("\nDADOS:\n1 - Nome\n2 - Data de nascimento\n3 - CPF\n4 - Genero\n5 - "
         "Estado civil\n6 - Nome da equipe\n7 - Nick da equipe\n8 - Quantidade "
         "de seguidores da equipe\n9 - Patrocinadora principal\n10 - Nickname "
         "na rede social\n11 - Quantidade de seguidores\n12 - Modelo do pc\n13 "
         "- Processador\n14 - Placa de video\n15 - Quantidade de memoria "
         "RAM\n16 - Quantidade de titulos\n17 - Posicao "
         "no rank mundial\n ");
  printf("Digite 0 caso tenha acabado a atualização\n");
  while (1) {
    printf("\nDigite o numero correspondente ao dado que se deseja atualizar: ");
    scanf("%d", &dado);
    
    switch (dado) {
    case 1:
      fflush(stdin);
      printf("Digite o novo nome do jogador: ");
      gets(jogadores[posicao].nome_do_jogador);
      fflush(stdin);
      file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\copia\\jogadores.dat", "wb");
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
      file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\copia\\jogadores.dat", "wb");
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
      file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\copia\\jogadores.dat", "wb");
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
      file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\copia\\jogadores.dat", "wb");
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
      file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\copia\\jogadores.dat", "wb");
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
      file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\copia\\jogadores.dat", "wb");
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
      file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\copia\\jogadores.dat", "wb");
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
      file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\copia\\jogadores.dat", "wb");
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
      file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\copia\\jogadores.dat", "wb");
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
      file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\copia\\jogadores.dat", "wb");
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
      file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\copia\\jogadores.dat", "wb");
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
      file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\copia\\jogadores.dat", "wb");
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
      file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\copia\\jogadores.dat", "wb");
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
      file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\copia\\jogadores.dat", "wb");
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
      file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\copia\\jogadores.dat", "wb");
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
      file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\copia\\jogadores.dat", "wb");
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
      file = fopen("C:\\Users\\kelly\\OneDrive\\Documentos\\ATP2\\copia\\jogadores.dat", "wb");
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


int main() {

  AtualizarCadastro();

  return (0);
}