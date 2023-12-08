#include <iostream>
#include "gui/window.h"
#include "world/world_view.h"

#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 700

int main() {
    Window window("World", WINDOW_WIDTH, WINDOW_HEIGHT);

    WorldView* view = new WorldView();
    window.attach_view(view);

    window.present();
}
