/********************************************************************************
** Form generated from reading UI file 'Qt_OpenCVp10392.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef QT_OPENCVP10392_H
#define QT_OPENCVP10392_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qt_OpenCVClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Qt_OpenCVClass)
    {
        if (Qt_OpenCVClass->objectName().isEmpty())
            Qt_OpenCVClass->setObjectName(QStringLiteral("Qt_OpenCVClass"));
        Qt_OpenCVClass->resize(600, 400);
        centralWidget = new QWidget(Qt_OpenCVClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Qt_OpenCVClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Qt_OpenCVClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        Qt_OpenCVClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Qt_OpenCVClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Qt_OpenCVClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Qt_OpenCVClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Qt_OpenCVClass->setStatusBar(statusBar);

        retranslateUi(Qt_OpenCVClass);

        QMetaObject::connectSlotsByName(Qt_OpenCVClass);
    } // setupUi

    void retranslateUi(QMainWindow *Qt_OpenCVClass)
    {
        Qt_OpenCVClass->setWindowTitle(QApplication::translate("Qt_OpenCVClass", "Qt_OpenCV", 0));
    } // retranslateUi

};

namespace Ui {
    class Qt_OpenCVClass: public Ui_Qt_OpenCVClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // QT_OPENCVP10392_H
