#include <iostream>

void get_five_numbers(int *arr) {
    for (int i = 0; i < 5; i++) {
        std::cout << "Enter number " << i + 1 << ": ";
        std::cin >> arr[i];
    }
}

int sum_five_vector(int *arr) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[5];
    get_five_numbers(arr);

    int sum = sum_five_vector(arr);
    std::cout << "\nThe sum of the numbers is: " << sum << std::endl;

    return 0;
}
