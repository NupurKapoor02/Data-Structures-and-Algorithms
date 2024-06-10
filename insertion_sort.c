#include <stdio.h>

void insertion_sort(int a[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0&&a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    
    for (int k=0;k<n;k++)
        printf("%d ",a[k]);
    printf("\n");
}

int main()
{
    int size;
    printf("Enter the number of elements in array:");
    scanf("%d",&size);
    int arr[size];
    for(int k=0;k<size;k++)
    {
        printf("Enter %d element:",(k+1));
        scanf("%d",&arr[k]);
    }
    
    printf("Unsorted array:\n");
    for (int k=0;k<size;k++)
        printf("%d ",arr[k]);
    
    printf("\nSorted array:\n");
    insertion_sort(arr,size);
}
