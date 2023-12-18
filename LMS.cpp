#include <iostream>
#include <vector>
#include <iomanip>

class Book {
public:
    std::string title;
    std::string author;
    bool available;

    Book(const std::string& title, const std::string& author) : title(title), author(author), available(true) {}
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void displayBooks() const {
        std::cout << "Library Catalog:\n";
        std::cout << std::setw(20) << "Title" << std::setw(20) << "Author" << std::setw(15) << "Status\n";
        std::cout << "-----------------------------------------------------------\n";
        
        for (const auto& book : books) {
            std::cout << std::setw(20) << book.title << std::setw(20) << book.author;
            std::cout << std::setw(15) << (book.available ? "Available" : "Not Available") << '\n';
        }
    }

    void borrowBook(const std::string& title) {
        for (auto& book : books) {
            if (book.title == title && book.available) {
                book.available = false;
                std::cout << "You have successfully borrowed the book: " << title << '\n';
                return;
            }
        }
        std::cout << "Book not available for borrowing or does not exist.\n";
    }

    void returnBook(const std::string& title) {
        for (auto& book : books) {
            if (book.title == title && !book.available) {
                book.available = true;
                std::cout << "You have successfully returned the book: " << title << '\n';
                return;
            }
        }
        std::cout << "Book not available for return or does not exist.\n";
    }
};

int main() {
    Library library;

    // Adding some initial books to the library
    library.addBook(Book("Balochistan: Bruised, Battered and Bloodied", "Francesca Marino"));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee"));
    library.addBook(Book("1984", "George Orwell"));
    library.addBook(Book("Man's search for Meaning", "Victor Frankl"));
    library.addBook(Book("Daughter of the East", "Benazir Bhutto"));
    library.addBook(Book("Governing the ungovernable", "Dr. Ishrat Hussain"));

    int choice;
    std::string title;

    do {
        std::cout << "\n BUETK Library Management System\n";
        std::cout << "1. Display Books\n";
        std::cout << "2. Borrow a Book\n";
        std::cout << "3. Return a Book\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                library.displayBooks();
                break;

            case 2:
                std::cout << "Enter the title of the book you want to borrow: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                library.borrowBook(title);
                break;

            case 3:
                std::cout << "Enter the title of the book you want to return: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                library.returnBook(title);
                break;

            case 4:
                std::cout << "Exiting the Library Management System.\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
