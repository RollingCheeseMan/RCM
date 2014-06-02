//
//  VertexData.h
//  RCM
//
//  Created by Alex Fishbeck on 6/2/14.
//  Copyright (c) 2014 Rolling Cheese Man. All rights reserved.
//

#ifndef RCM_VertexData_h
#define RCM_VertexData_h

#include "Vectors.h"

typedef struct {
    
    Vector3 positionCoordinates;
    
} VertexDataP;

typedef struct {
    
    Vector3 positionCoordinates;
    Vector3 normalCoordinates;
    
} VertexDataPN;

#endif
