#include "file.hpp"

using namespace std;

errors File::writeToFile(string path, float* result, string text)
{
    chrono::time_point<chrono::system_clock>actualTime;
    ofstream kolo;
    kolo.open(path, ios::app);
    if (kolo.good())
    {
        actualTime = chrono::system_clock::now();
        time_t now = chrono::system_clock::to_time_t(actualTime);
        kolo << ctime(&now);
        kolo << "\t" << text << " " << *result << endl << endl;
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