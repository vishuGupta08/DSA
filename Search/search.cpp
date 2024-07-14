#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int arr[], int low, int high, int element)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (element == arr[mid])
        {
            return mid;
        }
        if (element > arr[mid])
        {
            low = mid + 1;
        }
        else if (element < arr[mid])
        {
            high = mid - 1;
        }
    }
    return -1;
}

int binarySearchRec(int arr[], int low, int high, int element)
{
    if (low > high)
    {
        return -1; // Base case: element is not found
    }
    int mid = low + (high - low) / 2;
    if (element == arr[mid])
    {
        return mid;
    }
    if (element < arr[mid])
    {
        return binarySearchRec(arr, low, mid - 1, element);
    }

    if (element > arr[mid])
    {
        return binarySearchRec(arr, mid + 1, high, element);
    }

    return -1;
}
int main()
{
    // pre requisite for binary search is that input array must be sorted
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x = 40;
    // int result = binarySearch(arr, 0, size - 1, x);
    int result = binarySearchRec(arr, 0, size - 1, x);
    cout << result;

    return 0;
}