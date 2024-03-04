#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFormLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    lineEdit1 = new QLineEdit;
    lineEdit2 = new QLineEdit;
    lineEdit3 = new QLineEdit;

    // Create submit button
    submitButton = new QPushButton("Submit");

    // Create form layout and add widgets
    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("Input 1:", lineEdit1);
    formLayout->addRow("Input 2:", lineEdit2);
    formLayout->addRow("Input 3:", lineEdit3);
    formLayout->addRow(submitButton);

    // Set central widget
    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(formLayout);
    setCentralWidget(centralWidget);

    // Connect submit button clicked signal to validateForm slot
    connect(submitButton, &QPushButton::clicked, this, &MainWindow::validateForm);

}
void MainWindow::validateForm()
{
    if (lineEdit1->text().isEmpty() || lineEdit2->text().isEmpty() || lineEdit3->text().isEmpty()) {
        QMessageBox::critical(this, "Error", "All fields are required.");
    } else {
        QMessageBox::information(this, "Success", "Form submitted successfully.");
    }
}
MainWindow::~MainWindow()
{}
