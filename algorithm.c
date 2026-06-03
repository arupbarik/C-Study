#include <stdio.h>
int linearsearch(int arr[],int n,int target){
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==target){
            return i;
        }
    }
    return -1;
}
int binarysearch(int arr[], int n,int target){
    int low=0;
    int high=n-1;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if (arr[mid]==target)
        {
            return mid;
        }
        else if (target>arr[mid])
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
    
}
void bubblesort(int arr[],int n){
    for (int i = 0; i < n-1; i++)
    {
        int swap=0; //flag
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                // Swap
                int temp;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swap=1;
            }
            
        }
        if (swap==0)
        {
            break;
        }
        
    }
    
}
int main(){
    printf("start algorithm\n");

// Linear search
    int arr[6]={3,5,7,6,8,9};
    int n=6;
    int target=8;
    int result;
    result=linearsearch(arr,n,target);
    if (result!=-1)
    {
        printf("Found the index is %d\n",result);
    }
    else
    {
        printf("Not found\n");
    }
// Binary search
    int arrr[10]={1,2,3,4,5,6,7,8,9,10};
    int m=10;
    int tar=7;
    int final=binarysearch(arrr,m,tar);
    if (final!=-1)
    {
        printf("Found and the index is %d\n",final);
    }
    else {
        printf("Not Found\n");
    }
// Bubble sort
   int ar[10]={5,8,7,6,8,2,3,4,9,1};
   int x=10;
   bubblesort(ar,x);
   for (int i = 0; i < x; i++)
   {
     printf("%d\n",ar[i]);
   }
// Selection Sort
   
}