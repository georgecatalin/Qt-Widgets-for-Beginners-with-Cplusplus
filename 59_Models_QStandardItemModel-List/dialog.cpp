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
    QStringList headers;
    headers<<"My items";

    /* *** void QStandardItemModel::setHorizontalHeaderLabels(const QStringList &labels)
     * Sets the horizontal header labels using labels. If necessary, the column count is increased to the size of labels.
     * *** */

    qStandardItemModel.setHorizontalHeaderLabels(headers);

    /* *** QStandardItem Class
     * The QStandardItem class provides an item for use with the QStandardItemModel class.
     *
     * QStandardItem *QStandardItemModel::invisibleRootItem() const
     * Returns the model's invisible root item.
     *** */

    QStandardItem* root=qStandardItemModel.invisibleRootItem();

    /* ***
     * QString i;           // current file's number
     * QString total;       // number of files to process
     * QString fileName;    // current file's name
     *
     * QString status = QString("Processing file %1 of %2: %3")
     * .arg(i).arg(total).arg(fileName);
     *
     * First, arg(i) replaces %1.
     * Then arg(total) replaces %2.
     * Finally, arg(fileName) replaces %3.
     * *** */

    for(int p=0;p<100;p++)
    {
        QStandardItem* parentItem=new QStandardItem(QString("Parent %0").arg(p));
        root->appendRow(parentItem);

        /* *** Add the children for each parentItem *** */

        for(int c=0;c<30;c++)
        {
          QStandardItem* childItem=new QStandardItem(QString("Children %0").arg(c));
          parentItem->appendRow(childItem);

          for (int s=0;s<10;s++)
          {
            QStandardItem* subchildItem=new QStandardItem(QString("Subchild %0").arg(0));
            childItem->appendRow(subchildItem);
          }
        }


    }

    ui->treeView->setModel(&qStandardItemModel);
}

