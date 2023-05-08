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

//*завдання 2
#include <iostream>
#include <cstring>

using namespace std;

// Функція для впорядкування масиву
void bubbleSort(char* arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Функція бінарного пошуку
int binarySearch(char* arr[], int left, int right, char* value) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (strcmp(arr[mid], value) == 0) {
            return mid;
        }
        if (strcmp(arr[mid], value) > 0) {
            return binarySearch(arr, left, mid - 1, value);
        }
        return binarySearch(arr, mid + 1, right, value);
    }
    return -1;
}

int main() {
    char* arr[] = { "apple", "banana", "cherry", "dates", "kiwi", "orange", "peach" };
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    char* value = "kiwi";
    int index = binarySearch(arr, 0, n - 1, value);
    if (index == -1) {
        cout << "Element not found" << endl;
    }
    else {
        cout << "Element found at index " << index << endl;
    }
    return 0;
}
//*завдання 3
#include <iostream>
#include <stdexcept>
#include <vector>

template<typename T>
class Matrix {
public:
    Matrix(int rows, int cols) : rows_(rows), cols_(cols), data_(rows* cols) {}

    Matrix(const Matrix& other) : rows_(other.rows_), cols_(other.cols_), data_(other.data_) {}

    ~Matrix() {}

    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            rows_ = other.rows_;
            cols_ = other.cols_;
            data_ = other.data_;
        }
        return *this;
    }

    std::vector<T>& operator[](int row) {
        if (row < 0 || row >= rows_) {
            throw std::out_of_range("Invalid row index");
        }
        return data_.data() + row * cols_;
    }

    const std::vector<T>& operator[](int row) const {
        if (row < 0 || row >= rows_) {
            throw std::out_of_range("Invalid row index");
        }
        return data_.data() + row * cols_;
    }

    Matrix operator+(const Matrix& other) const {
        if (rows_ != other.rows_ || cols_ != other.cols_) {
            throw std::invalid_argument("Matrices must have the same dimensions");
        }
        Matrix result(rows_, cols_);
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                result[i][j] = (*this)[i][j] + other[i][j];
            }
        }
        return result;
    }

    Matrix& operator+=(const Matrix& other) {
        if (rows_ != other.rows_ || cols_ != other.cols_) {
            throw std::invalid_argument("Matrices must have the same dimensions");
        }
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                (*this)[i][j] += other[i][j];
            }
        }
        return *this;
    }

private:
    int rows_;
    int cols_;
    std::vector<T> data_;
};

