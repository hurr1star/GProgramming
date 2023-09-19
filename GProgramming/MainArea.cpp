#include <GLFW/glfw3.h>
#include <iostream>

int resX = 640;
int resY = 360;

bool colorSwap = false;
double lastColorChangeTime = 0.0;
double colorChangeInterval = 1.0; // 1 second interval

bool swapRunning = false;

void swap_bg_color()
{
    colorSwap = !colorSwap;
    // swap the color (oranange blue)
    if (colorSwap)
    {
        glClearColor(1.0f, 0.5f, 0.0f, 1.0f); // R, G, B, Alpha
    }
    else
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // R, G, B, Alpha
}

// Function to handle keyboard input
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_Q && action == GLFW_PRESS) {
        // 'q' key was pressed
        std::cout << "The 'q' key was pressed!" << std::endl;

        // call the core func for the colors
        //swap_bg_color();

        // Toogle the swap
        swapRunning = !swapRunning;

        std::cout << swapRunning << std::endl;
    }

    // Escape only on release ESC key
    if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
    {
        std::cout << "lets get outta here" << std::endl;

        // call window close
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

// Function to handle mouse cursor position
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {

    std::cout << "Mouse Position: X = " << xpos << ", Y = " << ypos << std::endl;
}

// Function to handle mouse scroll logic
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    std::cout << "Mouse Scroll X" << xoffset << ", Y = " << yoffset << std::endl;
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

    // Set up mouse scroll callback
    glfwSetScrollCallback(window, scroll_callback);

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Start with colorized window area
    swap_bg_color();

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // Render graphics here (not included in this basic example)
        // Calculate the time elapsed since the last color change
        double currentTime = glfwGetTime();
        std::cout << currentTime << std::endl;
        double elapsedTime = currentTime - lastColorChangeTime;
        std::cout << elapsedTime << std::endl;

        // Check if it's time to swap colors
        if (elapsedTime >= colorChangeInterval && swapRunning) {
            swap_bg_color();
            lastColorChangeTime = currentTime;
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW and clean up
    glfwTerminate();
    return 0;
}