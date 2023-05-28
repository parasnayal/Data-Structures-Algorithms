// Implementation of Array as an abstract data type
// We know that programming language provide us get and set method for the array
#include <iostream>
using namespace std;
class Array
{
private:
    int size, capacity, *ptr;

public:
    Array(int capacity, int size)
    {
        this->capacity = capacity;
        this->size = size;
        this->ptr = new int[capacity];
    }
    void display(Array *array_obj_ptr);
    void set(Array *array_obj_ptr);
    void get(Array *array_obj_ptr, int index);
};
void Array ::display(Array *array_obj_ptr)
{
    cout << "Elements of the array are => " << endl;
    for (int i = 0; i < array_obj_ptr->size; i++)
    {
        cout << array_obj_ptr->ptr[i] << "\t";
    }
    cout << endl;
}
void Array ::set(Array *array_obj_ptr)
{
    cout << "Enter the element of the array => " << endl;
    for (int i = 0; i < array_obj_ptr->size; i++)
    {
        // cin >> array_obj_ptr->ptr[i];
        cin >> *(array_obj_ptr->ptr + i);
    }
}
void Array ::get(Array *array_obj_ptr, int index)
{
    cout << "Element at the index " << index << " is => " << array_obj_ptr->ptr[index] << endl;
}
int main(void)
{
    Array array(10, 5);
    array.set(&array);
    array.display(&array);
    int index = 2;
    array.get(&array, index);
    return 0;
}