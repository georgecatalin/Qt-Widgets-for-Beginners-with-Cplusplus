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
    /* *** clear the pages out in the toolbox widget *** */

    /* ***
     * count : const int
     * This property holds the number of items contained in the toolbox.
     * By default, this property has a value of 0.
     * Access functions:
     * int count() const
     * *** */

    while (ui->toolBox->count()>0)
    {
        ui->toolBox->removeItem(0);
    }

    /* *** Add pages *** */
    addCategory("News");
    addCategory("Social Media");
    addCategory("Search Engines");

    addNews();
    addSocial();
    addSearch();
}

void Dialog::addCategory(QString category)
{
    QListWidget* myList=new QListWidget(this);
    ui->toolBox->addItem(myList,QIcon(":/files/Simple_UI/iconfinder_Open_1493293.png"),category);

    connect(myList,&QListWidget::itemDoubleClicked,this,&Dialog::itemDoubleClick)
;}

void Dialog::addLink(QListWidget *list, QString name, QString url)
{
    QListWidgetItem* item=new QListWidgetItem(QIcon(":/files/Simple_UI/iconfinder_Help_1493288.png"),name);

    /* ****
     * [virtual] void QListWidgetItem::setData(int role, const QVariant &value)
     * Sets the data for a given role to the given value.
     * Reimplement this function if you need extra roles or special behavior
     * for certain roles.

     * enum Qt::ItemDataRole
     * Each item in the model has a set of data elements associated with it,
     * each with its own role. The roles are used by the view to indicate to
     * the model which type of data it needs. Custom models should return data
     * in these types.
     *
     * The general purpose roles (and the associated types) are:
     * Qt::DisplayRole 0
     * The key data to be rendered in the form of text. (QString)
     * Qt::DecorationRole 1
     * The data to be rendered as a decoration in the form of an icon. (QColor, QIcon or QPixmap)
     * Qt::EditRole 2
     * The data in a form suitable for editing in an editor. (QString)
     * Qt::ToolTipRole 3
     * The data displayed in the item's tooltip. (QString)
     * Qt::StatusTipRole 4
     * The data displayed in the status bar. (QString)
     * Qt::WhatsThisRole 5
     * The data displayed for the item in "What's This?" mode. (QString)
     * Qt::SizeHintRole 13
     * The size hint for the item that will be supplied to views. (QSize)

     * Qt::UserRole 0x0100
     * The first role that can be used for application-specific purposes.

     *
     */
    item->setData(Qt::ItemDataRole::UserRole,url);
    list->addItem(item);
}

void Dialog::addNews()
{
    QListWidget* myList=qobject_cast<QListWidget*>(ui->toolBox->widget(0)); //see line 36 it is the first widget

    if(!myList)
    {
        qWarning()<<"Could not find a News Page in the toolbox widget";
        return;
    }

    this->addLink(myList,"Realitatea","http://www.realitatea.info");
    this->addLink(myList,"Antena3","http://www.antena3.ro");
    this->addLink(myList,"Digi24","http:://www.digi24.com");
}

void Dialog::addSocial()
{
    QListWidget* myList=qobject_cast<QListWidget*>(ui->toolBox->widget(1)); //see line 37 for index

    if(!myList)
    {
        qWarning()<<"Could not find Social Media Page in the toolbox widget";
        return;
    }

    addLink(myList,"Youtube","http://www.youtube.com");
    addLink(myList,"Linkedin","http://www.linkedin.com");
    addLink(myList,"Facebook","http://www.facebook.com");
}

void Dialog::addSearch()
{
    QListWidget* myList=qobject_cast<QListWidget*>(ui->toolBox->widget(2)); //see line 38 for index (3rd element in the collection)

    if(!myList)
    {
        qWarning()<<"Could not find Search Engines pages in the toolbox";
        return;
    }

    addLink(myList,"Google","http://www.google.com");
    addLink(myList,"Yahoo","http://www.yahoo.com");
}

void Dialog::itemDoubleClick(QListWidgetItem *item)
{
    QString url=item->data(Qt::ItemDataRole::UserRole).toString();

    /* *** QDesktopServices Class
     * The QDesktopServices class provides methods for accessing common desktop services.
     *

     * [static] bool QDesktopServices::openUrl(const QUrl &url)
     * Opens the given url in the appropriate Web browser for the user's desktop environment, and returns true if successful; otherwise
     * returns false.
     * If the URL is a reference to a local file (i.e., the URL scheme is "file") then it will be opened with a suitable application
     * instead of a Web browser.
     *
     * The following example opens a file on the Windows file system residing on a path that contains spaces:
     *
     * QDesktopServices::openUrl(QUrl("file:///C:/Documents and Settings/All Users/Desktop", QUrl::TolerantMode));
     *
     * If a mailto URL is specified, the user's e-mail client will be used to open a composer window containing the options
     * specified in the URL, similar to the way mailto links are handled by a Web browser.

     * *** */
    QDesktopServices::openUrl(QUrl(url));
}

