#ifndef MYGUI_H
#define MYGUI_H

#include "glwidget.h"


class MyGui : public QWidget
{
    Q_OBJECT

public:
    MyGui();

signals:
    void actionSignal(); //Appears to be function but WITHOUT codes.

public slots:
    void Run();
    void Stop();
    void Load();
    void Save();
    void Action();

private:
    QPushButton* exitButton;
    QPushButton* saveButton;
    QPushButton* loadButton;
    QPushButton* runButton;
    QPushButton* stopButton;
    glWidget* glwidget;
    int delay = 500;
    QTimer* timer;


//    QTextEdit* textArea;
};

#endif // MYGUI_H
