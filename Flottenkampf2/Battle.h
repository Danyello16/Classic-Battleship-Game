#ifndef BATTLE_H
#define BATTLE_H
using namespace std;


class Battle
{
    public:
        Battle();
        int widthMax;
        int width;
        int n1; int n2;
        Ship* fleet1[9];
        Ship* fleet2[9];

        void IntroText();
        void ChooseText();
        void RandomSpace();
        void ChooseFleet(Ship* ship[], int &n);
        void Show(Ship* fleet1[], Ship* fleet2[], int n1, int n2);
        void Fight(Ship* fleet1[], Ship* fleet2[], int n1, int n2);
        void dead(Ship* fleet1[], int i);
        void ActualBattle(Ship* fleet1[], Ship* fleet2[], int player);
        bool FleetDead(Ship* fleet1[], int n);
        void FleetCheck(Ship* fleet1[], int n);
};

#endif // BATTLE_H
