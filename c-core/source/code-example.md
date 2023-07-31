# Tổng hợp code example

## Example 1

<img width="751" alt="Screen Shot 2022-07-17 at 01 42 59" src="https://user-images.githubusercontent.com/29374426/179368107-7a322147-f799-4b9a-809a-e1cf4e1ea1ca.png">

```c
#include <stdio.h>
  char str[5][80], tmp[80];#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  system("cls");
  // INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:


  int i, j;
  for (i = 0; i < 5; i++)
    scanf("%s", str[i]);

  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:

  for (i = 0; i < 4; i++)
  {
    for (j = i + 1; j < 5; j++)
    {
      if (strcmp(str[i], str[j]) > 0)
      {
        // ham cmp so sanh 2 chuoi
        // uu tien alphabet
        strcpy(tmp, str[i]);
        strcpy(str[i], str[j]);
        strcpy(str[j], tmp);
      }
    }
  }
  for (i = 0; i < 5; i++)
    printf("%s ", str[i]);

  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system("pause");
  return (0);
}

```

## Example 2

<img width="762" alt="Screen Shot 2022-07-17 at 01 43 21" src="https://user-images.githubusercontent.com/29374426/179368118-66aa0e64-2609-4fc4-bdb4-7913a75c6a0d.png">

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  system("cls");
  // INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
  char str[100];
  gets(str);
  int j = strlen(str);
  int i;

  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
  for (i = j / 2 - 2; i <= j / 2 + 2; i++)
  {
    printf("%c", str[i]);
  }

  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system("pause");
  return (0);
}
```

**Đảo ngược số**

```c
//đảo ngược số

#include <stdio.h>
int reverse(int n)
{
    int reNum = n % 10; // b1 láº¥y chá»¯ sá»‘ cuá»‘i cÃ¹ng
    n /= 10;            // bá» chá»¯ sá»‘ cuá»‘i cÃ¹ng
    int last;
    while (n > 0)
    {
        last = n % 10;             // láº¥y chá»¯ sá»‘ cuá»‘i cÃ¹ng
        n /= 10;                   // bá» chá»¯ sá»‘ cuá»‘i cÃ¹ng
        reNum = reNum * 10 + last; // vÃ²ng láº·p Ä‘á»ƒ thá»±c hiá»‡n bÆ°á»›c 2 3 4
    }
    return reNum;
}
int main()
{

    int n;
    printf("INPUT NUMBER: ");
    scanf("%d", &n);
    printf("REVERSE NUMBER OF %d IS %d ", n, reverse(n));
    return 0;
}
```

```c
// armstrong

#include <stdio.h>
#include <math.h>

int countDigits(int num)
{
    int count = 0;
    while (num > 0)
    {
        num /= 10;
        count++;
    }
    return count;
}

bool isArmstrong(int num)
{
    int numDigit = countDigits(num);
    int tmp = num;
    int sum = 0;
    int last;
    while (tmp > 0)
    {
        last = tmp % 10;
        tmp /= 10;
        sum += pow(last, numDigit);
    }
    if (sum == num)
        return true;
    return false;
}

int main()
{
    int num;
    printf("input number: ");
    scanf("%d", &num);

    if (isArmstrong(num) == true)
    {
        printf("%d is Armstrong number.", num);
    }
    else
    {
        printf("%d is not Armstrong number.", num);
    }
    //getch();
}
```

## Example 3

<img width="807" alt="Screen Shot 2022-07-17 at 01 54 47" src="https://user-images.githubusercontent.com/29374426/179368427-23cc765f-3e42-4b4d-88ea-7d9ce1a7e64a.png">

```c
#include <stdio.h>
int main()
{
    int n, reversed = 0, remainder, original;
    printf("Enter an integer: ");
    scanf("%d", &n);
    original = n;

    // reversed integer is stored in reversed variable
    while (n != 0 && n >= 0)
    {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    // palindrome if orignal and reversed are equal
 // ve hinh tam giac can chieu dai 2 canh = n nhu vi du

//Vi du n=4
/*
   *
  **
 ***
****
 ***
  **
   *
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
  int n;
  scanf("%d", &n);
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
  int i,j;
  for(i = 0; i < 2*n - 1;i++) { //In cot dung de in 2*n so cot chua sao nhu n=4 thi co 8 cot chua sao
  //Trong vong for nay dung de in hang
    for(j = 0; j < n;j++) {//Trong 1 hang toi da la n sao
      if(i >= n -1 - j && i <= n -1 +j)
      /*i>= n -1 - j: Dieu kien in ra so sao hang phia duoi*/
      /*i <= n -1 +j: Dieu kien in ra so sao o hang phia tren*/
        printf("*");
      else printf(" ");
    }
  }
  printf("\n");
}
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
```

## Example 4

Nhập vào số nguyên dương n và n số nguyên. Tìm số xuất hiện nhiều nhất

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
   int n;
   int arr[1000], b[1000] = {0}, c[1000] = {0}; //Khoi tao 3 mang so nguyen
   int i;
   scanf("%d", &n); //Nhap so phan tu cua mang arr
   for(i = 0; i < n;i++)
   {
    scanf("%d", &arr[i]); // Nhap n phan tu mang so nguyen arr
  }
  for(i = 0; i < n;i++)
  {
   if(arr[i] > 0) //Mang so nguyen b[] ghi lai so lan xuat hien cua
    b[arr[i]]++;  //cac phan tu lon hon 0 trong day arr
   if(arr[i] < 0) //Mang so nguyen c[] ghi lai so lan xuat hien cua
    c[-arr[i]]++; //cac phan tu nho hon 0 trong day arr
  }
  int max = 0;
  for(i = 0; i <n ;i++)
  {
   if(arr[i] > 0)
   {
    if(b[arr[i]] > max)
     max = b[arr[i]];
   }
   else
   {
    if(c[-arr[i]] > max)
     max = c[-arr[i]];
   }
  }// Vong lap tra ra so lan xuat hien nhieu nhat cua mot phan tu trong arr
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
   for(i = 0; i <1000 ;i++)
  {
   if(b[i] == max)
   {
    printf("%d", i);
   }
   if(c[i] == max)
    printf("%d", -i);
  } //In ra phan tu co lan xuat hien nhieu nhat trong day

  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
```

