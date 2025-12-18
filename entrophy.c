/*
 * USO DE FUENTE DE ENTROPIA PARA GENERACIÓN DE NÚMEROS 
 * ALEATORIOS
 */

#include <sys/random.h>

unsigned int high_entrophy_number_getrandom(void)
{
  unsigned int n;
  ssize_t m = getrandom(&n, sizeof(n),GRND_NONBLOCK);
  if(m == -1) return -1;
  return n;
}

