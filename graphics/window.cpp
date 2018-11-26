#include "window.h"
#include <iostream>

namespace mike { namespace graphics {







Window::Window(const char*  name,int width, int height)
:name(name)
,height(height)
,width(width)

{
   if (!init())
        glfwTerminate();
    for (int i=0;i<MAX_KEYS;i++)
        keys[i]=false;
     for (int i=0;i<MAX_BUTTONS;i++)
        mouseButtons[i]=false;

}

Window::~Window()
{
    glfwTerminate();
}


   void Window::update()
   {

        GLenum error = glGetError();
        if (error!= GL_NO_ERROR)
                std::cout<<"OpenGL error: "<<error<<std::endl;

        glfwPollEvents();


        glfwSwapBuffers(window);

   }

   void Window::clear() const
   {
       glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   }

    void window_resize_callback(GLFWwindow *window, int width, int height)
   {
       Window* win=(Window *)glfwGetWindowUserPointer(window);

       glfwGetFramebufferSize(win->getWindow(),&width,&height);
       glViewport(0,0,width,height);
   }


     void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        Window* win=(Window *)glfwGetWindowUserPointer(window);

        win->keys[key] = (action != GLFW_RELEASE);

    }

    void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
    {
        Window* win=(Window *)glfwGetWindowUserPointer(window);

        win->mouseButtons[button] = (action != GLFW_RELEASE);

    }

    void cursor_position_callback(GLFWwindow *window,double xpos, double ypos)
    {
        Window* win=(Window *)glfwGetWindowUserPointer(window);
        win->mouseX=xpos;
        win->mouseY=ypos;
    }



    bool Window::isKeyPressed(unsigned int keycode) const
    {

        if (keycode>= MAX_KEYS)
            return false;
        return keys[keycode];
    }

  bool Window::isMouseButtonPressed(unsigned int button) const
  {
      if (button>=MAX_BUTTONS)
        return false;
      return mouseButtons[button];

  }

   bool Window::init()
   {

        if (!glfwInit())
    {
         std::cout << "Failed to initialize GLFW"<< std::endl;
         return false;
    }

       window = glfwCreateWindow(width,height,name,NULL,NULL);
        if (!window)
        {
            glfwTerminate();
            std::cout<<"failed to create GLFW window"<<std::endl;
            return false;
        }
        glfwMakeContextCurrent(window);
        glfwSetWindowUserPointer(window,this);
        glfwSetWindowSizeCallback(window, window_resize_callback);
        glfwSetKeyCallback(window,key_callback);
        glfwSetMouseButtonCallback(window, mouse_button_callback);
        glfwSetCursorPosCallback(window,cursor_position_callback);

        if (glewInit()!= GLEW_OK)
        {
            std::cout<<"Could not initialize GLEW" <<std::endl;
            return false;
        }

        glEnable(GL_DEPTH_TEST);
        glViewport(0,0,width,height);

      std::cout << "OpenGL " <<glGetString(GL_VERSION) <<std::endl;


    return true;

   }

void Window::getMousePosistion(double& x, double& y) const
{
    x=mouseX;
    y=mouseY;
}



}
}
