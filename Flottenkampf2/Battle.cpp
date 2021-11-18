#include <iostream>
#include <string>
#include "Ship.h"
#include "Hunter.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Battle.h"
using namespace std;


Battle::Battle()
{
    IntroText();
    cout << "\nInsert maximum map width (Between 4 and 36)\n";
    cin >> widthMax;
    n1 =1; n2 = 2;
    ChooseText();
    ChooseFleet(fleet1, n1);
    ChooseFleet(fleet2, n2);
    Show(fleet1, fleet2, n1, n2);
    Fight(fleet1, fleet2, n1, n2);
}

void Battle::ChooseFleet(Ship* ships[], int &n){
    width = 0;
    cout << "\n*Selecting fleet " << n << "*\n\n";
    n = -1;
        while (width + 4 <= widthMax){
        int nr; cin >> nr;

            switch(nr) {
            case 1:
                            width += 4;
                            cout << "Hunter chosen" << "(Room = " << width << ")\n";
                            n++;
                            ships[n] = new Hunter;

            break;
            case 2:
                        if (width + 8 <= widthMax ){
                            width += 8;
                            cout << "Cruiser chosen" << "(Room = " << width << ")\n";
                            n++;
                            ships[n] = new Cruiser;}
                            else cout << "Not enough room for Cruiser\n";
            break;
            case 3:
                        if (width + 8 <= widthMax ){
                            width += 6;
                            cout << "Destroyer chosen" << "(Room = " << width << ")\n";
                            n++;
                            ships[n] = new Destroyer;}
                            else cout << "Not enough room for Destroyer\n";
            break;

            default:
                cout << "Input not valid";
                break;
            } }


    cout << "\nChosen ships: \n";
    for (int i = 0; i <= n; i++){
        cout << ships[i]->name << endl;
}   cout << "           Number of ships " << n + 1 << endl;
}

void Battle::IntroText(){
    cout << "Welcome to BATTLESHIP FIGHT" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
}

void Battle::ChooseText(){
    cout << "\nChoose ship" << endl;
    cout << "Press 1 to choose Hunter(4)" << endl;
    cout << "Press 2 to choose Cruiser(8)" << endl;
    cout << "Press 3 to choose Destroyer(6)" << endl;
}

void Battle::RandomSpace(){
    int a = rand() % 10;
    for (int i = 0; i < a; i++) cout << " ";
}

void Battle::dead(Ship* fleet1[], int i){
    if (fleet1[i]->hull <= 1){
        fleet1[i]->alive = false;
        cout << "SUNK";
    } else cout << fleet1[i]->hull;
}

void Battle::Show(Ship* fleet1[], Ship* fleet2[], int n1, int n2){
    cout << "\nFleet 1:                                  Fleet 2:\n\n";
    int i = 0; int j = 0;
    while ((i <= n1) && (j <= n2)){
        RandomSpace();
        cout << i << fleet1[i]->name << " ["; dead(fleet1, i); cout << "]"; i++;
        RandomSpace();
        cout << "                       " << j << fleet2[j]->name << " ["; dead(fleet2, j); cout << "]\n"; j++;
    }
    while (i <= n1){
        RandomSpace();
        cout << i << fleet1[i]->name << " ["; dead(fleet1, i); cout << "]\n"; i++;}
    while (j <= n2){
        RandomSpace();
        cout << "                                  " << j << fleet2[i]->name << " ["; dead(fleet2, j); cout << "]\n"; j++;}
}

void Battle::Fight(Ship* fleet1[], Ship* fleet2[], int n1, int n2){
    int i; int j;
    while(42){
        ActualBattle(fleet1, fleet2, 1);
        Show(fleet1, fleet2, n1, n2);
        if (FleetDead(fleet2, n2)) break;
        ActualBattle(fleet2, fleet1, 2);
        Show(fleet1, fleet2, n1, n2);
        if (FleetDead(fleet1, n1)) break;
    }
}

bool Battle::FleetDead(Ship* fleet1[], int n){
    bool aux = false;
    for (int i = 0; i <= n; i++){
        if (fleet1[i]->alive) aux = true;
    }
    if (aux) return false;
        else return true;
}

void Battle::FleetCheck(Ship* fleet1[], int n){
    if (FleetDead(fleet1, n)) cout << endl;
}

void Battle::ActualBattle(Ship* fleet1[], Ship* fleet2[], int player){
    int i; int j;
    cout << "\nAdmiral " << player << ", choose attacking ship and target";
    while (42){
        cin >> i;
        if (fleet1[i]->alive) break;
        else cout << "Invalid input";
    }
    while (42){
        cin >> j;
        if (fleet2[j]->alive) break;
        else cout << "Invalid input";
    }
    fleet1[i]->Attack(fleet2, j);
    cout << "\n\n\n";
}











