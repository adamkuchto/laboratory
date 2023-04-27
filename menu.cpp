#include "menu.hpp"

using namespace std;

void menu(short *input)
{
    cout << endl
         << "\033[1;32mCo mam obliczyć?\033[0m\n";
    cout << "\t1. Pole koła" << endl;
    cout << "\t2. Obwód koła" << endl;
    cout << "\t3. Pole oraz obwód koła" << endl;
    cout << "\t4. Wyświetl zawartość pliku" << endl;
    cout << "\t5. Wyczyść zawartość pliku" << endl;
    cout << "\t6. Wyjdź" << endl;
    cin >> *input;
    if (*input < 1 || *input > MENU_SIZE)
    {
        cin.clear();
        cin.ignore();
        cout << "\033[1;31mBłąd, spróbuj jescze raz \033[0m" << endl;
        menu(input);
    }
}

void getValue(float *r)
{
    cout << "\033[1;32mPodaj promień koła \033[0m" << endl;
    cin.precision(3);
    cin >> *r;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "\033[1;31mBłąd, podano nieprawidłowe dane.\033[0m" << endl;
        getValue(r);
    }
}