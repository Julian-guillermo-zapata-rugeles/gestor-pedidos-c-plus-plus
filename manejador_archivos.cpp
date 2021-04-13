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
    *file_stream << complete_line.toStdString().c_str();
    cout << "datos escritos : "<<complete_line.toStdString().c_str()<<endl;


    if(file_stream->is_open()){
          file_stream->close();
          return true;
    }
    else{
          return false;
    }

}



QString manejador_archivos::generateTable()
{
    file_stream = new fstream();
    file_stream->open("operaciones",ios::in);
    // 7

    string line;
    string id;
    string fecha;
    string nombre;
    string producto;
    string cantidad;
    string precio;
    string descripcion;
    string tmp= "xxxx";
    QString tabla = "<center><table border=\"1\" width=\"100%\" style=\" border-color:#89a998 ;background-color:#bae5cf; border-width:2px;height:30px; \" > <tr> <th> ID </th> <th> ENTREGA </th>  <th> NOMBRE </th> <th> PRODUCTO </th> <th> CANTIDAD </th> <th> PRECIO C/U </th>  <th> TOTAL </th> </tr>";




    if(!file_stream->is_open()){
        cout << " ocurrió un error (FILE_ANALISIS) "<<endl;
    }
    else{
        do {
            *file_stream >> id >> fecha  >> nombre >> producto >> cantidad >> precio >> descripcion;

            line = "<tr><th>"
                    + id +"</th><th>"
                    +fecha +"</th><th>"
                    +nombre +"</th><th>"
                    +producto+"</th><th>"
                    +cantidad+"</th><th>"
                    +precio+"</th><th>"
                    +descripcion+"</th></tr>";
            if(tmp != id){
                tabla = tabla + QString::fromStdString(line)+"\n";
                tmp = id;
            }


        } while (!file_stream->eof());
    }
    tabla=tabla+"</table>";
    tabla=tabla.replace("_"," ");
    file_stream->close();
    return tabla;
}

