#include <stdio.h>
#include <stdlib.h>
#include "GF.h"
#include "entrophy.h"
#include "sss.h"

void checkCLI(int argc)
{
  if( argc < 4)
  {
    printf("\n\n\t.:CLI ARGUMENT ERROR:.\n");
    exit(1);
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
  construir_polinomio(&P, s);
  imprimir_polinomio(&P);
  inicializar_shares(&Ss, n);
  generar_shares(&Ss, &P);
  imprimir_shares(&Ss);
  destruir_shares(&Ss);
  destruir_polinomio(&P);

  return 0;
}
