#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    char *s_ptr, *e_ptr, temp;
    scanf("%s", s);

    s_ptr = s;
    e_ptr = s + strlen(s) - 1;

    printf("%c\n", *s_ptr);
    printf("%c\n", *e_ptr);

    while (s_ptr < e_ptr) {
        temp = *s_ptr;
        *s_ptr = *e_ptr;
        *e_ptr = temp;
        s_ptr++;
        e_ptr--;
    }

    printf("%s\n", s);

    return 0;
}
