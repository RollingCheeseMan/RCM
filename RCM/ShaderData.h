//
//  ShaderData.h
//  RCM
//
//  Created by Alex Fishbeck on 6/2/14.
//  Copyright (c) 2014 Rolling Cheese Man. All rights reserved.
//

#ifndef __RCM__ShaderData__
#define __RCM__ShaderData__

#include <iostream>
#include <GLFW/glfw3.h>

#include "Vectors.h"

class ShaderData
{
private:
    
    Vector4 _uColorValue;
    Vector3 _uLightPosition;
    
public:
    
    Vector4 get_uColorValue();
    void set_uColorValue(Vector4 newColor);
    
    Vector3 get_uLightPosition();
    void set_uLightPosition(Vector3 newPosition);
    
    ShaderData(Vector4 newColor, Vector3 newPosition);
    ~ShaderData();
};

#endif /* defined(__RCM__ShaderData__) */
