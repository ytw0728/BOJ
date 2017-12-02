#include <stdio.h>
#include <math.h>

int main() {
	for (int i = 2; i <= 100; i++) {
		for (int j = 2; j < i; j++) {
			for (int k = j + 1; k < i; k++){
				for(int l = k + 1; l < i; l++){
					if ( pow(i,3) == pow(j,3) + pow(k,3) + pow(l,3) ) printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,l);
				}
			}
		}	
	}
	return 0;
}