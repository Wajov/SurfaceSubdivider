#include "RenderWindow.h"

RenderWindow::RenderWindow(int width, int height) : QMainWindow() {
    this->width = width;
    this->height = height;

    methodLabel.setParent(this);
    methodLabel.setText("Method:");
    dooSabinButton.setParent(this);
    dooSabinButton.setText("Doo-Sabin");
    dooSabinButton.setChecked(true);
    catmullClarkButton.setParent(this);
    catmullClarkButton.setText("Catmull-Clark");
    loopButton.setParent(this);
    loopButton.setText("Loop");
    iterationLabel.setParent(this);
    iterationLabel.setText("Number of iteration:");
    iterationBox.setParent(this);
    for (int i = 0; i < 6; i++)
        iterationBox.addItem(QString::number(i));
    calculateButton.setParent(this);
    calculateButton.setText("Calculate");
    connect(&calculateButton, SIGNAL(clicked(bool)), this, SLOT(calculate()));
    vertical.addWidget(&methodLabel);
    vertical.addWidget(&dooSabinButton);
    vertical.addWidget(&catmullClarkButton);
    vertical.addWidget(&loopButton);
    vertical.addWidget(&iterationLabel);
    vertical.addWidget(&iterationBox);
    vertical.addWidget(&calculateButton);
    vertical.addStretch();

    Mesh mesh;
    renderWidget = new RenderWidget(this, mesh);
    renderWidget->setMinimumSize(this->width, this->height);

    horizontal.addLayout(&vertical);
    horizontal.addWidget(renderWidget);

    widget.setParent(this);
    widget.setLayout(&horizontal);
    setCentralWidget(&widget);
}

RenderWindow::~RenderWindow() {}

void RenderWindow::calculate() {
    Mesh mesh;
    for (int i = 0; i < iterationBox.currentIndex(); i++)
        mesh = mesh.subdivisionDooSabin();
    delete renderWidget;
    renderWidget = new RenderWidget(this, mesh);
    renderWidget->setMinimumSize(width, height);
    horizontal.addWidget(renderWidget);
}