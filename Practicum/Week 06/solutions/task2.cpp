#include <iostream>

const int ARRAY_SIZE = 5;

int scalar_product(int arr1[], int arr2[]) {
    int result = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        result += arr1[i] * arr2[i];
    }
    return result;
}

int main() {
    int arr1[ARRAY_SIZE] = {1, 2, 3, 4, 5};
    int arr2[ARRAY_SIZE] = {5, 4, 3, 2, 1};
    int result = scalar_product(arr1, arr2);
    std::cout << "Scalar product: " << result << std::endl;
    return 0;
}
