#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QColorDialog>
#include <QFontDialog>
#include <QApplication>
#include <QDesktopServices>
#include <QUrl>
#include "finddialog.h"
#include "replacedialog.h"

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

    void on_actionFind_triggered();

    void on_actionReplace_triggered();

    void on_actionSelect_All_triggered();

    void on_actionZoom_In_triggered();

    void on_actionZoom_out_triggered();

    void on_actionBold_triggered();

    void on_actionItalic_triggered();

    void on_actionUnderline_triggered();

    void on_actionStrikethrough_triggered();

    void on_actionColor_triggered();

    void on_actionFont_triggered();

    void on_actionHelp_triggered();

    void on_actionAbout_triggered();

    void on_textEdit_textChanged();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

private:
    Ui::MainWindow *ui;

    bool m_changed;
    QString m_path;

    void newFile();
    void openFile();
    void saveFile(QString path);
    void saveFileAs();
    void checkSaved();

    // QWidget interface
protected:
    /* *** Added this to intercept the event of closing the Window and ask the user if he really wants it
     * This would override the existing event function handler
     * *** */
    void closeEvent(QCloseEvent *event) override;
};
#endif // MAINWINDOW_H
