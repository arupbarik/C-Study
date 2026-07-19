#include <stdio.h>
void reversestring(int n){
    char str[n];
    for (int i = 0; i < n-1; i++)
    {
        scanf(" %c",&str[i]);
    }
    str[n-1]='\0';
    printf("Original string is :%s\n",str);
    for (int i = 0; i < n/2; i++)
    {
        char temp;
        temp=str[i];
        str[i]=str[n-2-i];
        str[n-2-i]=temp;
    }
    printf("Reverse string is :%s\n",str);
}
void stringpalindrome(int n){
    char str[n];
    for (int i = 0; i < n-1; i++)
    {
        scanf(" %c",&str[i]);
    }
    str[n-1]='\0';
    printf("Original string is :%s\n",str);
    char c[n];
    for (int i = 0; i < n; i++)
    {
        c[i]=str[i];
    }
    
    for (int i = 0; i < n/2; i++)
    {
        char temp;
        temp=c[i];
        c[i]=c[n-2-i];
        c[n-2-i]=temp;
    }
    printf("Reverse string is :%s\n",c);
    int ispalindrome=1;
    for (int i = 0; i < n-1; i++)
    {
        if (c[i]!=str[i])
        {
            ispalindrome=0;
            break;
        }
        
    }
    if (ispalindrome==1)
    {
        printf("It is a palindrome\n");
    }
    else
    {
        printf("It is not a palindrome\n");
    }
    
    
    
}
void pointerswap(int *m,int *n){
    int temp;
    temp=*m;
    *m=*n;
    *n=temp;
}
void vowel_consonent_count(int n){
    char arr[n];
    for (int i = 0; i < n-1; i++)
    {
        scanf(" %c",&arr[i]);
    }
    arr[n-1]='\0';
    printf("the string : %s\n",arr);
    int vcount=0,count=0;
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i]== 'a' || arr[i]== 'e'|| arr[i]== 'i' || arr[i]== 'o'|| arr[i]== 'u' || arr[i]== 'A'|| arr[i]== 'E' || arr[i]== 'I' || arr[i]== 'O'||arr[i]== 'U')
        {
            vcount++;
        }
        else
        {
            count++;
        }
    }
    printf("vowel is: %d\t consonent is: %d\n",vcount,count);
}
int bubblesort(int n){
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n-1; i++)
    {
        int swap=0;
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
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
    printf("array is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    
    
}
int largest_in_array(int n){
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
    return large;
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
    int a,b;
    printf("enter numbers\n");
    scanf("%d %d",&a,&b);
    int *m,*n;
    m=&a;
    n=&b;
    pointerswap(m,n);
    printf("a is :%d\t b is :%d\n",a,b);
    return 0;
}