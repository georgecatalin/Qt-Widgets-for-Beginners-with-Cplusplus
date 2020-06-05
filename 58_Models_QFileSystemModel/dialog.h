#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QDir>
#include <QModelIndex>
#include <QFileSystemModel>

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
    void on_treeView_activated(const QModelIndex &index);

private:
    Ui::Dialog *ui;

    QFileSystemModel dirModel;
    QFileSystemModel fileModel;

    void init();
};
#endif // DIALOG_H
