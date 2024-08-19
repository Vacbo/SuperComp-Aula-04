#include <iostream>

void get_3_3_matrix(int matrix[3][3]) {
    std::cout << "Enter the elements of the 3x3 matrix (row by row):" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

int sumDiagonal(int matrix[3][3]) {
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        sum += matrix[i][i];
    }
    return sum;
}

int main() {
    const int size = 3;
    int matrix[size][size];

    get_3_3_matrix(matrix);

    int principalDiagonalSum = sumDiagonal(matrix);

    std::cout << "\nThe sum of the principal diagonal is: " << principalDiagonalSum << std::endl;

    return 0;
}
