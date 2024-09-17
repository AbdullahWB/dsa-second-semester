#include <stdio.h>

int factorial(int num){
    int fact = 1;
    for(int i=1; i<=num; i++){
        fact *= i;
    }
    return fact;
}

int main()
{
    int n, sum=0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        sum += factorial(i);
    }
    printf("%d\n", sum);
    return 0;
}