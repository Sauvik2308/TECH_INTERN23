#include <stdio.h>
#define SIZE 100

void quick_sort(int arr[],int p,int r)
{
    int pivot_index;
    if(p<r)
    {
        pivot_index=partition(arr,p,r);
        quick_sort(arr,p,pivot_index-1);
        quick_sort(arr,pivot_index+1,r);
    }
}

int partition(int arr[],int p,int r)
{
    int j,temp;
    int x=arr[r];
    int i=p-1;
    for(j=p;j<=r-1;j++)
    {
        if(arr[j]<=x)
        {
            i=i+1;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=temp;

    return i+1;
}

main()
{
    int arr[SIZE],len,i;

    printf("Enter the number of elements in the array: ");
    scanf("%d",&len);

    printf("Enter %d elements one by one: ",len);
    for(i=0;i<len;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    quick_sort(arr,0,len-1);

    printf("Sorted Array: ");
    for(i=0;i<len;i++)
    {
        printf("%d, ",arr[i]);
    }
}