#include <iostream>

using namespace std;

void zeroMatrix(){
    const int rows = 3;
    const int cols = 10;
    int mat[rows][cols];

    for(int i = 0; i<rows; i++)  // цикл по строкам
        for(int j = 0; j<cols; j++)  // цикл по столбцам
            mat[i][j] = 0;

    for(int i = 0; i<rows; i++) {
        for(int j = 0; j<cols; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    /*
    0 0 0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0 0 0
    */
}

// Дана матрица. Составить алгоритм, находящий сумму элементов, значения которых больше 40.
void sumOver40(){
    const int rows = 5;
    const int cols = 4;
    int mat[rows][cols];

    srand(0);
    for(int i = 0; i<rows; i++)
        for(int j = 0; j<cols; j++)
            mat[i][j] = rand()%100;

    for(int i = 0; i<rows; i++) {
        for(int j = 0; j<cols; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    int sum = 0;
    for(int i = 0; i<rows; i++)
        for(int j = 0; j<cols; j++)
            if(mat[i][j] > 40)
                sum += mat[i][j];
    cout << sum << endl;
    /*
83 86 77 15
93 35 86 92
49 21 62 27
90 59 63 26
40 26 72 36
912
*/
}

/**
 * В квадратной матрице найти количество элемемнтов, лежащих на и ниже главной
 * диагонали, значения которых меньше 30
*/
void countUnderLine(){
    const int rows = 4;
    const int cols = 4;
    int mat[rows][cols];

    srand(0);
    for(int i = 0; i<rows; i++)
        for(int j = 0; j<cols; j++)
            mat[i][j] = rand() % 50;

    for(int i = 0; i<rows; i++) {
        for(int j = 0; j<cols; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    int count = 0;
    for(int i = 0; i<rows; i++)
        for(int j = 0; j<i+1; j++)
            if(mat[i][j] < 30)
                count ++;

    cout << count << endl;

    /*
33 36 27 15
43 35 36 42
49 21 12 27
40 9 13 26
5
*/
}


/**
 * Преобразовать матрицу: элементы столбца, в котором находится максимальный
 * элемент матрицы, заменить на номера строк.
 *
 * Начальное значение наибольшего элемента - первый элемент матрицы.
 * mc, mc - координаты наибольшего элемента (строка (r - row), столбец (c - column)).
*/
void editMatrix(){
    const int rows = 7;
    const int cols = 8;
    int mat[rows][cols];

    srand(0);
    for(int i = 0; i<rows; i++)
        for(int j = 0; j<cols; j++)
            mat[i][j] = rand() % 100 - 50;

    for(int i = 0; i<rows; i++) {
        for(int j = 0; j<cols; j++)
            cout << mat[i][j] << "\t";
        cout << endl;
    }

    int max = mat[0][0];
    int mr = 0, mc = 0;
    for(int i = 0; i<rows; i++)
        for(int j = 0; j<cols; j++)
            if(mat[i][j] > max){
                max = mat[i][j];
                mr = i;
                mc = j;
            }

    for(int i = 0; i<rows; i++)
        mat[i][mc] = mr;

    cout << max << " " << mr << " " << mc << endl;
    cout << endl;
    for(int i = 0; i<rows; i++) {
        for(int j = 0; j<cols; j++)
            cout << mat[i][j] << "\t";
        cout << endl;
    }

    /*
33	36	27	-35	43	-15	36	42
-1	-29	12	-23	40	9	13	-24
-10	-24	22	-14	-39	18	17	-21
32	-20	12	-27	17	-15	-21	-48
-28	8	19	17	43	6	-39	-8
-21	23	-29	-31	34	-13	48	-26
-35	20	-37	-24	41	30	6	23
48 5 6

33	36	27	-35	43	-15	5	42
-1	-29	12	-23	40	9	5	-24
-10	-24	22	-14	-39	18	5	-21
32	-20	12	-27	17	-15	5	-48
-28	8	19	17	43	6	5	-8
-21	23	-29	-31	34	-13	5	-26
-35	20	-37	-24	41	30	5	23
*/
}

/**
 * Для заданной квадратной матрицы сформировать одномерную таблицу (массив) из её
 * диагональных элементов.
*/
const int n = 4;

void getDiag(const int mat[n][n], int out[n]){
    for(int i = 0; i<n; i++)
        out[i] = mat[i][i];
}



/**
 * Умножение матрицы на число
*/
void multOn(float num, const int rows = 7, const int cols = 8){
        float mat[rows][cols];

        srand(0);
        for(int i = 0; i<rows; i++)
            for(int j = 0; j<cols; j++)
                mat[i][j] = rand() % 100 - 50;

        for(int i = 0; i<rows; i++) {
            for(int j = 0; j<cols; j++)
                cout << mat[i][j] << "\t";
            cout << endl;
        }

        for(int i = 0; i<rows; i++)
            for(int j = 0; j<cols; j++)
                mat[i][j] *= num;

        cout << endl;
        for(int i = 0; i<rows; i++) {
            for(int j = 0; j<cols; j++)
                cout << mat[i][j] << "\t";
            cout << endl;
        }

/*
33	36	27	-35
43	-15	36	42
-1	-29	12	-23
40	9	13	-24

108.9	118.8	89.1	-115.5
141.9	-49.5	118.8	138.6
-3.3	-95.7	39.6	-75.9
132	29.7	42.9	-79.2
    */
}


int main()
{
    sumOver40();
    countUnderLine();
    editMatrix();

    cout << endl;

    srand(0);
    int mat[n][n];
    int out[n];

    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            mat[i][j] = rand() % 100 - 50;

    for(int i = 0; i<n; i++)
        out[i] = 0;

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++)
            cout << mat[i][j] << "\t";
        cout << endl;
    }
    cout << endl;

    getDiag(mat, out);

    for(int i = 0; i<n; i++)
        cout << out[i] << " ";
    cout << endl;

/*
33	36	27	-35
43	-15	36	42
-1	-29	12	-23
40	9	13	-24

33 -15 12 -24
*/


    multOn(3.3, 4, 4);

    return 0;
}


