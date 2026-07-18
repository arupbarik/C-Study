#include <stdio.h>
int bubblesort(int n){
    
}
void largest_in_array(int n){
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int large=arr[0];
    for (int i = 0; i < n; i++)
    {
        if (large<arr[i])
        {
            large=arr[i];
        }
        else
        {
            continue;
        }
        
    }
    printf("The largest element is :%d\n",large);
}
int linearsearch(int n,int target){
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==target)
        {
            return i;
        }
    }
    return -1;
}
int main(){

    return 0;
}