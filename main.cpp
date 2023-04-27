#include "oblicz.hpp"
#include "menu.hpp"
#include "file.hpp"

using namespace std;

int main()
{
    short returnMenu = 0;
    short *ptrShort = &returnMenu;
    float r = 0;
    float *ptrFloat = &r;
    menu(ptrShort);

    if (returnMenu == MENU_SIZE)
    {
        return 0;
    }
    else if (returnMenu == 4)
    {
        File read;
        read.readFromFile(PATH);
    }
    else if (returnMenu == 5)
    {
        File clear;
        clear.clearFile(PATH);
    }
    else
    {
        getValue(ptrFloat);
        Oblicz test1(r);
        if (returnMenu == 1)
            test1.pole();
        else if (returnMenu == 2)
            test1.obwod();
        else if (returnMenu == 3)
        {
            test1.pole();
            test1.obwod();
        }
        else
            cout << "Nieoczekiwany błąd! " << endl;
    }
    ptrShort = nullptr;
    ptrFloat = nullptr;
    return 0;
}