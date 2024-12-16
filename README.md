# Library Management System
## Overview
This project is a simple yet efficient library management system designed to organize and manage books and users. It allows functionalities such as adding, searching, and deleting books and users, rating books, and displaying detailed information about them. The system ensures unique ID generation for books and users while maintaining an intuitive structure. Implemented in C++, it demonstrates object-oriented programming principles and supports scalability. It includes modules like Book, User, BookList, and UserList to streamline operations, making it a valuable tool for small to medium-sized libraries.

## Features

### **Key Features**
1. **Book Management**  
   - Add books to the library.  
   - Search for books by title or ID.  
   - Delete books from the library.  
   - Rate books and calculate their average rating.  
   - Display all books along with their details (title, ISBN, ID, category, author, and average rating).  
   - Retrieve the highest-rated book.

2. **User Management**  
   - Add users to the system.  
   - Search for users by name or ID.  
   - Delete users from the system.  
   - Retrieve books associated with a specific user (based on authorship).

3. **Dynamic Data Structures**  
   - The system supports dynamically sized arrays for books and users, enabling flexibility to scale as needed.

4. **Object-Oriented Programming Principles**  
   - Encapsulation and abstraction using classes like `Book`, `User`, `BookList`, and `UserList`.  
   - Operator overloading for streamlined input and output (`>>` and `<<` operators).  
   - Friend functions and member functions for efficient data access and manipulation.

5. **Menu-Driven Interaction**  
   - A user-friendly interface that allows navigating through options dynamically, such as viewing book lists, user lists, and performing operations.

6. **Static Member Usage**  
   - Automatic ID assignment using static counters, ensuring each book and user has a unique identifier.

## Usage Instructions
Here’s how to use your **Library Management System**:

---

### **Usage Instructions**

1. **Launching the Program**  
   - Compile the project using the provided Makefile:  
     ```bash
     make
     ```

2. **Main Menu**  
   - Once the program starts, you will see a dynamic menu prompting you to select from various options.  
   - Example:
     ```
     --------------------------------------
         Library System: Main Menu
     --------------------------------------
      > Books 
        Users 
        Exit 
     ```
   - Enter to the action wanted

3. **Book Management**  
   - **Add New Book:** Enter the title, ISBN, category, and author details when prompted.  
   - **View Book List:** Displays all books with details like title, category, author, and average rating.  
   - **Search for a Book:** Search by title or ID to view specific book details.  
   - **Rate a Book:** Use the menu to assign a rating to a book, which updates its average rating.  
   - **Delete a Book:** Select a book by ID to remove it from the system.

4. **User Management**  
   - **Add New User:** Enter the user’s name, age, email, and password when prompted.  
   - **View User List:** Displays all users with details like name, age, and associated books (if any).  
   - **Search for a User:** Search by name or ID to view specific user details.  
   - **Delete a User:** Select a user by ID to remove them from the system.

5. **Exiting the Program**  
   - Choose the "Exit" option from the main menu to end the program gracefully.  
   - All data will reset unless you implement file persistence.


## Code Overview

1. **User Class**  
   The `User` class represents a user of the library system. It stores the following attributes:
   - `name`: The user's name.
   - `age`: The user's age.
   - `email`: The user's email address.
   - `password`: The user's account password.
   - **Methods**:  
     - `setters` and `getters` for each attribute.
     - `addBook()` and `removeBook()` to associate and disassociate books with the user.
     - `operator<<` for outputting user information.

2. **Book Class**  
   The `Book` class represents a book in the library. It contains:
   - `title`: The title of the book.
   - `isbn`: The ISBN number of the book.
   - `category`: The book’s genre or category.
   - `averageRating`: The average rating of the book.
   - `author`: The `User` object representing the author of the book.
   - **Methods**:
     - Setters and getters for the attributes.
     - `rateBook()` to rate the book and update its average rating.
     - `operator<<` and `operator>>` for input/output of book details.

3. **BookList Class**  
   The `BookList` class manages a collection of `Book` objects. It has the following functionalities:
   - `addBook()`: Adds a new book to the list.
   - `searchBook()`: Finds a book by its title or ID.
   - `deleteBook()`: Deletes a book by its ID.
   - `getTheHighestRatedBook()`: Returns the highest-rated book.
   - `getBooksForUser()`: Retrieves all books for a given user.
   - **Memory management**: Dynamically allocates and deallocates memory for the list of books.

4. **UserList Class**  
   The `UserList` class manages a collection of `User` objects. It provides:
   - `addUser()`: Adds a new user to the system.
   - `searchUser()`: Finds a user by name or ID.
   - `deleteUser()`: Deletes a user by ID.
   - **Memory management**: Dynamically handles memory for the user list.

---

### **Main Program Flow (main.cpp)**

- **Menu-driven System**:  
   Upon launching, the system displays a menu where users can choose various operations such as adding, searching, or deleting books and users.
   
- **Dynamic Book and User Lists**:  
   The `BookList` and `UserList` are dynamically populated based on user inputs, such as adding new books or users.
   
- **Interactivity**:  
   The program asks for input from the user to select the desired operation and provides real-time feedback on the actions performed.

---

### **Memory Management**:
- Both `BookList` and `UserList` dynamically allocate memory for their respective objects using `new` and deallocate them using `delete` to ensure no memory leaks occur.

---

### **Error Handling**:
- The program uses basic error handling for invalid inputs, such as entering a non-existent book ID or an invalid user ID.
- There are warnings for incomplete functions in the code, specifically for `searchUser()` in `UserList`, where the function may reach its end without returning a value.

## Demo video
[Link](https://drive.google.com/file/d/18zERJseP-namBPhxzrkWphL93zKYmsrt/view?usp=sharing)
