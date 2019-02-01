	
	/*
 print-prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/
#include <stdio.h>

#include <stdlib.h>

#define COLUMNS 6
int is_prime(int n){
	if ( n < 2){
			return 0;
	}
	for ( int i = 2; i <= n /2; ++i){
		if (n%i == 0){
			return 0;
		}
	}
  return 1;
}

void print_number (int n ){
	if (n == 0){
		printf("\n");
	}
	else
	printf ("%10d", n);
}

void print_primes(int n){
	int j = 0;
	for (int i = 1; i <= n; i++){
		if (is_prime (i)== 1){
			print_number(i);
			j++;
			if (j %COLUMNS == 0){
			print_number(0);
			}
		}
	}
}

// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
  if(argc == 2)
    print_primes(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
}

/* printf("%10d ", 2);
  printf("%10d ", 3);
  printf("%10d ", 5);
  printf("%10d ", 7);
  printf("%10d ", 11);
  printf("%10d ", 13);
  printf("\n");
  printf("%10d ", 17);
  printf("%10d ", 19);*/