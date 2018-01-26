#ifndef INPUT_H
#define INPUT_H

#include <DxLib.h>
#include "const.h"

class Input {
public:
	Input();

	void update();
	int singlePress(int keyName); //単押しで整数値(=true),notでfalse
	bool longPress(int keyName); //SINGLE_PRESS_FRAME以上で長押しと判定しtrue,それ以外はfalse




protected:
	char key[256];
	int pressedFrame[256];

};


#endif // !INPUT_H
