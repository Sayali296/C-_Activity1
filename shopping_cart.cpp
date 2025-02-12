#include <iostream>
#include <vector>
using namespace std;

class Product {
private:
    string name;
    double price;
    int quantity;

public:
    // Constructor
    Product(string n, double p, int q) : name(n), price(p), quantity(q) {}

    // Copy Constructor
    Product(const Product &p) {
        name = p.name;
        price = p.price;
        quantity = p.quantity;
    }

    // Display product details
    void display() const {
        cout << "Product: " << name << ", Price: $" << price << ", Quantity: " << quantity << endl;
    }
};

int main() {
    vector<Product> cart; // Shopping cart

    char choice;
    do {
        string name;
        double price;
        int quantity;

        // Take product details from user
        cout << "\nEnter product name: ";
        cin >> name;
        cout << "Enter product price: ";
        cin >> price;
        cout << "Enter quantity: ";
        cin >> quantity;

        // Create a new product and add it to the cart
        Product newProduct(name, price, quantity);
        cart.push_back(newProduct);

        // Ask if the user wants to add more products
        cout << "Do you want to add another product? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Display cart details
    cout << "\nShopping Cart:\n";
    for (const auto &product : cart) {
        product.display();
    }

    return 0;
}
