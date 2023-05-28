// Implement insertion operation in an array
#include <iostream>
using namespace std;
void display(int array[], int size);
void insert_at_beg(int array[], int element, int size);
void insert_at_end(int array[], int element, int size);
void insert_at_index(int array[], int element, int size, int index);
int main(void)
{
    int size = 5;
    int array[size] = {10, 20, 30, 40, 50};

    size++;
    int element = 5;
    insert_at_beg(array, element, size);
    cout << "Elements of the array after inserting the element at the beginning are => " << endl;
    display(array, size);

    size++;
    element = 60;
    insert_at_end(array, element, size);
    cout << "Elements of the array after inserting the element at the end are => " << endl;
    display(array, size);

    size++;
    int index = 3;
    element = 10000;
    insert_at_index(array, element, size, index);
    cout << "Elements of the array after inserting the element at the index " << index << " are => " << endl;
    display(array, size);
    return 0;
}
void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "\t";
    }
    cout << endl;
}
void insert_at_beg(int array[], int element, int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            array[i] = element;
            return;
        }
        array[i] = array[i - 1];
    }
}
void insert_at_end(int array[], int element, int size)
{
    array[size - 1] = element;
}
void insert_at_index(int array[], int element, int size, int index)
{
    for (int i = size - 1; i >= index; i--)
    {
        if(i == index){
            array[index] = element;
            return;
        }
        array[i] = array[i-1];
    }
}