//
//  GameManager.h
//  RCM
//
//  Created by Alex Fishbeck on 6/2/14.
//  Copyright (c) 2014 Rolling Cheese Man. All rights reserved.
//

#ifndef __RCM__GameManager__
#define __RCM__GameManager__

#include <iostream>
#include <GLFW/glfw3.h>

#include "RenderSystem.h"
#include "ResourceManager.h"

class GameManager
{
private:
    
    bool _running;
    RenderSystem *_renderSystem;
    ResourceManager *_resourceManager;
    GLFWwindow *_window;
    
    GameManager(bool running);
    ~GameManager();
    
public:
    
    void runGameLoop();
    
    static GameManager& getGameManager();
    static void destroyGameManager();
};

#endif /* defined(__RCM__GameManager__) */