## Example 5

Tính tổng sum = 1/x + 1/x^2 + 1/x^3 +... + 1/x^n
Với x và n là số nguyên nhập từ bàn phím

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
   int x,n;
   scanf("%d%d", &x, &n); //Nhap vao hai so nguyen x va n
   double sum = 0; //Khoi tao gia tri cua tong bang khong
   int i;
   for(i = 0;i <= n;i++)
   {
    sum+= 1 / (pow(x,i)); //pow(x,i) la ham tinh luy thua bac i cua x
 }


  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
   printf("%.2lf\n", sum);


  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
// nhap vao mot chuoi bat ki, xoa het cac ki tu và so, chi giu lai cac chu cai

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
   char str[100];
   scanf("%[^\n]", str);
   int i,j;
   bool all_al = false;
   while(all_al == false) // lap de xoa ki tu khong phai chu cai
   {
    all_al = true;
    for(i = 0; i < strlen(str);i++)
    {
     if(!isalpha(str[i])) // kiem tra xem str[i] co phai la chu cai khong
   {
    for(j = i; j < strlen(str) ; j++) // xoa str[i] neu str[i] khong phai chu cai
    {
     str[j] = str[ j + 1];
    }
   }
  }
  for( i = 0; i < strlen(str);i++) // kiem tra trong str co ki tu nao khong phai chu cai khong
  {
   if(!isalpha(str[i]))
    all_al = false;
  }
 }







  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
   printf("%s\n", str);


  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
//nhap vao mot so tu nhien n, in ra 4 so nguyen to gan nhat lon hon n

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

bool isPrime(int n) // ham kiem tra so nguyen to
{
 if( n < 2)
  return false;
 int i;
 for(i = 2; i <= sqrt(n);i++)
 {
  if(n % i == 0)
   return false;
 }
 return true;
}

int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
   int count = 4;
   int n;
   scanf("%d", &n);
   int i = 1;

  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
 while(count > 0) // in ra 4 so nguyen to lon hon n
 {
  if(isPrime(n + i))
  {
   printf("%d\n", n + i);
   count--;
  }
  i++;
 }

  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  system ("pause");
  return(0);
}

```

## Example 6

<img width="735" alt="Screen Shot 2022-07-17 at 10 17 27" src="https://user-images.githubusercontent.com/29374426/179382380-6c959254-4619-4781-94d3-d93002b240c8.png">

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int sochan_max(int a[], int n)
{
    int max;
    int i = 0;
    while (a[i] % 2 != 0)
        i++;
    max = a[i];
    for (int j = i + 1; j < n; j++)
        if (a[j] % 2 == 0)
            if (max < a[j])
                max = a[j];
    return max;
}

int main()
{
     system("cls");
    // INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Fixed Do not edit anything here.
    printf("\nOUTPUT:\n");
    //@STUDENT: WRITE YOUR OUTPUT HERE:
    printf("%d", sochan_max(arr, 5));



  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system("pause");
  return (0);
}

```

## Example 7

