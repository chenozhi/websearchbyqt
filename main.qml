import QtQuick 2.0

Rectangle {
    width: 640
    height: 480
    Text {
        id:text
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }

    Connections{
        target: myParseResult
        onParseDone:{
             console.log("###Ω‚ŒˆÕÍ≥…: ")
            // text.text = total;
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {

            Qt.quit();
        }
    }
}
