//
//  bookLog.cpp
//  BookLog
//
//  Created by Marc Badyna on 4/22/25.
//

#include <iostream>
#include "bookLog.h"
#include <string>


Book::Book(int id, std::string title, std::string author, int pages) : id(id), title(title), author(author), pages(pages), isRead(false) {}

BookTracker::BookTracker() : nextId(1) {}

void Book::markAsRead() {
    isRead = true;
}

void Book::displayBooks() const {
    std::cout << "Book ID: " << id << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Pages: " << pages << std::endl;
    std::cout << "Status: " << (isRead ? "Read" : "Currently Reading") << std::endl;
}

int Book::getId() const {
    return id;
}

void BookTracker::addBook() {
    std::string title, author;
    int pages;
    
    std::cin.ignore();
    
    std::cout << "Book title: ";
    std::getline(std::cin, title);
    std::cout << "Author: ";
    std::getline(std::cin, author);
    std::cout << "Pages: ";
    std::cin >> pages;
    std::cin.ignore();
    
    Book newBook(nextId, title, author, pages);
    books.push_back(newBook);
    ++nextId;
    
    std::cout << "Book added!\n";
}

void BookTracker::displayAllBooks() {
    if (books.empty()) {
        std::cout << "No Books to Display..\n";
    } else {
        for (const Book& book : books) {
            book.displayBooks();
        }
    }
}

void BookTracker::markBookAsRead() {
    int id;
    std::cout << "Enter book ID: ";
    std::cin >> id;
    
    bool found = false;
    for (Book& book : books) {
        if (book.getId() == id) {
            book.markAsRead();
            std::cout << "Book marked as read.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Book not found.\n";
    }
}


