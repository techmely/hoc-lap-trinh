#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:

  
  char a[7];
  int i;
  for(i = 0; i < 7; i++){
  	scanf("%c ", &a[i]);
  }
  
  char b, c;
  b = a[6];
  for(i = 5; i >= 0; i--){
  	if(a[i] != a[6]){
  		c = a[i];
  		break;
	  }
  }
  
  int countb = 0, countc = 0;
  for(i= 0; i < 7; i++){
  	if(a[i] == b) countb++;
	if(a[i] == c) countc++; 
  }
  
  
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:

	printf("%d %c", countc, c);
	printf("%d %c\n", countb, b);
	





  
  
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
