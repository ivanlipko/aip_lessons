#include <iostream>
#include "dog.h"

#include <library.h>
#include <client.h>

using namespace std;

int main()
{
    Dog sharik;

    cout << sharik.getInfo() << endl;
    sharik.bark();
    sharik.eat(1);
    cout << sharik.getInfo() << endl;

    Dog tuzik("tuzik");
    cout << "tuzik " << tuzik.getInfo() << endl;


    /* Задача с ситуацией*/
    Client cli;
    cout << "Клиент " << cli.getNum() << " хочет " << cli.getBook() << " книгу\n";

    Library lib;
    lib.askBook(cli.getBook());
    lib.getBook(cli.getBook(), cli.getNum());


    return 0;
}
