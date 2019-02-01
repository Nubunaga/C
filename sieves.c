#include <stdio.h>
#include <stdlib.h>
void print_number (int n){
	if (n == 0){
		printf("\n");
	}
	else{
	printf ("%10d", n);
	}
}
void print_sieves(int n){
	char prime[n+1];
	int i;
	int k;
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
			k++;
			if( k == 6){
				print_number(0);
				k = 0;
			}
		}
	}
}
int main(int argc, char *argv[]){
  if(argc == 2)
    print_sieves(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");

  return 0;
}