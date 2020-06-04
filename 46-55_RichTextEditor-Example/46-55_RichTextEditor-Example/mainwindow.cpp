#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setCentralWidget(ui->textEdit);

    m_path="";
    m_changed=false;

    newFile();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    checkSaved();
    newFile();
}

void MainWindow::on_actionOpen_triggered()
{
    checkSaved();
    openFile();
}

void MainWindow::on_actionSave_triggered()
{
    /* *** If something special required, do here *** */
    saveFile(m_path);
}

void MainWindow::on_actionSave_As_triggered()
{
    saveFileAs();
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionFind_triggered()
{
    FindDialog* dialog=new FindDialog(this);
    if(!dialog->exec()) return;

    /* *** enum QTextDocument::FindFlag
     * ***** flags QTextDocument::FindFlags
     * This enum describes the options available to QTextDocument's find function. The options can be OR-ed together from the following
     * list:
     *
     * QTextDocument::FindBackward 0x00001 Search backwards instead of forwards.
     * QTextDocument::FindCaseSensitively 0x00002 By default find works case insensitive. Specifying this option
     * changes the behaviour to a case sensitive find operation.
     * QTextDocument::FindWholeWords 0x00004 Makes find match only complete words.
     * *** */
    QTextDocument::FindFlags flags;

    /* *** can not use the variables m_caseSensitive etc cause they are private. Use the getters instead which are public *** */
    if(dialog->caseSensitive()) flags= flags | QTextDocument::FindFlag::FindCaseSensitively; // QTextDocument::FindFlag is the ENUM, while QTextDocument::FindFlags is the TYPE OF THE ASSOCIATED VARIABLE
    if(dialog->wholeWords()) flags=flags | QTextDocument::FindFlag::FindWholeWords;
    if(dialog->backwards()) flags=flags | QTextDocument::FindFlag::FindBackward;

    bool search=ui->textEdit->find(dialog->text(),flags);

    if(search==false)
    {
        QMessageBox::information(this,"Not found","Could not find: "+dialog->text());
    }
}

void MainWindow::on_actionReplace_triggered()
{
        ReplaceDialog* dialog=new ReplaceDialog(this);
        if(!dialog->exec()) return;

        if(dialog->all()==true)
        {
            //Replace All
            QString text=ui->textEdit->toHtml();
            text=text.replace(dialog->text(),dialog->replaceText());
            ui->textEdit->setHtml(text);

            m_changed=true;
        }
        else
        {
            //Replace a single value
            bool search=ui->textEdit->find(dialog->text());

            /* *** QTextCursor Class
             * ***** The QTextCursor class offers an API to access and modify QTextDocuments.
             *
             * QTextCursor QTextEdit::textCursor() const
             * ***** Returns a copy of the QTextCursor that represents the currently visible cursor.
             * Note that changes on the returned cursor do not affect QTextEdit's cursor; use
             * setTextCursor() to update the visible cursor.
             *
             * void QTextCursor::insertHtml(const QString &html)
             * ***** Inserts the text html at the current position().
             * The text is interpreted as HTML.
             * *** */

            QTextCursor qTextCursor=ui->textEdit->textCursor();
            qTextCursor.insertHtml(dialog->replaceText());

            if(search==false) QMessageBox::information(this,"Not found","Could not find and replace "+dialog->text());

            m_changed=true;
        }
}

void MainWindow::on_actionSelect_All_triggered()
{
    ui->textEdit->selectAll();
}

void MainWindow::on_actionZoom_In_triggered()
{
    ui->textEdit->zoomIn(3);
}

void MainWindow::on_actionZoom_out_triggered()
{
    ui->textEdit->zoomOut(3);
}

void MainWindow::on_actionBold_triggered()
{
   /* *** QFont Class
    * The QFont class specifies a query for a font used for drawing text.
    * *** */

    QFont qFont=ui->textEdit->currentFont();

    /* *** bool QFont::bold() const
     * Returns true if weight() is a value greater than QFont::Medium; otherwise returns false.
     * *** */

    qFont.bold() ? qFont.setBold(false) : qFont.setBold(true);
    ui->textEdit->setCurrentFont(qFont);

    m_changed=true;
}

void MainWindow::on_actionItalic_triggered()
{
    QFont qFont=ui->textEdit->currentFont();
    qFont.italic() ? qFont.setItalic(false) : qFont.setItalic(true);
    ui->textEdit->setCurrentFont(qFont);

    m_changed=true; //set the status of the file to  'dirty' = needs to be saved because it has unsaved changes
}

void MainWindow::on_actionUnderline_triggered()
{
    QFont qFont=ui->textEdit->currentFont();
    qFont.underline() ? qFont.setUnderline(false) : qFont.setUnderline(true);
    ui->textEdit->setCurrentFont(qFont);

    m_changed=true;
}

void MainWindow::on_actionStrikethrough_triggered()
{
    QFont qFont=ui->textEdit->currentFont();
    qFont.strikeOut() ? qFont.setStrikeOut(false) : qFont.setStrikeOut(true);
    ui->textEdit->setCurrentFont(qFont);

    m_changed=true;
}

void MainWindow::on_actionColor_triggered()
{
    QColor currentColor=ui->textEdit->currentCharFormat().foreground().color();
    QColor myColor=QColorDialog::getColor(currentColor,this,"Select a new color: ");

    ui->textEdit->setTextColor(myColor);

    /* *** set the status of the file to 'dirty' = has unsaved changes *** */
    m_changed=true;
}

void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont currentFont=ui->textEdit->currentFont();
    QFont qFont=QFontDialog::getFont(&ok,currentFont,this,"Select a font:");

    if(ok==true) ui->textEdit->setCurrentFont(qFont);

    m_changed=true;
}

