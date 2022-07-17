#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	char s1[100], s2[100], s3[100];
	fflush(stdin);
	gets(s1);
	fflush(stdin);
	gets(s2);
	fflush(stdin);
	gets(s3);
  
  int n1 = strlen(s1);
  int n2 = strlen(s2);
  int n3 = strlen(s3);
  int i;
  int j;
  int check = 1;
  for(i = n1 -1; i > 0; i--){
  	check = 1;
  	for(j = i; j < i + n2; j++){
  		if(s1[j] != s2[j-i]){
  			check = 0;
  			break;
		  }
	  }
	if(check){
		break;
	}
  }
  int timThay = i;
  for(i = timThay; i < timThay+ n2; i++){
  	s1[i] = s1[i+n2];
  }
  s1[n1-n2] = '\0';
  n1 = strlen(s1);
  for(i = n1 + n3 +1; i >= timThay + n3; i--){
  	s1[i] = s1[i-n3];
  }
  for(i = timThay; i < timThay + n3; i++){
  	s1[i] = s3[i - timThay];
  }
  
  
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:

puts(s1);






  
  
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
