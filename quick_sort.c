#include <stdio.h>

void swap(int *a,int *b) 
{
  int t=*a;
  *a=*b;
  *b=t;
}

int divide(int a[],int l,int h) 
{
  int pivot=a[h];
  int i=(l-1);
  for(int j=l;j<h;j++) 
  {
    if (a[j]<=pivot) 
    {
      i++;
      swap(&a[i],&a[j]);
    }
  }
  swap(&a[i+1],&a[h]);
  return (i+1);
}

void quick_Sort(int a[],int l,int h) 
{
  if (l<h) 
  {
    int temp=divide(a,l,h);
    quick_Sort(a,l,temp-1);
    quick_Sort(a,temp+1,h);
  }
}

int main() 
{
  int n;
  printf("Enter size of array:");
  scanf("%d",&n);
  int a[n];
  
  for(int i=0;i<n;i++)
  {
      printf("Enter %d element:",(i+1));
      scanf("%d",&a[i]);
  }
  
  printf("Unsorted Array\n");
  for (int i=0;i<n;i++) 
  {
    printf("%d  ",a[i]);
  }
  printf("\n");
  
  quick_Sort(a, 0, n - 1);
  
  printf("Sorted array:\n");
  for (int i=0;i<n;i++) 
  {
    printf("%d  ",a[i]);
  }
  printf("\n");
}
