import Qt3D.Core 2.12
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0
import QtQuick 2.6 as QQ2


Entity {
    id: root

    Entity {
        id: sun
        components: [
            DirectionalLight {
                color: Qt.rgba(0.8, 0.8, 0.8, 0.5)
                worldDirection: Qt.vector3d(-0.6, -0.5, -1)
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
        position: Qt.vector3d( x, y, 33.0 )
        upVector: Qt.vector3d( 0.0, 1.0, 0.0 )
        viewCenter: Qt.vector3d( x, y, 0.0 )
    }

    RenderSettings {
        id: frameFraph
        activeFrameGraph: ForwardRenderer {
            clearColor: Qt.rgba(0, 0, 0, 1)
            camera: camera
        }
    }

    Ball {
        id: ball
        position: Qt.vector3d(camera.x, camera.y, 2.0)
    }

    components: [frameFraph]
}
