//
//  ShaderInterface.cpp
//  RCM
//
//  Created by Alex Fishbeck on 6/2/14.
//  Copyright (c) 2014 Rolling Cheese Man. All rights reserved.
//

#include "ShaderInterface.h"

char *ShaderInterface::loadTextFromFile(const char *file)
{
    FILE *currentFile = fopen(file, "rt");
    fseek(currentFile, 0, SEEK_END);
    int count = (int)ftell(currentFile);
    
    rewind(currentFile);
    char *data = (char *)malloc(sizeof(char)*(count+1));
    count = (int)fread(data, sizeof(char), count, currentFile);
    data[count] = '\0';
    
    fclose(currentFile);
    
    return data;
}

GLuint ShaderInterface::getProgramHandle()
{
    return shader->getProgramHandle();
}

GLint ShaderInterface::get_aPositionVertex()
{
    return _aPositionVertex;
}

GLint ShaderInterface::get_aPositionNormal()
{
    return _aPositionNormal;
}

GLint ShaderInterface::get_uColor()
{
    return _uColor;
}

GLint ShaderInterface::get_uPositionLight()
{
    return _uPositionLight;
}

ShaderInterface::ShaderInterface(const char *vs, const char *fs)
{
    _vertexShaderString = loadTextFromFile(vs);
    _fragmentShaderString = loadTextFromFile(fs);
    
    shader = new ShaderLoader(_vertexShaderString, _fragmentShaderString);
    
    free(_vertexShaderString);
    free(_fragmentShaderString);
    
    _aPositionVertex = glGetAttribLocation(shader->getProgramHandle(), "aPositionVertex");
    _aPositionNormal = glGetAttribLocation(shader->getProgramHandle(), "aPositionNormal");
    
    _uColor = glGetUniformLocation(shader->getProgramHandle(), "uColor");
    _uPositionLight = glGetUniformLocation(shader->getProgramHandle(), "uPositionLight");
}

ShaderInterface::~ShaderInterface()
{
    delete shader;
}