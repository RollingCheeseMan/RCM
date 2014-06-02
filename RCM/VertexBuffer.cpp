//
//  VertexBuffer.cpp
//  RCM
//
//  Created by Alex Fishbeck on 6/2/14.
//  Copyright (c) 2014 Rolling Cheese Man. All rights reserved.
//

#include "VertexBuffer.h"

GLuint VertexBuffer::getVertexBufferID()
{
    return _vertexBufferID;
}

ShaderInterface *VertexBuffer::getShader()
{
    return _shader;
}

ShaderData *VertexBuffer::getShaderData()
{
    return _shaderData;
}

VertexBuffer::VertexBuffer(const GLvoid *data,
                           GLsizeiptr size,
                           GLenum mode,
                           GLsizei count,
                           GLsizei stride,
                           ShaderInterface *shader,
                           ShaderData *shaderData,
                           GLvoid *positionOffset,
                           GLvoid *normalOffset):
_mode(mode), _count(count), _stride(stride),
_shader(shader), _shaderData(shaderData),
_positionOffset(positionOffset), _normalOffset(normalOffset)
{
    glGenBuffers(1, &_vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &_vertexBufferID);
    _vertexBufferID = 0;
}

void VertexBuffer::configureVertexAttributes()
{
    if (_shader->get_aPositionVertex() != -1) {
        glEnableVertexAttribArray(_shader->get_aPositionVertex());
        glVertexAttribPointer(_shader->get_aPositionVertex(), 3, GL_FLOAT, GL_FALSE, _stride, _positionOffset);
    }
    
    if (_shader->get_aPositionNormal() != -1) {
        glEnableVertexAttribArray(_shader->get_aPositionNormal());
        glVertexAttribPointer(_shader->get_aPositionNormal(), 3, GL_FLOAT, GL_FALSE, _stride, _normalOffset);
    }
}

void VertexBuffer::renderVertexBuffer()
{
    glDrawArrays(_mode, 0, _count);
}