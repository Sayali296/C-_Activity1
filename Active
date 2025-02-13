# C-_Activity1

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Product {
    int id;
    string name;
    double price;
    string category;
    string review;
};

struct User {
    string username;
    string password;
    double balance;
};

void showProducts(Product products[], int numProducts) {
    cout << "\n🔹 Available Products:\n";
    cout << "---------------------------------------------------------------\n";
    cout << "| ID  | Name                | Category    | Price   |\n";
    cout << "---------------------------------------------------------------\n";
    for (int i = 0; i < numProducts; i++) {
        cout << "| " << products[i].id << "   | "
             << products[i].name << "   | "
             << products[i].category << "   | "
             << products[i].price << " Rs|\n";
    }
    cout << "---------------------------------------------------------------\n";
}

void toLowerCase(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

void searchProducts(Product products[], int numProducts, string searchTerm) {
    toLowerCase(searchTerm);
    cout << "\n🔍 Search Results for '" << searchTerm << "':\n";
    bool found = false;
    cout << "---------------------------------------------------------------\n";
    cout << "| ID  | Name                | Category    | Price   | Review |\n";
    cout << "---------------------------------------------------------------\n";
    for (int i = 0; i < numProducts; i++) {
        string productName = products[i].name;
        toLowerCase(productName);
        if (productName.find(searchTerm) != string::npos || to_string(products[i].id) == searchTerm) {
            cout << "| " << products[i].id << "   | "
                 << products[i].name << "   | "
                 << products[i].category << "   | "
                 << products[i].price << " Rs | "
                 << (products[i].review.empty() ? "No reviews" : products[i].review) << " |\n";
            found = true;
        }
    }
    cout << "---------------------------------------------------------------\n";
    if (!found) {
        cout << "No products found.\n";
    }
}

void registerUser(User& user) {
    cout << "Enter Username: ";
    cin >> user.username;
    cout << "Enter Password: ";
    cin >> user.password;
    user.balance = 10000;
    cout << "Registration successful! Welcome, " << user.username << ".\n";
}

bool loginUser(User& user) {
    string enteredUsername, enteredPassword;
    cout << "Enter Username: ";
    cin >> enteredUsername;
    cout << "Enter Password: ";
    cin >> enteredPassword;

    if (enteredUsername == user.username && enteredPassword == user.password) {
        cout << "Login successful! Welcome back, " << user.username << ".\n";
        return true;
    } else {
        cout << "Invalid credentials. Please try again.\n";
        return false;
    }
}

void showCart(Product products[], int cart[], int cartCount[], int cartCapacity, double total) {
    cout << "\n🔹 Your Cart:\n";
    cout << "---------------------------------------------------------------\n";
    cout << "| ID  | Name                | Quantity | Price   |\n";
    cout << "---------------------------------------------------------------\n";
    for (int i = 0; i < cartCapacity; i++) {
        if (cart[i] != 0) {
            cout << "| " << products[cart[i] - 1].id << "   | "
                 << products[cart[i] - 1].name << "   | "
                 << cartCount[i] << "       | "
                 << products[cart[i] - 1].price * cartCount[i] << " Rs|\n";
        }
    }
    cout << "---------------------------------------------------------------\n";
    cout << "Total: " << total << " Rs\n";
}

void addReview(Product &product) {
    cout << "Enter your review for " << product.name << ": ";
    cin.ignore(); // To ignore the newline left over from previous input
    getline(cin, product.review);
    cout << "Thank you for your review!\n";
}

int main() {
    Product products[20] = {
        {1, "Laptop", 50000, "Electronics", ""},
        {2, "Smartphone", 20000, "Electronics", ""},
        {3, "Headphones", 1500, "Accessories", ""},
        {4, "Smartwatch", 3000, "Accessories", ""},
        {5, "USB Drive", 500, "Electronics", ""},
        {6, "Keyboard", 1500, "Electronics", ""},
        {7, "Mouse", 800, "Electronics", ""},
        {8, "Monitor", 12000, "Electronics", ""},
        {9, "TV", 30000, "Electronics", ""},
        {10, "Air Conditioner", 25000, "Home Appliances", ""},
        {11, "Washing Machine", 15000, "Home Appliances", ""},
        {12, "Refrigerator", 18000, "Home Appliances", ""},
        {13, "Blender", 2000, "Home Appliances", ""},
        {14, "Sofa", 10000, "Furniture", ""},
        {15, "Bed", 12000, "Furniture", ""},
        {16, "Dining Table", 15000, "Furniture", ""},
        {17, "Wardrobe", 8000, "Furniture", ""},
        {18, "Shoes", 2500, "Fashion", ""},
        {19, "Shirt", 1000, "Fashion", ""},
        {20, "Jeans", 1500, "Fashion", ""}
    };

    User currentUser = {"", "", 0};
    int cart[5] = {0};
    int cartCount[5] = {0};
    int cartCapacity = 5;
    double total = 0;
    int choice, productId, quantity;
    bool isLoggedIn = false;

    while (true) {
        cout << "\n📌 Online Shopping System\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Show Products\n";
        cout << "4. Search Products\n";
        cout << "5. Add Product to Cart\n";
        cout << "6. Remove Product from Cart\n";
        cout << "7. Show Cart\n";
        cout << "8. Checkout\n";
        cout << "9. Add Review\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser(currentUser);
                break;

            case 2:
                isLoggedIn = loginUser(currentUser);
                break;

            case 3:
                showProducts(products, 20);
                break;

            case 4:
                if (!isLoggedIn) {
                    cout << "Please log in first.\n";
                    break;
                }
                {
                    string searchTerm;
                    cout << "Enter search term (ID or Name): ";
                    cin >> searchTerm;
                    searchProducts(products, 20, searchTerm);
                }
                break;

            case 5:
                if (!isLoggedIn) {
                    cout << "Please log in first.\n";
                    break;
                }
                cout << "Enter Product ID to add to cart: ";
                cin >> productId;
                if (productId < 1 || productId > 20) {
                    cout << "Invalid Product ID!\n";
                } else {
                    cout << "Enter quantity to add: ";
                    cin >> quantity;
                    bool found = false;
                    for (int i = 0; i < cartCapacity; i++) {
                        if (cart[i] == productId) {
                            cartCount[i] += quantity;
                            total += products[productId - 1].price * quantity;
                            cout << "Updated product quantity in cart.\n";
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        for (int i = 0; i < cartCapacity; i++) {
                            if (cart[i] == 0) {
                                cart[i] = productId;
                                cartCount[i] = quantity;
                                total += products[productId - 1].price * quantity;
                                cout << "Product added to cart.\n";
                                break;
                            }
                        }
                    }
                }
                break;

            case 6:
                if (!isLoggedIn) {
                    cout << "Please log in first.\n";
                    break;
                }
                cout << "Enter Product ID to remove from cart: ";
                cin >> productId;
                if (productId < 1 || productId > 20) {
                    cout << "Invalid Product ID!\n";
                } else {
                    bool found = false;
                    for (int i = 0; i < cartCapacity; i++) {
                        if (cart[i] == productId) {
                            total -= products[productId - 1].price * cartCount[i];
                            cart[i] = 0;
                            cartCount[i] = 0;
                            cout << "Product removed from cart.\n";
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Product not found in cart.\n";
                    }
                }
                break;

            case 7:
                if (cart[0] == 0) {
                    cout << "Your cart is empty.\n";
                } else {
                    showCart(products, cart, cartCount, cartCapacity, total);
                }
                break;

            case 8:
                if (cart[0] == 0) {
                    cout << "Your cart is empty. Please add products first.\n";
                    break;
                }
                if (total <= currentUser.balance) {
                    currentUser.balance -= total;
                    cout << "Checkout successful! Remaining balance: " << currentUser.balance << " Rs\n";
                    total = 0;
                    for (int i = 0; i < cartCapacity; i++) {
                        cart[i] = 0;
                        cartCount[i] = 0;
                    }
                } else {
                    cout << "Insufficient balance. Please add funds.\n";
                }
                break;

            case 9:
                if (!isLoggedIn) {
                    cout << "Please log in first.\n";
                    break;
                }
                cout << "Enter Product ID to add a review: ";
                cin >> productId;
                if (productId < 1 || productId > 20) {
                    cout << "Invalid Product ID!\n";
                } else {
                    addReview(products[productId - 1]);
                }
                break;

            case 10:
                cout << "Thank you for visiting our Online Shopping System!\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
