//
//  Engine.h
//  bleh
//
//  Created by Vicky Gough on 03/06/2018.
//  Copyright © 2018 Vicky Gough. All rights reserved.
//

#ifndef Engine_h
#define Engine_h

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW3
#include <GLFW/glfw3.h>

// Engine class - this will deal with glfw directly.
class Engine {
    
public:
    static int SCREEN_WIDTH;
    static int SCREEN_HEIGHT;
    Engine(); // CONSTRUCTOR. Initialises stuff within the class to 0 or another value. This is useful because if we dont initialise the values and they get called in a Engine.print() function, the print function will spew out random numbers. Which is why we would need an init function. BUT we don't want to call init() everytime we call a new member of a class, SO this is a special function that gets rid of that messy line of code!
        // see this: https://www.youtube.com/watch?v=FXhALMsHwEY v useful video on constructors
    ~Engine(); // ~ means that the function is the DESTRUCTOR for the class it is defined in. The rest of the name (after ~) must match the name of the class.
    
    bool initialiseGLFW(char *window_title); //bool for error checking.
    void Update(); // basic game dev function - update the current state
    void Render(); // basic game dev function - render the current state after updating
    bool ShouldClose();
    
private:
    static GLFWwindow *window;
    
};


#endif /* Engine_h */
