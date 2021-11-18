#include <iostream>
#include <string>
#include "Ship.h"
#include "Hunter.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Battle.h"
using namespace std;

Hunter::Hunter()
{
    name = "Hunter";
    hull = 75;
    width = 4;
    damage = 70;
    alive = true;
}

void Hunter::Attack(Ship* fleet2[], int j){
    int a = rand() % 10 + 1;
    if (a >= 9){
        fleet2[j]->hull = fleet2[j]->hull - damage*3;
        cout << a << "CRITICA HIT on " << fleet2[j]->name << "\n\n";
        } else
    if (a >= fleet2[j]->width){
        fleet2[j]->hull = fleet2[j]->hull - damage;
        cout << a << fleet2[j]->name << " was HIT\n\n";
    } else cout << a << "Torpedo missed the target";
}
