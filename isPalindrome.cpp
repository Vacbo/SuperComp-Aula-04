#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string &str) {
    int n = str.length();
    for (int i = 0; i < n / 2; ++i) {
        if (str[i] != str[n - i - 1]) {
            return false;
        }
    }
    return true;
}

std::string getString() {
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);
    return str;
}

int main() {
    std::string input;

    input = getString();

    if (isPalindrome(input)) {
        std::cout << "The string is a palindrome." << std::endl;
    } else {
        std::cout << "The string is not a palindrome." << std::endl;
    }

    return 0;
}
