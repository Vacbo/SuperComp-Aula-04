#include <iostream>

void get_ten_numbers(int *numbers) {
    for (int i = 0; i < 10; i++) {
        std::cout << "Enter number " << i + 1 << ": ";
        std::cin >> numbers[i];
    }
}

int find_greatest(int *numbers) {
    int greatest = numbers[0];
    for (int i = 1; i < 10; i++) {
        if (numbers[i] > greatest) {
            greatest = numbers[i];
        }
    }
    return greatest;
}

int main() {
    int numbers[10];
    get_ten_numbers(numbers);

    int greatest = find_greatest(numbers);
    std::cout << "\nThe greatest number is: " << greatest << std::endl;

    return 0;
}
