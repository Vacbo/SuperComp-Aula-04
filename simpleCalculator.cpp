#include <iostream>
#include <limits>

int calculate(int a, int b, char op) {
    const int errorCode = std::numeric_limits<int>::min();

    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                std::cerr << "\nError: Division by zero is not allowed." << std::endl;
                return errorCode;
            }
            return a / b;
        default:
            std::cerr << "\nError: Invalid operator." << std::endl;
            return errorCode;
    }
}

void get_input(int &a, int &b, char &op) {
    std::cout << "Enter the first number: ";
    std::cin >> a;

    std::cout << "Enter the operator (+, -, *, /): ";
    std::cin >> op;

    std::cout << "Enter the second number: ";
    std::cin >> b;
}

int main() {
    int a, b;
    char op;

    get_input(a, b, op);

    int result = calculate(a, b, op);

    const int errorCode = std::numeric_limits<int>::min();

    if (result != errorCode){
        std::cout << "\nResult: " << result << std::endl;
    }

    return 0;
}
