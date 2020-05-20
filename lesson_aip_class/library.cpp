#include "library.h"
#include <iostream>

Library::Library()
{
    for(int i=0; i<NBOOKS; i++)
        books_[i] = rand() % 100;
}

int Library::findbook(const int b)
{
    int count = 0;
    for(int i=0; i<NBOOKS; i++)
        if(books_[i] == b)
            count++;
    return count;  // количество книг
}

bool Library::askBook(const int b)
{
    int count = findbook(b);
    std::cout << "Мы нашли " << count << " книг\n";

    return count>0;
}

void Library::getBook(const int b, const int num)
{
    clients_.push_back(num);  // записываем пользователя, который взял книгу

    int pos = 0;
    for(int i=0; i<NBOOKS; i++)
        if(books_[i] == b){
            pos = i;
            books_[i] = -1;
            break;  // берём первую попавшуюся книгу
        }
    std::cout << "Ваша книга на " + std::to_string(pos) + " месте\n";
}


/* чем плоха функция getBook? позволяет получить книгу без проверки, а есть ли она
 * чем плоха работа с клиентами? не записываем какую книгу взяли
 * В программе не ясно, как потом возвращать книгу
*/
