// oop-lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <optional>
#include <utility>
#include <vector>

using namespace std;

class Book{
private:q
    std::string title;
public:
    Book Rename(std::string new_title)
    {
        this->title = std::move(new_title);
        return *this;
    }
    std::string CurrentTitle()
    {
        return this->title;
    }
};
class Student {
private: 
    std::string name;
    std::optional<std::vector<Book>>  library;
public:
    void NameStudent(std::string new_name)
    {
        this->name = std::move(new_name);
    }
    void GetBook(const Book &book)
    {
        this->library->push_back(book);
    }
    Book ReturnBook()
    {
        Book returned_to_library = this->library->back();
        this->library->pop_back();
        return returned_to_library;
    }
};

int main()
{
    Student put_student;
    put_student.NameStudent("Jagoda");
    Book book;
    Book newBook = book.Rename("Twilight");
    put_student.GetBook(newBook);
    Book read_book = put_student.ReturnBook();
    std::cout << read_book.CurrentTitle();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
