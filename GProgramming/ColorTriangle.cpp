#include <GLFW/glfw3.h>
#include <iostream>

int resX = 1920;
int resY = 1080;

// Vertex data for a triangle
GLfloat vertices[] = {
    -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // Bottom-left vertex (x, y, r, g, b, a)
     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // Bottom-right vertex
     0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f  // Top vertex
};

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(1920, 1080, "Magic Triangle", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Main rendering loop
    while (!glfwWindowShouldClose(window)) {
        // Poll for and process events
        glfwPollEvents();

        // Clear the buffer
        glClear(GL_COLOR_BUFFER_BIT);

        // Render the triangle
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), vertices);
        glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), &vertices[3]);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);

        // Swap front and back buffers
        glfwSwapBuffers(window);
    }

    // Clean up and exit
    glfwTerminate();

    return 0;
}