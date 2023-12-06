#include <iostream>

using namespace std;

class S21Matrix {
private:
    int rows;
    int cols;
    int** data;

public:
    S21Matrix() : rows(0), cols(0), data(nullptr) {}

    S21Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = 0;
            }
        }
    }

    S21Matrix(const S21Matrix& other) : rows(other.rows), cols(other.cols) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    S21Matrix(S21Matrix&& other) : rows(other.rows), cols(other.cols), data(other.data) {
        other.rows = 0;
        other.cols = 0;
        other.data = nullptr;
    }

    ~S21Matrix() {
        if (data != nullptr) {
            for (int i = 0; i < rows; ++i) {
                delete[] data[i];
            }
            delete[] data;
        }
    }
};

int main() {

    S21Matrix matrix1;
    S21Matrix matrix2(3, 3);
    S21Matrix matrix3(matrix2);
    S21Matrix matrix4(move(matrix2));

    return 0;
}
