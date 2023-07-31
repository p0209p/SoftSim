#include "window.hpp"

int main() {
    Window w;
    w.init_window(1920, 1080);
    w.run_window();
    w.close_window();
    return 0;
}
