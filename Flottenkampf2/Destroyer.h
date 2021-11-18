#ifndef DESTROYER_H
#define DESTROYER_H

#include "Ship.h"


class Destroyer : public Ship
{
    public:
        Destroyer();
        void Attack(Ship* fleet2[], int j);
};


#endif // DESTROYER_H
