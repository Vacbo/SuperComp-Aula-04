#include <iostream>
#include <vector>

void bubbleSort(std::vector<int> &vector) {
    int n = vector.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (vector[j] > vector[j + 1]) {
                std::swap(vector[j], vector[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

void printVector(const std::vector<int> &vector) {
    for (int elem : vector) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vector = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Unsorted array: ";
    printVector(vector);

    bubbleSort(vector);

    std::cout << "Sorted array: ";
    printVector(vector);

    return 0;
}
