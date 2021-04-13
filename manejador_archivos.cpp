#include "manejador_archivos.h"

manejador_archivos::manejador_archivos()
{

}

void manejador_archivos::checkFileExist()
{

    file_stream = new fstream();

    file_stream->open("operaciones",ios::in);
    if(!file_stream->is_open()){
        cout << " se agregó el archivo porque no existe "<<endl;
    }
    else{
        cout << " ya existe el archivo (se omite)  " <<endl;
    }
    file_stream->close();

}

bool manejador_archivos::writeNewInformation(QString complete_line)
{

    file_stream = new fstream();
    file_stream->open("operaciones",ios::out|ios::app);
    *file_stream << complete_line.toStdString().c_str()<<endl;
    cout << "datos escritos : "<<complete_line.toStdString().c_str()<<endl;


    if(file_stream->is_open()){
          file_stream->close();
          return true;
    }
    else{
          return false;
    }

}

