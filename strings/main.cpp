#include <iostream>
#include <string>

using namespace std;

void menuCompare(){
    string base;
    string substr;

    cout << "\nCompare submenu:\n";
    cout << "Write base string: ";
    cin >> base;
    cout << "Write substring : ";
    cin >> substr;

    cout << "base.compare(substr) is " << base.compare(substr) << endl;
}

void menuFind(){
    string base;
    string substr;
    int spos;

    cout << "\nFind submenu:\n";
    cout << "Write base string: ";
    cin >> base;
    cout << "Write substring which need to find: ";
    cin >> substr;
    cout << "Write starting position: ";
    cin >> spos;

    cout << "base.find(substr) is " << base.find(substr, spos) << endl;
}

void menuAppend(){
    string base;
    string substr;

    cout << "\nAppend submenu:\n";
    cout << "Write base string: ";
    cin >> base;
    cout << "Write substring which need to append: ";
    cin >> substr;

    cout << "base is " << base.append(substr) << endl;
}

void menuReplace(){
    string base;
    string substr;
    int pos;

    cout << "\nReplace submenu:\n";
    cout << "Write base string: ";
    cin >> base;
    cout << "What to replace: ";
    cin >> substr;
    cout << "Pos where replace: ";
    cin >> pos;

    cout << "base is " << base.replace(pos, substr.length(), substr) << endl;
}

void menuSubstr(){
    string base;
    int spos, len;

    cout << "\nSubstr submenu:\n";
    cout << "Write base string: ";
    cin >> base;
    cout << "Start position: ";
    cin >> spos;
    cout << "Length: ";
    cin >> len;

    string substr = base.substr(spos, len);
    cout << "Sub string is " << substr << endl;
}

/**
 * @brief getUniqueSymbols
 * Возвращает уникальные символы из строки.
 * @return
 *
 * Задача: Оставить в строке только один экземпляр каждого встречающегося символа.
 * Решение: простое и понятное (не самое быстрое).
 *      1. Берём очередной символ из in в c.
 *      2. Если c нет в out, то добавить в out.
 *
 */
string getUniqueSymbols(const string in){
    string out;
    char c;

    for(unsigned int i = 0; i<in.length(); i++){
        c = in[i];
        if(out.find(c) == out.npos)
            out.append(&c,1);
    }

    return out;
}
/**
 * @brief reverse
 * @param in - string
 * @return out  - string reversed of in
 *
 * Задача
 *  Перевернуть строку, т.е. последние символы должны стать первыми, а первые последними.
 *
 * Алгоритм решения задачи:
 *  1. Найти середину строки.
 *  2. Перебрать символы строки от начала до ее середины:
 *      а. очередной символ сохранить в переменной c;
 *      б. а на его место записать противоположный с конца;
 *      в. на место противоположного записать сохраненный в c.
 *
 */
string reverse(string in){
    string out;
/* // Количество итераций = in.length()
   // дополнительная память под выходную переменную
    for(unsigned int i=0; i<in.length(); i++)
        out.append(&in.at(in.length()-i-1),1);
*/

    // Количество итераций = in.length() / 2
    // дополнительная память int+char
    int n = in.length() / 2;
    char c;
    for(int i=0; i<n; i++){
        c = in[i];
        in[i] = in[in.length()-i-1];
        in[in.length()-i-1] = c;
    }
    out = in;

    return out;
}

/**
 * @brief freqof
 * @param c  - char
 * @param in - string
 * @return  frequency of occurance c in in
 */
int freqof(char c, string in){
    unsigned int s = 0;
    for(unsigned int i=0; i<in.length(); i++)
//         if(in.at(i) == c)   // метод at() проверяет выход за границы строки
        if(in[i] == c)         // метод [] не проверяет границы
            s++;
    return s;
}

/**
 * @brief diagCout
 * @param in
 * Задача
 *    Вывести на экране строку, введенную пользователем, по диагонали.
 * Прямой способ решения.
 */
void diagCout(string in){
    for(unsigned int i=0; i<in.length(); i++){
        for(unsigned int j=0; j<i; j++)
            cout << " ";
        cout << in[i] << endl;
    }
}

void demo(){
    string s1 = "abcdef";
    string s2 = "ghjk";

    cout << "Your string: ";
    cin >> s1;
    cout << s1 << endl;

    cout << s1.length() << " " << s1.size() << endl;
    cout << s2.empty() << " " << s2.capacity() << endl;
    cout << s2.max_size() << endl;

    string s3 = s1 + s2;
    bool equal = s1 == s2;

    cout << "s1 + s2 = " << s3 << endl;
    cout << equal << endl;

    // Вставить в заданную позицию строки другую строку.
    short int pos = 3;
    s3 = s1.insert(pos,s2);
    cout << "s1.insert(pos,s2) = " << s3 << endl;

    cout << "Write your char: ";
    char c;
    cin >> c;
    cout << "freqof('a') = " << freqof('a', s1);
}


int main()
{
    diagCout("Hi coder!");
    cout << "Write <exit> to close app" << endl;

    string inp = "";
    string menuText = "\n------------------------------------"
                      "\nFunctions list:"
                      "\nx - exit"
                      "\n0 - demo strinig"
                      "\n1 - compare"
                      "\n2 - find"
                      "\n3 - append"
                      "\n4 - replace"
                      "\n5 - substr"
            "\n6 getUniqueSymbols"
            "\n7 reverse";

    while(inp != "exit" && inp != "x"){
        cout << menuText << "\nSelect operation: ";
        cin >> inp;

        if(inp == "0")
            demo();
        if(inp == "1")
            menuCompare();
        if(inp == "2")
            menuFind();
        if(inp == "3")
            menuAppend();
        if(inp == "4")
            menuReplace();
        if(inp == "5")
            menuSubstr();
        if(inp == "6"){
            string in;
            cin >> in;
            cout << getUniqueSymbols(in);
        }
        if(inp == "7"){
            string in;
            cin >> in;
            cout << reverse(in);
        }
    }

    return 0;
}


/*
 * Что делает эта программа?
 * Как организован переход к разным возможностям программы?
 * Как организовано взаимодействие с пользователем?
 * Чего на ваш взгляд не хватает этой программе?
 * Как её можно улучшить?
 * Какие значения возвращает compare?
 * Как эту программу превратить в текстовый квест?
*/

