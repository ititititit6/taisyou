#ifndef INPUT_H
#define INPUT_H

#include <DxLib.h>
#include "const.h"

class Input {
public:
	Input();

	void update();
	int singlePress(int keyName); //�P�����Ő����l(=true),not��false
	bool longPress(int keyName); //SINGLE_PRESS_FRAME�ȏ�Œ������Ɣ��肵true,����ȊO��false




protected:
	char key[256];
	int pressedFrame[256];

};


#endif // !INPUT_H
