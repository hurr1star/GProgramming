#include <GLFW/glfw3.h>
#include <iostream>

int resX = 640;
int resY = 360;

// Function to handle keyboard input
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_Q && action == GLFW_PRESS) {
        // 'q' key was pressed
        std::cout << "The 'q' key was pressed!" << std::endl;
    }
}

// Function to handle mouse cursor position
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
    std::cout << "Mouse Position: X = " << xpos << ", Y = " << ypos << std::endl;
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(resX, resY, "GLFW Window", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Set up the keyboard input callback
    glfwSetKeyCallback(window, key_callback);

    // Set up the cursor position callback
    glfwSetCursorPosCallback(window, cursor_position_callback);

    // Make the window's context current
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        // Render graphics here (not included in this basic example)

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW and clean up
    glfwTerminate();
    return 0;
}