#ifndef SELECTIONS_H
#define SELECTIONS_H

#include <QDialog>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFileInfoList>
#include <QListWidgetItem>

namespace Ui {
class Selections;
}

class Selections : public QDialog
{
    Q_OBJECT

public:
    explicit Selections(QWidget *parent = nullptr);
    ~Selections();

    QString selected();
    void setSelected(QString value);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Selections *ui;

    QString m_selected;
    void init();
};

#endif // SELECTIONS_H
