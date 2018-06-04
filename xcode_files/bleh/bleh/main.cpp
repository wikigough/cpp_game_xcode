//
//  main.cpp
//  bleh: I'm a sexy mofo
//
//  Created by Vicky Gough on 27/05/2018.
//  Copyright © 2018 Vicky Gough. All rights reserved.
//

// SO USEFUL: https://www.youtube.com/watch?v=4zjCqjfjcPs


#include "main.h"


int main(void) {
    
    Engine engine; // constructor automatically executed
    engine.initialiseGLFW("GAME ON");
    
    while (!engine.ShouldClose()) {
        engine.Update();
        engine.Render();
    }
    
    return 0;
}