void MainWindow::on_actionHelp_triggered()
{

}

void MainWindow::on_actionAbout_triggered()
{

}

void MainWindow::on_textEdit_textChanged()
{
    m_changed=true;
}

void MainWindow::newFile()
{
    ui->textEdit->clear();
    ui->statusbar->showMessage("New File");

    m_changed=false;
    m_path="";
}

void MainWindow::openFile()
{
    QString path=QFileDialog::getOpenFileName(this,"Open file",QString(),"Text Format files (*.txt);;All files (*.*)");
    if(path.isEmpty()) return;

    QFile qFile(path);
    if(!qFile.open(QIODevice::ReadOnly))
    {
       QMessageBox::critical(this,"Error",qFile.errorString());
       return;
    }

    QTextStream stream(&qFile);
    ui->textEdit->setHtml(stream.readAll());

    qFile.close();

    m_changed=false;
    m_path=path;

    ui->statusbar->showMessage("Open file: "+ path);
}

void MainWindow::saveFile(QString path)
{
    if(path.isEmpty())
    {
        saveFileAs();
        return;
    }

    QFile qFile(path);

    if(!qFile.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this,"Error",qFile.errorString());
        ui->statusbar->showMessage("Error when saving file.");
        return;
    }

    QTextStream stream(&qFile);
    stream<<ui->textEdit->toHtml();

    qFile.close();

    m_changed=false;
    m_path=path;

    ui->statusbar->showMessage("Saved file to "+ path);
}

void MainWindow::saveFileAs()
{
    QString path=QFileDialog::getSaveFileName(this,"Save file as: ");
    if(path.isEmpty()) return;

    saveFile(path);
}

void MainWindow::checkSaved()
{
    if(m_changed==false) return;

    QMessageBox::StandardButton myValue=QMessageBox::question(this,"Save file?","You have changes in your file. Would you like to save it?");

    if(myValue!=QMessageBox::StandardButton::Yes) return;

    if(m_path.isEmpty())
    {
        saveFileAs();
    }
    else
    {
        saveFile(m_path);
    }
}


void MainWindow::closeEvent(QCloseEvent *event)
{

    event->accept();
}

