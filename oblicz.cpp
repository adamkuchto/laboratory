#include "oblicz.hpp"
#include "file.hpp"

File write;
errors error;

void Oblicz::obwod()
{
    float result = 2 * M_PI * r;
    std::cout << "Obwod koła o promieniu " << r << " wynosi: ";
    std::cout << "\033[1;35m" << result << "\033[0m" << std::endl;
    error = write.writeToFile(PATH, &result, "Obwód koła");
    if (error == OPEN_FILE_ERRROR)
        std::cout << "Błąd podczas zapisu do pliku" <<  std::endl;
    else if (error == WRITE_OK)
        std::cout << "Wynik zapisany w pliku" <<  std::endl;
    else
        std::cout << "Nieoczekiwany błąd podczas operacji na pliku" << std::endl;
}

void Oblicz::pole()
{
    float result = M_PI * r * r;
    std::cout << "Pole koła o promieniu " << r << " wynosi: ";
    std::cout << "\033[1;35m" << result << "\033[0m" << std::endl;
    error = write.writeToFile(PATH, &result, "Pole koła: ");
    if (error == OPEN_FILE_ERRROR)
        std::cout << "Błąd podczas zapisu do pliku" <<  std::endl;
    else if (error == WRITE_OK)
        std::cout << "Wynik zapisany w pliku" <<  std::endl;
    else
        std::cout << "Nieoczekiwany błąd podczas operacji na pliku" << std::endl;
}

Oblicz::Oblicz(float _r)
{
    r = _r;
}