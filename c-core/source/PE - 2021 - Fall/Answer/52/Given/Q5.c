#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:

  int n;
  int a[100];
  scanf("%d", &n);
  int i;
  for(i = 0; i < n; i++){
  	scanf("%d", &a[i]);
  }
  
  int check = 1;
  for(i = 0; i < n; i++){
  	if(a[i] % 2 == 1){
  		check = 0;
  		break;
	  }
  }
  
  
  
  
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:




	if(check){
		printf("Even array of %d elements", n);
	}
	else
		printf("Not even array of %d elements", n);



  
  
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
