#include <iostream>
#include <fstream>
#include <chrono>

#define PATH "file.txt"

enum errors{
    WRITE_OK = 0,
    READ_OK,
    CLEAR_OK,
    OPEN_FILE_ERRROR,
};

class File
{
    private:
        std::string path;
    public:
        /**
         * Zapisuje wyniki do pliku.
         * @param path Ścieżka do pliku.
         * @param result Wskaznik do zmiennej z wynikiem obliczeń.
         * @param text Tekst opisujący wynik.
         * @return OPEN_FILE_ERROR Błąd podczas otwierania pliku.
         * @return WRITE_OK jeśli pomyślnie zapisano dane do pliku.
        */
        errors writeToFile(std::string path, float* result, std::string text);

        /**
         * Odczytuje dane zapisane w pliku a następnie wyświetla je na ekranie terminala.
         * @param path Ścieżka do pliku.
         * @return OPEN_FILE_ERROR Błąd podczas otwierania pliku.
         * @return READ_OK Plik został odzczytany.
        */
        errors readFromFile(std::string path);

        /**
         * Czyśći zawartość pliku.
         * @param path Ścieżka do pliku.
         * @return OPEN_FILE_ERROR Błąd podczas otwierania pliku.
         * @return CLEAR_OK Plik został wyczyszczony.
        */
        errors clearFile(std::string path);
};