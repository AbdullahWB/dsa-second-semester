#include <stdio.h>

int main() {
    char arr[11] = { 'a', 'b', 'c', 'd', 'e', '\0' };
    int pos = -1;
    char x = 'x';

    for (int i = 0; i < 10; i++) {
        if (arr[i] == 'b') {
            pos = i;
            break; 
        }
    }

    // if (pos != -1) {
        for (int i = 10 - 1; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos + 1] = x;
    // }
    for (int i = 0; i < 11; i++) {
        if (arr[i] != '\0') {
            printf("%c ", arr[i]);
        }
    }
    printf("\n");

    return 0;
}
