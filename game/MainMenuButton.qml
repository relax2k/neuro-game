import QtQuick 2.6
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12


Item {
    id: root
    anchors.top: parent.top
    width: parent.width / 20

    Button {
        id: singlePlayerButton
        Layout.alignment: Qt.AlignCenter
        opacity: 0.9
        text: "Menu"
        font.pointSize: 10
        width: parent.width
        onClicked: {
            mainMenu.visible = true
            mainMenuButton.visible = false
        }
    }
}
