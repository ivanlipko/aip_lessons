#include <iostream>
#include <cmath>

struct Point{
    float x, y;
};

struct Robot{
    Point pos;
    int number;
    float dist;
};

float getDist(Point a, Point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

void inputRobot(Robot &in){
    std::cout << "Enter attributes of robot." << std::endl;

    std::cout << "Number: ";
    std::cin >> in.number;

    std::cout << "Position (x,y): ";
    std::cin >> in.pos.x >> in.pos.y;
}

int main() {
    Robot car;
    Robot quad;

    inputRobot(car);
    inputRobot(quad);

    Point finish = {100, 100};

    car.dist = getDist(car.pos, finish);
    quad.dist = getDist(quad.pos, finish);

    if(car.dist < quad.dist)
        std::cout << car.number << "-car closer " << car.dist ;
    else
        std::cout << quad.number << "-quad closer "<< quad.dist ;

    std::cout << std::endl;
    return 0;
}


/*
 * #include <iostream>
#include <cmath>

struct Point{
    float x, y;
};

struct Robot{
    Point pos;
    int number;
    float dist;
};

float getDist(Point a, Point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main(){
    Robot car;
    Robot quad;

    std::cout << "Enter  position of robot #1: ";
    car.number = 1;
    std::cin >> car.pos.x >> car.pos.y;

    std::cout << "Enter  position of robot #2: ";
    quad.number = 2;
    std::cin >> quad.pos.x >> quad.pos.y;

    Point finish = {100, 100};

    car.dist = getDist(car.pos, finish);
    quad.dist = getDist(quad.pos, finish);

    if(car.dist < quad.dist)
        std::cout << "car closer";
    else
        std::cout << "quad closer";

    return 0;
}
*/

/*
// *
#include <iostream>

struct Point3d {
   int x, y, z;
   int size;
};


int main()
{
    Point3d pA = {2,2,1, 5} ;
    Point3d pB = {4,3,0, 10};  // инициализация

    std::cout << pA.x << " " << pA.y  << " " << pA.size << std::endl;
    std::cout << pB.x << " " << pB.y  << " " << pB.size << std::endl;

    if (pA.x < pB.x) {
       std::cout << "pA левее pB" << std::endl;
    }else{
        std::cout << "pA правее pB" << std::endl;
    }

    if (pA.size < pB.size) {
       std::cout << "pA меньше pB" << std::endl;
    }



    return 0;
}
*/
