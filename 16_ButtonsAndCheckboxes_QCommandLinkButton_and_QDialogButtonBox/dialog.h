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
    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_3_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_buttonBox_helpRequested();

private:
    Ui::Dialog *ui;
    void selectOption(QObject* object);
};
#endif // DIALOG_H
