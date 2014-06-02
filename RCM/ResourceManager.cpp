//
//  ResourceManager.cpp
//  RCM
//
//  Created by Alex Fishbeck on 6/2/14.
//  Copyright (c) 2014 Rolling Cheese Man. All rights reserved.
//

#include "ResourceManager.h"

#include "Triangle.h"
#include "Cube.h"

ResourceManager::ResourceManager()
{
    _shaderArray = new std::vector<ShaderInterface *>();
    ShaderInterface *colorShader = new ShaderInterface("ColorShader.vsh", "ColorShader.fsh");
    _shaderArray->push_back(colorShader);
    ShaderInterface *lightShader = new ShaderInterface("SimpleLightShader.vsh", "SimpleLightShader.fsh");
    _shaderArray->push_back(lightShader);
    
    shaderData = new ShaderData(makeVector4(1.0f, 0.0f, 1.0f, 1.0f), makeVector3(1.0f, 1.0f, 1.0f));
    
    _vertexBufferArray = new std::vector<VertexBuffer *>();
    VertexBuffer *triangleVertexBuffer = new VertexBuffer(triangleVertices,
                                                          sizeof(triangleVertices),
                                                          GL_TRIANGLES,
                                                          3,
                                                          sizeof(GL_FLOAT)*3,
                                                          _shaderArray->at(0),
                                                          shaderData,
                                                          NULL,
                                                          NULL);
    _vertexBufferArray->push_back(triangleVertexBuffer);
    VertexBuffer *cubeVertexBuffer = new VertexBuffer(cubeVertices,
                                                          sizeof(cubeVertices),
                                                          GL_TRIANGLES,
                                                          36,
                                                          sizeof(VertexDataPN),
                                                          _shaderArray->at(1),
                                                          shaderData,
                                                          (GLvoid *)(offsetof(VertexDataPN, positionCoordinates)),
                                                          (GLvoid *)(offsetof(VertexDataPN, normalCoordinates)));
    _vertexBufferArray->push_back(cubeVertexBuffer);
}

ResourceManager::~ResourceManager()
{
    for (std::vector<ShaderInterface *>::iterator i = _shaderArray->begin(); i != _shaderArray->end(); i++) {
        delete *i;
    }
    delete _shaderArray;
    
    for (std::vector<VertexBuffer *>::iterator i = _vertexBufferArray->begin(); i != _vertexBufferArray->end(); i++) {
        delete *i;
    }
        delete _vertexBufferArray;
}

std::vector<ShaderInterface *>* ResourceManager::getShaderArray()
{
    return _shaderArray;
}

std::vector<VertexBuffer *>* ResourceManager::getVertexBufferArray()
{
    return _vertexBufferArray;
}

ResourceManager& ResourceManager::getResourceManager()
{
    static ResourceManager *resourceManager = NULL;
    
    if (resourceManager == NULL) {
        resourceManager = new ResourceManager();
    }
    
    return *resourceManager;
}

void ResourceManager::destroyResourceManager()
{
    ResourceManager *resourceManager = &getResourceManager();
    delete resourceManager;
}