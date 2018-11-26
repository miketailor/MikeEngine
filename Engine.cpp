#include "Engine.h"
#include <iostream>

namespace mike {
Engine::Engine()
{
std::cout<<"Engine created"<<std::endl;
}

Engine::~Engine()
{
std::cout<<"Engine destroyed"<<std::endl;
}

void Engine::run()
{
    std::cout<<"Engine loop"<<std::endl;
}
}
