#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QStringList>
#include <QStringListModel>
#include <QPushButton>
#include <QInputDialog>
#include <QModelIndex>


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
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void add();
    void remove();

private:
    Ui::Dialog *ui;

    QStringList list;
    QStringListModel model;

    void init();
};
#endif // DIALOG_H
