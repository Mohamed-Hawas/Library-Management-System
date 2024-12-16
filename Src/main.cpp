#include "../Inc/book.h"
#include "../Inc/user.h"
#include "../Inc/book_list.h"
#include "../Inc/user_list.h"
#include <iostream>
#include <vector>
#include <conio.h> // For _getch() on Windows
#include <iomanip>
using namespace std;

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string BLUE = "\033[34m";
const std::string YELLOW = "\033[33m";
const std::string RESET = "\033[0m";

vector<string> mainMenu = {"Main Menu", "Books", "Users", "Exit"};
vector<string> booksMenu = {"Books Menu", "List all books", "Add Book", "Search with ID", "Search with title", "Delete book", "Step back", "Exit"};
vector<string> usersMenu = {"Users Menu", "List all users", "Add user", "Search with ID", "Search with name", "Delete user", "Step back", "Exit"};
// vector<string> emptyMenu = {""}; // Empty menu
vector<vector<string>> menus = {mainMenu, booksMenu, usersMenu};

void displayMenu(const vector<string> &options, int selected)
{
    system("cls"); // Clear screen
    cout << "--------------------------------------\n";
    cout << "    Liberary System : " << options[0] << "\n";
    cout << "--------------------------------------\n";
    cout << "Select one of the following:\n";
    for (size_t i = 1; i < options.size(); ++i)
    {
        if (i == selected)
        {
            cout << GREEN << " > " << options[i] << RESET << endl; // Highlight selected option
        }
        else
        {
            cout << "   " << options[i] << endl;
        }
    }
}

