/********************************************************************************
** Form generated from reading UI file 'replacedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLACEDIALOG_H
#define UI_REPLACEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ReplaceDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *txtFind;
    QLabel *label_2;
    QLineEdit *txtReplace;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ReplaceDialog)
    {
        if (ReplaceDialog->objectName().isEmpty())
            ReplaceDialog->setObjectName(QString::fromUtf8("ReplaceDialog"));
        ReplaceDialog->resize(400, 203);
        verticalLayout = new QVBoxLayout(ReplaceDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ReplaceDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        txtFind = new QLineEdit(ReplaceDialog);
        txtFind->setObjectName(QString::fromUtf8("txtFind"));

        verticalLayout->addWidget(txtFind);

        label_2 = new QLabel(ReplaceDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        txtReplace = new QLineEdit(ReplaceDialog);
        txtReplace->setObjectName(QString::fromUtf8("txtReplace"));

        verticalLayout->addWidget(txtReplace);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(ReplaceDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ReplaceDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ReplaceDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ReplaceDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ReplaceDialog);
    } // setupUi

    void retranslateUi(QDialog *ReplaceDialog)
    {
        ReplaceDialog->setWindowTitle(QCoreApplication::translate("ReplaceDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ReplaceDialog", "Text to find:", nullptr));
        label_2->setText(QCoreApplication::translate("ReplaceDialog", "Text to replace:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReplaceDialog: public Ui_ReplaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLACEDIALOG_H
