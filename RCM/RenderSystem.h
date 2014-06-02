//
//  RenderSystem.h
//  RCM
//
//  Created by Alex Fishbeck on 6/2/14.
//  Copyright (c) 2014 Rolling Cheese Man. All rights reserved.
//

#ifndef __RCM__RenderSystem__
#define __RCM__RenderSystem__

#include <iostream>
#include <GLFW/glfw3.h>
#include <GLKit/GLKMath.h>
#include <vector>

#include "VertexBuffer.h"
#include "ShaderInterface.h"

class RenderSystem
{
private:
    
    GLFWwindow *_window;
    
    RenderSystem();
    ~RenderSystem();
    
public:
    
    void render(VertexBuffer *vertexBuffer);
    
    static RenderSystem& getRenderSystem();
    static void destroyRenderSystem();
};

#endif /* defined(__RCM__RenderSystem__) */
