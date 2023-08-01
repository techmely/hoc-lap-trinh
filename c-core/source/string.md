# Tổng hợp code C về String

## Đếm số kí tự số trong xâu nhập từ bàn phím

```c
#include <stdio.h>
#include <conio.h>
#include <string.h>
int demktso(char s[])
{
 int i,dem=0;
 for (i=0;i<strlen(s);i++)
        if ( s[i]>='0' && s[i]<='9' )
   dem++;
 return dem;
}
void main()
{
    char s[100];
    gets(s);
    printf("so ki tu so la  :  %d",demktso(s));
    getch();
}

```

## Đếm số kí tự hoa trong xâu nhập từ bàn phím

```c
#include <stdio.h>
#include <conio.h>
#include <string.h>
int demkthoa(char s[])
{
 int i,dem=0;
 for (i=0;i<strlen(s);i++)
        if ( s[i]>='A' && s[i]<='Z' )
   dem++;
 return dem;
}
void main()
{
    char s[100];
    gets(s);
    printf("so ki tu hoa la  :  %d",demkthoa(s));
    getch();
}
```

## Đếm số kí tự thường trong xâu nhập từ bàn phím

```c
#include <stdio.h>
#include <conio.h>
#include <string.h>
int demktthuong(char s[])
{
 int i,dem=0;
 for (i=0;i<strlen(s);i++)
        if ( s[i]>='a' && s[i]<='z' )
   dem++;
 return dem;
}
void main()
{
    char s[100];
    gets(s);
    printf("so ki tu thuong la  :  %d",demktthuong(s));
    getch();
}
```

## Đếm các số tự nhiên trong xâu nhập từ bàn phím. Các kí tự số gần nhau ghép thành 1 số tự nhiên

Ví dụ: a123bc4d56ef cho ra đáp án là : 3

```c
#include <stdio.h>
#include <conio.h>
#include <string.h>
void main()
{
    char s[100];
    int i=0,j,dem=0;
    gets(s);
    while (i<=strlen(s))
    {
        j=0;
        while ( s[i]>='0' && s[i]<='9' )
        {
             i++;
             j++;
        }
        i++;
        if (j!=0) dem++;
     }
     printf("%d",dem);
     getch();
}
```

## Tính độ dài của một chuỗi C

```c
#include <stdio.h> int main() {
    char s[] = "Chương trinh đang chạy";
    int i;
    for (i = 0; s[i] != '\0'; ++i);
      printf("Độ dài chuỗi: %d", i);
    return 0;
}
```

## nối hai chuỗi trong C

```c
#include <stdio.h> int main() {
  char s1[100] = "Lập trình ", s2[] = "c cơ bản";
  int length, j;
  // chiều dài cửa hàng của s1 trong biến chiều dài
  length = 0;
  while (s1[length] != '\0') {
    ++length;
  }
  // nối s2 thành s1
  for (j = 0; s2[j] != '\0'; ++j, ++length) {
    s1[length] = s2[j];
  }
  // chấm dứt chuỗi s1
  s1[length] = '\0';
  printf("Chuỗi sau cùng: ");
  puts(s1);
  return 0;
}
```

## Nhập vào 1 chuỗi và xuất chuỗi đó ra theo chiều ngược lại

Ví dụ: Nhập vào `tran van thoa` xuất ra `aoht nav nart`

```c
#include <conio.h> #include <stdio.h> #include <string.h>  //thư viện chuỗi

int main()
{
    char xau[30];
    printf("Nhap vao 1 chuoi: ");
    gets(xau);
    for(int i=strlen(xau)-1;i>=0;i--)  //strlen trả về độ dài của chuỗi
    {
        printf("%c",xau[i]);
    }
    getch();
}

```

## Nhập vào 1 chuỗi và xuất chuỗi đó ra theo chiều ngược lại

Ví dụ: Nhập vào `tran van thoa` xuất ra `thoa van tran`

