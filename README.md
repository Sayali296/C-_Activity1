# C-_Activity1
#include <iostream>
#include <string>
using namespace std;
class Book {
private:
    int bookId;
    string title;
    string author;
    string location; 
public:
    Book(int id, string t, string a, string loc) {
        bookId = id;
        title = t;
        author = a;
        location = loc;
    }
    void displayBookDetails() const {
        cout << "Book ID: " << bookId << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Location: " << location << endl;  // Display location
        cout << "----------------------" << endl;
    }
int main() {
    int numberOfBooks;
    cout << "Enter the number of books: ";
    cin >> numberOfBooks;
    cin.ignore();
    Book** books = new Book*[numberOfBooks];
    for (int i = 0; i < numberOfBooks; i++) {
        int bookId;
        string title, author, location;
        cout << "Enter details for Book " << (i + 1) << ":" << endl;
        cout << "Enter Book ID: ";
        cin >> bookId;
        cin.ignore(); 
 cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);
        cout << "Enter Location in Library: ";
        getline(cin, location); 
        books[i] = new Book(bookId, title, author, location);
    }
    cout << "\nBooks in the Library:" << endl;
    for (int i = 0; i < numberOfBooks; i++) {
        books[i]->displayBookDetails();  
    }
    for (int i = 0; i < numberOfBooks; i++) {
        delete books[i];  
    
    delete[] books;   
return 0;
}
