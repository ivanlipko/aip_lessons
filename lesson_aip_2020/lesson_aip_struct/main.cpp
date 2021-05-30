#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

struct Student{
    string name;
    int age;
    float mark_avg;
};

void randString(string &str){
    static const char alphabet[] =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    str = "     ";

    for(int i=0; i < str.length(); i++){
        int r = rand() % (sizeof(alphabet)-1);
        str[i] = alphabet[r];
    }
    str[str.length()] = 0;
}

void showStudent(const Student s){
    cout << s.name<< "\t"
         << s.age << "\t"
         << s.mark_avg << endl;
}

int findStudentsMark(const Student s[], const int l, const float key){
    int count = 0;
    for(int i=0; i<l; i++){
        if(s[i].age > key){
            showStudent(s[i]);
            count++;
        }
    }
    return count;
}

void bubbleSort(Student data[], int len) {
    Student tmp;
    for(int i = 0; i<len; i++){
        for(int j = len-1; j >= i+1; j--){
            if(data[j].mark_avg < data[j-1].mark_avg){
                tmp = data[j];
                data[j] = data[j-1];
                data[j-1] = tmp;
            }
        }
    }
}

void writeTextFile(const Student s[], const int l){
    ofstream f;

    f.open("data.txt");
    for(int i = 0; i < l; i++)
        f << s[i].name<< "\t"
          << s[i].age << "\t"
          << s[i].mark_avg << endl;
    f.close();
}

int main()
{
    const int len = 20;
    Student students[len];

    for(int i=0; i<len; i++){
        students[i].age = rand() % 25;
        students[i].mark_avg = 5.0* (float) rand()/RAND_MAX;
        randString(students[i].name);

        showStudent(students[i]);
    }


    float avg_mark = 15.0;
    cout << endl << "Find all who more than " << avg_mark << endl;
    int findCount = findStudentsMark(students, len, avg_mark);
    cout << "Total " << findCount << " elements" << endl;

    cout << endl << "Sorted " << endl;
    bubbleSort(students, len);

    for(int i=0; i<len; i++)
        showStudent(students[i]);


    writeTextFile(students, len);

    return 0;
}


/*

lrBbm	8	1.97191
hCDar	17	1.38887
wKkYH	13	4.58098
dqSCD	18	0.686158
JmOWF	17	1.09128
sjyBl	17	2.46792
EFSAr	21	4.45765
ynEcd	20	2.62998
gxxpk	12	0.100115
RellN	2	1.33333
apqfW	24	0.196402
OPkMC	14	3.19989
HnWnk	13	1.65169
wHsqm	10	3.28652
buqCL	19	4.55486
iVswM	1	3.2054
qtBxI	1	1.13053
VTRRb	19	0.515856
pTnsN	6	1.91594
ZqfjM	3	0.761949

Find all who more than 3
wKkYH	13	4.58098
EFSAr	21	4.45765
OPkMC	14	3.19989
wHsqm	10	3.28652
buqCL	19	4.55486
iVswM	1	3.2054


Sorted
iVswM	1	3.2054
qtBxI	1	1.13053
RellN	2	1.33333
ZqfjM	3	0.761949
pTnsN	6	1.91594
lrBbm	8	1.97191
wHsqm	10	3.28652
gxxpk	12	0.100115
wKkYH	13	4.58098
HnWnk	13	1.65169
OPkMC	14	3.19989
hCDar	17	1.38887
JmOWF	17	1.09128
sjyBl	17	2.46792
dqSCD	18	0.686158
buqCL	19	4.55486
VTRRb	19	0.515856
ynEcd	20	2.62998
EFSAr	21	4.45765
apqfW	24	0.196402


Sorted
gxxpk	12	0.100115
apqfW	24	0.196402
VTRRb	19	0.515856
dqSCD	18	0.686158
ZqfjM	3	0.761949
JmOWF	17	1.09128
qtBxI	1	1.13053
RellN	2	1.33333
hCDar	17	1.38887
HnWnk	13	1.65169
pTnsN	6	1.91594
lrBbm	8	1.97191
sjyBl	17	2.46792
ynEcd	20	2.62998
OPkMC	14	3.19989
iVswM	1	3.2054
wHsqm	10	3.28652
EFSAr	21	4.45765
buqCL	19	4.55486
wKkYH	13	4.58098


*/






