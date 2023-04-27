#include <iostream>
#include <cmath>
#include <cctype>

class Oblicz
{
private:
    float r;

public:
    /**
     * Oblicza i wyświetla obwód koła.
    */
    void obwod();

    /**
     * Oblicza i wyświetla pole koła.
    */
    void pole();

    /**
     * Konstruktor.
     * @param _r Promień koła.
    */
    Oblicz(float _r);
};