#include "Timer.h"

//QueryPerformanceCounter‚Å‚â‚Á‚½
/*Timer::Timer() {
	QueryPerformanceFrequency(&timeFreq);
	QueryPerformanceCounter(&timeBegin);
	timeStart = timeBegin;
	frameTime = 0;
	frameRate = 0;
}

void Timer::update() {
	QueryPerformanceCounter(&timeEnd);
	frameTime = (timeEnd.QuadPart - timeStart.QuadPart) / timeFreq.QuadPart;
	frameRate = 1 / frameTime;
	if (FRAME_TIME > frameTime) {
		Sleep(FRAME_TIME - frameTime);
	}

	timeStart = timeEnd;
}

float Timer::fps() {
	return frameRate;
}

float Timer::keika() {
	return timeEnd.QuadPart - timeStart.QuadPart;//(timeEnd.QuadPart - timeBegin.QuadPart) / timeFreq.QuadPart;
}
*/

Timer::Timer() {
	timeBegin = GetNowCount();
	timer1 = timeBegin;
	timer2 = 0;
	count = 0;
}

void Timer::update() {

	timer2 = GetNowCount();

	frameTime[count] = timer2 - timer1;
	
	float ave = 0;

	for (int i = 0; i < 60; i++) {
		ave += frameTime[i];
	}

	ave /= 60;

	frameRate = (float)(1.0f / ave * 1000);

	/*if (FRAME_TIME > ave) {
		Sleep(FRAME_TIME - ave);
	}*/

	timer1 = timer2;
	count++;
	count %= 60;
}

float Timer::fps() {
	return frameRate;
}
