#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSettings>
#include <QVariant>
#include <QMessageBox>
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
    void on_btnAdd_clicked();

    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Dialog *ui;

    void init();
    void load();
    void save();
};
#endif // DIALOG_H
