import Qt3D.Core 2.12
import Qt3D.Render 2.0
import Qt3D.Extras 2.0

import Engine.Objs 1.0


CBall {

    property alias position: transform.translation

    PhongMaterial {
        id: material
        diffuse: "yellow"
    }

    SphereMesh {
        id: mesh
    }

    Transform {
        id: transform
    }

    components: [material, mesh, transform]
}
