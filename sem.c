#include<stdio.h>
// #include<math.h>
// #include<stdlib.h>
int main(){
    printf("hello sem\n");
    //Write a C program to count the number of even and odd elements in a 1-D array of n integers entered by the user.
    // int n;
    // printf("How many numbers do you want to enter?\n");
    // scanf("%d",&n);
    // int numbers[n];
    // printf("please start\n");
    // int count=0;
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d",&numbers[i]);
    //     if (numbers[i]%2==0)
    //     {
    //         count++;
    //     }
        
    // }
    // for (int j = 0; j < n; j++)
    // {
    //     printf("%d\n",numbers[j]);
    // }
    // printf("No. of even is %d\n",count);
    // printf("No. of odd is %d\n",n-count);

    //Write a C program to find the second largest element in a 1-D array without sorting the array.
    // int arsize;
    // int largest;
    // int secondlargest;
    // printf("Enter which u prefer for an array\n");
    // scanf("%d",&arsize);
    // int arr[arsize];
    // printf("input of array\n");
    // for (int i = 0; i < arsize; i++)
    // {
    //     scanf("%d",&arr[i]);
    // }
    // if (arsize < 2)
    // {
    //     printf("Second largest element does not exist.\n");
    // }    
    // else
    // {
    //     if (arr[0] > arr[1])
    // {
    //     largest = arr[0];
    //     secondlargest = arr[1];
    // }
    // else    return 0;
    // {     
    //     largest = arr[1];
    //     secondlargest = arr[0];
    // }
    // for (int i = 2; i < arsize; i++)
    // {
    //     if (largest<arr[i])
    //     {
    //         secondlargest=largest;
    //         largest=arr[i];
    //     }
    //     else if (secondlargest<arr[i] && largest>arr[i])
    //     {
    //         secondlargest=arr[i];
    //     }
    // }
    // printf("the largest is %d\n", largest);
    // printf("the secondlargest is %d\n",secondlargest);
    // }
    
    //Write a C program to remove all duplicate elements from a 1-D array without using another array.
    int size;

    printf("Enter the size of array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements:\n");

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                for (int k = j; k < size - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }

                size--;
                j--;
            }
        }
    }

    printf("Array after removing duplicates:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    

    
    
}