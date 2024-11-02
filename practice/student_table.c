#include <stdio.h>

// typedef struct{
//     char name[20];
//     float grades;
// }Std;

// typedef struct{
//     Std elem[20];
//     int listSize[20];
// }StdList;



struct Std
{
    char name[20];
    float grades;
};

struct StdList{
    struct Std elem[20];
    int listSize[20];
};

int main()
{
    struct StdList list;
    for(int i = 0; i < 4; i++){
        fgets(list.elem[i].name, 20, stdin);
        scanf("%f", &list.elem[i].grades);
        getchar();
    }
    printf("--------output-----------\n");

    for(int i = 0; i < 4; i++){
        printf("Name: %s", list.elem[i].name);
        printf("Grade: %.2f\n", list.elem[i].grades);
    }

    return 0;
}