#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setCentralWidget(ui->plainTextEdit);

    /* *** connect the signals to the slots in the constructor of the window class *** */
    connect(ui->actionNew,&QAction::triggered,this,&MainWindow::newFile); //note about using carefully the MainWindow class in '&MainWindow::newFile'
    connect(ui->actionOpen,&QAction::triggered,this,&MainWindow::openFile);
    connect(ui->actionSave,&QAction::triggered,this,&MainWindow::saveFile);
    connect(ui->actionSave_As,&QAction::triggered,this,&MainWindow::saveFileAs);
    connect(ui->actionExit,&QAction::triggered,this,&MainWindow::close);

    connect(ui->actionCopy,&QAction::triggered,ui->plainTextEdit,&QPlainTextEdit::copy);
    connect(ui->actionCut,&QAction::triggered,ui->plainTextEdit,&QPlainTextEdit::cut);
    connect(ui->actionPaste,&QAction::triggered,ui->plainTextEdit,&QPlainTextEdit::paste);
    connect(ui->actionSelect_All,&QAction::triggered,ui->plainTextEdit,&QPlainTextEdit::selectAll);

    /* *** there is no selectNone in the class &QPlainTextEdit, hence we add the one which is coded in the main window << 'this,&MainWindow::selectNone' *** */
    connect(ui->actionSelect_None,&QAction::triggered,this,&MainWindow::selectNone);

    newFile();
    bool m_saved=true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFile()
{
    ui->plainTextEdit->clear();
    m_filename.clear();
    m_saved=false;

    ui->statusbar->showMessage("New File");
}

void MainWindow::openFile()
{
    QString path=QFileDialog::getOpenFileName(this,"Open File",QString()," Text Files (*.txt);; All files (*.*)");
    if(path.isEmpty()) return;

    m_filename=path;
    QFile qFile(m_filename);

    if(!qFile.open(QIODevice::ReadOnly))
    {
        newFile();
        QMessageBox::critical(this,"Error",qFile.errorString());
        return;
    }

    QTextStream stream(&qFile);
    ui->plainTextEdit->setPlainText(stream.readAll());

    m_saved=true;
    qFile.close();

    ui->statusbar->showMessage(m_filename);
}

void MainWindow::saveFile()
{
    if(m_filename.isEmpty())
    {
        saveFileAs();
        return;
    }

    QFile qFile(m_filename);

    if(!qFile.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this,"Error",qFile.errorString());
        return;
    }

    QTextStream stream(&qFile);
    stream<<ui->plainTextEdit->toPlainText();

    qFile.close();
    m_saved=true;

    ui->statusbar->showMessage("Saved..."+m_filename);
}

void MainWindow::saveFileAs()
{
    QString path=QFileDialog::getSaveFileName(this,"Save File",QString(),"Text Files (*.txt);; All files (*.*)");

    if(path.isEmpty()) return; //it means nothing has been selected

    m_filename=path;
    saveFile();
}

void MainWindow::selectNone()
{
    /* *** QTextCursor contains information about both the cursor's position *** */
    QTextCursor qTextCursor=ui->plainTextEdit->textCursor();

    /* *** int QTextCursor::position() const
     * Returns the absolute position of the cursor within the document. The cursor is positioned between characters.
     * *** */
    int position=qTextCursor.position();

    /* *** void QTextCursor::clearSelection()
     * Clears the current selection by setting the anchor to the cursor position.
     * ***  */
    qTextCursor.clearSelection();

    /* ***
     * enum QTextCursor::MoveMode
     * QTextCursor::MoveAnchor = Moves the anchor to the same position as the cursor itself.
     * QTextCursor::KeepAnchor = Keeps the anchor where it is.
    *** */

    qTextCursor.setPosition(position,QTextCursor::MoveMode::KeepAnchor);
    ui->plainTextEdit->setTextCursor(qTextCursor);
}

void MainWindow::close()
{

}


void MainWindow::on_actionToolbar_top_triggered()
{
   addToolBar(Qt::ToolBarArea::TopToolBarArea,ui->toolBar);
}

void MainWindow::on_actionToolbar_bottom_triggered()
{
     addToolBar(Qt::ToolBarArea::BottomToolBarArea,ui->toolBar);
}

void MainWindow::on_actionToolbar_left_triggered()
{
    addToolBar(Qt::ToolBarArea::LeftToolBarArea,ui->toolBar);
}

void MainWindow::on_actionToolbar_right_triggered()
{
    addToolBar(Qt::ToolBarArea::RightToolBarArea,ui->toolBar);
}


void MainWindow::on_actionToolbar_floatable_toggled(bool arg1)
{
    ui->toolBar->setFloatable(arg1);
}

void MainWindow::on_actionToolbar_movable_toggled(bool arg1)
{
    ui->toolBar->setMovable(arg1);
}
