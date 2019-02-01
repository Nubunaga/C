#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLUMNS 6
int counterclock = 0;
void print_number (int n){
	printf("%10d", n);
	counterclock++;
	
	if ( counterclock == COLUMNS){
		printf("\n");
		counterclock = 0;
	}
}
void print_sieves(int n){
	char *prime =(char *) malloc(n);
	int i;
	for (i = 0; i <= n ; i++){
		prime [i] = 1;
	}
	for (int k = 2; k*k <= n; k++){
		if (prime[k] == 1){
			for (int j = k*k; j<=n; j+=k){
				prime[j] = 0;
			}			
		}
	}
	for (i = 2; i <= n ; ++i){
		if (prime[i]==1){
			print_number(i);
		}
	}
	free(prime);
}
int main(int argc, char *argv[]){
		clock_t begin = clock();
  if(argc == 2)
    print_sieves(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");

clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("\n");
printf("%2.1f",time_spent);
  return 0;
}
