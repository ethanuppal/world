#include <iostream>
#include "gui/window.h"
#include "world/world.h"

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400

int main() {
    Window window("World", WINDOW_WIDTH, WINDOW_HEIGHT);

    Scene* scene = new Scene();
    WorldView* view = new WorldView(scene);
    window.attach_view(view);

    window.present();
}
