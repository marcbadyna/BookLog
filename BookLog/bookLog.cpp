//
//  bookLog.cpp
//  BookLog
//
//  Created by Marc Badyna on 4/22/25.
//

#include <iostream>
#include "bookLog.h"
#include <string>


Book::Book(int id, std::string title, std::string author, int pages) : title(title), author(author), pages(pages), isRead(false) {}

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

int Book::getId() {
    return id;
}

void BookTracker::addBook() {
    std::string title, author;
    int pages;
    
    std::cout << "Book title: \n";
    std::getline(std::cin, title);
    std::cout << "Author: \n";
    std::getline(std::cin, author);
    std::cout << "Pages: \n";
    std::cin >> pages;
    
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
    
    for (Book& book : books) {
        if (book.getId() == id) {
            book.markAsRead();
            std::cout << "Book marked as read.\n";
        }
    }
    std::cout << "Book not found.\n";
}


