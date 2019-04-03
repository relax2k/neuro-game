import QtQuick 2.6
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

import Engine.Core 1.0


Item {
    id: root
    anchors.top: parent.top
    width: parent.width / 20

    Button {
        id: singlePlayerButton
        Layout.alignment: Qt.AlignCenter
        opacity: 0.9
        text: "Menu"
        font.pointSize: root.width / 5
        width: parent.width
        onClicked: {
            Engine.state = State.MENU
            mainMenu.visible = true
            mainMenuButton.visible = false
        }
    }
}
