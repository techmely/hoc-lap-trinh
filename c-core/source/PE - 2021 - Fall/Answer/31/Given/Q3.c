#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:

	int a[5];
  	int i;
  	for(i = 0 ; i < 5; i++){
  		scanf("%d", &a[i]);
  	}
  	
  	int num = 0;
  	int b[5];
  	for(i = 0; i < 5; i++){
  		if(a[i] % 2 == 1){
  			b[num++] = a[i];
		  }
	  }
	int j;
	int temp;
	for(i = 0; i < num - 1; i++){
		for(j = num - 1; j > 0; j--){
			if(b[j] < b[j-1]){
				temp = b[j];
				b[j] = b[j-1];
				b[j-1] = temp;
			}
		}
	}

  
  
  
  
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:

	for(i = 0; i < num-1; i++){
		printf("%d\n", b[i]);
	}
	printf("%d", b[num-1]);






  
  
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
