#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <qtextedit.h>
#include <QFontDialog>
#include <QFont>
#include <QFontDatabase>
#include <QTextCursor>
#include <QColor>
#include <QColorDialog>
#include <QSyntaxHighlighter>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//метод создания нового файла
void MainWindow::on_actionNew_triggered()
{
    file_path=""; //очищаю путь
    ui->textEdit->setText(""); // делаю редактор пустым
}

//функция открытия файла
void MainWindow::on_actionOpen_triggered()
{
 QString file_name = QFileDialog::getOpenFileName(this,"Open a file");
 QFile file (file_name);
 file_path=file_name;

  if(!file.open(QFile::ReadOnly | QFile::Text)){
    QMessageBox::critical(this,"Error Opening File","File Cannot be Opened!");
    return;
  }
  else{
    //чтение
    QTextStream inputData(&file);
    QString fileText = inputData.readAll();
    ui->textEdit->setHtml(fileText);
    file.close();
  }
}

//вырезание
void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

//копирование
void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

//вставка
void MainWindow::on_actionPaste_triggered()
{
     ui->textEdit->paste();
}
//отмена назад
void MainWindow::on_actionUndo_triggered()
{
     ui->textEdit->undo();
}

//отмена впереёд
void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

//выход
void MainWindow::on_actionExit_triggered()
{
     QApplication::quit();
}

//сохранение файла по имени
void MainWindow::on_actionSave_As_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this,"Open a file");
    QFile file (file_name);
    file_path = file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
       //Если пользователь отменяет действие, то ничего не происходит
        return;
     }
     else{
       //чтение файла
       QTextStream writeData(&file);
       QString fileText = ui->textEdit->toHtml();
       writeData << fileText;
       file.flush();
       file.close();
     }
}

//расположение текста слева
void MainWindow::on_actionLeft_Align_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignLeft);
}

//расположение текста справа
void MainWindow::on_actionRight_Align_triggered()
{
     ui->textEdit->setAlignment(Qt::AlignRight);
}

//расположение текста по центру
void MainWindow::on_actionCenter_Align_triggered()
{
     ui->textEdit->setAlignment(Qt::AlignCenter);
}

//выборка стиля текста
void MainWindow::on_actionFonts_triggered()
{
    bool ok;
    QFont fontStyle = QFontDialog::getFont(&ok,this);

    if(ok){
            QTextCharFormat format;
            format.setFont(fontStyle);
            QTextCursor txtCursor(ui->textEdit->textCursor());
            txtCursor.setCharFormat(format);
            txtCursor.clearSelection();
            ui->textEdit->setTextCursor(txtCursor);
    }
    else{
            return;
    }
}


//выборка палитры текста
void MainWindow::on_actionColor_Font_triggered()
{
    QColor txtColour = QColorDialog::getColor();
    ui->textEdit->setTextColor(txtColour);
}

//инфа об авторе программы
void MainWindow::on_actionAboutQtTxtEditor_triggered()
{
     QMessageBox::about(this,"About QtTextEdit"," Copyright Levdansky Igor 2017");
}

//инфа об  программе-разработке
void MainWindow::on_actionAboutQt_triggered()
{
     QMessageBox::aboutQt(this,"About Qt Creator.");
}
