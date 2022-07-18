import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4

Item {
    property QtObject module: null

    states: [
        State {
        name: "GUESSING"
        PropertyChanges {target: object; visible: true}
        },
        State {
            name: "CORRECT_ANSWER"
            PropertyChanges {target: object; visible: true}
        },
        State {
            name: "WRONG_ANSWER"
            PropertyChanges {target: object; visible: true}
        }
    ]

    Text {
        width: parent.width * 0.5
        height: parent.height * 0.3
        anchors.top: parent.top
        anchors.topMargin: parent.height * 0.1
        anchors.horizontalCenter: parent.horizontalCenter

        text: module ? module.values[0] : ""
        fontSizeMode: Text.Fit
        font.pixelSize: 72
        horizontalAlignment: Text.AlignHCenter
    }

    TextInput {
        id: input
        height: parent.height * 0.1
        width: parent.width * 0.5
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        clip: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter

        Rectangle{
            anchors.fill: parent
            color: "transparent"
            border.width: 1
        }

        onAccepted: console.log(input.text);
    }

    Rectangle{
        anchors.fill: parent
        color: "transparent"
        border.width: 1
    }
}
