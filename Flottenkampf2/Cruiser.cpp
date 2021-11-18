#include <iostream>
#include <string>
#include "Ship.h"
#include "Hunter.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Battle.h"
using namespace std;

Cruiser::Cruiser()
{
    name = "Cruiser";
    hull = 250;
    width = 8;
    damage = 50;
    alive = true;
}


void Cruiser::Attack(Ship* fleet2[], int j){
    bool hit = true; int i = 1; int a;
    while ((i <= 3) && (hit)){
        a = rand() % 10 + 1;
        if (a >= fleet2[j]->width){ fleet2[j]->hull = fleet2[j]->hull - damage; cout << a << fleet2[j]->name << " was HIT\n";}
        else {cout << a << "Missiles missed the target"; hit = false; }
        i++;
}
    cout << endl;
}
