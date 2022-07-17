#include<stdio.h>
/*
----------SO NGUYEN TO------------------
int isPrime(int n){
	if(n < 2) return 0;
	int i;
	for(i = 2; i < n; i++){
		if(n % i == 0) return 0;
	}
	return 1;
}
---------------BUBBLE SORT - BE --> LON -----
void sort(int a[], int n){
	int i, j;
	int temp;
	for(i = 0; i < n-1; i++){
		for(j = n -1 ; j > 0; j--){
			if(a[j] < a[j-1]){
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
}
---------------NHAP MANG--------------------
	int n;
	scanf("%d", &n);
	
	int a[100];
	int i;
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	
------TACH CHUOI THANH TU, TRA VE SO LUONG TU----
int changeToWords(char words[][100], char s[]){
	int i;
	int count = 0;
	for(i = 0; i < strlen(s); i++){
		int j = 0;
		while(s[i] != ' ' && s[i] != '\0'){
			words[count][j] =  s[i];
			j++;
			i++;
		}
		words[count][j] = '\0';
		count++;
	}
	return count;
}
-----WORDS SORT----------------------------
void sortWords(char s[][100], int n){
	 int i, j;
	 char *str;
	 for(i = 0; i < n-1; i++){
		for(j = n- 1; j > i; j--){
			if(strcmp(s[j], s[j-1]) == -1){
				strcpy(str, s[j]);
				strcpy(s[j], s[j-1]);
				strcpy(s[j-1], str);
			}
		}
	}
}
unsigned long long frac(int n){
	if(n == 0 || n == 1) return 1;
	int i;unsigned long long product = 1;
	for(i = 2; i <= n; i++){
		product *= i;
	}
	return product;
}
*/
void sort(int a[], int n){
	int i, j;
	int temp;
	for(i = 0; i < n-1; i++){
		for(j = n -1 ; j > 0; j--){
			if(a[j] < a[j-1]){
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
}
int main(){
	int a[100];
	int i;
	for(i = 0; i < 7; i++){
		scanf("%d", &a[i]);
	}
	
	int b[100], num = 0;
	for(i = 0; i < 7; i++){
		if(100 <= a[i] && a[i] <= 999){
			b[num++] = a[i];
		}
	}
	
	if(num == 0){
		printf("No three-digit number");
	}
	else{
		sort(b, num);
		int max = 0;
		int count = 0;
		int j;
		for(i = 0; i  < num; i++){
			count = 0;
			for(j = i; j < num; j++){
				if(b[i] == b[j]){
					count++;
				}
			}
			if(count > max) max = count;
		}
		
		for(i = 0; i  < num; i++){
			count = 0;
			for(j = i; j < num; j++){
				if(b[i] == b[j]){
					count++;
				}
			}
			if(count == max){
				printf("%d ", b[i]);
			}
		}
	}
	return 0;
}