int main()
{
    std::string title, isbn, category, author, name, email, password;
    int id, age;
    double averageRating;
    int selectedOption = 1, selectedMenu = 0;
    BookList bookList(20);
    UserList userList(20);

    // Create authors
    User author1("John Doe", 35, "password123", "johndoe@example.com");
    User author2("Jane Smith", 40, "securepass", "janesmith@example.com");
    User author3("Alice Johnson", 28, "alicepass", "alicej@example.com");
    User author4("Mark Brown", 45, "markpass", "markbrown@example.com");
    User author5("Emma Davis", 32, "emmapass", "emmad@example.com");

    // Add users to the list
    userList.addUser(author1);
    userList.addUser(author2);
    userList.addUser(author3);
    userList.addUser(author4);
    userList.addUser(author5);

    // Create books with authors
    Book book1("The Great Adventure", "ISBN123456", "Fiction", author1);
    Book book2("Cooking 101", "ISBN789101", "Cooking", author2);
    Book book3("Space Exploration", "ISBN112131", "Science", author3);
    Book book4("History of Art", "ISBN141516", "Art", author4);
    Book book5("The World of AI", "ISBN171819", "Technology", author5);
    Book book6("Gardening Tips", "ISBN202122", "Gardening", author2);
    Book book7("Mystery of the Ocean", "ISBN232425", "Mystery", author3);
    Book book8("Adventures in Coding", "ISBN262728", "Programming", author1);
    Book book9("The Ultimate Guide to Fitness", "ISBN293031", "Health", author5);
    Book book10("The Psychology of Colors", "ISBN323334", "Psychology", author4);

    // Add books to the BookList
    bookList.addBook(book1);
    bookList.addBook(book2);
    bookList.addBook(book3);
    bookList.addBook(book4);
    bookList.addBook(book5);
    bookList.addBook(book6);
    bookList.addBook(book7);
    bookList.addBook(book8);
    bookList.addBook(book9);
    bookList.addBook(book10);

    while (true)
    {
        displayMenu(menus[selectedMenu], selectedOption);
        char key = _getch(); // Get key press
        if (key == 'w' && selectedOption > 1)
        { // Up
            selectedOption--;
        }
        else if (key == 's' && selectedOption < menus[selectedMenu].size() - 1)
        { // Down
            selectedOption++;
        }
        else if (key == 'a' && selectedMenu > 0)
        { // step back
            selectedOption = 1;
            selectedMenu = 0;
        }
        else if (key == '\r' || key == 'd')
        {                  // Enter
            system("cls"); // Clear screen
            cout << "--------------------------------------\n";
            cout << "    Liberary System : " << (menus[selectedMenu])[0] << "\n";
            cout << "--------------------------------------\n";
            switch (selectedMenu)
            {
            case 0: // Main Menu
                if (mainMenu[selectedOption] == "Books")
                {
                    selectedMenu = 1;
                }
                else if (mainMenu[selectedOption] == "Users")
                {
                    selectedOption = 1;
                    selectedMenu = 2;
                }
                else if (mainMenu[selectedOption] == "Exit")
                {
                    return 0;
                }
                break;

            case 1: // Book Menu
                if (booksMenu[selectedOption] == "List all books")
                {
                    cout << bookList << endl;
                    cout << RED << "Press Enter to step back.\n"
                         << RESET;
                    std::cin.ignore();
                }
                else if (booksMenu[selectedOption] == "Add Book")
                {
                    Book book;

                    std::cout << "Enter book title: ";
                    std::getline(std::cin, title);
                    book.setTitle(title);

                    std::cout << "Enter ISBN: ";
                    std::getline(std::cin, isbn);
                    book.setIsbn(isbn);

                    std::cout << "Enter category: ";
                    std::getline(std::cin, category);
                    book.setCategory(category);

                    bookList.addBook(book);
                    cout << GREEN << "The book added successfully.\n"
                         << RESET;
                    cout << RED << "Press Enter to step back.\n"
                         << RESET;
                    std::cin.ignore(); // Clear newline character from the buffer
                }
                else if (booksMenu[selectedOption] == "Search with ID")
                {
                    std::cout << "Enter book ID: ";
                    cin >> id;
                    std::cin.ignore(); // Clear newline character from the buffer
                    cout << GREEN << "The book details.\n"
                         << RESET;
                    cout << bookList.searchBook(id);
                    cout << RED << "Press Enter to step back.\n"
                         << RESET;
                    std::cin.ignore(); // Clear newline character from the buffer
                }
                else if (booksMenu[selectedOption] == "Search with title")
                {
                    std::cout << "Enter book title: ";
                    getline(cin, title);
                    cout << GREEN << "The book details.\n"
                         << RESET;
                    cout << bookList.searchBook(title);
                    cout << RED << "Press Enter to step back.\n"
                         << RESET;
                    std::cin.ignore(); // Clear newline character from the buffer
                }
                else if (booksMenu[selectedOption] == "Delete book")
                {
                    std::cout << "Enter book ID: ";
                    cin >> id;
                    std::cin.ignore(); // Clear newline character from the buffer
                    bookList.deleteBook(id);
                    cout << GREEN << "The book deleted.\n"
                         << RESET;
                    cout << RED << "Press Enter to step back.\n"
                         << RESET;
                    std::cin.ignore(); // Clear newline character from the buffer
                }
                else if (booksMenu[selectedOption] == "Step back")
                {
                    selectedOption = 1;
                    selectedMenu = 0;
                }
                else if (booksMenu[selectedOption] == "Exit")
                {
                    return 0;
                }
                break;

            case 2: // User Menu
                if (usersMenu[selectedOption] == "List all users")
                {
                    cout << userList << endl;
                    cout << RED << "Press Enter to step back.\n"
                         << RESET;
                    std::cin.ignore();
                }
                else if (usersMenu[selectedOption] == "Add user")
                {
                    User user;

                    // std::cout << "Enter user name: ";
                    // std::getline(std::cin, name);
                    // user.setName(name);

                    // std::cout << "Enter email: ";
                    // std::getline(std::cin, email);
                    // user.setEmail(email);

                    // std::cout << "Enter password: ";
                    // std::getline(std::cin, password);
                    // user.setPassword(password);
                    cin >> user;
                    userList.addUser(user);
                    cout << GREEN << "The user added successfully.\n"
                         << RESET;
                    cout << RED << "Press Enter to step back.\n"
                         << RESET;

                    std::cin.ignore(); // Clear newline character from the buffer
                }
                else if (usersMenu[selectedOption] == "Search with ID")
                {
                    std::cout << "Enter user ID: ";
                    cin >> id;
                    std::cin.ignore(); // Clear newline character from the buffer
                    cout << GREEN << "The user details.\n"
                         << RESET;
                    cout << userList.searchUser(id);
                    cout << RED << "Press Enter to step back.\n"
                         << RESET;
                    std::cin.ignore(); // Clear newline character from the buffer
                }
                else if (usersMenu[selectedOption] == "Search with name")
                {
                    std::cout << "Enter user name: ";
                    getline(cin, name);
                    cout << GREEN << "User details.\n"
                         << RESET;
                    if (cout << userList.searchUser(name))
                        cout << RED << "Press Enter to step back.\n"
                             << RESET;

                    std::cin.ignore();
                }
                else if (usersMenu[selectedOption] == "Delete user")
                {
                    std::cout << "Enter user ID: ";
                    cin >> id;
                    std::cin.ignore(); // Clear newline character from the buffer
                    userList.deleteUser(id);
                    cout << GREEN << "The user deleted.\n"
                         << RESET;
                    cout << RED << "Press Enter to step back.\n"
                         << RESET;
                    std::cin.ignore();
                }
                else if (usersMenu[selectedOption] == "Step back")
                {
                    selectedOption = 1;
                    selectedMenu = 0;
                }
                else if (usersMenu[selectedOption] == "Exit")
                {
                    return 0;
                }
                break;
                break;

            default:
                break;
            }
        }
    }

    return 0;
}
