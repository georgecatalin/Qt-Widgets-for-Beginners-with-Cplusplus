#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QUrl>
#include <QDesktopServices>
#include <QListWidget>
#include <QListWidgetItem>

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

    void init();
    void addCategory(QString category);
    void addLink(QListWidget* list,QString name, QString url);
    void addNews();
    void addSocial();
    void addSearch();

private slots:
    void itemDoubleClick(QListWidgetItem* item);

};
#endif // DIALOG_H
