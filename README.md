#include <iostream>
#include <string>
using namespace std;
class Book {
private:
    int bookId;
    string title;
    string author;
public:
    Book(int id, string t, string a) {
        bookId = id;
        title = t;
        author = a;
    }
    void displayBookDetails() {
        cout << "Book ID: " << bookId << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "----------------------" << endl;
    }
};
int main() {
    int numberOfBooks;
    cout << "Enter the number of books: ";
    cin >> numberOfBooks;
    cin.ignore(); 
    Book* books[numberOfBooks];
    for (int i = 0; i < numberOfBooks; i++) {
        int bookId;
        string title, author;
        cout << "Enter details for Book " << (i + 1) << ":" << endl;
        cout << "Enter Book ID: ";
        cin >> bookId;
        cin.ignore(); 
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);
        books[i] = new Book(bookId, title, author);
    }
    cout << "\nBooks in the Library:" << endl;
    for (int i = 0; i < numberOfBooks; i++) {
        books[i]->displayBookDetails();
        delete books[i]; 
    }
    return 0;
}
