#include <iostream>

void get_string(char* str) {
    std::cout << "Enter a string: ";
    std::cin.getline(str, 100);
}

int get_length(char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    char str[100];
    get_string(str);
    std::cout << "\nLength of the string: " << get_length(str) << std::endl;

    return 0;
}
