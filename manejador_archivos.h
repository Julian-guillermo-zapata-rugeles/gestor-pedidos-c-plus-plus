#ifndef MANEJADOR_ARCHIVOS_H
#define MANEJADOR_ARCHIVOS_H
#include <fstream>
#include <string>
#include <QString>
#include <iostream>


using namespace std;

class manejador_archivos
{
public:
    manejador_archivos();
    void checkFileExist();
    bool writeNewInformation(QString complete_line);
    QString generateTable();

private:
    fstream *file_stream;

};

#endif // MANEJADOR_ARCHIVOS_H
