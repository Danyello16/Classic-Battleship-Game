#ifndef CRUISER_H
#define CRUISER_H

#include "Ship.h"


class Cruiser : public Ship
{
    public:
        Cruiser();
        void Attack(Ship* fleet2[], int j);
};

#endif // CRUISER_H
