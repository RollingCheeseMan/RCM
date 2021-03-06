//
//  Matricies.h
//  RCM
//
//  Created by Alex Fishbeck on 6/2/14.
//  Copyright (c) 2014 Rolling Cheese Man. All rights reserved.
//

#ifndef __RCM__Matricies__
#define __RCM__Matricies__

#include <iostream>
#include <GLFW/glfw3.h>
#include <math.h>

typedef struct {
    
    GLfloat m00;
    GLfloat m01;
    GLfloat m02;
    GLfloat m10;
    GLfloat m11;
    GLfloat m12;
    GLfloat m20;
    GLfloat m21;
    GLfloat m22;
    
} Matrix3;

Matrix3 scalerMultiplyMatrix3(Matrix3 matrix, GLfloat scalerValue);
Matrix3 addMatrix3(Matrix3 matrixA, Matrix3 matrixB);
Matrix3 makeRotationMatrix3(GLfloat angle, GLfloat xAxis, GLfloat yAxis, GLfloat zAxis);

const Matrix3 identityMatrix3 = {   1.0f, 0.0f, 0.0f,
                                    0.0f, 1.0f, 0.0f,
                                    0.0f, 0.0f, 1.0f};

#endif /* defined(__RCM__Matricies__) */
