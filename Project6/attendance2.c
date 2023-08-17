#include <stdio.h>

int main()
{
  char ar[20];
  printf("Enter a name\n");
  scanf("%[^\n]", ar);
  printf("%s", ar);
  return 0;
}