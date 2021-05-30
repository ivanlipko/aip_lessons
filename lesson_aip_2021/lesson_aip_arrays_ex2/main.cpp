#include <iostream>
#include <stdlib.h>

/*
 * Не константа, а макрокоманда: автоподстановка вместо n число 15
*/
#define n 15

/*
 * Modify array in function. Const "l" is a Length of array.
*/
void input(int arr[], const int l){
    for(int i=0; i<l; i++)
        arr[i] = rand() % 7;
}

void output(int arr[], const int l){
    for(int i=0; i<l; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

/*
 *  Поиск наибольшего элемента в массиве.
 * Используем квалификатор const чтобы сообщить о том,
 * что массив внутри функции не будет изменяться.
*/
int max(const int arr[], const int l){
    int max_number = arr[0];  // считаем что первый элемент массива - самый большой
    for(int i=1; i<l; i++)  // поиск начинаем со второго элемента
        if(max_number < arr[i])   // если нашли больше
            max_number = arr[i];  // то обновляемся
    return max_number;
}

int main()
{
    int arrA[n];
    const int m = n*2;
    int arrB[m];
    int arrC[3];

    srand(2);  // инициализация ГСЧ. Делается один раз в проге

    input(arrA, n);
    input(arrB, m);
    input(arrC, 3);

    output(arrA, n);
    output(arrB, m);
    output(arrC, 3);

    int maxA = max(arrA, n);
    int maxB = max(arrB, m);
    int maxC = max(arrC, 3);

    std::cout << maxA << std::endl
              << maxB << std::endl
              << maxC << std::endl;

    std::cin.get();
    std::cin.get();

    return 0;
}
