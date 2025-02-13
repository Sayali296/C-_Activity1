#include <iostream>
#include <string>

using namespace std;

struct Book
{
    int id;
    string title, author, genre, publisher;
    int year;
};

class Library
{
private:
    Book books[100];
    int count = 0, nextId = 1;

public:
    void addBook()
    {
        if (count >= 100)
        {
            cout << "Library is full!\n";
            return;
        }
        books[count].id = nextId++;
        cin.ignore();
        cout << "Enter title: ";
        getline(cin, books[count].title);
        cout << "Enter author: ";
        getline(cin, books[count].author);
        cout << "Enter genre: ";
        getline(cin, books[count].genre);
        cout << "Enter publisher: ";
        getline(cin, books[count].publisher);
        cout << "Enter publication year: ";
        cin >> books[count].year;
        count++;
        cout << "Book added successfully!\n";
    }

    void showBooks() const
    {
        if (count == 0)
        {
            cout << "No books in the library.\n";
            return;
        }
        for (int i = 0; i < count; i++)
        {
            cout << "ID: " << books[i].id << " | " << books[i].title << " by " << books[i].author
                 << " | Genre: " << books[i].genre << " | Publisher: " << books[i].publisher
                 << " | Year: " << books[i].year << endl;
        }
    }

    void findBook() const
    {
        if (count == 0)
        {
            cout << "No books in the library.\n";
            return;
        }
        cin.ignore();
        string searchTitle;
        cout << "Enter title to search: ";
        getline(cin, searchTitle);
        for (int i = 0; i < count; i++)
        {
            if (books[i].title == searchTitle)
            {
                cout << "Book found! ID: " << books[i].id << " | " << books[i].author
                     << " | Genre: " << books[i].genre << " | Publisher: " << books[i].publisher
                     << " | Year: " << books[i].year << endl;
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void deleteBook()
    {
        if (count == 0)
        {
            cout << "No books in the library.\n";
            return;
        }
        int deleteId;
        cout << "Enter ID to delete: ";
        cin >> deleteId;
        for (int i = 0; i < count; i++)
        {
            if (books[i].id == deleteId)
            {
                for (int j = i; j < count - 1; j++)
                {
                    books[j] = books[j + 1];
                }
                count--;
                cout << "Book deleted successfully!\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

int main()
{
    Library lib;
    int choice;
    while (true)
    {
        cout << "\n1. Add Book  2. Show Books  3. Find Book  4. Delete Book  5. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            lib.addBook();
            break;
        case 2:
            lib.showBooks();
            break;
        case 3:
            lib.findBook();
            break;
        case 4:
            lib.deleteBook();
            break;
        case 5:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
