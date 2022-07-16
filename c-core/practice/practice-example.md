# Tổng hợp code example

## 1

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

## 2

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
