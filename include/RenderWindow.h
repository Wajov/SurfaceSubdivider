#ifndef RENDER_WINDOW_H
#define RENDER_WINDOW_H

#include <string>

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QRadioButton>
#include <QComboBox>
#include <QPushButton>

#include "Mesh.h"
#include "RenderWidget.h"

class RenderWindow : public QMainWindow {
    Q_OBJECT
private:
    int width, height;
    QWidget widget;
    QVBoxLayout vertical;
    QHBoxLayout horizontal;
    QLabel methodLabel, iterationLabel;
    QRadioButton dooSabinButton, catmullClarkButton, loopButton;
    QComboBox iterationBox;
    QPushButton calculateButton;
    RenderWidget *renderWidget;

public:
    RenderWindow(int width, int height);
    ~RenderWindow() override;

private slots:
    void calculate();
};

#endif