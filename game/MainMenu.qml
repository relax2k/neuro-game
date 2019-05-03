import QtQuick 2.6
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
import Engine.Core 1.0

Item {

    id: root
    anchors.centerIn: parent
    width: parent.width
    height: parent.height

    Rectangle {
        id:rect

        anchors.fill: parent
        color: "white"
        opacity: 1
    }

    Column {
        id: column
        anchors.centerIn: rect
        width: rect.width * 0.8
        spacing: 5
        opacity: 0.9

        Button {
            id: singlePlayerButton
            Layout.alignment: Qt.AlignCenter
            text: "Singleplayer"
            font.pointSize: root.width / 15
            width: parent.width
//            onClicked: { Engine.singlePlayer() }
        }

        Button {
            id: multiplayerButton
            Layout.alignment: Qt.AlignCenter
            text: "Multiplayer"
            font.pointSize: root.width / 15
            width: parent.width
//            onClicked: { cppController.multiPlayrButtClickd() }
        }

        Button {
            id: settingsButton
            Layout.alignment: Qt.AlignCenter
            text: "Settings"
            font.pointSize: root.width / 15
            width: parent.width

//            onClicked: { cppController.settngsButtClickd() }
        }

        Button {
            id: exitButton
            Layout.alignment: Qt.AlignCenter
            text: "Exit"
            font.pointSize: root.width / 15
            width: parent.width
            onClicked: Qt.quit()
        }
    }
}
