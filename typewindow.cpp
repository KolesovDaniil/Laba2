#include "typewindow.h"
#include "ui_typewindow.h"
#include <QTextStream>
#include <QString>
#include <QMessageBox>

TypeWindow::TypeWindow(QWidget *parent, Table* _table, int _row, int _column, QString _str, QTableWidgetItem* _item):
    QDialog(parent),
    ui(new Ui::TypeWindow),
    table(_table),
    row(_row), column(_column),
    str(_str), item(_item)

{
    ui->setupUi(this);
    ui->lineEdit->setText(str);
    char cellType = table->type_check(row,column);
    switch (cellType) {
    case 's':
        ui->comboBox->setCurrentIndex(0);
        break;
    case 'n':
        ui->comboBox->setCurrentIndex(1);
        break;
    case 'f':
        ui->comboBox->setCurrentIndex(2);
        break;
    }
}

TypeWindow::~TypeWindow()
{
    delete ui;
}

void TypeWindow::on_pushButton_2_clicked()
{
    QString type = ui->comboBox->currentText();
    QTextStream Qcout(stdout);
    Qcout << type;
    if(type=="Строка"){
        table->update_cell(this->row,this->column,'s',ui->lineEdit->text().toUtf8().constData());
        item->setText(ui->lineEdit->text());
        this->close();
    }
    if(type=="Число"){
        if(ui->lineEdit->text()==""){
            QMessageBox::warning(this,"Ошибка","Введите число");
        }
        else{
            table->update_cell(this->row,this->column,'n',ui->lineEdit->text().toUtf8().constData());
            item->setText(ui->lineEdit->text());
            this->close();
        }
    }
    if(type=="Функция"){
        table->update_cell(this->row,this->column,'f',ui->lineEdit->text().toUtf8().constData());
        QString str_out = QString::fromStdString(table->process(row,column));
        Qcout << str_out;
        if (str_out=="Not only num cells"){
            QMessageBox::warning(this,"Ошибка","Невозможно вычислить функцию. В диапазоне содержатся не только числовые ячейки.");
//                table->updateCell(this->row, this->column, 's', "");
//                item->setText("");

        }
        else if (str_out=="Error"){
            QMessageBox::warning(this,"Ошибка","Некорректная функция");
//                table->updateCell(this->row, this->column, 's', "");
//                item->setText("");
        }
        else {
            item->setText(str_out);
            table->update_cell(this->row, this->column, 'n', item->text().toUtf8().constData());
            this->close();
        }
    }
}

void TypeWindow::on_pushButton_clicked()
{
    this->close();
}

void TypeWindow::on_comboBox_currentIndexChanged(int index)
{
    if(index==1){
        ui->lineEdit->setValidator(new QRegExpValidator(QRegExp( "^\\d+\\.\\d+$")));
        ui->lineEdit->clear();
    }
    if(index==0){
        ui->lineEdit->setValidator(new QRegExpValidator(QRegExp( "^.+$")));
        ui->lineEdit->clear();
    }
    if(index==2){
        ui->lineEdit->setValidator(new QRegExpValidator(QRegExp( "^\\=[A-Z]{3}\\s\\d{1}\\s\\d{1}\\s\\d{1}\\s\\d{1}$"))); //написать регулярку для функции
        ui->lineEdit->clear();
    }
}
