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
    qFileSystemModel.setRootPath(QDir::currentPath());

    ui->treeView->setModel(&qFileSystemModel);
    ui->listView->setModel(&qFileSystemModel);

    for (int i=1;i<qFileSystemModel.columnCount();i++)
    {
        ui->treeView->hideColumn(i);
    }

    ui->listView->setViewMode(QListView::ViewMode::ListMode);
}


void Dialog::on_treeView_activated(const QModelIndex &index)
{
    ui->listView->setRootIndex(index);
}

void Dialog::on_listView_activated(const QModelIndex &index)
{
    ui->listView->setRootIndex(index); //set the upper element in the list to index

    ui->treeView->setCurrentIndex(index); //Sets the current item to be the item at index.
    ui->treeView->expand(index); //Expands the model item specified by the index.
}
