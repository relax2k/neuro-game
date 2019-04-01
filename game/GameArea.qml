import Qt3D.Core 2.12
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0
import QtSensors 5.11
import QtQuick 2.6 as QQ2


Entity {

    id: root

    property alias gameRoot: root
    property alias timerInterval: timer.interval
    property int initialTimeInterval: 5


    Entity {
        id: sun
        components: [
            DirectionalLight {
                color: Qt.rgba(0.8, 0.8, 0.8, 1)
                worldDirection: Qt.vector3d(-0.6, -0.5, -1)
            },
            DirectionalLight {
                color: Qt.rgba(0.8, 0.8, 0.8, 1)
                worldDirection: Qt.vector3d(-0.6, -0.5, 1)
            },
            DirectionalLight {
                color: Qt.rgba(0.8, 0.8, 0.8, 1)
                worldDirection: Qt.vector3d(0.6, -0.5, 1)
            }
        ]
    }

    Camera {
        property real x: 24.5
        property real y: 14.0

        id: camera
        projectionType: CameraLens.PerspectiveProjection
        fieldOfView: 45
        aspectRatio: 16/9
        nearPlane : 0.1
        farPlane : 1000.0
        position: Qt.vector3d( -(x + 10), -(y + 10), -50.0 )
        upVector: Qt.vector3d( 0.0, 1.0, 0.0 )
        viewCenter: Qt.vector3d( x, y, 0.0 )
    }

    RenderSettings {
        id: frameFraph
        activeFrameGraph: ForwardRenderer {
            clearColor: Qt.rgba(0.05, 0.55, 0.95, 1)
            camera: camera
        }
    }


    Ball {
        id: ball
        position: Qt.vector3d(camera.x, camera.y, 2.0)
    }

    Block {
        id: block
        position: Qt.vector3d(camera.x + 2, camera.y - 2, -20.0)
    }


    KeyboardDevice {
        id: keyboardController
    }

    InputSettings {
        id: inputSettings
    }

    KeyboardHandler {
        id: input
        sourceDevice: keyboardController
        focus: true
        onPressed: { }
    }


    QQ2.Component.onCompleted: {
        console.log("Start game...");
        timer.start()
    }

    QQ2.Timer {
        id: timer
        interval: initialTimeInterval
        repeat: true
        property real r: 10
        property real t: 0.1;
        onTriggered: {
            ball.position = Qt.vector3d(r * Math.sin(t), r * Math.cos(t), 0)
            t += 0.1;
        }
    }


    components: [frameFraph, input]
}
