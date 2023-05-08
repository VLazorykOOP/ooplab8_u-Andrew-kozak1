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
#include <vector>

template<typename T>
class Matrix {
public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data.resize(rows * cols);
    }

    Matrix(const Matrix<T>& other) {
        rows = other.rows;
        cols = other.cols;
        data = other.data;
    }

    ~Matrix() {
        data.clear();
    }

    Matrix<T>& operator=(const Matrix<T>& other) {
        rows = other.rows;
        cols = other.cols;
        data = other.data;
        return *this;
    }

    std::vector<T>& operator[](int row) {
        return data[row * cols];
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = (*this)[i][j] + other[i][j];
            }
        }
        return result;
    }

    Matrix<T>& operator+=(const Matrix<T>& other) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                (*this)[i][j] += other[i][j];
            }
        }
        return *this;
    }

private:
    int rows, cols;
    std::vector<std::vector<T>> data;
};int main() {
    // створення матриці 3x3 зі значеннями 1
    Matrix<int> m1(3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m1[i][j] = 1;
        }
    }

    // створення матриці 3x3 зі значеннями 2
    Matrix<int> m2(3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m2[i][j] = 2;
        }
    }

    // виведення початкових матриць
    std::cout << "Matrix 1:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << m1[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    std::cout << "Matrix 2:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << m2[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    // тестування операцій
    Matrix<int> m3 = m1 + m2;
    std::cout << "Matrix 1 + Matrix 2:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << m3[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    m1 += m2;
    std::cout << "Matrix 1 += Matrix 2:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << m1[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    return 0;
}
int main() {
    // створення матриці 3x3 зі значеннями 1
    Matrix<int> m1(3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m1[i][j] = 1;
        }
    }

    // створення матриці 3x3 зі значеннями 2
    Matrix<int> m2(3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m2[i][j] = 2;
        }
    }

    // виведення початкових матриць
    std::cout << "Matrix 1:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << m1[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    std::cout << "Matrix 2:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << m2[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    // тестування операцій
    Matrix<int> m3 = m1 + m2;
    std::cout << "Matrix 1 + Matrix 2:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << m3[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    m1 += m2;
    std::cout << "Matrix 1 += Matrix 2:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << m1[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    return 0;
}

