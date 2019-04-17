import QtQuick 2.6
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12



Item {
    id: root
    anchors.centerIn: parent
    width: parent.width * 0.8

    Rectangle {
        id:rectPlayMenu

        anchors.fill: parent
        color: "black"
        opacity: 1
    }

    Column {
        id: columnPlayMenu
        anchors.centerIn: rectPlayMenu
        width: rectPlayMenu.width * 0.8
        spacing: 5
        opacity: 0.9

        Button {
            id: singlePlayerButton
            Layout.alignment: Qt.AlignCenter
            opacity: 0.9
            text: "Menu"
            font.pointSize: root.width / 10
            width: parent.width
            onClicked: { }
        }
    }
}
