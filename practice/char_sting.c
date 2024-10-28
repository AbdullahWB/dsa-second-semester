#include <stdio.h>
int main()
{
    char arr[10] = {'a', 'b', 'c', 'd', 'e'};
    char x = 'x';
    int pos = -1;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == 'b')
        {
            pos = i;
            break;
        }
    }
    for(int i = 9-1; i > pos; i--){
        arr[i] = arr[i-1];
    }
    arr[pos+1] = x;
    for (int i = 0; i < 10; i++){
        if(arr[i] != '\0'){
            printf("%c ", arr[i]);
        }
    }
    return 0;
}