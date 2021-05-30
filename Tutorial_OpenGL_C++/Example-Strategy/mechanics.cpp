#include <mechanics.h>
#include <draw.h>
#include <stdlib.h>
#include <math.h>

cordinates frame[2];
color Color;
Unit units[MAX_UNITS_COUNT];
Structure buildings[MAX_UNITS_COUNT];
int unitCount = 0;
int structCount = 0;
bool isSpaceArea;

void addObject(int id , int x, int y ,  bool isBuildingMode)
{
    if(!isBuildingMode) //Создание юнита
    {
        for(int i = 0; i < structCount;i++)
        {
            if (buildings[i].isActive)
            {
                buildings[i].queve++;
            }
        }
    }
    else  //Создание постройки
    {
        isSpaceArea = true;
        for(int j = 0;j<unitCount;j++)
        {
            if(x > units[j].x * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 - 50) && x < units[j].x * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 + 50) && y > -units[j].y * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 - 50) && y < -units[j].y * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 + 50))
            {
                isSpaceArea = false;
                break;
            }
        }
        for(int j = 0;j<structCount;j++)
        {
            if(x > buildings[j].x * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 - 100) && x < buildings[j].x * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 + 100) && y > -buildings[j].y * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 - 100) && y < -buildings[j].y * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 + 100))
            {
                isSpaceArea = false;
                break;
            }
        }
        if (isSpaceArea)
        {
            structCount++ ;
            buildings[structCount-1].player = currentPlayer;
            buildings[structCount-1].id = id;
            buildings[structCount-1].hitPoints = 1000;
            buildings[structCount-1].x = (double)(x - WINDOW_SIZE / 2) / (WINDOW_SIZE / 2);
            buildings[structCount-1].y = -(double)(y - WINDOW_SIZE / 2) / (WINDOW_SIZE / 2);
            buildings[structCount-1].rallyPointX = (double)(x - WINDOW_SIZE / 2) / (WINDOW_SIZE / 2);
            buildings[structCount-1].rallyPointY = -(double)(y - WINDOW_SIZE / 2) / (WINDOW_SIZE / 2) - 0.2;
            isBuildingMode = false;
        }
    }
}

void deleteUnit()
{
    for (int i = 0;i < unitCount;i++) //Удаление выделенного юнита
    {
         if(units[i].isActive)
         {
             for(int j = i;j < unitCount;j++)
             {
                 units[j].hitPoints = units[j+1].hitPoints;
                 units[j].x = units[j+1].x;
                 units[j].y = units[j+1].y;
                 units[j].isActive = units[j+1].isActive;
                 units[j].id = units[j+1].id;
                 units[j].rallyPointX = units[j+1].rallyPointX;
                 units[j].rallyPointY = units[j+1].rallyPointY;
                 units[j].speedModifierX = units[j+1].speedModifierX;
                 units[j].speedModifierY = units[j+1].speedModifierY;
             }
             unitCount--;
             break;
         }
    }
    for (int i = 0;i < structCount;i++) //Удаление выделенной постройки
    {
        if(buildings[i].isActive)
        {
            for(int j = i; j < structCount; j++)
            {
                buildings[j].queve = buildings[j+1].queve;
                buildings[j].progress = buildings[j+1].progress;
                buildings[j].player = buildings[j+1].player;
                buildings[j].hitPoints = buildings[j+1].hitPoints;
                buildings[j].x = buildings[j+1].x;
                buildings[j].y = buildings[j+1].y;
                buildings[j].isActive = buildings[j+1].isActive;
                buildings[j].id = buildings[j+1].id;
            }
            structCount--;
            break;
        }
    }
}

