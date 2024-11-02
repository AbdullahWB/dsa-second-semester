#include <stdio.h>
#include <string.h>

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

struct StdList
{
    struct Std elem[20];
    int listSize;
};

int main()
{
    struct StdList list;
    list.listSize = 4;
    for (int i = 0; i < list.listSize; i++)
    {
        fgets(list.elem[i].name, 20, stdin);
        scanf("%f", &list.elem[i].grades);
        getchar();
    }
    int k = -1;
    for (int i = 0; i < list.listSize; i++)
    {
        if (strcmp(list.elem[i].name, "jarry") == 0)
        {
            k = i;
            break;
        }
    }
    for (int i = list.listSize - 1; i > k; i--)
    {
        list.elem[i + 1] = list.elem[i];
    }
    strcpy(list.elem[k + 1].name, "brush");
    list.elem[k + 1].grades = 99.0;
    list.listSize++;
    printf("--------output-----------\n");

    for (int i = 0; i < 4; i++)
    {
        printf("Name: %s", list.elem[i].name);
        printf("Grade: %.2f\n", list.elem[i].grades);
    }

    return 0;
}