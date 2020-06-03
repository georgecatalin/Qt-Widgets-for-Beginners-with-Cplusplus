#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QPlainTextEdit>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>

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
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSave_As_triggered();
    void on_actionExit_triggered();
    void on_actionCopy_triggered();
    void on_actionCut_triggered();
    void on_actionPaste_triggered();
    void on_actionSelect_All_triggered();
    void on_actionNext_triggered();
    void on_actionPrevious_triggered();
    void on_actionCascade_triggered();
    void on_actionTile_triggered();
    void on_actionClose_triggered();
    void on_actionClose_All_triggered();

private:
    Ui::MainWindow *ui;

    QMdiSubWindow *newDocument();

};
#endif // MAINWINDOW_H
