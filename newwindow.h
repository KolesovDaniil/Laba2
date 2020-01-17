#ifndef NEWWINDOW_H
#define NEWWINDOW_H

#include <QDialog>
#include <table.h>

namespace Ui {
class NewWindow;
}

class NewWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NewWindow(QWidget *parent = nullptr, Table* _table=nullptr);
    ~NewWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Table* table;
    Ui::NewWindow *ui;
};

#endif // NEWWINDOW_H
