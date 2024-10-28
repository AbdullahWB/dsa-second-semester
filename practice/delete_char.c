#include <stdio.h>
#include <string.h>
int main()
{
    char str[20];
    scanf("%s", str);
    int pos = 0;
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == 'd'){
            pos = i;
            break;
        }
    }
    // printf("%c", pos);
    for(int i = pos; i < str[i] != '\0'; i++){
        str[i] = str[i+1];
    }
    for(int i = 0; i < strlen(str); i++){
        printf("%c ", str[i]);
    }
    return 0;
}