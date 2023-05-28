// Delete operation in an array
#include <iostream>
using namespace std;
void display(int array[], int size);
void delete_at_beg(int array[], int size);
void delete_at_index(int array[], int size, int index);
int main(void)
{
    int size = 5;
    int array[size] = {10, 20, 30, 40, 50};

    delete_at_beg(array, size);
    size--;
    cout << "Elements of the array after deleting the element from the beginning are => " << endl;
    display(array, size);

    int index = 2;
    delete_at_index(array, size, index);
    size--;
    cout << "Elements of the array after deleting the element from the index" << index << " are => " << endl;
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
void delete_at_beg(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        array[i] = array[i + 1];
    }
}

void delete_at_index(int array[], int size, int index)
{

    if (index == 0)
    {
        delete_at_beg(array, size);
    }
    else
    {
        for (int i = index; i < size; i++)
        {
            array[i] = array[i + 1];
        }
    }
}