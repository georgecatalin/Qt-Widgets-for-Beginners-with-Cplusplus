#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QIcon>
#include <QTextStream>
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
    void on_btnNew_clicked();

    void on_btnOpen_clicked();

    void on_btnSave_clicked();

    void on_plainTextEdit_textChanged();
    void acceptThisObject();

private:
    Ui::Dialog *ui;

    bool m_saved;
    void load();
    void save();


    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
};
#endif // DIALOG_H
