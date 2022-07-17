#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:

  
  int n;
  scanf("%d", &n);
  
  
  
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:

	int i, j;
	for(i = 0; i < n-1; i++){
		for(j = 0; j < n; j++){
			printf("*");
		}
		printf("\n");
	}
	for(j = 0; j < n; j++){
			printf("*");
		}






  
  
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
