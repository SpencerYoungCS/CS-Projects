#include "mygui.h"

//Contains Slots, Buttons, Visuals

MyGui::MyGui()
{
    timer = NULL;
    runButton = new QPushButton("Run");
    stopButton = new QPushButton("Stop");
    saveButton = new QPushButton("Save");
    loadButton = new QPushButton("Load");
    exitButton = new QPushButton("Exit");
    glwidget = new glWidget;
    glwidget->setMinimumSize(640, 480);
//    textArea = new QTextEdit;

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(runButton);
    buttonLayout->addWidget(stopButton);
    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(loadButton);
    buttonLayout->addWidget(exitButton);

    QVBoxLayout* overall = new QVBoxLayout;
    overall->addWidget(glwidget);
    overall->addLayout(buttonLayout);

    setLayout(overall);
//----------------------BUTTONS AND SIGNALS-----------------------------------

    connect(this, SIGNAL(actionSignal()), this, SLOT(Action()));     // Allows Action Signal

    connect(runButton, SIGNAL(clicked()), this, SLOT(Run()));

    connect(stopButton,SIGNAL(clicked()), this, SLOT(Stop()));

    connect(loadButton, SIGNAL(clicked()), this, SLOT(Load()));

    connect(saveButton, SIGNAL(clicked()), this, SLOT(Save()));

    connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));
}

//------------------------SLOT FUNCTIONS-------------------------------------------

void MyGui::Run(){
    if(!timer){
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), glwidget,  SLOT(process()));
        timer->start(delay);
        cout << "timer started: " << endl;
    }
}

void MyGui::Stop(){
    if(timer){
        delete timer;
        timer = NULL;
        cout << "timer stopped" << endl;
    }
}
void MyGui::Load(){
    cout << "\n\nLOADING...\n\n";
    emit actionSignal();
}

void MyGui::Save(){
    cout << "\n\nSAVING...\n\n";
    emit actionSignal();
}

void MyGui::Action(){
    cout << "\n\nTAKING ACTION...\n\n";
}
