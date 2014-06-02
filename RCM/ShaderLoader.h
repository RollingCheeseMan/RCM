//
//  ShaderLoader.h
//  RCM
//
//  Created by Alex Fishbeck on 6/2/14.
//  Copyright (c) 2014 Rolling Cheese Man. All rights reserved.
//

#ifndef __RCM__ShaderLoader__
#define __RCM__ShaderLoader__

#include <iostream>
#include <GLFW/glfw3.h>

class ShaderLoader
{
private:
    
    GLuint _programHandle;
    GLuint compileShader(GLenum shader, const char *source);
    
public:
    
    GLuint getProgramHandle();
    
    ShaderLoader(const char *sourceVS, const char *sourceFS);
    ~ShaderLoader();
};

#endif /* defined(__RCM__ShaderLoader__) */
