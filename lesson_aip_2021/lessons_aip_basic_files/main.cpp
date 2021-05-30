/*

#include <iostream>
#include <iomanip>  // чтобы работал precision
#include <math.h>  // функции модуля числа, синуса, косинуса и прочее здесь

int main()
{
    float dx, xs, xf;
    const float eps = 0.000001;  // всё, что меньше этого числа считаем нулём

    std::cout << "Enter [xs, sf]: ";
    std::cin >> xs >> xf;

    std::cout << "Enter dx: ";
    std::cin >> dx;

    // заголовок таблицы
    std::cout << "\tx\t\ty" << std::endl;

    std::cout.precision(5);
    float f;
    float x = xs;  // начинаем считать с левого края интервала
    while (x < xf){
        if(fabs(x - 2) < eps)
            std::cout << "\t"
                      << x
                      << "\t\t Divide on zero"
                      << std::endl;
        else {
            f = (x + 1)*(x + 1) + 3/(x - 2);

            std::cout << "\t"
                      << x
                      << "\t\t"
                      << f
                      << std::endl;
        }
        x += dx;
    }

    return 0;
}


*/


#include <iostream>
#include <fstream>
#include <string>  // для считывания строк
//using namespace std;  // чтобы запомнить, какие команды и типы работают через std

void basicFileWrite();
void checkFileOpening();
void basicTextRead();
void basicTextRead2();
void readWriteNumbers();

int main () {

//   basicFileWrite();
   //    checkFileOpening();
   //    basicTextRead();
//   basicTextRead2();

    readWriteNumbers();

   return 0;
}


/**
* Basic file operations.
*
* This code creates a file called example.txt and inserts a sentence into it in
* the same way we are used to do with cout, but using the file stream myfile
* instead.
*/
void basicFileWrite(){
   std::ofstream outFile;
   outFile.open("example.txt");
   outFile << "A string writed in a file.\n";
   outFile << "Строка на русском в файле.\n";
   outFile.close();

   outFile.open("example.txt", std::ios::app);
   outFile << "Add new string.\n";
   outFile << "Ещё одна строка на русском в файле.\n";
   outFile.close();
}

/**
* @brief checkFileOpening
* Базовая проверка открытия файла.
*/
void checkFileOpening(){
   std::ofstream f;
   f.open("example.txt");

   if(!f.is_open()){  // если файл не открыт
       std::cout << "Error. Unable to open file!";
       return;
   }

   int n1=3, n2=2;
   f << "A number is " << 1 + 2 << std::endl;
   f << "Числа на русском " << (float)n1/n2 << " " << n1 - n2;

   f.close();
}

/**
* @brief basicTextRead
*Построчное считывание содержимого файла. Разделителем строк являются символы перевода строки (по ASCII для Unix “0A” он же \n, и для Windows “0A0D” они же  \r\n)
*/
void basicTextRead() {
   std::string line;
   std::fstream f("example.txt", std::ios::in);

   if (f.is_open())  {
       while ( std::getline(f,line) ){
           std::cout << line << '\n';
       }
       f.close();
   }
   else
       std::cout << "Unable to open file";
}

/**
* @brief basicTextRead2
* Считываем файл поточными способами (>>). При этом считываем по словам.
* Разделителем между словами является пробел.
*/
void basicTextRead2() {
   std::string word;
   std::fstream f("example.txt", std::ios::in);

   if (f.is_open())  {
       std::cout << "File started \n -------------------- \n";
       while ( !f.eof() ){
           f >> word;
           std::cout << word << '\n';
       }
       f.close();
       std::cout << "\n -------------------- \n File end \n";
   }
   else
       std::cout << "Unable to open file";
}

/**
 * @brief readWriteNumbers
 * Пример записи переменных в файл и считывания их из файла.
 */
void readWriteNumbers(){
    int num1 = 14678;
    float num2 = 15.3786;

    std::fstream f("example.txt", std::ios::out); // открываем для записи
    f << num1 << num2;
    f.close();

    // для чистоты эксперимента -- обнуляем переменные
    num1 = 0;
    num2 = 0;

    f.open("example.txt", std::ios::in); // открываем для чтения
    f >> num1 >> num2;
    f.close();

    std::cout << num1 << " " << num2 << std::endl;

    // В результате получаем числа 1467815 и 0.3786  что является ошибочным.
    // Подумайте почему?

    // Теперь пишем числа через пробел
    num1 = 14678;
    num2 = 15.3786;

    f.open("example.txt", std::ios::out); // открываем для записи
    f << num1 << " " << num2;
    f.close();

    f.open("example.txt", std::ios::in); // открываем для чтения
    f >> num1 >> num2;
    f.close();

    std::cout << num1 << " " << num2 << std::endl;
}
