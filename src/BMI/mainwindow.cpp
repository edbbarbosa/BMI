#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "bmi.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QLabel>
#include <QDoubleValidator>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(200, 150);

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *vboxLayout = new QVBoxLayout(centralWidget);
    QFormLayout *formLayout = new QFormLayout();

    // Create widgets
    heightEdit = new QLineEdit;
    weightEdit = new QLineEdit;

    // Add widgets to form layout
    formLayout->addRow("Height (in cm):", heightEdit);
    formLayout->addRow("Weight (in kg):", weightEdit);

    QPushButton *okButton = new QPushButton("OK");

    bmiLabel = new QLabel;

    // Add form layout to vertical layout
    vboxLayout->addLayout(formLayout);
    vboxLayout->addWidget(bmiLabel);
    vboxLayout->addWidget(okButton);

    QDoubleValidator* validator = new QDoubleValidator(0, 0, 2, this);
    heightEdit->setValidator(validator);
    weightEdit->setValidator(validator);

    connect(okButton, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonClicked()
{
    Bmi bmi(heightEdit->text().toDouble(), weightEdit->text().toDouble());
    if(heightEdit->text().toDouble() && weightEdit->text().toDouble())
    {
        bmiLabel->setText(QString::number(bmi.getBmi()));
    }
    else
    {
        bmiLabel->setText("Error");
    }
}
