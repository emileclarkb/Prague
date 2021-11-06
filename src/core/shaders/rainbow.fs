#version 330 core

out vec4 FragColor;
//in vec3 ourColor;
in vec4 gl_FragCoord;

// Uniforms
uniform float time;
uniform vec2 resolution;


// Constant Declarations
// ray march constants
const uint MAX_STEPS = 25;
const uint MAX_DIST = 10;
const float HIT_DIST = 0.01;

//const vec2 screen = resolution.xy;
const float PI = 3.141592653589;
const float TAU = 2 * PI;
const float FOV = PI / 2;

const vec3 pos = vec3(0.0);
const vec2 screen = vec2(8, 6);


// signed distance function
float SDF(vec3 p) {
    // render sphere
    return length(vec3(0.0, 0.0, 1.0) - p) - 0.5;
}


void main() {
    // normalize uv
    vec2 uv1 = gl_FragCoord.xy / resolution;
    vec2 uv = screen * ((gl_FragCoord.xy / resolution) - 0.5);

    // distance from position to screen
    float d = screen.x / tan(FOV / 2);
    // view direction (switch to polar)
    vec3 view = vec3(0.0, 0.0, 1.0);
    view *= d;

    // construct ray
    vec3 ray = view + vec3(uv * screen, 0.0);
    ray = normalize(ray);

    float totalDist = 1;
    float marchDist;
    bool hit = false;
    int i = 0;
    for (; i < MAX_STEPS; i++) {
        marchDist = SDF(pos + ray * totalDist);
        totalDist += marchDist;

        if (marchDist <= HIT_DIST) {
            hit = true;
        }
        else if (totalDist >= MAX_DIST) {
            break;
        }
    }

    // vec3 col = vec3(i / MAX_STEPS, 0.0, 0.0);
    //vec3 col = vec3(0.0);
    //if (hit) {
    vec3 col = 0.5 + 0.5 * cos(time + uv1.xyx + vec3(0,2,4));
    //}
    FragColor = vec4(col, 1.0);
}
