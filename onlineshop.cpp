// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
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
    Product(const Product &other) {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
    }

    // Display function
    void display() const {
        cout << "Product: " << name << ", Price: $" << price << ", Quantity: " << quantity << endl;
    }
};

int main() {
    const int SIZE = 3;
    
    // Creating an array of Product objects
    Product cart[SIZE] = {
        Product("Laptop", 1200.99, 1),
        Product("Smartphone", 699.49, 2),
        Product("Headphones", 129.99, 1)
    };

    // Display original products
    cout << "Original Products in Cart:\n";
    for (int i = 0; i < SIZE; i++) {
        cart[i].display();
    }

    // Creating a duplicate product using the copy constructor
    Product duplicateProduct = cart[1];
    
    cout << "\nDuplicate Product:\n";
    duplicateProduct.display();

    return 0;
}
