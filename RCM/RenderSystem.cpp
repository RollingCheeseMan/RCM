//
//  RenderSystem.cpp
//  RCM
//
//  Created by Alex Fishbeck on 6/2/14.
//  Copyright (c) 2014 Rolling Cheese Man. All rights reserved.
//

#include "RenderSystem.h"

RenderSystem::RenderSystem(): _window(glfwGetCurrentContext())
{
    
}

RenderSystem::~RenderSystem()
{
    
}

void RenderSystem::render(VertexBuffer *vertexBuffer)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glUseProgram(vertexBuffer->getShader()->getProgramHandle());
    
    glLoadIdentity();
    GLKMatrix4MakeLookAt(3.0f, 2.0f, -5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    
    glUniform4f((vertexBuffer->getShader())->get_uColor(), 1.0, 0.0, 0.0, 1.0);
                
    vertexBuffer->configureVertexAttributes();
    vertexBuffer->renderVertexBuffer();
    
    glfwSwapBuffers(_window);
    glfwPollEvents();
}

RenderSystem& RenderSystem::getRenderSystem()
{
    static RenderSystem *renderSystem = NULL;
    
    if (renderSystem == NULL) {
        renderSystem = new RenderSystem();
        
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        
        glMatrixMode(GL_PROJECTION);
        GLKMatrix4MakePerspective(65.0f, 1280.0f/720.0f, 1, 1000);
        glViewport(0.0f, 0.0f, 1280.0f, 720.0f);
        glMatrixMode(GL_MODELVIEW);
        
        glEnable(GL_CULL_FACE);
    }
    
    return *renderSystem;
}

void RenderSystem::destroyRenderSystem()
{
    RenderSystem *renderSystem = &getRenderSystem();
    delete renderSystem;
}