import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4

Window {
    visible: true
    width: 1280
    height: 720

    title: qsTr("Transcription")

    property double scrollPosition: 0.0

    Text {
        id: moduleName
        width: parent.width
        height: 20
        text: transcription.modules[0].moduleName
        horizontalAlignment: Text.AlignHCenter
    }

    Item {
        anchors.top: moduleName.bottom
        anchors.topMargin: 20
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        ListView {
            height: parent.height
            model: transcription.modules[0].keys
            anchors.right: parent.horizontalCenter
            anchors.left: parent.left
            anchors.leftMargin: 20
            clip: true
            interactive: false

            delegate: Rectangle{
                width: parent.width
                height: 20
                border.width: 1
                border.color: "black"
                color: "transparent"

                Text {
                    text: modelData
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                }
            }

            ScrollBar.vertical: ScrollBar {
                policy: ScrollBar.AlwaysOff
                position: scrollPosition
            }
        }

        ListView {
            anchors.left: parent.horizontalCenter
//            width: parent.width / 2
            height: parent.height
            anchors.right: parent.right
            model: transcription.modules[0].values
            interactive: false

            clip: true
            delegate: Rectangle{
                width: parent.width - 20
                height: 20
                border.width: 1
                border.color: "black"
                color: "transparent"

                Text {
                    text: modelData
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                }
            }
            ScrollBar.vertical: ScrollBar {
                id: scrollBar
                anchors.right: parent.right
                width: 20
                height: parent.height
                clip: true
                policy: ScrollBar.AlwaysOn

                onPositionChanged: scrollPosition = position
            }
        }
    }
}
