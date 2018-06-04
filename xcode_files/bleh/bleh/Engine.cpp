//
//  Engine.cpp
//  bleh
//
//  Created by Vicky Gough on 03/06/2018.
//  Copyright © 2018 Vicky Gough. All rights reserved.
//

#include "Engine.h"
#include <iostream>
using namespace std;

//static set-ups
int Engine::SCREEN_WIDTH = 1024;
int Engine::SCREEN_HEIGHT = 768;
GLFWwindow* Engine::window = NULL;

Engine::Engine() {
    // CONSTRUCTOR
    
}

Engine::~Engine() {
    // DESTRCUCTOR
}

bool Engine::initialiseGLFW(char *window_title)
{
    
    //initialise the library
    if(!glfwInit()) {
        cout << "Error initialising GLFW." << endl;
        return false;
    }
    
    //create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, window_title, NULL, NULL);
    
    if(!window) {
        cout << "Error creating window." << endl;
        glfwTerminate();
        return false;
    }
    
    /** GLFW SET-UP**/
    // make the window's context current - ie if we want to change rendering, it will use the window that we just generated as the current one.
    glfwMakeContextCurrent(window);
    
    // check window width and height vs screen width and height - good sanity check.
    int width, height; // local
    glfwGetFramebufferSize(window, &width, &height);
    glfwSwapInterval(1); // there is a front and back buffer. code works on back buffer, then will swap whats in back buffer to front buffer (what the user sees) every interval frame.
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor()); // using this we can make sure that the window is always centredon the monitor.
    int xPos = (mode->width - SCREEN_WIDTH)/2;
    int yPos = (mode->height - SCREEN_HEIGHT)/2;
    glfwSetWindowPos(window, xPos, yPos);
    
    /** GL SET-UP **/
    // viewport (camera)
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION); // 2d projection matrices
    glLoadIdentity(); // refresh camera position etc - loading the identity matrix
    glOrtho(0, width, 0, height, -10, 10); // we can set here what is top left, top right etc
    glDepthRange(-10,10);
    glMatrixMode(GL_MODELVIEW); // a state machine!!
    
    // alpha blending
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_BLEND);;
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    return true;
    
    
}

void Engine::Update() {
    // pull for and process events
    glfwPollEvents();

    
}

void Engine::Render() {
    
    glClearColor(0, 1, 0, 1); // clears entire back buffer with green (R,G,B, alpha)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //input bitfield mask - clears the depth of camera and buffer bit
    
    /** RENDER CODE HERE **/
    
    glfwSwapBuffers(window);
    
}

bool Engine::ShouldClose() {
    if(!glfwWindowShouldClose(window)) {
        return false;
    }
    
    return true;
}

