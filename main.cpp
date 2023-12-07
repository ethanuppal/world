#include <iostream>
#include "gui/window.h"
#include "world/world.h"

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400

int main() {
    Window window("World", WINDOW_WIDTH, WINDOW_HEIGHT);

    Scene* scene = new Scene();
    scene->add(new Block(0, 0, 50, 50, 255, 0, 0, 255),
        Scene::Layer::background);
    scene->translate(-50, -50);

    WorldView* view = new WorldView(scene);
    window.attach_view(view);

    window.present();
}
