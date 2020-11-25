#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int muitoMal;
    int mal;
    int neutro;
    int bem;
    int muitoBem;
}ESTADO_PSICOLOGICO;
typedef struct {
    int muitoMal;
    int mal;
    int neutro;
    int bem;
    int muitoBem;
}QUALIDADE_DA_ALIMENTACAO;
typedef struct {
    int muitoMal;
    int mal;
    int bem;
    int muitoBem;
}QUALIDADE_DO_SONO;
typedef struct {
    int muitoMal;
    int mal;
    int bem;
    int muitoBem;
}NIVEL_DE_SEDENTARISMO;

typedef struct {
    char estado[30];
    int numeroDeCasos;
    int estadoPsicologicoMaisEscolhido;
    int alimentacaoMaisEscolhido;
    int sonoMaisEscolhido;
    int sedentarismoMaisEscolhido;
    ESTADO_PSICOLOGICO psicologico;
    QUALIDADE_DA_ALIMENTACAO alimentacao;
    QUALIDADE_DO_SONO sono;
    NIVEL_DE_SEDENTARISMO sedentarismo;
}NODE1;

typedef struct {
    char estado[30];
    int numeroDeCasos;
    int estadoPsicologicoMaisEscolhido;
    ESTADO_PSICOLOGICO psicologico;
}NODE2;