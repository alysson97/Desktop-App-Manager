#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "resumeeditor.h"
#include "linkorganizer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString cardStyle = R"(
        QPushButton {
            background-color: #ffffff;
            border: 1px solid #ccc;
            border-radius: 6px;
            padding: 8Tpx;
            font-size: normal;
            color: #333;
        }

        QPushButton:hover {
            background-color: #f0f0f0;
            border: 1px solid #999;
        }

        QPushButton:pressed {
            background-color: #e0e0e0;
        }
    )";

    ui->btnResumeEditor->setStyleSheet(cardStyle);
    ui->btnLinkOrganizer->setStyleSheet(cardStyle);

    connect(ui->btnResumeEditor, &QPushButton::clicked, this, []() {
        auto *editor = new ResumeEditor();
        editor->setAttribute(Qt::WA_DeleteOnClose); // libera memória ao fechar
        editor->show();
    });

    connect(ui->btnLinkOrganizer, &QPushButton::clicked, this, []() {
        auto *organizer = new LinkOrganizer();
        organizer->setAttribute(Qt::WA_DeleteOnClose);
        organizer->show();
    });
}

MainWindow::~MainWindow() {
    delete ui;
}
