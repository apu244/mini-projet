#include <stdio.h>

#define MAX 4500

void fib(char a1[], char a2[])
{
  for (int i = MAX - 1; i >= 0; i--)
    a1[i] = a2[i];
}

void add(char a1[], char a2[], char target[])
{
  int carry = 0;
  for (int i = MAX - 1; i >= 0; i--)
  {
    int num = (a1[i] - '0') + (a2[i] - '0') + carry;
    target[i] = (num % 10) + '0';
    carry = num / 10;
  }
}

char f1[MAX];
char f2[MAX];
char target[MAX];

int main()
{

  for (int i = 0; i < MAX; i++)
  {
    f1[i] = f2[i] = target[i] = '0';
  }
  f2[MAX - 1] = '1';

  int n;
  scanf("%d", &n);

  if (n == 0 || n == 1)
  {
    printf("%c", n + '0');
  }
  else
  {
    for (int i = 2; i <= n; i++)
    {
      add(f1, f2, target);
      fib(f1, f2);
      fib(f2, target);
    }

    int n = 0;
    for (int i = 0; i < MAX; i++)
    {
      if (n == 0 && target[i] == '0')
        continue;

      if (n == 0 && target[i] != '0')
        n = 1;
      printf("%c", target[i]);
    }
    printf("\n");
  }
  return 0;
}
