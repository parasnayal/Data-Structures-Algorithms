// Selection Sort Algorithm
// Time complexity in both case O(n^2)
// Auxiliary Space: O(n)(in recursive way)
// Yes, Selection Sort Algorithm is an in-place algorithm
// The default implementation of the Selection Sort Algorithm is not stable. However, it can be made stable.
#include <iostream>
using namespace std;
// void selection_sort(int arr[], int size);
void recurive_selection_sort(int arr[], int size, int index);
void display(int arr[], int size);
int minIndex(int arr[], int i, int n);
int main(void)
{
    int arr[] = {4, 5, 3, 2, 4, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Elements of the array before sorting => " << endl;
    display(arr, size);

    // selection_sort(arr, size);
    recurive_selection_sort(arr, size - 1, 0);
    cout << "Elements of the array after sorting => " << endl;
    display(arr, size);
    return 0;
}

// void selection_sort(int arr[], int size)
// {
//     for (int i = 0; i < size - 1; i++)
//     {
//         int min = i;
//         for (int j = i + 1; j < size; j++)
//         {
//             if (arr[min] > arr[j]){
//                 min = j;
//             }
//         }
//         swap(arr[i] , arr[min]);
//     }
// }

int minIndex(int arr[], int i, int n)
{
    if (i == n)
    {
        return i;
    }
    int k = minIndex(arr, i + 1, n);
    return (arr[i] < arr[k]) ? i : k;
}

void recurive_selection_sort(int arr[], int size, int index = 0)
{
    if (index == size)
    {
        return;
    }
    int k = minIndex(arr, index, size);
    swap(arr[index], arr[k]);
    recurive_selection_sort(arr, size, index + 1);
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}