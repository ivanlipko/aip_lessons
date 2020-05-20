#include <iostream>

using namespace std;

struct Fish{
    float weight;
    int type;
} fish;

int main()
{
    short int num;
    short int * pnum;  // имя "pnum" это мнемоника Pointer to NUMber

    cout << "Пример с указателями. Введите число: ";
    cin >> num;
    cout << "num (" << &num << ") = " << num << endl;

    cout << "pnum (" << pnum << ") = " << *pnum << endl;
    pnum = &num;
    cout << "pnum (" << pnum << ") = " << *pnum << endl;

    // изменяем значение по указателю
    *pnum = num + 10;
    cout << "pnum (" << pnum << ") = " << *pnum << endl;
    cout << "num (" << &num << ") = " << num << endl;

    cout << endl;

    // вводим новую переменную и меням адрес указателя
    short int num2 = 345;
    pnum = &num2;
    cout << "num2 (" << &num2 << ") = " << num2 << endl;
    cout << "pnum (" << pnum << ") = " << *pnum << endl;

    cout << endl;

    // аналогично для структур
    fish.type = 1;
    fish.weight = 20;

    cout << &fish << " (" << fish.type << "," << fish.weight << ")" << endl;

    Fish *pfish = &fish;
    cout << pfish << " (" << pfish->type << "," << pfish->weight << ")" << endl;

    return 0;
}
