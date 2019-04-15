import QtQuick 2.6
import QtQuick.Controls 1.4
import QtQuick.Scene3D 2.0


Item {

    id: mainWindow

    visible: true
    width: 1280
    height: 768


    Scene3D {
        id: scene
        anchors.fill: parent
        focus: true
        aspects: "input"

        GameArea {
           id: gameArea
        }
    }


    MainMenu {
        id: mainMenu
        visible: true
    }

    MainMenuButton {
        id: mainMenuButton
        visible: false
    }
}
