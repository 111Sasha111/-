#include <iostream>
#include <vector>

using namespace std;

class S21Matrix {
private:
    vector<vector<double>> matrix;

public:
    S21Matrix(const vector<vector<double>>& inputMatrix) : matrix(inputMatrix) {}

    bool EqMatrix(const S21Matrix& other) const {
        return matrix == other.matrix;
    }

    void SumMatrix(const S21Matrix& other) {
        if (matrix.size() != other.matrix.size() || matrix[0].size() != other.matrix[0].size()) {
            cerr << "Error: Matrices have different dimensions for addition." << endl;
            return;
        }

        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix[0].size(); ++j) {
                matrix[i][j] += other.matrix[i][j];
            }
        }
    }

    void SubMatrix(const S21Matrix& other) {
        if (matrix.size() != other.matrix.size() || matrix[0].size() != other.matrix[0].size()) {
            cerr << "Error: Matrices have different dimensions for subtraction." << endl;
            return;
        }

        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix[0].size(); ++j) {
                matrix[i][j] -= other.matrix[i][j];
            }
        }
    }

    void MulNumber(const double num) {
        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix[0].size(); ++j) {
                matrix[i][j] *= num;
            }
        }
    }

    void MulMatrix(const S21Matrix& other) {
        if (matrix[0].size() != other.matrix.size()) {
            cerr << "Error: Incompatible dimensions for matrix multiplication." << endl;
            return;
        }

        vector<vector<double>> result(matrix.size(), vector<double>(other.matrix[0].size(), 0.0));

        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < other.matrix[0].size(); ++j) {
                for (size_t k = 0; k < matrix[0].size(); ++k) {
                    result[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }

        matrix = result;
    }

    S21Matrix Transpose() const {
        vector<vector<double>> transposed(matrix[0].size(), vector<double>(matrix.size(), 0.0));

        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix[0].size(); ++j) {
                transposed[j][i] = matrix[i][j];
            }
        }

        return S21Matrix(transposed);
    }

    void PrintMatrix() const {
        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix[0].size(); ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    vector<vector<double>> mat1 = {{1, 2, 3}, {4, 5, 6}};
    vector<vector<double>> mat2 = {{7, 8}, {9, 10}, {11, 12}};

    S21Matrix matrix1(mat1);
    S21Matrix matrix2(mat2);

    matrix1.PrintMatrix();
    cout << endl;

    S21Matrix transposedMatrix = matrix1.Transpose();
    transposedMatrix.PrintMatrix();
    cout << endl;

    matrix1.MulMatrix(matrix2);
    matrix1.PrintMatrix();

    return 0;
}
