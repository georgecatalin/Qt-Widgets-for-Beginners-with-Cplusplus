#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QListView>
#include <QTreeView>
#include <QDir>
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

    void on_listView_activated(const QModelIndex &index);

private:
    Ui::Dialog *ui;

    QDir qDir;
    QFileSystemModel qFileSystemModel;
    void init();
};
#endif // DIALOG_H
