
/*Definición de operaciones dentro de un Campo finito de Galois*/


int multiplicative_inv_modulo(int a, int P)
{
  if(!a) //EN UN CAMPO FINITO DE GALOIS TODO ELEMENTO DEL CAMPO TIENE INVERSO, EXCEPTO EL CERO.
  {
    return -1;
  }
  long long t = 0, newt = 1;
  long long r = P, newr = a;

  while(newr != 0)
  {
    long long q = r/newr;
    long long temp = newt;
    newt = t-q*newt;
    t = temp;
    temp = newr;
    newr = r-q*newr;
    r = temp;
  }

  if(r != 1)  //GCD(a,P) != 1 -> NO EXISTE INVERSO
    return -1;
  if(t < 0)
    t += P;
  return (int)t;
}

int additive_inv_modulo(int a, int P)
{
  return (int)(((long long)P-(((long long)a%P+P)%P))%P); 
}

int add_modulo(int a, int b, int P)
{
  return (int)(((long long)a+b)%P);
}

int sub_modulo(int a, int b, int P)
{
  return add_modulo(a, additive_inv_modulo(b,P), P);
}

int mul_modulo(int a, int b, int P)
{
  return (int)(((long long)a*b)%P);
}

int div_modulo(int a, int b, int P)
{
  int b_i = multiplicative_inv_modulo(b, P);
  if(b_i != -1)
  {
    return mul_modulo(a, b_i, P);
  }
  else
    return -1;
}