void moveUnit()
{
    for(int i = 0;i < unitCount; i++) //Движение юнитов
    {
        if(units[i].x < units[i].rallyPointX) //вправо
        {
            isSpaceArea = true;
            for(int j=0;j<structCount;j++)
                if(units[i].x + 0.002 * units[i].speedModifierX < buildings[j].x && units[i].x + 0.002 * units[i].speedModifierX + .15  > buildings[j].x && units[i].y + .15 > buildings[j].y && units[i].y - .15 < buildings[j].y)
                {
                    isSpaceArea = false;
                    if (buildings[j].player != units[i].player)
                    {
                       buildings[j].hitPoints = buildings[j].hitPoints - 5;
                    }
                    break;
                }
            for(int j=0;j<unitCount;j++)
            if(j!=i && units[i].x + 0.002 * units[i].speedModifierX < units[j].x && units[i].x + 0.002 * units[i].speedModifierX + .1  > units[j].x && units[i].y + .1 > units[j].y && units[i].y - .1 < units[j].y)
            {
                isSpaceArea = false;
                if (units[j].player == units[i].player)
                {
                    units[j].rallyPointX = units[j].rallyPointX + 0.002 ;
                }
                else
                {
                    units[j].hitPoints = units[j].hitPoints - 5;
                }
                //units[j].x = units[j].x + 0.004 ;
                break;
            }
            if(isSpaceArea)
            units[i].x = units[i].x + 0.002 * units[i].speedModifierX;
        }

        if(units[i].x > units[i].rallyPointX) //влево
        {
            isSpaceArea = true;
            for(int j=0;j<structCount;j++)
                if(units[i].x - 0.002 * units[i].speedModifierX > buildings[j].x && units[i].x - 0.002 * units[i].speedModifierX - .15  < buildings[j].x && units[i].y + .15 > buildings[j].y && units[i].y - .15 < buildings[j].y)
                {
                    isSpaceArea = false;
                    if (buildings[j].player != units[i].player)
                    {
                       buildings[j].hitPoints = buildings[j].hitPoints - 5;
                    }
                    break;
                }
            for(int j=0;j<unitCount;j++)
            if(j!=i && units[i].x - 0.002 * units[i].speedModifierX > units[j].x && units[i].x - 0.002 * units[i].speedModifierX - .1  < units[j].x && units[i].y + .1 > units[j].y && units[i].y - .1 < units[j].y)
            {
                isSpaceArea = false;
                if (units[j].player == units[i].player)
                {
                    units[j].rallyPointX = units[j].rallyPointX - 0.002 ;
                }
                else
                {
                    units[j].hitPoints = units[j].hitPoints - 5;
                }

                //units[j].x = units[j].x - 0.004 ;
                break;
            }
            if(isSpaceArea)
            units[i].x = units[i].x - 0.002 * units[i].speedModifierX;
        }

        if(units[i].y > units[i].rallyPointY) //вниз
        {
            isSpaceArea = true;
            for(int j=0;j<structCount;j++)
                if(units[i].y - 0.002 * units[i].speedModifierY > buildings[j].y && units[i].y - 0.002 * units[i].speedModifierY - .15  < buildings[j].y && units[i].x + .15 > buildings[j].x && units[i].x - .15 < buildings[j].x)
                {
                   isSpaceArea = false;
                   if (buildings[j].player != units[i].player)
                   {
                      buildings[j].hitPoints = buildings[j].hitPoints - 5;
                   }
                   break;
                }
            for(int j=0;j<unitCount;j++)
            if(j!=i && units[i].y - 0.002 * units[i].speedModifierY > units[j].y && units[i].y - 0.002 * units[i].speedModifierY - .1  < units[j].y && units[i].x + .1 > units[j].x && units[i].x - .1 < units[j].x)
            {
                isSpaceArea = false;
                if (units[j].player == units[i].player)
                {
                    units[j].rallyPointY = units[j].rallyPointY - 0.002 ;
                }
                else
                {
                    units[j].hitPoints = units[j].hitPoints - 5;
                }
                //units[j].y = units[j].y - 0.004 ;
                break;
            }
            if(isSpaceArea)
            units[i].y = units[i].y - 0.002 * units[i].speedModifierY;
        }

        if(units[i].y < units[i].rallyPointY)  //вверх
        {
            isSpaceArea = true;
            for(int j=0;j<structCount;j++)
                if(units[i].y + 0.002 * units[i].speedModifierY < buildings[j].y && units[i].y + 0.002 * units[i].speedModifierY + .15  > buildings[j].y && units[i].x + .15 > buildings[j].x && units[i].x - .15 < buildings[j].x)
                {
                    isSpaceArea = false;
                    if (buildings[j].player != units[i].player)
                    {
                       buildings[j].hitPoints = buildings[j].hitPoints - 5;
                    }
                    break;
                }
            for(int j=0;j<unitCount;j++)
            if(j!=i && units[i].y + 0.002 * units[i].speedModifierY < units[j].y && units[i].y + 0.002 * units[i].speedModifierY + .1  > units[j].y && units[i].x + .1 > units[j].x && units[i].x - .1 < units[j].x)
            {
                isSpaceArea = false;
                units[j].rallyPointY = units[j].rallyPointY + 0.002 ;
                if (units[j].player == units[i].player)
                {
                    units[j].rallyPointY = units[j].rallyPointY + 0.002 ;
                }
                else
                {
                    units[j].hitPoints = units[j].hitPoints - 5;
                }
                //units[j].y = units[j].y + 0.004 ;
                break;
            }
            if(isSpaceArea)
            units[i].y = units[i].y + 0.002 * units[i].speedModifierY;
        }
    }
}

