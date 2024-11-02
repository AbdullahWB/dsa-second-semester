#include<stdio.h>
#include<string.h>

int main()
{
    char str[20];
    int len;
    gets(str);
    len = strlen(str);
    if(len > 5 && len < 15) {
        for(int i = len; i >= 4; i--) {
            str[i + 1] = str[i];
        }
        str[4] = 'x';
        str[len + 1] = '\0';
    } else {
        return 1;
    }
    puts(str);
    return 0;
}
