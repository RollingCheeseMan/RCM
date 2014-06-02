//
//  ResourceManager.h
//  RCM
//
//  Created by Alex Fishbeck on 6/2/14.
//  Copyright (c) 2014 Rolling Cheese Man. All rights reserved.
//

#ifndef __RCM__ResourceManager__
#define __RCM__ResourceManager__

#include <iostream>
#include <vector>

#include "ShaderInterface.h"
#include "ShaderData.h"
#include "VertexBuffer.h"

class ResourceManager
{
private:
    
    std::vector<ShaderInterface *> *_shaderArray;
    std::vector<VertexBuffer *> *_vertexBufferArray;
    
    ShaderData *shaderData;
    
    ResourceManager();
    ~ResourceManager();
    
public:
    
    std::vector<ShaderInterface *>* getShaderArray();
    std::vector<VertexBuffer *>* getVertexBufferArray();
    
    static ResourceManager& getResourceManager();
    static void destroyResourceManager();
};

#endif /* defined(__RCM__ResourceManager__) */
