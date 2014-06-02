//
//  GameManager.cpp
//  RCM
//
//  Created by Alex Fishbeck on 6/2/14.
//  Copyright (c) 2014 Rolling Cheese Man. All rights reserved.
//

#include "GameManager.h"

GameManager::GameManager(bool running):
_running(running), _window(glfwGetCurrentContext()),
_renderSystem(&RenderSystem::getRenderSystem()), _resourceManager(&ResourceManager::getResourceManager())
{
    
}

GameManager::~GameManager()
{
    ResourceManager::destroyResourceManager();
    RenderSystem::destroyRenderSystem();
}

void GameManager::runGameLoop()
{
    double lastTime = glfwGetTime();
    double deltaTime = 0.0f;
    
    while (_running) {
        double currentTime = glfwGetTime();
        deltaTime += (currentTime - lastTime) * 60.0f;
        lastTime = currentTime;
        
        while (deltaTime >= 1.0f) {
            _running = !glfwWindowShouldClose(_window);

            --deltaTime;
        }
        
        _renderSystem->render(_resourceManager->getVertexBufferArray()->at(0));
    }
}

GameManager& GameManager::getGameManager()
{
    static GameManager *gameManager = NULL;
    
    if (gameManager == NULL) {
        glfwInit();
        
        glfwWindowHint(GLFW_DEPTH_BITS, 24);
        glfwWindowHint(GLFW_RED_BITS, 8);
        glfwWindowHint(GLFW_GREEN_BITS, 8);
        glfwWindowHint(GLFW_BLUE_BITS, 8);
        glfwWindowHint(GLFW_ALPHA_BITS, 8);
        glfwWindowHint(GLFW_SAMPLES, 16);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        
        GLFWwindow *window = glfwCreateWindow(1280, 720, "RCM", NULL, NULL);
        glfwMakeContextCurrent(window);
        
        gameManager = new GameManager(true);
    }
    
    return *gameManager;
}

void GameManager::destroyGameManager()
{
    GameManager *gameManager = &getGameManager();
    delete gameManager;
    
    GLFWwindow *window = glfwGetCurrentContext();
    glfwDestroyWindow(window);
    
    glfwTerminate();
}