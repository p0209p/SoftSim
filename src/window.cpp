#include "window.hpp"

Window::Window() {
    window = nullptr;
    height = 1080;
    width = 1920;
}

void Window::init_window() {
    glfwInit();
    window = glfwCreateWindow(1920, 1080, "SoftSim", NULL, NULL);
    if (!window) {
        std::cout<<"GLFW cannot be initialized";
        exit(1);
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD\n";
        exit(1);
    }
}

void Window::close_window() {
    glfwDestroyWindow(window);
}
