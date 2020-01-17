#ifndef TYPEWINDOW_H
#define TYPEWINDOW_H

#include <QDialog>
#include <table.h>
#include <QAbstractButton>
#include <QTableWidgetItem>

namespace Ui {
class TypeWindow;
}

class TypeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TypeWindow(QWidget *parent = nullptr, Table* _table=nullptr,
                        int _row=0, int _column=0, QString str = "", QTableWidgetItem* _item = nullptr);
    ~TypeWindow();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    QTableWidgetItem* item;
    QString str;
    int row,column;
    Table* table;
    Ui::TypeWindow *ui;
};

#endif // TYPEWINDOW_H
