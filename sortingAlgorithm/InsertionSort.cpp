// Best case => O(n)
// Worst case => O(n^2)
// Average case => O(n^2)
// Insertion sort is an in-place algorithm (which does not need extra space)
// Insertion sort is an stable algorithm.
#include <iostream>
using namespace std;
// void insertion_sort(int arr[], int size);
void recursive_insertion_sort(int arr[], int size);
void display(int arr[], int size);
int main(void)
{
    int arr[] = {5, 4, 10, 1, 6, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Element of the array before sorting => " << endl;
    display(arr, size);
    recursive_insertion_sort(arr, size);
    // insertion_sort(arr, size);
    cout << "Element of the array after sorting => " << endl;
    display(arr, size);
    return 0;
}

// void insertion_sort(int arr[], int size)
// {
//     for (int i = 1; i < size; i++)
//     {
//         int temp = arr[i];
//         int j = i - 1;
//         while (j >= 0 && arr[j] > temp)
//         {
//             arr[j + 1] = arr[j];
//             j--;
//         }
//         arr[j + 1] = temp;
//     }
// }

void recursive_insertion_sort(int arr[], int size)
{
    if (size <= 1)
    {
        return;
    }
    recursive_insertion_sort(arr, size - 1);
    int temp = arr[size - 1];
    int j = size - 2;
    while (j >= 0 && arr[j] > temp)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = temp;
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}