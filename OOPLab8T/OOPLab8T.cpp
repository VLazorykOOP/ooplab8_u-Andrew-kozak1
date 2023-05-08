#include <iostream>
#include <cstring>

template <typename T>
void min_and_count(const T* arr, int size, T& min_val, int& count) {
    min_val = arr[0];
    count = 1;

    for (int i = 1; i < size; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
            count = 1;
        }
        else if (arr[i] == min_val) {
            count++;
        }
    }
}

template <>
void min_and_count<char*>(const char** arr, int size, char*& min_val, int& count) {
    min_val = arr[0];
    count = 1;

    for (int i = 1; i < size; i++) {
        if (strcmp(arr[i], min_val) < 0) {
            min_val = arr[i];
            count = 1;
        }
        else if (strcmp(arr[i], min_val) == 0) {
            count++;
        }
    }
}

int main() {
    // Виклики функції для різних типів даних
    int int_arr[] = { 1, 2, 3, 1, 4, 1 };
    int int_min_val, int_count;
    min_and_count(int_arr, 6, int_min_val, int_count);
    std::cout << "Min value: " << int_min_val << ", count: " << int_count << std::endl;

    double double_arr[] = { 1.5, 2.1, 1.5, 3.7, 1.5 };
    double double_min_val;
    int double_count;
    min_and_count(double_arr, 5, double_min_val, double_count);
    std::cout << "Min value: " << double_min_val << ", count: " << double_count << std::endl;

    char* char_arr[] = { "hello", "world", "hi", "hi", "world" };
    char* char_min_val;
    int char_count;
    min_and_count(char_arr, 5, char_min_val, char_count);
    std::cout << "Min value: " << char_min_val << ", count: " << char_count << std::endl;

    return 0;
}
