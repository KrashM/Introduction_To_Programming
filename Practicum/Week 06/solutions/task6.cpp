#include <iostream>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void remove_shift(int arr[], int &size, int remove_at_index) { // preserves order
    if (remove_at_index < 0 || remove_at_index >= size) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    
    for (int i = remove_at_index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    --size;
}

void remove_swap(int arr[], int &size, int remove_at_index) { // does not preserve order, but its faster
    if (remove_at_index < 0 || remove_at_index >= size) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    arr[remove_at_index] = arr[size - 1];
    --size;
}

void removeEven(int arr[], int &size) {
    int i = 0;
    while (i < size) {
        if (arr[i] % 2 == 0) {
            // remove_swap(arr, size, i);
            remove_shift(arr, size, i);
            continue;
        }
        ++i;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int capacity = sizeof(arr) / sizeof(arr[0]);
    int size = capacity;

    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    removeEven(arr, size);

    std::cout << "Array with even numbers removed: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
