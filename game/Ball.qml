import Qt3D.Core 2.12
import Qt3D.Render 2.0
import Qt3D.Extras 2.0

import Engine.Objs 1.0


CBall {

    // TODO(Yuki/ball texturing)

    property alias position: transform.translation

    PhongMaterial {
        id: material
        diffuse: "red"
    }

    SphereMesh {
        id: mesh
    }

    Transform {
        id: transform
//        translation: position
    }

    components: [material, mesh, transform]
}
