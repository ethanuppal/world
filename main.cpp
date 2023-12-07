#include <iostream>
#include "gui/window.h"
#include "app/world_view.h"

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400

int main() {
    Window window("My Window", WINDOW_WIDTH, WINDOW_HEIGHT);
    window.attach_view(new WorldView());
    window.present();
}
