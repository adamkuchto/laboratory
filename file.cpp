#include "file.hpp"

using namespace std;

errors File::writeToFile(string path, float* result, string text)
{
    ofstream kolo;
    kolo.open(path, ios::app);
    if (kolo.good())
    {
        kolo << text << " " << *result << "\n";
    }
    else
    {
        return OPEN_FILE_ERRROR;
    }
    kolo.close();
    return WRITE_OK;
}

errors File::readFromFile(string path)
{
    ifstream read;
    string text;

    read.open(path);
    if (read.good())
    {
        while (getline(read, text))
        {
            cout << text << endl;
        }
    }
    else
    {
        return OPEN_FILE_ERRROR;
    }
    read.close();
    return READ_OK;
}

errors File::clearFile(string path)
{
    ofstream clear;
    clear.open(path, ofstream::out | ofstream::trunc);
    if (clear.good())
        cout << "Zawartość pliku " << path << " została wyczyszczona." << endl;
    else
        return OPEN_FILE_ERRROR;

    clear.close();
    return CLEAR_OK;
}