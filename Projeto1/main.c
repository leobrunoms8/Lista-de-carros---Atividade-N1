#include <stdio.h>
 
void Recursao1(int i)
 {
   if(i>=5) return;
   printf("%d ",i);
   Recursao1(i+1);
 }
 
void Recursao2(int i)
 {
   if(i>=5) return;
   Recursao2(i+1);
   printf("%d ",i);
 }
 
int main()
{
  printf("Recursao1\n");
  Recursao1(0);
  printf("\n\nRecursao2\n");
  Recursao2(0);
  return 0;
}

