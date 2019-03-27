import QtQuick 2.3
import QtQuick.Controls 2.5


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
            anchors.centerIn: parent
            width: parent.width * 0.8

            Button {
                id: singlePlayerButton
                anchors.horizontalCenter: parent.Center
                text: "Singleplayer"
                font.pointSize: 30
                width: parent.width
            }

            Button {
                id: multiplayerButton
                anchors.horizontalCenter: parent.Center
                text: "Multiplayer"
                font.pointSize: 30
                width: parent.width
            }

            Button {
                id: settingsButton
                anchors.horizontalCenter: parent.Center
                text: "Settings"
                font.pointSize: 30
                width: parent.width
            }

            Button {
                id: exitButton
                anchors.horizontalCenter: parent.Center
                text: "Exit"
                font.pointSize: 30
                width: parent.width
            }
        }
    }
}
