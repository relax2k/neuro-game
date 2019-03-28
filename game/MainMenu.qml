import QtQuick 2.3
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12


Item {
    id: root
    anchors.centerIn: parent
    width: parent.width / 3
    height: parent.height / 1.5

    Rectangle {
        anchors.fill: parent
        color: "black"
        opacity: 0.75

        Column {
            id: column
            anchors.centerIn: parent
            width: parent.width * 0.8
            spacing: 5

            Button {
                id: singlePlayerButton
                Layout.alignment: Qt.AlignCenter
                text: "Singleplayer"
                font.pointSize: 30
                width: parent.width
            }

            Button {
                id: multiplayerButton
                Layout.alignment: Qt.AlignCenter
                text: "Multiplayer"
                font.pointSize: 30
                width: parent.width
            }

            Button {
                id: settingsButton
                Layout.alignment: Qt.AlignCenter
                text: "Settings"
                font.pointSize: 30
                width: parent.width
            }

            Button {
                id: exitButton
                Layout.alignment: Qt.AlignCenter
                text: "Exit"
                font.pointSize: 30
                width: parent.width
            }
        }
    }
}
