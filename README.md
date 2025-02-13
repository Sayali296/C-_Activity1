# C-_Activity1

#include <iostream>
#include <string>

using namespace std;

const int MAX_PRODUCTS = 5;
const int MAX_CART_ITEMS = 10;

struct Product {
    int id;
    string name;
    double price;
};

struct CartItem {
    int productId;
    int quantity;
    double totalPrice;
    string productName;
};

void displayProducts(Product products[], int size) {
    cout << "\nAvailable Products:\n";
    for (int i = 0; i < size; i++) {
        cout << products[i].id << " - " << products[i].name << " | $" << products[i].price << endl;
    }
}

void addToCart(Product products[], CartItem cart[], int &cartCount) {
    if (cartCount >= MAX_CART_ITEMS) {
        cout << "Cart is full! You cannot add more items.\n";
        return;
    }

    int productId, quantity;
    cout << "\nEnter Product ID to add to cart: ";
    cin >> productId;
    cout << "Enter Quantity: ";
    cin >> quantity;

    bool productFound = false;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].id == productId) {
            cart[cartCount].productId = productId;
            cart[cartCount].productName = products[i].name;
            cart[cartCount].quantity = quantity;
            cart[cartCount].totalPrice = products[i].price * quantity;
            cartCount++;
            cout << "Product \"" << products[i].name << "\" added to cart!\n";
            productFound = true;
            break;
        }
    }

    if (!productFound) {
        cout << "Invalid Product ID!\n";
    }
}

void displayCart(CartItem cart[], int cartCount) {
    if (cartCount == 0) {
        cout << "Your cart is empty!\n";
        return;
    }

    double total = 0;
    cout << "\n===== Order Summary =====\n";
    for (int i = 0; i < cartCount; i++) {
        cout << cart[i].productId << " - " << cart[i].productName << " | $" 
             << cart[i].totalPrice / cart[i].quantity
             << " x " << cart[i].quantity << " = $" << cart[i].totalPrice << endl;
        total += cart[i].totalPrice;
    }
    cout << "-------------------------\n";
    cout << "Total Amount: $" << total << "\n\n";
}

int main() {
    Product products[MAX_PRODUCTS] = {
        {1, "Laptop", 750.99},
        {2, "Smartphone", 499.49},
        {3, "Headphones", 99.99},
        {4, "Smartwatch", 149.99},
        {5, "Tablet", 299.99}
    };

    CartItem cart[MAX_CART_ITEMS]; 
    int cartCount = 0; 

    int choice;

    while (true) {
        cout << "\n==== Online Shopping System ====\n";
        cout << "1. View Products\n";
        cout << "2. Add to Cart\n";
        cout << "3. View Cart\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayProducts(products, MAX_PRODUCTS);
                break;

            case 2:
                addToCart(products, cart, cartCount);
                break;

            case 3:
                displayCart(cart, cartCount);
                break;

            case 4:
                cout << "Thank you for shopping with us!\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}
