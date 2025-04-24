//
//  main.cpp
//  BookLog
//
//  Created by Marc Badyna on 4/22/25.
//

#include <iostream>
#include "bookLog.h"
#include <sqlite3.h>

int main() {
    sqlite3* db;
        int exit = sqlite3_open("books.db", &db);

        if (exit) {
            std::cerr << "Error opening DB: " << sqlite3_errmsg(db) << std::endl;
            return 1;
        } else {
            std::cout << "Opened DB successfully!" << std::endl;
        }

        sqlite3_close(db);
    
    BookTracker tracker;
    int choice;
    
    do {
        std::cout << "----Book Log----\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. View All Books\n";
        std::cout << "3. Mark Book as Read\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;
        switch (choice) {
            case 1:
                tracker.addBook();
                break;
            case 2:
                tracker.displayAllBooks();
                break;
            case 3:
                tracker.markBookAsRead();
                break;
            case 4:
                break;
            default:
                std::cout << "Invalid Choice!";
                break;
        }
    } while(choice != 4);
    
    std::cout << "Goodbye!\n";
    return 0;
}