<img width="774" alt="Screen Shot 2022-07-17 at 10 21 01" src="https://user-images.githubusercontent.com/29374426/179382390-7611ddc3-fc17-42b0-88e5-326fd542f61a.png">

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main()
{
    // system("cls");
    // INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
    int arr[5];
    int i, j;
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Fixed Do not edit anything here.
    printf("OUTPUT:\n");
    //@STUDENT: WRITE YOUR OUTPUT HERE:
    for (i = 0; i < 5; i++)
    {
        for (j = 4; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }

    for (i = 0; i < 5; i++)
    {
        if (arr[i] % 2 == 0)
        {
            printf("%d\n", arr[i]);
        }
    }
}

```

## Example 8

<img width="765" alt="Screen Shot 2022-07-17 at 10 21 32" src="https://user-images.githubusercontent.com/29374426/179382400-dad6f566-8476-4eee-8a5f-c39e9c2931cf.png">

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    system("cls");
    // INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
    int n, arr[10], i, check = 0, j, k;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j] && arr[i] % 2 != 0)
            {
                for (k = j; k < n; k++)
                {
                    arr[k] = arr[k + 1];
                }

                n--;
                j--;
            }
        }
    }
    // Fixed Do not edit anything here.
    printf("OUTPUT:\n");
    //@STUDENT: WRITE YOUR OUTPUT HERE:
    for (i = 0; i < n; i++)
    {
        if (check == 0)
            check = 1;
        else
            printf("\n");
        printf("%d", arr[i]);
    }
    //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system("pause");
    return (0);
}

```

## Example 9

<img width="754" alt="Screen Shot 2022-07-17 at 10 26 47" src="https://user-images.githubusercontent.com/29374426/179382522-110268c1-4331-47c5-85c4-f79516be8ab2.png">

```c
#include <stdio.h>
#include <string.h>
int main()
{
    system("cls");
    // INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
    char s[100];
    gets(s);
    int i, j, count = 0;
    char tmp[50][50];
    for (i = 0; i < strlen(s); i++)
    {
        j = 0;

        while (s[i] != ' ' && s[i] != '\0')
        {
            tmp[count][j] = s[i];
            j++;
            i++;
        }
        tmp[count][j] = '\0';
        if (tmp[count][0] == 'h' && tmp[count][j - 1] == 'g')
            count++;
    }

    // Fixed Do not edit anything here.
    printf("\nOUTPUT:\n");
    //@STUDENT: WRITE YOUR OUTPUT HERE:

    printf("%d", count);

    //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system("pause");
    return (0);
}
```

## Example 10

<img width="752" alt="Screen Shot 2022-07-17 at 10 26 28" src="https://user-images.githubusercontent.com/29374426/179382513-92c3875a-110b-4abb-96b4-aaa3f1d67697.png">

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main() ,
{
    system("cls");
    // INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
    int n, i, str[21], j, k, count = 0;
    char c[21];
    scanf("%d ", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%c", &c[i]);
        getchar();
    }
    // Fixed Do not edit anything here.
    printf("OUTPUT:\n");
    //@STUDENT: WRITE YOUR OUTPUT HERE:
    for (i = 0; i < n; i++)
    {
        str[i] = 1;
        for (j = 0; j < n + 1; j++)
        {
            if (i != j)
            {
                if (c[i] == c[j])
                {
                    str[i]++;
                    for (k = j; k < n; k++)
                        c[k] = c[k + 1];
                    n--;
                    j--;
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (str[i] >= 2)
        {
            printf("%c", c[i]);
            if (count != 1)
                printf("\n");
            count++;
            if (count == 2)
                break;
        }
    }
    //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system("pause");
    return (0);
}

```

## Example 11

<img width="685" alt="Screen Shot 2022-07-17 at 10 26 06" src="https://user-images.githubusercontent.com/29374426/179382502-08dca9df-db8a-4cf0-90d5-4a608f60ae12.png">

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    system("cls");
    // INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
    int a, tmp, flag = 0;
    scanf("%d", &a);
    tmp = a;
    while (a % 2 == 0)
    {
        a /= 2;
        flag++;
    }
    // Fixed Do not edit anything here.
    printf("OUTPUT:\n");
    //@STUDENT: WRITE YOUR OUTPUT HERE:
    if (a == 1)
    {
        printf("%d", flag);
    }
    else
    {
        printf("%d is not a power of 2", tmp);
    }
    //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system("pause");
    return (0);
}
```

## Example 12

<img width="792" alt="Screen Shot 2022-07-17 at 10 25 31" src="https://user-images.githubusercontent.com/29374426/179382495-1a796d0a-23b0-4f2a-837c-63e15769e099.png">

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    system("cls");
    // INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
    char s[100];
    int i, count = 0, tmp = 0;
    gets(s);
    // Fixed Do not edit anything here.
    printf("OUTPUT:\n");
    //@STUDENT: WRITE YOUR OUTPUT HERE:

    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] != ' ' && tmp < 3)
        {
            while (s[i] != ' ')
            {
                count++;
                ++i;
                ;
            }
            tmp++;
        }
    }
    printf("%d", count);
    //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system("pause");
    return (0);
}
```

## Example 13

<img width="787" alt="Screen Shot 2022-07-17 at 10 25 10" src="https://user-images.githubusercontent.com/29374426/179382477-ebc96ec3-4b2b-49f9-bc46-b30b1ffdd408.png">

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int checkprime(int n)
{
    int i;
    if (n < 2)
        return 0;
    for (i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;
    return 1;
}
int main()
{
    system("cls");
    // INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
    int n;
    scanf("%d", &n);

    // Fixed Do not edit anything here.
    printf("OUTPUT:\n");
    //@STUDENT: WRITE YOUR OUTPUT HERE:

    if (checkprime(n))
    {
        printf("0x%X", n);
    }

    else
    {
        printf("%d is not a prime number", n);
    }
    //--FIXED PART - DO NOT EDIT ANY THINGS HERE
    printf("\n");
    system("pause");
    return (0);
}

```
