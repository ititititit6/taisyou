#ifndef FONT_H
#define FONT_H
#include <Windows.h>

#include "const.h"

void LoadExFont(LPSTR font_path);

void UnloadExFont(LPSTR font_path);


//font名配列にせず、fonthandleで管理



#endif // !FONT_H