//
//  bookLog.h
//  BookLog
//
//  Created by Marc Badyna on 4/22/25.
//

#ifndef bookLog_h
#define bookLog_h
#include <string>
#include <vector>

class Book {
private:
    int id;
    std::string title;
    std::string author;
    int pages;
    bool isRead;
public:
    Book(int id, std::string title, std::string author, int pages);
    void markAsRead();
    void displayBooks() const;
    int getId() const;
};

class BookTracker {
private:
    std::vector<Book> books;
    int nextId;
public:
    BookTracker();
    void addBook();
    void displayAllBooks();
    void markBookAsRead();
};

#endif
