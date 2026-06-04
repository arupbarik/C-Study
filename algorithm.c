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
void selectionsort(int arr[],int n){
    for (int i=0;i<n-1;i++){
        int minindex=i;
        for(int j=i+1;j<n;j++){
            if (arr[j]<arr[minindex])
            {
                minindex=j;
            }
            
        }
        int temp=arr[minindex];
        arr[minindex]=arr[i];
        arr[i]=temp;
    }
}
int main(){
    printf("start algorithm\n");

// Linear search
    printf("This is linear search\n");
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
    printf("This is binary search\n");
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
   printf("This is bubble sort\n");
   for (int i = 0; i < x; i++)
   {
     printf("%d\n",ar[i]);
   }
// Selection Sort
   int array[5]={5,6,8,1,4};
   int a=5;
   selectionsort(array,a);
   printf("This is selection sort\n");
   for (int k = 0; k < a; k++)
   {
    printf("%d\n",array[k]);
   }
// Insertion sort
   int ary[5]={5,6,8,9,1};
   int b=5;
}