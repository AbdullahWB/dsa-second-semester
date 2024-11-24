#include <stdio.h>
int main()
{
    int x = 10;
    int *p = &x;
    printf("The value of x is: %d\n", x);
    // printf("The address of x is: %d\n", &x);
    printf("The value of x through pointer p is: %d\n", *p);
    // printf("The address of x through pointer p is: %d\n", &p);
    int **pp = &p;
    printf("The value of x through pointer pp is: %d\n", **pp);
    int ***ppp = &pp;
    // printf("The value of x through pointer ppp is: %d\n", ***ppp);
    return 0;
}