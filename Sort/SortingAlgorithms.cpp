
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            int temp;
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

// more efficient than bubble and selection
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// example of divide and conquer technique
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0;    // for left
    int j = 0;    // for right
    int k = left; // original array;

    while (i < n1 && j < n2)
    {

        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    // choose any pivot and rearrange the array accordingly

    int pivot = arr[low];
    int left = low, right = high;
    while (left < right)
    {

        while (arr[left] < pivot)
        {
            left++;
        }
        while (arr[right] > pivot)
        {
            right--;
        }
        if (left < right)
        {
            swap(&arr[left], &arr[right]);
            // right is the correct position of the pivot
        }
    }
    return right;
}
// example of divide and conquer
void quickSort(int arr[], int low, int high)
{
    if (high > low)
    {
        int pivot = partition(arr, low, high);
        // pivot element is now at correct position
        // so just sort the left and right halves of this pivot
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if ( n> left && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (n> right && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // create max heap from the input array
    // max heap is formed by mutiple heapify operatios for i = n/2 -1 till 0
    // why n/2 -1 --> right child = 2*i +2
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    // here the max heap is formed

    // --> Loop Starts
    for(int i= n-1; i> 0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr,i, 0);
    }
    // swap first element(because it is the largest, after heapify) to the last

    // reduce the size of array by one
    // heapify on index 0
    // --> Loop Ends
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int arr[] = {6, 2, 3, 4, 5, 7, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    // insertionSort(arr, n);
    // mergeSort(arr, 0, n - 1);
    // quickSort(arr,0, n-1);
    heapSort(arr, n);
    printArray(arr, n);
    return 0;
}