/*
 * Работа с файлами.
 * Инициализируем массив структур и сохраняем в файл.
 * Записываем нвоые данные и считываем старые.
 * Убеждаемся, что данные из файла считаны корректно.
*/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
const int string_len = 3;

struct Address{
    string street;
    int build;
    int room;
};

struct Student{
    string name;
    int age;
    float mark_avg;
    Address address;
};

void showStudent(const Student s){
    cout << s.name<< "\t"
         << s.age << "\t"
         << s.mark_avg << "\t\t["
         << s.address.street << ","
         << s.address.build << ","
         << s.address.room << "]" << endl;
}

void showStudents(const Student sts[], const int len){
    cout << "name \t"
         << "age \t"
         << "mark_avg \t["
         << "street,"
         << "build,"
         << "room]" << endl;

    for(int i=0; i<len; i++){
        showStudent(sts[i]);
    }

    cout << endl;
}

void randString(string &str, const int len){
    static const char alphabet[] =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // очищаем и заносим данные
    str.clear();
    str.append(len, ' ');

    for(int i=0; i < str.length(); i++){
        int r = rand() % (sizeof(alphabet)-1);
        str[i] = alphabet[r];
    }
    str[str.length()] = 0;  // последний символ сообщает о том, что строка закончилась
}

void initStudents(Student sts[], const int len){
    for(int i=0; i<len; i++){
        // Student
        sts[i].age = rand() % 25;
        sts[i].mark_avg = 5.0* (float) rand()/RAND_MAX;
        randString(sts[i].name, string_len);

        // Address
        randString(sts[i].address.street, string_len);
        sts[i].address.build = rand() % 25;
        sts[i].address.room = rand() % 50;
    }
}

void writeTextFile(const Student sts[], const int l){
    ofstream f;

    f.open("data.txt");
    for(int i = 0; i < l; i++)  // Все атрибуты struct  в одной строке
        f << sts[i].name<< " "
          << sts[i].age << " "
          << sts[i].mark_avg << " "
          << sts[i].address.street << " "
          << sts[i].address.build << " "
          << sts[i].address.room << endl;
    f.close();
}

void openTextFile(Student sts[], const int l){
    ifstream f;

    f.open("data.txt");
    for(int i = 0; i < l; i++)
        f >> sts[i].name
          >> sts[i].age
          >> sts[i].mark_avg
          >> sts[i].address.street
          >> sts[i].address.build
          >> sts[i].address.room;
    f.close();
}


void writeBinFile(Student sts[], const int l){
    // in-function WRITE code
    fstream f;
    f.open("data.bin.txt", ios::out | ios::binary);
    f.write((char*)sts, sizeof(Student)*l);
    f.close();

    /*
     * Non-function WRITE code
    //    fstream f;
    //    f.open("data.bin.txt", ios::out | ios::binary);
    //    f.write((char*)&students, sizeof(students));
    //    f.close();
    //    cout << "Размер данных:\n";
    //    cout << sizeof(Student) << endl;
    //    cout << sizeof(Student) * len << endl;
    //    cout << sizeof(students) << endl << endl;

    //    cout << sizeof(sts) << endl;
    //    cout << sizeof(sts[0]) << " " << sizeof(sts[1]) << endl;
    */
}

void openBinFile(Student sts[], const int l){
    fstream f;
    f.open("data.bin.txt", ios::in | ios::binary);
    f.read((char*)sts, sizeof(Student)*l);
    f.close();
}


int main()
{
    // init
    cout.precision(3);
    srand(5);

    const int len = 20;
    Student students[len];

    cout << "Начальный массив:\n";
    initStudents(students, len);
    writeTextFile(students, len);
    showStudents(students, 5);

    cout << "Новый массив:\n";
    initStudents(students, len);
    showStudents(students, 5);

    cout << "Считанный массив:\n";
    openTextFile(students, len);
    showStudents(students, 5);

    cout << "Бинарный файл.\n";
    writeBinFile(students, len);

    cout << "Новый массив:\n";
    initStudents(students, len);
    showStudents(students, 5);

    cout << "Считанный массив:\n";
    openBinFile(students,len);
    showStudents(students, 5);

    return 0;
}



/*
Начальный массив:
name 	age 	mark_avg 	[street,build,room]
WQS	0	0.232		[OKP,23,31]
UOE	1	1.37		[AMW,3,36]
HJV	14	2.31		[OJN,2,17]
GGV	21	3.24		[ZUH,10,15]
XHZ	3	3.14		[BJN,1,15]

Новый массив:
name 	age 	mark_avg 	[street,build,room]
WLD	20	0.863		[YOB,11,44]
TSZ	1	1.17		[XHZ,8,10]
BZY	8	2.2		[LAF,10,8]
NBX	24	4.35		[SZL,7,13]
YAV	16	3.78		[XYC,19,39]

Считанный массив:
name 	age 	mark_avg 	[street,build,room]
WQS	0	0.232		[OKP,23,31]
UOE	1	1.37		[AMW,3,36]
HJV	14	2.31		[OJN,2,17]
GGV	21	3.24		[ZUH,10,15]
XHZ	3	3.14		[BJN,1,15]

Бинарный файл.
Новый массив:
name 	age 	mark_avg 	[street,build,room]
EQC	24	3.97		[BZB,20,9]
ONK	19	1.57		[SOM,0,49]
JJF	0	0.554		[MSJ,23,32]
CGJ	0	1.21		[EIK,1,45]
SNF	22	2.37		[FFT,6,46]

Считанный массив:
name 	age 	mark_avg 	[street,build,room]
WQS	0	0.232		[OKP,23,31]
UOE	1	1.37		[AMW,3,36]
HJV	14	2.31		[OJN,2,17]
GGV	21	3.24		[ZUH,10,15]
XHZ	3	3.14		[BJN,1,15]

Press <RETURN> to close this window...

*/
