#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace mike { namespace graphics {

#define MAX_KEYS 1024
#define MAX_BUTTONS 32
class Window
{
    public:

        Window(const char* name,int width, int height);
        virtual ~Window();
        void update();
        void clear() const;
        bool isClosed()const {return glfwWindowShouldClose(window);};
        inline int getWidth() const {return width;};
        inline int getHeight() const {return height;};
        friend void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
        friend void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
        friend void cursor_position_callback(GLFWwindow *window,double xpos, double ypos);
        bool isKeyPressed(unsigned int keycode) const;
        bool isMouseButtonPressed(unsigned int button) const ;
        void getMousePosistion(double& x, double& y) const;
        GLFWwindow* getWindow() {return window;};
    protected:

    private:
        const char* name;
        int height,width;
        GLFWwindow* window;
        bool closed;

        bool keys[MAX_KEYS];
        bool mouseButtons[MAX_BUTTONS];
        double mouseX,mouseY;
        bool init();


};

} }

#endif // WINDOW_H



