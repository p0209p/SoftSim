#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>

class Window {
    public:
        GLFWwindow *window;
        int height;
        int width;
        Window();
        void init_window(int w, int h);
        void run_window();
        void close_window();
};

#endif