void objectFight()
{
    for (int i = 0; i < structCount; i++)
    {
        if(buildings[i].hitPoints < 1)
        {
            for(int j = i; j < structCount; j++)
            {
                buildings[j].hitPoints = buildings[j+1].hitPoints;
                buildings[j].queve = buildings[j+1].queve;
                buildings[j].progress = buildings[j+1].progress;
                buildings[j].player = buildings[j+1].player;
                buildings[j].hitPoints = buildings[j+1].hitPoints;
                buildings[j].x = buildings[j+1].x;
                buildings[j].y = buildings[j+1].y;
                buildings[j].isActive = buildings[j+1].isActive;
                buildings[j].id = buildings[j+1].id;
            }
            structCount--;
            break;
        }
    }

    for (int i = 0; i < unitCount; i++)
    {
        if(units[i].hitPoints < 1)
        {
            for(int j = i; j < unitCount; j++)
            {
                units[j].hitPoints = units[j+1].hitPoints;
                units[j].player = units[j+1].player;
                units[j].x = units[j+1].x;
                units[j].y = units[j+1].y;
                units[j].isActive = units[j+1].isActive;
                units[j].id = units[j+1].id;
                units[j].rallyPointX = units[j+1].rallyPointX;
                units[j].rallyPointY = units[j+1].rallyPointY;
                units[j].speedModifierX = units[j+1].speedModifierX;
                units[j].speedModifierY = units[j+1].speedModifierY;
            }
            unitCount--;
            break;
        }
    }
}

void creatingProgress()
{
    for(int i = 0; i < structCount;i++)
    {
        if(buildings[i].queve > 0)
        {
            if (buildings[i].progress < 100) buildings[i].progress++;
            if (buildings[i].progress == 100)
            {
                buildings[i].queve--;
                buildings[i].progress = 0;

                if (unitCount <= MAX_UNITS_COUNT)
                {
                    unitCount++ ;
                    units[unitCount-1].player = buildings[i].player;
                    units[unitCount-1].hitPoints = 100;
                    units[unitCount-1].id = buildings[i].id;
                    units[unitCount-1].x = buildings[i].x;
                    units[unitCount-1].y = buildings[i].y - 0.2;
                    units[unitCount-1].rallyPointX = buildings[i].rallyPointX;
                    units[unitCount-1].rallyPointY = buildings[i].rallyPointY;

                    if (fabs(units[unitCount-1].rallyPointY - units[unitCount-1].y) < fabs(units[unitCount-1].rallyPointX - units[unitCount-1].x))
                         units[unitCount-1].speedModifierY = fabs(units[unitCount-1].rallyPointY - units[unitCount-1].y) / fabs(units[unitCount-1].rallyPointX - units[unitCount-1].x);
                    if (fabs(units[unitCount-1].rallyPointY - units[unitCount-1].y) > fabs(units[unitCount-1].rallyPointX - units[unitCount-1].x))
                         units[unitCount-1].speedModifierX = fabs(units[unitCount-1].rallyPointX - units[unitCount-1].x) / fabs(units[unitCount-1].rallyPointY - units[unitCount-1].y);
                }
            }
        }
    }
}

void updateScene()
{
    objectFight();
    creatingProgress();
    moveUnit();
}

