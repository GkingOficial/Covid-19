#include<stdio.h>
#include<stdlib.h>

typedef struct {
    // cada inteiro representando uma porcentagem
    int muitoMal;
    int mal;
    int neutro;
    int bem;
    int muitoBem;
}ESTADO_PSICOLOGICO;
typedef struct {
    // cada inteiro representando uma porcentagem
    int muitoMal;
    int mal;
    int neutro;
    int bem;
    int muitoBem;
}QUALIDADE_DA_ALIMENTACAO;
typedef struct {
    // cada inteiro representando uma porcentagem
    int muitoMal;
    int mal;
    int neutro;
    int bem;
    int muitoBem;
}QUALIDADE_DO_SONO;
typedef struct {
    // cada inteiro representando uma porcentagem
    int muitoMal;
    int mal;
    int neutro;
    int bem;
    int muitoBem;
}NIVEL_DE_SEDENTARISMO;

typedef struct {
    char Estado[30];
    int casos;
    ESTADO_PSICOLOGICO psicologico;
    QUALIDADE_DA_ALIMENTACAO alimentacao;
    QUALIDADE_DO_SONO sono;
    NIVEL_DE_SEDENTARISMO sedentarismo;
}NODE;