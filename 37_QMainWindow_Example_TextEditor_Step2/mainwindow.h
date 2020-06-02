#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QString m_filename;
    bool m_saved;

private slots:
    void newFile();
    void openFile();
    void saveFile();
    void saveFileAs();
    void selectNone();
    void close();

    void on_actionToolbar_top_triggered();
    void on_actionToolbar_bottom_triggered();
    void on_actionToolbar_left_triggered();
    void on_actionToolbar_right_triggered();
    void on_actionToolbar_floatable_toggled(bool arg1);
    void on_actionToolbar_movable_toggled(bool arg1);
};
#endif // MAINWINDOW_H
