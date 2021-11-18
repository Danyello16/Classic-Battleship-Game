#include <iostream>
#include <string>
#include "Ship.h"
#include "Hunter.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Battle.h"
using namespace std;

Destroyer::Destroyer()
{
    name = "Destroyer";
    hull = 150;
    width = 6;
    damage = 60;
    alive = true;
}


void Destroyer::Attack(Ship* fleet2[], int j){

        fleet2[j]->hull = fleet2[j]->hull - damage;
        cout << fleet2[j]->name << " was HIT (A destroyer never misses)\n\n";
}
