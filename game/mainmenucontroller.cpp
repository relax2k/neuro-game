#include "mainmenucontroller.hpp"

MainMenuController::MainMenuController(QObject *parent) : QObject(parent)
{

}

void MainMenuController::singlePlayrButtClickd()
{
    QMessageBox msgBox;
    msgBox.setText("Singleplayer button clicked.");
    msgBox.exec();
}

void MainMenuController::multiPlayrButtClickd()
{
    QMessageBox msgBox;
    msgBox.setText("Multiplayer button clicked.");
    msgBox.exec();
}

void MainMenuController::settngsButtClickd()
{
    QMessageBox msgBox;
    msgBox.setText("Settings button clicked.");
    msgBox.exec();
}
