/*Abstracción de Campo Finito de Galois
 * GF(P) = {x; x ~ a(modP); a,x números enteros}
 * */

#define PRIME_NUMBER 100003


//INVERSO MULTIPLICATIVO
int multiplicative_inv_modulo(int, int);

//INVERSO ADITIVO
int additive_inv_modulo(int, int);

//OPERACIONES
int add_modulo(int, int, int);   //SUMA EN UN CAMPO FINITO
int sub_modulo(int, int, int);   //RESTA EN UN CAMPO FINITO
int mul_modulo(int, int, int);   //PRODUCTO EN UN CAMPO FINITO
int div_modulo(int, int, int);   //DIVICIÓN EN UN CAMPO FINITO






#include "GF.c"
