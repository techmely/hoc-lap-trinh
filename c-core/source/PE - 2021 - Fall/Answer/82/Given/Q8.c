#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int isPrime(int n){
	if (n < 2){
		return 0;
	}
	int i;
	for(i = 2; i < n; i++){
		if(n % i == 0){
			return 0;
		}
	}
	return 1;
}

int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:

  int a, b;
  scanf("%d%d", &a, &b);
  int i;
  int count = 0;
  int x[2];
  for(i = b - 1; i > a && count < 2; i--){
  	if(isPrime(i)){
  		x[count++] = i;
	  }
  }
  
  
  
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
printf("%d %d", x[1], x[0]);







  
  
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
