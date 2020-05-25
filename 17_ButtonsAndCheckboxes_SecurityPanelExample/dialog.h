#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>

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
    void append();

    void on_btnSave_clicked();

    void on_btnVerify_clicked();

private:
    Ui::Dialog *ui;

    QString temp; //what is entered with the keyboard of the app
    QString code; //what is saved after clicking SAVE button on the dialpad
};
#endif // DIALOG_H
