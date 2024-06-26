#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int a[n1], b[n2];
    for (i=0;i<n1;i++)
        a[i]=arr[l+i];
    for (j=0;j<n2;j++)
        b[j]=arr[m+1+j];
        i=0; 
    j=0; 
    k = l; 
    while(i<n1 && j<n2) 
    {
        if (a[i]<=b[j]) 
        {
            arr[k]=a[i];
            i++;
        }
        else 
        {
            arr[k]=b[j];
            j++;
        }
        k++;
    }
    while (i<n1) 
    {
        arr[k]=a[i];
        i++;
        k++;
    }
    while (j<n2) 
    {
        arr[k]=b[j];
        j++;
        k++;
    }
}
  
void mergeSort(int arr[], int l, int r)
{
    if (l < r) 
    {
        int m=l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int a[], int n)
{
    int i;
    for (i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
  
int main()
{
    int n;
    printf("Enter the no. of elements in array: ");
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++)
    {
        printf("Enter %d element:",(i+1));
        scanf("%d",&a[i]);
    }

    printf("Given array is \n");
    printArray(a,n);
  
    mergeSort(a, 0, n-1);
  
    printf("\nSorted array is \n");
    printArray(a,n);
    return 0;
}
