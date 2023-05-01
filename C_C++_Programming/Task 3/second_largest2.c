#include <stdio.h>
#include <limits.h>

int find_second_largest(int arr[], int size) {
    if (size < 2) {
        return -1; // no second largest element
    }
    
    int max_num = arr[0];
    int sec_max_num = INT_MIN;
    int i;
    
    for (i = 1; i < size; i++) {
        if (arr[i] > max_num) {
            sec_max_num = max_num;
            max_num = arr[i];
        } else if (arr[i] > sec_max_num && arr[i] != max_num) {
            sec_max_num = arr[i];
        }
    }
    
    return sec_max_num != INT_MIN ? sec_max_num : -1; // no second largest element
}

int main() {
    int size,i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    if (size < 2) {
        printf("The array must have at least 2 elements.\n");
        return 0;
    }
    
    int arr[size];
    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    int second_largest = find_second_largest(arr, size);
    
    if (second_largest == -1) {
        printf("There is no second largest element in the array.\n");
    } else {
        printf("The second largest element in the array is: %d\n", second_largest);
    }
    
    return 0;
}

