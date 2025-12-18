
/*Definición de operaciones dentro de un Campo finito de Galois*/


int eea(int a, int P)
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

int add_modulo(int a, int b, int P)
{
  return (int)(((long long)a+b)%P);
}

int sub_modulo(int a, int b, int P)
{
  int sub = (a-b)%P;
  return (sub<0) ? sub+P : sub;
}

int mul_modulo(int a, int b, int P)
{
  return (int)(((long long)a*b)%P);
}

int div_modulo(int a, int b, int P)
{
  int b_i = eea(b, P);
  if(b_i != -1)
  {
    return mul_modulo(a, b_i, P);
  }
  else
    return -1;
}
