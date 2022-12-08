#include <QtWidgets/QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "errors_processing.h"
#include "iostream"

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    param.param_draw.sc.scene = new QGraphicsScene();
    param.param_draw.sc.pen = QPen(Qt::red);
    param.param_draw.v.w = 750;
    param.param_draw.v.h = 750;
    param.filename = "coordinate_adj_matrix.txt";
    param.param_draw.sc.scene->setSceneRect(0,0,param.param_draw.v.w, param.param_draw.v.h);
    model_manager(LOAD_MODEL, param);
    model_manager(DRAW_MODEL, param);
    param.param_draw.v.view = ui->graphicsView;
    param.param_draw.v.view->setScene(param.param_draw.sc.scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bmove_clicked()
{
    param.param_move.x = ui->move_x->text().toDouble();
    param.param_move.y = ui->move_y->text().toDouble();
    param.param_move.z = ui->move_z->text().toDouble();

    int error = model_manager(MOVE_MODEL, param);

    if (error != SUCCESS)
        error_message("Не удалось переместить модель");
    else
    {
        free(param.param_draw.sc.scene);
        param.param_draw.sc.scene = new QGraphicsScene();
        param.param_draw.sc.scene->setSceneRect(0,0,param.param_draw.v.w, param.param_draw.v.h); // размер сцены
        model_manager(DRAW_MODEL, param);
        param.param_draw.v.view = ui->graphicsView;
        param.param_draw.v.view->setScene(param.param_draw.sc.scene);
    }
}

void MainWindow::on_bscale_clicked()
{
    int error = SUCCESS;

    param.param_scale.kx = ui->scale_x->text().toDouble();
    param.param_scale.ky = ui->scale_y->text().toDouble();
    param.param_scale.kz = ui->scale_z->text().toDouble();

    error = model_manager(SCALE_MODEL, param);

    if (error != SUCCESS)
        error_message("Не удалось промасштабировать модель");
    else
    {
        free(param.param_draw.sc.scene);
        param.param_draw.sc.scene = new QGraphicsScene();
        param.param_draw.sc.scene->setSceneRect(0,0,param.param_draw.v.w, param.param_draw.v.h); // размер сцены
        model_manager(DRAW_MODEL, param);
        param.param_draw.v.view = ui->graphicsView;
        param.param_draw.v.view->setScene(param.param_draw.sc.scene);
    }
}

void MainWindow::on_brotate_clicked()
{
    int error = SUCCESS;

    param.param_rotate.deg_x = ui->rotate_x->text().toDouble();
    param.param_rotate.deg_y = ui->rotate_y->text().toDouble();
    param.param_rotate.deg_z = ui->rotate_z->text().toDouble();

    error = model_manager(ROTATE_MODEL, param);

    if (error != SUCCESS)
        error_message("Не удалось повернуть модель");
    else
    {
        free(param.param_draw.sc.scene);
        param.param_draw.sc.scene = new QGraphicsScene();
        param.param_draw.sc.scene->setSceneRect(0,0,param.param_draw.v.w, param.param_draw.v.h); // размер сцены
        model_manager(DRAW_MODEL, param);
        param.param_draw.v.view = ui->graphicsView;
        param.param_draw.v.view->setScene(param.param_draw.sc.scene);
    }

}

void error_message(const char *text)
{
    QMessageBox qmbox;
    qmbox.setText(text);
    qmbox.exec();
    QApplication::quit();
}