#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>
#include <vector>

#define NBOOKS 100

class Library
{
    int books_[NBOOKS];
    std::vector <int> clients_;

    int findbook(const int b);

public:
    Library();

    bool askBook(const int b);
    void getBook(const int b, const int num);
};

#endif // LIBRARY_H
