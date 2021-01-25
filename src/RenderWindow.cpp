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
    iterationLabel.setText("Number of iterations:");
    iterationBox.setParent(this);
    for (int i = 0; i < 9; i++)
        iterationBox.addItem(QString::number(i));
    calculateButton.setParent(this);
    calculateButton.setText("Calculate");
    connect(&calculateButton, SIGNAL(clicked(bool)), this, SLOT(calculate()));
    vertexLabel.setParent(this);
    facetLabel.setParent(this);
    vertical.addWidget(&methodLabel);
    vertical.addWidget(&dooSabinButton);
    vertical.addWidget(&catmullClarkButton);
    vertical.addWidget(&loopButton);
    vertical.addWidget(&iterationLabel);
    vertical.addWidget(&iterationBox);
    vertical.addWidget(&calculateButton);
    vertical.addWidget(&vertexLabel);
    vertical.addWidget(&facetLabel);
    vertical.addStretch();

    renderWidget = nullptr;
    horizontal.addLayout(&vertical);

    widget.setParent(this);
    widget.setLayout(&horizontal);
    setCentralWidget(&widget);

    calculate();
}

RenderWindow::~RenderWindow() {}

void RenderWindow::calculate() {
    Mesh mesh;
    for (int i = 0; i < iterationBox.currentIndex(); i++)
        if (dooSabinButton.isChecked())
            mesh = mesh.subdivide(new DooSabinSubdivider());
        else if (catmullClarkButton.isChecked())
            mesh = mesh.subdivide(new CatmullClarkSubdivider());
        else if (loopButton.isChecked())
            mesh = mesh.subdivide(new LoopSubdivider());
    vertexLabel.setText(QString("Number of Vertices: %1").arg(mesh.numberOfVertices()));
    facetLabel.setText(QString("Number of Facets: %1").arg(mesh.numberOfFacets()));
    delete renderWidget;
    renderWidget = new RenderWidget(this, mesh);
    renderWidget->setMinimumSize(width, height);
    horizontal.addWidget(renderWidget);
}