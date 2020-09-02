#include <stdio.h>

int main(){
	int A, B, Temp;
	scanf("%d %d", &A, &B);
	
	while(B != 0) {
		A = A - B;
				
		if(B > A) {
			Temp = A;
			A = B;
			B = Temp;
		}	
	}
	
	printf("%d", A);
	
	return 0;
}
