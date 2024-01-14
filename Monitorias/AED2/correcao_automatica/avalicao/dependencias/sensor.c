
//----------
#include "listase.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// Contexto especialista

typedef struct info_temperatura {
  int seq;
  int dia;
  int mes;
  int ano;
  int hora;
  int minuto;
  int radiacao_solar;
  double temperatura;
  double umidade_relativa;
} sensor1;

typedef struct info_massa {
  int seq;
  int dia;
  int mes;
  int ano;
  int hora;
  int minuto;
  double velocidade_media;
  double velocidade_instantanea;
  int direcao;
} sensor2;

sensor1 *criar_info1(int seq, int dia, int mes, int ano, int hora, int minuto,
                     int radiacao_solar, double temperatura,
                     double umidade_relativa) {
  sensor1 *info_new = malloc(sizeof(sensor1));

  info_new->seq = seq;
  info_new->dia = dia;
  info_new->mes = mes;
  info_new->ano = ano;
  info_new->hora = hora;
  info_new->minuto = minuto;
  info_new->radiacao_solar = radiacao_solar;
  info_new->temperatura = temperatura;
  info_new->umidade_relativa = umidade_relativa;

  return info_new;
}

sensor2 *criar_info2(int seq, int dia, int mes, int ano, int hora, int minuto,
                     double velocidadeM, double velocidade, int direcao) {
  sensor2 *info_new = malloc(sizeof(sensor1));

  info_new->seq = seq;
  info_new->dia = dia;
  info_new->mes = mes;
  info_new->ano = ano;
  info_new->hora = hora;
  info_new->minuto = minuto;
  info_new->velocidade_media = velocidadeM;
  info_new->velocidade_instantanea = velocidade;
  info_new->direcao = direcao;
  return info_new;
}

void imprimir_info1(void *m) {
  sensor1 *mm = m;
  printf("%d ", mm->seq);
  printf("%d/%d/%d ", mm->dia, mm->mes, mm->ano);
  printf("%d:%d ", mm->hora, mm->minuto);
  printf("%d ", mm->radiacao_solar);
  printf("%0.2lf ", mm->temperatura);
  printf("%0.2lf\n", mm->umidade_relativa);
} // pensar como fazer

void imprimir_info2(void *m) {
  sensor2 *mm = m;
  printf("%d ", mm->seq);
  printf("%d/%d/%d ", mm->dia, mm->mes, mm->ano);
  printf("%d:%d ", mm->hora, mm->minuto);
  printf("%0.2lf ", mm->velocidade_media);
  printf("%0.2lf ", mm->velocidade_instantanea);
  printf("%d\n", mm->direcao);
}

int comparar_info1(void *m1, void *m2) {
  sensor1 *mm1 = m1;
  sensor1 *mm2 = m2;

  if (mm1->ano < mm2->ano) {
    return -1;
  } else if (mm1->ano > mm2->ano) {
    return 1;
  } else {
    if (mm1->mes < mm2->mes) {
      return -1;
    } else if (mm1->mes > mm2->mes) {
      return 1;
    } else {
      if (mm1->dia < mm2->dia) {
        return -1;
      } else if (mm1->dia > mm2->dia) {
        return 1;
      } else {
        if (mm1->hora < mm2->hora) {
          return -1;
        } else if (mm1->hora > mm2->hora) {
          return 1;
        } else {
          if (mm1->minuto < mm2->minuto) {
            return -1;
          } else if (mm1->minuto > mm2->minuto) {
            return 1;
          } else {
            return 0;
          }
        }
      }
    }
  }
}

int main(int argc, char const *argv[]) {

  const int tipo = (int)argv[1][0] - 48;

  const char *nome_arquivo = argv[2];

  FILE *arq = fopen(nome_arquivo, "r");

  t_lse *sensores = NULL;
  sensor1 *m = NULL;
  sensor2 *n = NULL;
  char comando;
  int seq;
  int dia;
  int mes;
  int ano;
  int hora;
  int minuto;
  int radiacao_solar;
  double temperatura, velocidade_media, velocidade_instantanea;
  double umidade_relativa;
  int direcao;

  if (tipo == 1) {
    sensores = criar_lse(imprimir_info1, comparar_info1);
    while (fscanf(arq, "%d %d/%d/%d %d:%d %d %lf %lf", &seq, &dia, &mes, &ano,
                  &hora, &minuto, &radiacao_solar, &temperatura,
                  &umidade_relativa) != EOF) {
      m = criar_info1(seq, dia, mes, ano, hora, minuto, radiacao_solar,
                      temperatura, umidade_relativa);
      inserir_lse(sensores, m);
    }
  } else if (tipo == 2) {
    sensores = criar_lse(imprimir_info2, comparar_info1);
    while (fscanf(arq, "%d %d/%d/%d %d:%d %lf %lf %d", &seq, &dia, &mes, &ano,
                  &hora, &minuto, &velocidade_media, &velocidade_instantanea,
                  &direcao) != EOF) {
      n = criar_info2(seq, dia, mes, ano, hora, minuto, velocidade_media,
                      velocidade_instantanea, direcao);
      inserir_lse(sensores, n);
    }
  }
  fclose(arq);

  scanf("%c", &comando);
  while (comando != 'F') {
    if (comando == 'R') {
      scanf("%d/%d/%d %d:%d", &dia, &mes, &ano, &hora, &minuto);
      sensor1 *remov = criar_info1(0, dia, mes, ano, hora, minuto, 0, 0, 0);
      remover_lse(sensores, remov);
    }

    else if (comando == 'I') {
      int inicio, fim;
      scanf("%d %d", &inicio, &fim);
      while (inicio <= fim) {
        sensor1 *imprimir = acessar_lse(sensores, inicio);
        if (tipo == 1) {
          if (imprimir != NULL) {
            imprimir_info1(imprimir);
          }
        } else if (tipo == 2) {
          imprimir_info2(imprimir);
        }
        inicio++;
      }
    } else if (comando == 'A') {
      int elemento;
      scanf("%d", &elemento);
      sensor1 *acess = acessar_lse(sensores, elemento);
      if (tipo == 1) {
        imprimir_info1(acess);
      } else if (tipo == 2) {
        imprimir_info2(acess);
      }
    } else if (comando == 'B') {
      scanf("%d/%d/%d %d:%d", &dia, &mes, &ano, &hora, &minuto);
      sensor1 *proc = criar_info1(0, dia, mes, ano, hora, minuto, 0, 0, 0);
      sensor1 *busca = buscar_lse(sensores, proc);
      if (tipo == 1) {
        imprimir_info1(busca);
      } else if (tipo == 2) {
        imprimir_info2(busca);
      }
    } else if (comando == 'P') {
      int inicio, fim;
      scanf("%d %d", &inicio, &fim);
      if (tipo == 1) {
        while (fim >= inicio) {
          sensor1 *deletar = acessar_lse(sensores, fim);
          if (deletar != NULL) {
            deletar = remover_lse(sensores, deletar);
            free(deletar);
          }
          fim--;
        }
      }
      if (tipo == 2) {
        while (fim >= inicio) {
          sensor2 *deletar2 = acessar_lse(sensores, fim);
          if (deletar2 != NULL) {
            deletar2 = remover_lse(sensores, deletar2);
            free(deletar2);
          }
          fim--;
        }
      }
    }
    scanf("%c", &comando);
  }
  return 0;
}