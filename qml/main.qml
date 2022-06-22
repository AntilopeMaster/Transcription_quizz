import QtQuick 2.9
import QtQuick.Window 2.11
import QtQuick.Controls 1.5


Window {
    id:  mainWindow
    visible: true
    width: 1280
    height: 720

    title: qsTr("Transcription")

    AddModule {
        id: addModuleDialog

        width: mainWindow.width / 2
        height: mainWindow.height / 2
    }


    ComboBox {
        id: moduleComboBox

        model : transcription.modulesName

        width: parent.width * 0.3
        height: parent.height * 0.05
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.leftMargin: parent.width * 0.05
        anchors.topMargin: parent.height * 0.05 - height / 2
    }

    Button {
        width: parent.width * 0.3
        height: parent.height * 0.05

        anchors.left: moduleComboBox.right
        anchors.leftMargin: parent.width * 0.05
        anchors.verticalCenter: moduleComboBox.verticalCenter

        text: "Ajouter un module"

        onClicked: addModuleDialog.visible = true
//        onClicked: transcription.addModules("")
    }


    ModuleContent {
       height: parent.height * 0.9
       width: parent.width * 0.9

       anchors.horizontalCenter: parent.horizontalCenter
       module: transcription.modules[moduleComboBox.currentIndex]
       anchors.bottom: parent.bottom
    }
}
