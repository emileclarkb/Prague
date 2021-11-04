#version 330 core

out vec4 FragColor;
//in vec3 ourColor;
in vec4 gl_FragCoord;

// Uniforms
uniform float time;
uniform vec2 resolution;


// Constant Declarations
//const vec2 screen = resolution.xy;
const float PI = 3.141592653589;
const float TAU = 2 * PI;
const uint FOV = PI / 2;

const vec3 pos = vec3(0.0f);

void main() {
    // normalize uv
    vec2 uv = gl_FragCoord.xy / resolution;

    // construct ray
    //vec3 ray =

    vec3 col = 0.5 + 0.5 * cos(time + uv.xyx + vec3(0,2,4));
    FragColor = vec4(col, 1.0);
}
