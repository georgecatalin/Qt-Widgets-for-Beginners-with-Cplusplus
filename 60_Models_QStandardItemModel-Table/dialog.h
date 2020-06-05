#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void itemChanged(QStandardItem* item);

private:
    Ui::Dialog *ui;

    QStandardItemModel model;
    void init();
};
#endif // DIALOG_H
