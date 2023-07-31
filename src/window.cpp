#include "window.hpp"

Window::Window() {
    window = nullptr;
    width = 1920;
    height = 1080;
}

void Window::init_window(int w=1920, int h=1080) {
    glfwInit();
    window = glfwCreateWindow(w,h,"SoftSim",NULL,NULL);
    if (!window) {
        std::cout<<"Window cannot be opened";
        exit(1);
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD\n";
    }
}

void Window::run_window() {
    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();
    }
}

void Window::close_window() {
    glfwDestroyWindow(window);
}
