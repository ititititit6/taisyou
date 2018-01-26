#include "Input.h"

Input::Input() {
	for (int i = 0; i < 256; i++) {
		key[i] = 0;
		pressedFrame[i] = 0;
	}
}

void Input::update() {
	GetHitKeyStateAll(key);
	for (int i = 0; i < 256; i++) {
		if (key[i] == 0) {
			pressedFrame[i] = 0;
		} else
		pressedFrame[i]++;
	}
}

int Input::singlePress(int keyName) {
	if (pressedFrame[keyName] <= SINGLE_PRESS_FRAME) return pressedFrame[keyName];
	else return 0;
}

bool Input::longPress(int keyName) {
	if (pressedFrame[keyName] > SINGLE_PRESS_FRAME) return true;
	else return false;
}
