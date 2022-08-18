import QtQuick 2.9
import QtQuick.Window 2.11
import QtQuick.Dialogs 1.3
import QtQuick.Controls 1.5


Window {
    id: addModuleWindow
    flags: Qt.NonModal | Qt.Dialog

    FileDialog {
        id: fileDialog
        width: addModuleDialog.width * 0.6
        height: addModuleDialog.height * 0.6
        title: "Choisissez un fichier de module"
//        folder: shortcuts.home
        nameFilters: ["Modules files (*.module)"]
        onAccepted: {
           console.log("You chose: " + fileDialog.fileUrl)
        }
    }

    Column {
        anchors.fill: parent

        Item {
            width: parent.width
            height: parent.height / 3

            Text {
                id: modulePathText
                width: parent.width * 0.7
                height: parent.height * 0.2
                anchors.verticalCenter: parent.verticalCenter
                verticalAlignment: Text.AlignVCenter
                text: fileDialog.fileUrl
            }

            Button {
                id: modulePathButton
                height: parent.height * 0.2
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                text: "Sélectionner un fichier"

                onClicked: fileDialog.open()
            }

        }

        Item {
            width: parent.width
            height: parent.height / 3

            Text {
                id: moduleNameText
                width: parent.width * 0.2
                height: parent.height * 0.2
                anchors.verticalCenter: parent.verticalCenter
                verticalAlignment: Text.AlignVCenter
                text: "Nom du module :"
            }

            TextInput {
                id: moduleNameInput
                anchors.left: moduleNameText.right
                maximumLength: 20
                width: parent.width * 0.4
                height: parent.height * 0.2
                anchors.verticalCenter: parent.verticalCenter
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                Rectangle {
                    anchors.fill: parent
                    color: "transparent"
                    border.width: 1
                }
            }
        }

        Item {
            width: parent.width
            height: parent.height / 3

            Button {
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width * 0.6
                height: parent.height * 0.5

                enabled: {
                    return fileDialog.fileUrl.toString() !== ""
                }

                text: "Ajouter le module"

                onClicked: {
                    transcription.addModules(fileDialog.fileUrl, moduleNameInput.text)
                    addModuleWindow.close()
                }
            }
        }
    }
}
