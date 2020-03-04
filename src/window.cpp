#include <QtWidgets>

#include "Model.h"
#include "window.h"
#include "ui_form.h"

#include "visual_opengl_widget.h"

// Timer constants
constexpr int SLIDER_TIMER_INTERVAL = 10;

// Model constants
constexpr Model::Point START_POINT = {1, 1, 1};
constexpr int COUNT_POINTS = 200'000;
constexpr int STEPS_PER_COUNT = 10;
constexpr double TAU = 0.001;
constexpr int DIV_NORMALIZE = 8;

Window::Window(QWidget *parent) : QWidget(parent), ui(new Ui::Window) {
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus);

    sliderTimer = new QTimer(this);
    sliderTimer->setInterval(SLIDER_TIMER_INTERVAL);

    connect(sliderTimer, SIGNAL(timeout()), this, SLOT(updateSlider()));

}

QVector3D getQPoint(const Model::Point &point) {
    return QVector3D(point.x / DIV_NORMALIZE, point.y / DIV_NORMALIZE, point.z / DIV_NORMALIZE); //TODO: implement normalization
}

void Window::slot_restart_button() {
    Model::ModelName modelName = Model::ModelName::Rossler;
    if (ui->comboBox->currentText() == "Аттрактор Лоренца") {
        modelName = Model::ModelName::Lorenz;
    } else if (ui->comboBox->currentText() == "Аттрактор Рёсслера") {
        modelName = Model::ModelName::Rossler;
    }

    std::vector<long double> constants = {
        ui->doubleSpinBox->value(),
        ui->doubleSpinBox_2->value(),
        ui->doubleSpinBox_3->value()
    };

    ui->visualOpenGLWidget->clearAll();
    QVector<QVector3D> buffer;
    auto pushBackVector = [&buffer](const Model::Point &point) {
        buffer.push_back(
            QVector3D(point.x / DIV_NORMALIZE,
                      point.y / DIV_NORMALIZE,
                      point.z / DIV_NORMALIZE)
        );
    };
    Model::generate_points(pushBackVector,
                           START_POINT,
                           COUNT_POINTS,
                           STEPS_PER_COUNT,
                           TAU,
                           modelName,
                           constants);
    ui->visualOpenGLWidget->addNewLocus(buffer);

    timeValue = 0;
    ui->horizontalSlider->setValue(timeValue);
    sliderTimer->start();
}

void Window::slot_time_slider(int timeValue_) {
    timeValue = timeValue_;
    ui->visualOpenGLWidget->setCurrentTime((COUNT_POINTS / ui->horizontalSlider->maximum()) * timeValue);
}

void Window::updateSlider() {
    ui->horizontalSlider->setValue(++timeValue);
    ui->visualOpenGLWidget->setCurrentTime((COUNT_POINTS / ui->horizontalSlider->maximum()) * timeValue);
    ui->visualOpenGLWidget->repaint();
}

Window::~Window() {
    delete ui;
}

void Window::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape)
        close();
    else {
        ui->visualOpenGLWidget->keyPressEvent(event);
    }
}

void Window::keyReleaseEvent(QKeyEvent *event) {
    ui->visualOpenGLWidget->keyReleaseEvent(event);
}

