#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <emscripten/emscripten.h>
#include <iostream>

GLFWwindow* window;

void render() {
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // Red background
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
}

int main() {
    if (!glfwInit()) return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);

    window = glfwCreateWindow(800, 600, "OpenGL ES 3.2", nullptr, nullptr);
    if (!window) return -1;

    glfwMakeContextCurrent(window);
    if (!gladLoadGLES2Loader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to init GLAD\n";
        return -1;
    }

    emscripten_set_main_loop(render, 0, true); // ✅ non-blocking
    return 0;
}