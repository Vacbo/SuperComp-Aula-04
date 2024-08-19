#include <iostream>
#include <vector>
#include <string>

struct Item {
    std::string name;
    int quantity;
    double price;
};

void addItem(std::vector<Item>& inventory) {
    Item newItem;
    std::cout << "Enter the item name: ";
    std::cin.ignore();
    std::getline(std::cin, newItem.name);
    std::cout << "Enter the quantity: ";
    std::cin >> newItem.quantity;
    std::cout << "Enter the price: ";
    std::cin >> newItem.price;

    // Check if the item already exists in the inventory
    for (auto& item : inventory) {
        if (item.name == newItem.name) {
            item.quantity += newItem.quantity;
            std::cout << "Quantity added to the existing item." << std::endl;
            return;
        }
    }

    // If the item does not exist, add it to the inventory
    inventory.push_back(newItem);
    std::cout << "Item added to inventory." << std::endl;
}

void removeItem(std::vector<Item>& inventory) {
    std::string name;
    std::cout << "Enter the name of the item to be removed: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->name == name) {
            inventory.erase(it);
            std::cout << "Item removed from inventory." << std::endl;
            return;
        }
    }

    std::cout << "Item not found in inventory." << std::endl;
}

void updateItemQuantity(std::vector<Item>& inventory) {
    std::string name;
    int quantityChange;
    std::cout << "Enter the name of the item to update the quantity: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    for (auto& item : inventory) {
        if (item.name == name) {
            std::cout << "Enter the quantity to add (positive) or remove (negative): ";
            std::cin >> quantityChange;
            if (item.quantity + quantityChange < 0) {
                std::cout << "Error: Quantity cannot be negative." << std::endl;
            } else {
                item.quantity += quantityChange;
                std::cout << "Item quantity updated." << std::endl;
            }
            return;
        }
    }

    std::cout << "Item not found in inventory." << std::endl;
}

void viewInventory(const std::vector<Item>& inventory) {
    if (inventory.empty()) {
        std::cout << "The inventory is empty." << std::endl;
    } else {
        std::cout << "Current inventory:" << std::endl;
        for (const auto& item : inventory) {
            std::cout << "Name: " << item.name << ", Quantity: " << item.quantity << ", Price: $" << item.price << std::endl;
        }
    }
}

int main() {
    std::vector<Item> inventory;
    int option;

    do {
        std::cout << "\nStock Control System" << std::endl;
        std::cout << "1. Add item" << std::endl;
        std::cout << "2. Remove item" << std::endl;
        std::cout << "3. Update item quantity" << std::endl;  // New option
        std::cout << "4. View inventory" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Choose an option: ";
        std::cin >> option;
        std::cout << "\n";


        switch (option) {
            case 1:
                addItem(inventory);
                break;
            case 2:
                removeItem(inventory);
                break;
            case 3:
                updateItemQuantity(inventory);  // New functionality
                break;
            case 4:
                viewInventory(inventory);
                break;
            case 5:
                std::cout << "Exiting the system..." << std::endl;
                break;
            default:
                std::cout << "Invalid option! Please try again." << std::endl;
        }
    } while (option != 5);

    return 0;
}
