#include <iostream>
#include <vector>
#include <string>

using namespace std; // Use the std namespace for standard library elements

class Item {
public:
    string name;
    int quantity;

    Item(const string& itemName, int itemQuantity)
        : name(itemName), quantity(itemQuantity) {}
};

class Inventory {
private:
    vector<Item> items;

public:
    void addItem(const string& name, int quantity) {
        items.emplace_back(name, quantity);
    }

    void removeItem(const string& name) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->name == name) {
                items.erase(it);
                break;
            }
        }
    }

    void displayInventory() {
        cout << "Inventory:\n";
        for (const auto& item : items) {
            cout << "Name: " << item.name << ", Quantity: " << item.quantity << "\n";
        }
    }
};

int main() {
    Inventory inventory;

    while (true) {
        cout << "Options:\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. Display Inventory\n";
        cout << "4. Quit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int quantity;
            cout << "Enter item name: ";
            cin >> name;
            cout << "Enter item quantity: ";
            cin >> quantity;
            inventory.addItem(name, quantity);
            break;
        }
        case 2: {
            string name;
            cout << "Enter item name to remove: ";
            cin >> name;
            inventory.removeItem(name);
            break;
        }
        case 3:
            inventory.displayInventory();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}
