//
//  Vectors.h
//  RCM
//
//  Created by Alex Fishbeck on 6/2/14.
//  Copyright (c) 2014 Rolling Cheese Man. All rights reserved.
//

#ifndef __RCM__Vectors__
#define __RCM__Vectors__

#include <iostream>
#include <GLFW/glfw3.h>
#include <math.h>

#include "Matricies.h"

typedef struct {
    
    GLdouble x;
    GLdouble y;
    
} Vector2;

typedef struct {
    
    GLfloat x;
    GLfloat y;
    GLfloat z;
    
} Vector3;

Vector3 makeVector3(GLfloat x, GLfloat y, GLfloat z);
Vector3 addVector3(Vector3 vectorA, Vector3 vectorB);
Vector3 subtractVector3(Vector3 vectorA, Vector3 vectorB);
Vector3 normalizeVector3(Vector3 vector);
Vector3 scalerMultiplyVector3(Vector3 vectorToMultiply, GLfloat scalerValue);
Vector3 crossProductVector3(Vector3 vectorA, Vector3 vectorB);
GLfloat dotProductVector3(Vector3 vectorA, Vector3 vectorB);
Vector3 transformVector3(Vector3 vector, Matrix3 transformationMatrix);

typedef struct {
    
    GLfloat x;
    GLfloat y;
    GLfloat z;
    GLfloat w;
    
} Vector4;

Vector4 makeVector4(GLfloat x, GLfloat y, GLfloat z, GLfloat w);

#endif /* defined(__RCM__Vectors__) */
