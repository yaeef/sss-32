/*
 * Prototipos de funciones y estructuras usadas para el esquema de shamir
 */

typedef struct
{
  unsigned int *coeficientes;
  unsigned int k;
}polinomio;

typedef struct
{
  unsigned int x;
  unsigned int y;
}share;

typedef struct
{
  share *S;
  unsigned int n;
}shares;

unsigned int generar_numero_aleatorio();

void inicializar_polinomio(polinomio* , unsigned int);

void destruir_polinomio(polinomio* );

void construir_polinomio(polinomio *P, unsigned int s);

void inicializar_shares(shares* , unsigned int );

void destruir_shares(shares* );

int evaluar_polinomio(polinomio*, unsigned int );

void generar_shares(shares* , polinomio * );

void imprimir_polinomio(polinomio * );

void imprimir_shares(shares* );


#include "sss.c"
