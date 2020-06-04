#ifndef REPLACEDIALOG_H
#define REPLACEDIALOG_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class ReplaceDialog;
}

class ReplaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReplaceDialog(QWidget *parent = nullptr);
    ~ReplaceDialog();

    bool all() const;

    QString text() const;

    QString replaceText() const;

private slots:
    void on_buttonBox_rejected();
    void replace();
    void replaceAll();

private:
    Ui::ReplaceDialog *ui;

    bool m_all;
    QString m_text;
    QString m_replaceText;

    void init();
    void save(); //save the values of variables
};

#endif // REPLACEDIALOG_H
