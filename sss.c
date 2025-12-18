/*Primera versión del esquema de shamir*/

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

