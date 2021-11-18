#ifndef SHIP_H
#define SHIP_H
using namespace std;


class Ship
{
    public:
        Ship();
        string name;
        int hull;
        int width;
        int damage;
        bool alive;
        virtual void Attack(Ship* fleet2[], int j);
};

#endif // SHIP_H
