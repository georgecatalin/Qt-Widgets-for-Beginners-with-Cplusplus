#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class FindDialog;
}

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindDialog(QWidget *parent = nullptr);
    ~FindDialog();

    bool caseSensitive() const;

    bool wholeWords() const;

    bool backwards() const;

    QString text() const;

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void goBack();

private:
    Ui::FindDialog *ui;

    QString m_text;
    bool m_caseSensitive;
    bool m_wholeWords;
    bool m_backwards;

    void init();
    void save();
};

#endif // FINDDIALOG_H
