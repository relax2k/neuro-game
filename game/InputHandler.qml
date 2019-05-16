import QtQuick 2.0
import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0


Entity {

    KeyboardDevice {
        id: keyboardController
    }

    InputSettings { id: inputSettings }

    KeyboardHandler {
        id: input
        sourceDevice: keyboardController
        focus: true
        onPressed: {
            console.log("pressed!")
        }
    }

    components: [input]
}
