#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionExit_triggered();

    void on_actionSave_As_triggered();

    void on_actionLeft_Align_triggered();

    void on_actionRight_Align_triggered();

    void on_actionCenter_Align_triggered();

    void on_actionFonts_triggered();

    void on_actionColor_Font_triggered();

    void on_actionAboutQtTxtEditor_triggered();

    void on_actionAboutQt_triggered();

private:
    Ui::MainWindow *ui;
    QString file_path;
};

#endif // MAINWINDOW_H
