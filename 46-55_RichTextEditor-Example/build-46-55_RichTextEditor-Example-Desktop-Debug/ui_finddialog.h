/********************************************************************************
** Form generated from reading UI file 'finddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIALOG_H
#define UI_FINDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FindDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *chkMatchWholeWord;
    QCheckBox *chkCaseSensitive;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FindDialog)
    {
        if (FindDialog->objectName().isEmpty())
            FindDialog->setObjectName(QString::fromUtf8("FindDialog"));
        FindDialog->resize(470, 240);
        verticalLayout = new QVBoxLayout(FindDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(FindDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(FindDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        chkMatchWholeWord = new QCheckBox(FindDialog);
        chkMatchWholeWord->setObjectName(QString::fromUtf8("chkMatchWholeWord"));

        verticalLayout->addWidget(chkMatchWholeWord);

        chkCaseSensitive = new QCheckBox(FindDialog);
        chkCaseSensitive->setObjectName(QString::fromUtf8("chkCaseSensitive"));

        verticalLayout->addWidget(chkCaseSensitive);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(FindDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(FindDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), FindDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FindDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(FindDialog);
    } // setupUi

    void retranslateUi(QDialog *FindDialog)
    {
        FindDialog->setWindowTitle(QCoreApplication::translate("FindDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("FindDialog", "Find", nullptr));
        chkMatchWholeWord->setText(QCoreApplication::translate("FindDialog", "Match Whole Word", nullptr));
        chkCaseSensitive->setText(QCoreApplication::translate("FindDialog", "Case Sensitive", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindDialog: public Ui_FindDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H
