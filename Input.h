#ifndef INPUT_H
#define INPUT_H

#include <DxLib.h>
#include "const.h"

class Input {
public:
	Input();

	void update();
	int singlePress(int keyName); //’P‰Ÿ‚µ‚Å®”’l(=true),not‚Åfalse
	bool longPress(int keyName); //SINGLE_PRESS_FRAMEˆÈã‚Å’·‰Ÿ‚µ‚Æ”»’è‚µtrue,‚»‚êˆÈŠO‚Ífalse




protected:
	char key[256];
	int pressedFrame[256];

};


#endif // !INPUT_H
