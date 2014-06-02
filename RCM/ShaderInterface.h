//
//  ShaderInterface.h
//  RCM
//
//  Created by Alex Fishbeck on 6/2/14.
//  Copyright (c) 2014 Rolling Cheese Man. All rights reserved.
//

#ifndef __RCM__ShaderInterface__
#define __RCM__ShaderInterface__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "ShaderLoader.h"

class ShaderInterface
{
private:
    
    ShaderLoader *shader;
    
    GLint _aPositionVertex;
    GLint _aPositionNormal;
    GLint _uColor;
    GLint _uPositionLight;
    
    char *_vertexShaderString;
    char *_fragmentShaderString;
    
    char *loadTextFromFile(const char *file);
    
public:
    
    GLuint getProgramHandle();
    
    GLint get_aPositionVertex();
    GLint get_aPositionNormal();
    GLint get_uColor();
    GLint get_uPositionLight();
    
    ShaderInterface(const char *vs, const char *fs);
    ~ShaderInterface();
};

#endif /* defined(__RCM__ShaderInterface__) */
