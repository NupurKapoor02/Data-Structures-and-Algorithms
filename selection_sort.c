#include <stdio.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int selection_sort(int arr[],int n)
{
    int i,j,min;
    for (i=0;i<n-1;i++)
    {
        min=i;
        for (j=i+1;j<n;j++)
        {
            if (arr[j]<arr[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            swap(&arr[min],&arr[i]);
        }
    }
    return 0;
}

void print(int arr[],int n)
{
    int i;
    for (i=0;i<n;i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{ 
    int n;
    printf("Enter the number of elements of the array:");
    scanf("%d",&n);
    int arr[n];
    for(int k=0;k<n;k++)
    {
        printf("Enter the element:");
        scanf("%d",&arr[k]);
    }
    
    printf("Unsorted array:\n");
    print(arr,n);
    selection_sort(arr, n);
    printf("Sorted array: \n"); 
    print(arr, n);
    return 0;
}
