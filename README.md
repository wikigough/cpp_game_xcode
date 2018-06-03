# cpp_game_xcode
Learning how to make a game in macOS XCode via command line setting and using OpenGL graphics.

#instructions on how to include OpenGL graphics in macOS
Based on this video:
https://www.youtube.com/watch?v=4zjCqjfjcPs

1. Setup and install homebrew. Use official website and follow their instructions - will need mac command line. https://brew.sh
2. Put these into the command line (it should be then installed in homebrew/Cellar):
    brew install glfw3
    brew install glew
3. Open up Xcode and make new project as OSX -> Application -> Command Line tool
4. Enter name that you want for your project. Make sure it's a c++ application'
5. Click on project name in the project navigator
6. Click on build phases tab >> Link binary with libraries >> click on the '+' sign
7. start typing "opengl" and add OpenGl.framework
8. Click on '+' again, as we are adding another framework
9. Click on 'other'
10. Navigate to Macintosh HD
11. Press Command+Shift+.(full stop) in order to see hidden files
12. Navigate to Macintosh HD/usr/local/Cellar
13. Include the glew and glfw3 .dylib files
14. Link binary with Libraries should have the glew and glfw3 .dylib files and the OpenGL.framewwork

