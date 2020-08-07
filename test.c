#include <stdio.h>
void fun(int ptr)
{
  ptr = 15;
}

void funn(int **str)
{
  **str = 100;
}
int main()
{
  int i = 3;
  int *p;

  p = &i;

  printf("la valeur de p %d\n", *p);
  printf("la valeur de la variable p %p\n", p);

  printf("l'adresse de i %p\n", &i);
  printf("l'adresse de p %p\n", &p);
  // *p = 10;
  // printf("la valeur de p %d\n", *p);

  printf("la valeur de p %d\n", *p);
  fun(*p);
  printf("la valeujjjjjjjr de p %d\n", *p);

  funn(&p);
  printf("la valeur de p %d\n", *p);


}
