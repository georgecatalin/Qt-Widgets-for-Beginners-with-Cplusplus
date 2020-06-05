#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QFileInfo>
#include <QFileInfoList>
#include <QStringList>
#include <QDir>
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;

    QStandardItemModel qStandardItemModel;

    void init();
    void addFile(QStandardItem* root,QFileInfo info);
};
#endif // DIALOG_H
