#include <stdio.h>
#define SIZE 100


void MAX_HEAPIFY(int A[],int heap_size,int i)
{
    int l=(2*i)+1;
    int r=(2*i)+2;
    int largest=i,temp;

    if(l<heap_size && A[l]>A[largest])
    {
        largest=l;
    }

    if(r<heap_size && A[r]>A[largest])
    {
        largest=r;
    }

    if(i!=largest)
    {
        temp=A[i];
        A[i]=A[largest];
        A[largest]=temp;
        MAX_HEAPIFY(A,heap_size,largest);
    }
}

void BUILD_MAX_HEAP(int A[],int n)
{
    int i;
    for(i=n/2-1; i>=0; i--)
        MAX_HEAPIFY(A,n,i);
}

void HEAPSORT(int A[], int n)
{
    int i,temp;

    BUILD_MAX_HEAP(A,n);
    for(i=n-1;i>0;i--)
    {
        temp=A[0];
        A[0]=A[i];
        A[i]=temp;
        MAX_HEAPIFY(A,i,0);
    }

}

main()
{
    int i,n;
    int A[SIZE];

    printf("Enter the number of elements to be inserted in the array: ");
    scanf("%d",&n);

    printf("\n\nEnter the array elements one-by-one: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }

    HEAPSORT(A,n);

    printf("Sorted Array: ");
    for(i=0;i<n;i++)
    {
        printf("%d, ",A[i]);
    }

    return 0;
}
