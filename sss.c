/*Primera versión del esquema de shamir*/


//BIBLIOTECAS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GF.h"
#include "entrophy.h"

//ESTRUCTURAS
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

//FUNCIONES

unsigned int generar_numero_aleatorio()
{
  return high_entrophy_number_getrandom() % PRIME_NUMBER;
}

void inicializar_polinomio(polinomio *P, unsigned int k)
{
  P->coeficientes = (unsigned int*)malloc(k*sizeof(unsigned int));
  P->k = k;
}

void destruir_polinomio(polinomio *P)
{
  free(P->coeficientes);
  P->k = 0;
}

void construir_polinomio(polinomio *P, unsigned int s)
{
  *(((*P).coeficientes)+0) = s;
  for(int i=1; i<P->k; i++)
    *(((*P).coeficientes)+i) = generar_numero_aleatorio();
}

void inicializar_shares(shares *Ss, unsigned int x)
{
  Ss->S = (share*)malloc(x*sizeof(share));
  Ss->n = x;
}

void destruir_shares(shares *Ss)
{
  free(Ss->S);
  Ss->n = 0;
}

int evaluar_polinomio(polinomio *P, unsigned int x)
{
  unsigned int r = 0;
  unsigned int x_i_power = 1;

  r = *(((*P).coeficientes)+0);
  x_i_power = (x) % PRIME_NUMBER;

  for(int i=1; i<P->k; i++)
  {
    unsigned int ai = *(((*P).coeficientes)+i);
    unsigned int term = mul_modulo(ai, x_i_power, PRIME_NUMBER);
    r = add_modulo(r, term, PRIME_NUMBER);
    x_i_power = mul_modulo(x_i_power, x, PRIME_NUMBER);
  }
  return r;
}

void generar_shares(shares *Ss, polinomio *P)
{
  for(int i=0; i<Ss->n; i++)
  {
    (*(((*Ss).S)+i)).x = i+1;
    (*(((*Ss).S)+i)).y = evaluar_polinomio(P,i+1);
  }
}
void imprimir_polinomio(polinomio *P)
{
  for(int i=0;i<P->k;i++)
    printf("[%u]", *(((*P).coeficientes)+i));
  printf("\n");
}
void imprimir_shares(shares *Ss)
{
  for(int i=0;i<Ss->n;i++)
    printf("(%d,%d)\n", (*(((*Ss).S)+i)).x , (*(((*Ss).S)+i)).y);
  printf("\n");
}

void checkCLI(int argc)
{
  if(argc < 4)
  {
    printf("\n\n\t.:ERROR CLI ARGUMENTS:.\n\n");
    exit(EXIT_FAILURE);
  }
}

int main(int argc, char **argv)
{
  checkCLI(argc);
  unsigned int s = atoi(*(argv+1));
  unsigned int n = atoi(*(argv+2));
  unsigned int k = atoi(*(argv+3));
  polinomio P;
  shares Ss;
  inicializar_polinomio(&P, k);
  construir_polinomio(&P,s);
  imprimir_polinomio(&P);
  inicializar_shares(&Ss, n);
  generar_shares(&Ss, &P);
  imprimir_shares(&Ss);
  destruir_shares(&Ss);
  destruir_polinomio(&P);
  

  //printf("%d\n", eea(3,PRIME_NUMBER));
  //printf("%d", div_modulo(7, 3, PRIME_NUMBER));

  return 0;
}
