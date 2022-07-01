#include <stdio.h>
#include <assert.h>

// sum_even_in_array(a, n, count) returns the sum of the even integers
//   in the array a of length n; *count is updated to the number of
//   even integers in the array
// requires: count points to memory that can be updated
int sum_even_in_array(int a[], int n, int * count)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            sum += a[i];
            *count++;
        }         
    }

    return sum;
}

int main(void)
{

    // TEST 1 // 
    int count1 = 0;
    int arr[5] = {1, 3, 5, 7, 9};
    assert(sum_even_in_array(arr, 5, &count1) == 0);

    // TEST 2 // 
    int count2 = 0;
    int arr2[5] = {2, 4, 6, 8, 10};
    assert(sum_even_in_array(arr2, 5, &count2) == 30);

    // TEST 3 //
    int count3 = 0;
    int arr3[7] = {21, 100, 3, 0, 6, 11, 1};
    assert(sum_even_in_array(arr3, 7, &count3) == 106);   

    printf("All tests passed successfully\n");

    return 0;
}

// EXPLANATION // 

// I used a for loop to iterate over all values of the array that was used as an argument of the created function
// Within the for loop, I have an if statement which checks whether each element of the array is an even number
// If the element is an even number, then the value of count (which is the number of even numbers in the array) 
// increases as well as the value of the variable sum which is increased by whatever even number that was stored in
// that particular position in the array. When the function finishes iterating over every element in the array,
// what's returned is whatever value that's stored in the variable 'sum'.