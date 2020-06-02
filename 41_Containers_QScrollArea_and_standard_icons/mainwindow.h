#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QStyle>
#include <QLabel>
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
    void on_actionOpen_triggered();

    void on_actionZoom_Out_triggered();

    void on_actionZoom_In_triggered();

private:
    Ui::MainWindow *ui;
    QLabel* m_lblImage;
    QString m_path;
    QPixmap m_img;

};
#endif // MAINWINDOW_H
