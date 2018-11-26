#include <iostream>
#include "graphics/window.h"


int main()
{
mike::graphics::Window window("TEST",800,600);


while (!window.isClosed())
{
    window.clear();
    window.update();
}

}
