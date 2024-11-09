#include <stdio.h>
#include <limits.h>
int main()
{

    int a[5] = {1, 2, 3, 4, 5};

    for (int *i = a; i <= (a + 4); i++)
    {
        printf("%d \n", *i);
    }
    printf("==========\n");

    for(int i = 0; i < 5; i++){
        printf("%d \n", a + i);
        printf("%d \n", *(a + i));
        printf("%d \n", i[a]);
        printf("%d \n", a[i]);
        printf("----------\n");
    }

    // int i = 0, cnt = 0;
    // int arr[1] = {0};
    // printf("number of arr: %d count: %d\n", (arr + 1), cnt);
    // for(i = 0; i < arr[i] != 0; i++){
    //     printf("number of arr: %d count: %d\n", (arr+i), cnt);
    //     i++;
    //     cnt++;
    // }
    // int x;
    // x = 5;

    // int *p;
    // p = &x;
    // int *q = p;
    // printf("from x %d\n", x);
    // printf("from &x %d\n", &x);
    // printf("from p %d\n", p);
    // printf("from *p %d\n", *p);
    // printf("from &p %d\n", &p);
    // printf("from q %d\n", q);
    // printf("from *q %d\n", *q);
    // *q = &p;
    // printf("from *q but value of &p %d\n", *q);
    // printf("from &q %d\n", &q);

    // printf("The value of x is: %d\n", x);
    // printf("The address of x is: %d\n", &x);
    // int *p = &x;
    // printf("The value of x through pointer p is: %d\n", *p);
    // printf("The address of x through pointer p is: %d\n", p);
    // printf("-------------------------------------------------\n");
    // *p = 10;
    // printf("The value of x is: %d\n", x);
    // printf("The address of x is: %d\n", &x);
    // printf("The value of x through pointer p is: %d\n", *p);
    // printf("The address of x through pointer p is: %d\n", p);
    // printf("The address pointer p is: %d\n", &p);
    return 0;
}