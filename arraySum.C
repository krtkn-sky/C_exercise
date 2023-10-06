#include <stdio.h>

int main(){
    int n;
    printf("Enter no of elements in the array -> ");
    scanf("%d",&n);
    int arr[n],sum=0;
    printf("Enter %d elements -> \n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        sum += arr[i];
    }
    printf("Sum of elements -> %d",sum);
    return 0;
}