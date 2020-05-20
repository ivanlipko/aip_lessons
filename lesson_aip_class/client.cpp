#include "client.h"

Client::Client()
{
    num_ = 3;
    book_ = 2;
}

int Client::getNum()
{
    return num_;
}

int Client::getBook()
{
    return book_;
}
