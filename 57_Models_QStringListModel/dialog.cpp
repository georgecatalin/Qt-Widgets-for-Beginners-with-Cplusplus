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


void Dialog::on_buttonBox_accepted()
{
    this->accept();
}

void Dialog::on_buttonBox_rejected()
{
    this->reject();
}

void Dialog::add()
{
    QString toAdd=QInputDialog::getText(this,"Add Item","Enter the item to add");
    if(toAdd.isEmpty()) return;

    //Use the inherited functions of QAbstractModel

    if(model.insertRow(model.rowCount())) //if succeded to enter a row
    {
        QModelIndex qModelIndex=model.index(model.rowCount()-1,0); //row position and column position
        model.setData(qModelIndex,toAdd);
    }
}

void Dialog::remove()
{
    QModelIndex index=ui->listView->currentIndex();

    /* *** bool QAbstractItemModel::removeRow(int row, const QModelIndex &parent = QModelIndex())
     * ***** Removes the given row from the child items of the parent specified.
     * Returns true if the row is removed; otherwise returns false.
     *
     * *** int QModelIndex::row() const
     * Returns the row this model index refers to.
     * *** */

    model.removeRow(index.row());
}

void Dialog::init()
{
    //Set up the data. Model and data are two different things
    list.append("Cat");
    list.append("Dog");
    list.append("Bird");
    list.append("Fish");

    /* *** void QStringListModel::setStringList(const QStringList &strings)
     * Sets the model's internal string list to strings. The model will notify any
     * attached views that its underlying data has changed.
     * *** */

    //Set up the model
    model.setStringList(list);

    /* *** void QAbstractItemView::setModel(QAbstractItemModel *model)
     * Sets the model for the view to present.
     * *** */

    //Set up the view
    ui->listView->setModel(&model);

    //Build the ui
    QPushButton* btnAdd=new QPushButton("Add",this);
    QPushButton* btnRemove=new QPushButton("Remove",this);

    connect(btnAdd,&QPushButton::clicked,this,&Dialog::add);
    connect(btnRemove,&QPushButton::clicked,this,&Dialog::remove);

    ui->buttonBox->addButton(btnAdd,QDialogButtonBox::ButtonRole::ActionRole);
    ui->buttonBox->addButton(btnRemove,QDialogButtonBox::ButtonRole::ActionRole);
}
