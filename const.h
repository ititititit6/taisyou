#ifndef CONST_H
#define CONST_H
#include <Windows.h>
#include <string>

//mainLoop
#define MODE_MENU 0
#define MODE_NOVEL 1
#define MODE_SLG 2


//input
const int SINGLE_PRESS_FRAME = 60;

//timer
const int FRAME_RATE = 60;
const float FRAME_TIME = 1.0f / (float)FRAME_RATE * 1000;

//font
const LPSTR FONT_PATH = "AsebiMin-Light.otf";
const LPSTR DEFAULT_FONT = "AsebiMin-Light.otf";

//main
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;

//novel(sentence)
const int msPerC = 70;

const int DEFAULT_SIZE = 32;
const int DEFAULT_LINELENGTH = 16;

const float TEXTAREA_X = 0;
const float TEXTAREA_Y = 0;


//File
const std::string HEADER_PATH = "header.dat";
const std::string ARCHIVE_PATH = "test.arc";


#endif // !CONST_H
