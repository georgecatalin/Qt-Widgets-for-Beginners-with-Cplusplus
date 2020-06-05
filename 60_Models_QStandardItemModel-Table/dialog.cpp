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

void Dialog::itemChanged(QStandardItem *item)
{
    qInfo()<<"Index= "<<item->index().row()<<" , "<<item->index().column()<<" = "<<item->text();
}

void Dialog::init()
{
    model.insertRows(0,5);
    model.insertColumns(0,4);

    for(int r=0;r<model.rowCount();r++)
    {
        for(int c=0;c<model.columnCount();c++)
        {
            QStandardItem* item=new QStandardItem(QString("row %0, column %1").arg(r).arg(c));

            /* *** void QStandardItemModel::setItem(int row, int column, QStandardItem *item)
             * Sets the item for the given row and column to item. The model takes ownership of the item. If necessary, the row count
             * and column count are increased to fit the item. The previous item at the given location (if there was one) is deleted.
             * *** */

            model.setItem(r,c,item);
        }
    }

    ui->tableView->setModel(&model);

    connect(&model,&QStandardItemModel::itemChanged,this,&Dialog::itemChanged); //connect signal to slot so the program sees when modifications done to the model
}

