#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int *top; 
    int *base;
    int size; 
} stack;

int initstack(stack *s, int len) {
    s->base = (int *)malloc(len * sizeof(int)); 
    if (s->base == NULL) {
        return -1; 
    }
    s->top = s->base; 
    s->size = len; 
    return 0; 
}

int push(stack *s, int m) {
    if (s->top - s->base >= s->size) {
        return -1;
    }
    *(s->top) = m;
    s->top++;
    return 0;
}

int pop(stack *s) {
    if (s->top == s->base) {
        return -1;
    }
    s->top--;
    return *(s->top);
}

int main() {
    stack s;
    int a, m;

    if (initstack(&s, 20) != 0) {
        return -1;
    }

    scanf("%d", &a);

    while (a > 0) {
        push(&s, a % 8);
        a /= 8;
    }

    while (s.top > s.base) {
        m = pop(&s);
        printf("%d", m);
    }
    printf("\n");
    free(s.base);

    return 0;
}
