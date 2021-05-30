#include <iostream>

struct Student{
    std::string name;
    int height;
    int age;
};

void generateStudents(Student students[], int count);
void outputStudents(Student students[], int count);
int extremum(Student array[], int count);
void getSumCount(Student array[], int count, int key, int &ncount, int &sum);

int main(){
    srand(15);

    const int count = 30;
    Student students[count];

    generateStudents(students, count);
    outputStudents(students,  count);
    std::cout << "extremum is "
              << extremum(students,  count)
              << std::endl;

    int key = 17;
    int ncount = 0;
    int sum = 0;
    getSumCount(students, count, key, ncount, sum);
    float avg = (float) sum / ncount;

    std::cout << "sum is " << sum << std::endl;
    std::cout << "avg is " << avg << std::endl;
}

void generateStudents(Student students[], int count){
    for (int i=0; i<count; i++) {
        students[i].age = rand() % 25;
        students[i].height = rand() % 200;
        students[i].name = rand() % (90-65)+65;
    }
}

void outputStudents(Student students[], int count){
    for (int i=0; i<count; i++) {
        std::cout << students[i].name << " "
                  << students[i].age << " "
                  << students[i].height
                  << std::endl;
    }
}

// find max or min
int extremum(Student array[], int count){
    int m = array[0].age;
    for (int i=1; i<count; i++) {
        if(m < array[i].age){
            m = array[i].age;
        }
    }
    return m;
}

// sum heights = s0 + s1 + s2 + s3 + ...
// if AGE > KEY
void getSumCount(Student array[], int count, int key, int &ncount, int &sum){
    sum = 0;
    ncount = 0;
    for (int i=0; i<count; i++) {
        if(array[i].age > key){
            sum += array[i].height;
            ncount++;
        }
    }
}



/*
#include <iostream>
#include <ctime>
#include <cmath>

struct Point{
    float x,y;
};

float getDist(Point a, Point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main()
{
    srand(time(NULL));

    const int count = 5;
    Point points[count];

    for(int i=0; i<count; i++){
        points[i].x = rand() % 50;  // 0 ... 50-1
        points[i].y = rand() % 50;  // 0 ... 50-1
    }

    for(int i=0; i<count; i++)
        std::cout << "ages[" << i << "] = ("
                  << points[i].x << ","
                  << points[i].y << ")" << std::endl;

    Point finish = {0, 0};
    float dists[count];
    for(int i=0; i<count; i++){
//        std::cout << getDist(finish, points[i]) << std::endl;
        dists[i] = getDist(finish, points[i]);
    }

    float max = dists[0];
    for(int i=1; i<count; i++)
        if (max < dists[i]){
            max = dists[i];
        }
    std::cout << max << std::endl;

    return 0;
}

*/
