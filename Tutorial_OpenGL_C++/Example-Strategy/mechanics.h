#ifndef MECHANICS_H
#define MECHANICS_H

#define MAX_UNITS_COUNT 100
#define WINDOW_SIZE 1000

typedef struct {
    double x;
    double y;
    double rallyPointX;
    double rallyPointY;
    double speedModifierX = 1;
    double speedModifierY = 1;
    bool isActive = false;
    int id;
    int player;
    int hitPoints;
} Unit;

typedef struct {
    double x;
    double y;
    bool isActive = false;
    int id;
    int player;
    double rallyPointX;
    double rallyPointY;
    int progress = 0;
    int queve = 0;
    int hitPoints;
} Structure;

struct cordinates{
    int x;
    int y;
};

struct color{
    double r;
    double g;
    double b;
};

extern cordinates frame[2];
extern color Color;
extern Unit units[MAX_UNITS_COUNT];
extern Structure buildings[MAX_UNITS_COUNT];
extern int unitCount;
extern int structCount;
extern bool isSpaceArea;
extern int currentPlayer;

void addObject(int id = 0,int x = 0 , int y = 0 , bool isBuildingMode = false);
void deleteUnit();
void moveUnit();
void updateScene();
void mouseLeftButton(int x = 0, int y = 0 , bool hold = false , bool ShiftKey = false);
void mouseRightButton(int x = 0, int y = 0);

#endif // MECHANICS_H
