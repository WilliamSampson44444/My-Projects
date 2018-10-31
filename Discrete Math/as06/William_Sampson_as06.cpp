/*
  William Sampson
  williamsampson44444@gmail.com
  wfsampson
  Assignment 6: Pretty-much real-deal decryption!
  Main file for Assignment 6.
  Status: COMPLETE
  The GMP library is a pain in the ass to learn, but the functionality is CRAZY
  Function: Given p, q, e, and c, decrypts a message
 */

#include <iostream>
#include <iomanip>
#include <gmp.h>

using namespace std;

int main(int argc, char* argv[]){
  mpz_t p, q, e, c, hl, z, d, n;
  mpz_inits(p, q, e, c, hl, z, d, n, NULL);
  mpz_set_str(p, argv[1], 16);
  mpz_set_str(q, argv[2], 16);
  mpz_set_str(e, argv[3], 16);
  mpz_set_str(c, argv[4], 16);
  //BEGIN ARITHMETIC
  mpz_mul(n, p, q);//n = p * q
  mpz_sub_ui(p, p, 1);//p -= 1
  mpz_sub_ui(q, q, 1);//q -= 1
  mpz_lcm(hl, p, q);//hl = lcm(p-1, q-1)
  mpz_gcdext(z, p, q, e, hl);//Given e & hl, solves gcd eqn: (e)p + (hl)q = z
  mpz_mod(d, p, hl);//d = x % hl
  mpz_powm(hl, c, d, n);//hl = c^d % n
  cout << hex << hl << endl;
}
