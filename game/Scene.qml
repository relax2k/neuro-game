import QtQuick 2.0
import Qt3D.Render 2.0
import Qt3D.Core 2.12


Item {

    id: scene

    Ball {
        id: ball
    }

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
}
