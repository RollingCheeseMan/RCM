attribute vec3 aPositionVertex;
attribute vec3 aPositionNormal;

uniform vec4 uColor;
uniform uLightPosition;

varying vec4 vFinalVertexColor;

void main()
{
    vec3 normal = normalize(gl_NormalMatrix * aPositionNormal);
    
    vec3 lightPosition = normalize(uLightPosition);
    
    float dotProduct = max(dot(normal, lightPosition), 0.0);
    
    vFinalVertexColor = dotProduct * uColor;
    
    gl_Position = gl_ModelViewMatrixProjection * vec4(aPositionVertex, 1.0);
}