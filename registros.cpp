#include "registros.h"
#include "ui_registros.h"


using namespace std;
registros::registros(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registros)
{
    ui->setupUi(this);
    fecha_elejida = "N/A";
    srand(time(0));

}

registros::~registros()
{
    delete ui;
}


void registros::on_pushButton_clicked()
{
    QString id;
    id =id + ui->t_name->toPlainText().at(0);
    id =id + ui->t_name->toPlainText().at(1);
    id =id + ui->t_name->toPlainText().at(2);
    id =id + ui->t_name->toPlainText().at(3);
    short int aleatorio = 10 + rand() % 100 ;
    id = id + QString::number(aleatorio);

    QString information = id + ";" + fecha_elejida +";" + ui->t_name->toPlainText()+";"+ui->t_producto->toPlainText()+";"+ui->t_cantidad->toPlainText()
            +";"+ui->t_precio->toPlainText()+";"+ui->t_detalles->toPlainText();
    information = information.replace(" ","_");
    //cout << information.toStdString().c_str() << endl;
    bool response=gestorArchivos.writeNewInformation(information);
    if (response==true) {
        this->close();
    }


}

void registros::on_calendarWidget_clicked(const QDate &date)
{
    QString fecha = date.toString();
    cout << "fecha "<< fecha.toStdString().c_str()<< endl;
    fecha_elejida = fecha;
}
