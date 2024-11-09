#include <stdio.h>
int main()
{
    int x;
    x = 5;
    printf("The value of x is: %d\n", x);
    printf("The address of x is: %d\n", &x);
    int *p = &x;
    printf("The value of x through pointer p is: %d\n", *p);
    printf("The address of x through pointer p is: %d\n", p);
    printf("-------------------------------------------------\n");
    *p = 10;
    printf("The value of x is: %d\n", x);
    printf("The address of x is: %d\n", &x);
    printf("The value of x through pointer p is: %d\n", *p);
    printf("The address of x through pointer p is: %d\n", p);
    printf("The address pointer p is: %d\n", &p);
    return 0;
}