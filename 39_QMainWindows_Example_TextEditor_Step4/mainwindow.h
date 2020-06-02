#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QLabel>
#include <QStatusBar>
#include <QDebug>
#include <QListWidgetItem>
#include <QScopedPointer>
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void newFile();
    void openFile();
    void saveFile();
    void saveFileAs();
    void selectNone();

    void on_actionToolbar_top_triggered();
    void on_actionToolbar_bottom_triggered();
    void on_actionToolbar_left_triggered();
    void on_actionToolbar_right_triggered();
    void on_actionToolbar_floatable_toggled(bool arg1);
    void on_actionToolbar_movable_toggled(bool arg1);


    void on_plainTextEdit_textChanged();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_actionAnimals_triggered();

    void on_actionShapes_triggered();

    void on_actionFood_triggered();

private:
    Ui::MainWindow *ui;

    QString m_filename;
    bool m_saved;

    void setupStatusbar();
    void updateStatus(QString message);

};
#endif // MAINWINDOW_H
