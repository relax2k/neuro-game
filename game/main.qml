import QtQuick 2.6
import QtQuick.Controls 1.4
import QtQuick.Scene3D 2.0


Item {

    id: mainWindow

    visible: true
    width: 320 // TODO
    height: 768

    MainMenu {
        id: mainMenu
        visible: true
    }

    MainMenuButton {
        id: mainMenuButton
        visible: false
    }
}
