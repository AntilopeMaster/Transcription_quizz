import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4

Item {

    property double scrollPosition: 0.0

    property QtObject module: null

    Text {
        id: moduleNameText
        width: parent.width
        height: 20
        text: module ? module.moduleName : ""
        horizontalAlignment: Text.AlignHCenter
    }

    Item {
        anchors.top: moduleNameText.bottom
        anchors.topMargin: 20
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        ListView {
            height: parent.height
            model: module ? module.keys : null
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
            height: parent.height
            anchors.right: parent.right
            model: module ? module.values : null
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