```c
#include <stdio.h> #include <conio.h> #include <string.h>

int main()
{
   char xau[50];
   printf("Nhap vao mot chuoi: ");
   gets(xau);
   int a=strlen(xau)-1;
   for(int i=strlen(xau)-1;i>=0;i--)
   {
      if(xau[i]==32 || i==0)
      {
         if(i==0)
         {
            printf(" ");
         }
         for(int j=i;j<=a;j++)
         {
            printf("%c",xau[j]);
         }
         a=i-1;
      }
   }
   getch();
}

```

## Nhập vào họ và tên tách ra họ, tên

Ví dụ Nhập vào `tran van thoa` xuất ra `tran thoa`

```c
#include <conio.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char xau[30];
    printf("Nhap vao mot chuoi: ");
    gets(xau);
    for(int i=0;i<strlen(xau);i++)
    {
        if(xau[i]!=32)
        {
            printf("%c",xau[i]);
        }
        else         {
         for(int j=strlen(xau)-1;j>=i;j--)
         {
            if(xau[j]==32)
            {
               for(int k=j;k<=strlen(xau)-1;k++)
               printf("%c",xau[k]);
               break;
            }
         }
         break;
      }
    }
    getch();
}
```

## Nhập vào họ và tên xuất ra họ, tên đệm, tên mỗi từ 1 dòng

VD Nhập vào `tran van thoa` xuất ra
`tran van thoa`

```c
#include <conio.h> #include <stdio.h> #include <string.h>

int main()
{
    char xau[30];
    printf("Nhap vao mot chuoi: ");
    gets(xau);
    for(int i=0;i<=strlen(xau)-1;i++)
    {
      if(xau[i]!=32)
      {
          printf("%c",xau[i]);
      }
        else       {
            printf("\n");
      }
    }
    getch();
}
```

## Nhập vào 1 dãy số và đọc dãy số đó

Ví dụ: 123 đọc là một trăm hai mươi ba

```c
#include <conio.h>
#include <stdio.h>
#include <string.h>

char doc_so[50];
char *docso(int n)
{
   char doc[10][5]={"","Mot","Hai","Ba","Bon","Nam","Sau","Bay","Tam","Chin"};
   doc_so[0]=0;
   int donvi=n%10;
   n=n/10;
   int chuc=n%10;
   int tram=n/10;
   if(tram>0)
   {
      strcat(doc_so,doc[tram]);
      strcat(doc_so," Tram ");
   }
   if(chuc>0)
   {
      if(chuc==1)
      strcat(doc_so," Muoi ");
      else       {
         strcat(doc_so,doc[chuc]);
         strcat(doc_so," Muoi ");
      }
   }
   if(donvi>0)
   strcat(doc_so,doc[donvi]);
   return doc_so;
}
int main()
{
   int n;
    printf("Nhap vao mot day so: ");
    scanf("%d",&n);
    if(n==0)
    {
      printf("Khong");
   }
   else    {
      int tram=n%1000;
      n=n/1000;
      int ngan=n%1000;
      n=n/1000;
      int trieu=n%1000;
      int ty=n/1000;
      if(ty>0)
      {
         printf("%s Ty",docso(ty));
      }
      if(trieu>0)
      {
         printf(" %s Trieu ",docso(trieu));
      }
      if(ngan>0)
      {
         printf(" %s Ngan ",docso(ngan));
      }
      if(tram>0)
      {
         printf(" %s ",docso(tram));
      }
   }
   getch();
}

```

## Nhập vào 1 chuỗi sau đó nhập vào váo 1 từ và kiểm tra xem từ đó có xuất hiện trong chuỗi trên hay không, nếu có thì xuất hiện bao nhiêu lần

Ví dụ Nhập vào `tran van thoa`. Nhập kí tự t --> có 2 lần

```c
#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
    char xau[50];
    char kitukiemtra;
    int dem;
    printf("Nhap vao mot chuoi: ");
    gets(xau);
    printf("Nhap vao ki tu muon kiem tra: ");
    scanf("%c",&kitukiemtra);
    for(int i=0;i<strlen(xau)-1;i++)
    {
        if(xau[i]==kitukiemtra)
        dem++;
    }
    if(dem==0)
    printf("Ki tu %c khong co trong chuoi",kitukiemtra);
    else     printf("Ki tu %c xuat hien %d lan trong chuoi",kitukiemtra,dem);
    getch();
}

```
