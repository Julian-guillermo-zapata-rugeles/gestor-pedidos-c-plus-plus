#include "registros.h"
#include "ui_registros.h"


using namespace std;
registros::registros(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registros)
{
    ui->setupUi(this);
}

registros::~registros()
{
    delete ui;
}


void registros::on_pushButton_clicked()
{
    QString name = ui->t_name->toPlainText();
    QString information = ui->t_name->toPlainText()+";"+ui->t_producto->toPlainText()+";"+ui->t_cantidad->toPlainText()
            +";"+ui->t_precio->toPlainText()+";"+ui->t_detalles->toPlainText();
    information = information.replace(" ","_");
    //cout << information.toStdString().c_str() << endl;
    bool response=gestorArchivos.writeNewInformation(information);
    if (response==true) {
        this->close();
    }


}
