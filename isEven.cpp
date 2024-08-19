#include <iostream>

void get_input(int &a) {
    std::cout << "Enter a number: ";
    std::cin >> a;
}

int isEven(int a) {
    return a % 2 == 0;
}

int main() {
    int a;
    get_input(a);
    if (isEven(a)) {
        std::cout << a << " is even." << std::endl;
    } else {
        std::cout << a << " is odd." << std::endl;
    }
    return 0;
}
