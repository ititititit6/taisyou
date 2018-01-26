#ifndef TIMER_H
#define TIMER_H

#include "const.h"
#include <time.h>
#include <DxLib.h>
#include <Windows.h>

class Timer {
public:
	Timer();
	void update();
	float fps();

private:
	/*
	LARGE_INTEGER timeBegin;
	LARGE_INTEGER timeStart;
	LARGE_INTEGER timeEnd;
	LARGE_INTEGER timeFreq;

	float frameTime;
	float frameRate;
	DWORD sleepTime;
	*/

	int timeBegin,
		timer1,
		timer2,
		count;

	int frameTime[60] = { 0 };

	float frameRate;
};

#endif // !TIMER_H