void mouseLeftButton(int x , int y, bool hold, bool ShiftKey)
{
    if(hold)
    {
        frame[0].x = x;
        frame[0].y = y;
    }
        frame[1].x = x;
        frame[1].y = y;

    if (!ShiftKey)
    {
        for (int j = 0; j<structCount; j++) buildings[j].isActive = false;
        for (int j = 0; j<unitCount; j++) units[j].isActive = false;
    }
    if(frame[0].x > frame[1].x && frame[0].y > frame[1].y)
    {
        for(int i = 0; i<structCount ; i++)  //ВЫДЕЛЕНИЕ ПОСТРОЙКИ
            if (frame[0].x > buildings[i].x * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 - 50) && frame[1].x < buildings[i].x * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 + 50) && frame[0].y > -buildings[i].y * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 - 50) && frame[1].y < -buildings[i].y * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 + 50))
            {
                buildings[i].isActive = true;
            }
        for (int i = 0;i < unitCount;i++)  //ВЫДЕЛЕНИЕ ЮНИТА
            if (frame[0].x > units[i].x * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 - 25) && frame[1].x < units[i].x * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 + 25) && frame[0].y > -units[i].y * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 - 25) && frame[1].y < -units[i].y * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 + 25))
            {
                units[i].isActive = true;
            }
    }
    if(frame[0].x < frame[1].x && frame[0].y > frame[1].y)
    {
        for(int i = 0; i<structCount ; i++)  //ВЫДЕЛЕНИЕ ПОСТРОЙКИ
            if (frame[0].x < buildings[i].x * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 - 50) && frame[1].x > buildings[i].x * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 + 50) && frame[0].y > -buildings[i].y * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 - 50) && frame[1].y < -buildings[i].y * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 + 50))
            {
                buildings[i].isActive = true;
            }
        for (int i = 0;i < unitCount;i++)  //ВЫДЕЛЕНИЕ ЮНИТА
            if (frame[0].x < units[i].x * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 - 25) && frame[1].x > units[i].x * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 + 25) && frame[0].y > -units[i].y * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 - 25) && frame[1].y < -units[i].y * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 + 25))
            {
                units[i].isActive = true;
            }
    }
    if(frame[0].x < frame[1].x && frame[0].y < frame[1].y)
    {
        for(int i = 0; i<structCount ; i++)  //ВЫДЕЛЕНИЕ ПОСТРОЙКИ
            if (frame[0].x < buildings[i].x * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 - 50) && frame[1].x > buildings[i].x * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 + 50) && frame[0].y < -buildings[i].y * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 - 50) && frame[1].y > -buildings[i].y * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 + 50))
            {
                buildings[i].isActive = true;
            }
        for (int i = 0;i < unitCount;i++)  //ВЫДЕЛЕНИЕ ЮНИТА
            if (frame[0].x < units[i].x * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 - 25) && frame[1].x > units[i].x * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 + 25) && frame[0].y < -units[i].y * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 - 25) && frame[1].y > -units[i].y * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 + 25))
            {
                units[i].isActive = true;
            }
    }
    if(frame[0].x > frame[1].x && frame[0].y < frame[1].y)
    {
        for(int i = 0; i<structCount ; i++)  //ВЫДЕЛЕНИЕ ПОСТРОЙКИ
            if (frame[0].x > buildings[i].x * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 - 50) && frame[1].x < buildings[i].x * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 + 50) && frame[0].y < -buildings[i].y * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 - 50) && frame[1].y > -buildings[i].y * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 + 50))
            {
                buildings[i].isActive = true;
            }
        for (int i = 0;i < unitCount;i++)  //ВЫДЕЛЕНИЕ ЮНИТА
            if (frame[0].x > units[i].x * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 - 25) && frame[1].x < units[i].x * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 + 25) && frame[0].y < -units[i].y * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 - 25) && frame[1].y > -units[i].y * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 + 25))
            {
                units[i].isActive = true;
            }
    }
    for(int i = 0; i<structCount ; i++)  //ВЫДЕЛЕНИЕ ПОСТРОЙКИ
        if (x > buildings[i].x * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 - 50) && x < buildings[i].x * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 + 50) && y > -buildings[i].y * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 - 50) && y < -buildings[i].y * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 + 50))
        {
            buildings[i].isActive = true;
            break;
        }
    for (int i = 0;i < unitCount;i++)  //ВЫДЕЛЕНИЕ ЮНИТА
        if (x > units[i].x * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 - 25) && x < units[i].x * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 + 25) && y > -units[i].y * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 - 25) && y < -units[i].y * WINDOW_SIZE / 2 + (WINDOW_SIZE / 2 + 25))
        {
            units[i].isActive = true;
            break;
        }
}

void mouseRightButton(int x , int y)
{
    for(int i = 0; i < structCount ; i++)
    {
        if (buildings[i].isActive)  //раллипоинты построек
        {
                buildings[i].rallyPointX =  (double)(x - WINDOW_SIZE / 2) / (WINDOW_SIZE / 2);
                buildings[i].rallyPointY =  -(double)(y - WINDOW_SIZE / 2) / (WINDOW_SIZE / 2);
        }
    }
    for(int i = 0; i < unitCount ; i++)
    {
        if (units[i].isActive)  //ПЕРЕМЕЩЕНИЕ ЮНИТА
        {
                units[i].speedModifierX = 1;
                units[i].speedModifierY = 1;
                units[i].rallyPointX =  (double)(x - WINDOW_SIZE / 2) / (WINDOW_SIZE / 2);
                units[i].rallyPointY =  -(double)(y - WINDOW_SIZE / 2) / (WINDOW_SIZE / 2);
                if (fabs(units[i].rallyPointY - units[i].y) < fabs(units[i].rallyPointX - units[i].x))
                     units[i].speedModifierY = fabs(units[i].rallyPointY - units[i].y) / fabs(units[i].rallyPointX - units[i].x);
                if (fabs(units[i].rallyPointY - units[i].y) > fabs(units[i].rallyPointX - units[i].x))
                     units[i].speedModifierX = fabs(units[i].rallyPointX - units[i].x) / fabs(units[i].rallyPointY - units[i].y);
        }
    }
}
