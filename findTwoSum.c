#include <stdio.h>
#include <stdlib.h>
struct result
{
    int *p;
    int size;
};
struct result newArrayWithInput();
void printFinalArray(struct result ptr);
void findTwoSum(struct result ptr, int target);
int main()
{
    int target;
    struct result ptr = newArrayWithInput();
    printFinalArray(ptr);
    printf("\nEnter a Target number ==> ");
    scanf("%d", &target);
    findTwoSum(ptr, target);

    return 0;
}
struct result newArrayWithInput()
{
    int sizeOfArray;
    printf("Give the size of array ==> ");
    scanf("%d", &sizeOfArray);
    int *arr = malloc(sizeOfArray * sizeof(int)); // Heap allocation
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < sizeOfArray; i++)
    {
        printf("Enter the %d value ==> ", i + 1);
        scanf("%d", &arr[i]);
    }

    struct result result;
    result.p = arr;
    result.size = sizeOfArray;

    return result;
}
void printFinalArray(struct result ptr)
{
    for (int i = 0; i < ptr.size; i++)
    {
        printf("%d\t", *(ptr.p + i));
    }
}
void findTwoSum(struct result ptr, int target)
{
    int flag=0;
    printf("Your Result is ==> ");
    for (int i = 0; i < ptr.size; i++)
    {
        for (int j = i; j < ptr.size; j++)
        {
            if ((*(ptr.p + i) + (*(ptr.p + j))) == target && i != j)
            {
                flag=1;

                printf("(%d,%d),", *(ptr.p + i), *(ptr.p + j));
                break;
            }
        }
    }
    if(flag!=1){
        printf("Empty");
    }else{
    printf("\b ");
    }
}
