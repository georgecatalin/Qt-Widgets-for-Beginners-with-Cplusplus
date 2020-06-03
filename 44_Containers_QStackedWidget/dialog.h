#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
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
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

    void next();
    void back();


private:
    Ui::Dialog *ui;

    /* *** Declare the buttons as private variables so to be able to handle them later in the code *** */

    QPushButton* btnBack;
    QPushButton* btnNext;

    void init();
    void checkButtons();
};
#endif // DIALOG_H
