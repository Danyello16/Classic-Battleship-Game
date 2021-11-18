#ifndef JAGER_H
#define JAGER_H

#include "Ship.h"

class Hunter : public Ship
{
    public:
        Hunter();
        void Attack(Ship* fleet2[], int j);
};

#endif // JAGER_H
