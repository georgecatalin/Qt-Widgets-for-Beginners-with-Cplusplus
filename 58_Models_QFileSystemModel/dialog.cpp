#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    init();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::init()
{
    /* *** Set the model *** */
    dirModel.setRootPath(QDir::currentPath());
    dirModel.setFilter(QDir::Filter::Drives | QDir::Filter::AllDirs | QDir::Filter::NoDotDot);

    /* *** Set the view *** */
    ui->treeView->setModel(&dirModel);

    /* *** Hide the unnecessary columns, other than the 1st column(index 0) *** */
    for (int i=1;i<dirModel.columnCount();i++)
    {
        ui->treeView->hideColumn(i);
    }

    /* *** Setup the List View *** */
    fileModel.setRootPath(dirModel.rootPath());
    fileModel.setFilter(QDir::Filter::Files);

    ui->listView->setModel(&fileModel);
}


void Dialog::on_treeView_activated(const QModelIndex &index)
{
    /* *** QString QFileSystemModel::filePath(const QModelIndex &index) const
     * Returns the path of the item stored in the model under the index given.
     * *** */

    QString path=fileModel.filePath(index);
    qDebug()<<path;

    fileModel.setFilter(QDir::Filter::Files);

    /* *** void QAbstractItemView::setRootIndex(const QModelIndex &index)
     * Sets the root item to the item at the given index.
     *
     *
     * *** QModelIndex QFileSystemModel::setRootPath(const QString &newPath)
     * Sets the directory that is being watched by the model to newPath by installing a file
     * system watcher on it. Any changes to files and directories within this directory will be
     * reflected in the model.
     * If the path is changed, the rootPathChanged() signal will be emitted.
    * *** */
    ui->listView->setRootIndex(fileModel.setRootPath(path));
}

