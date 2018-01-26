#include <DxLib.h>
#include <string>
#include <iostream>

#include "const.h"
#include "Novel.h"
#include "Input.h"
#include "Timer.h"
#include "SLG.h"
#include "Sentence.h"

int modeFlag = MODE_NOVEL;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	ChangeWindowMode(TRUE);
	SetGraphMode(WINDOW_WIDTH,WINDOW_HEIGHT,32);
	SetWindowText("Game1");

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	Timer timer;
	Input input;
	Novel novel;

	
	/*ChangeFont("�n���ؖ��� Light");
	SetFontSize(64);
	ChangeFontType(DX_FONTTYPE_ANTIALIASING);*/

	//Sentence sss("��y�͔L�ł���B���O�͂܂������B�ǂ��Ő��ꂽ���Ƃ�ƌ��������ʁB���ł����Â����߂��߂������Ńj���[�j���[�����Ă����������͋L�����Ă���B",0,0);

	novel.loadScript("sceneTemplate.txt");


	/*
	while (ProcessMessage() != -1) {//���C�����[�v
		switch (modeFlag) {
		case MODE_MENU:
			break;

		case MODE_NOVEL:

			break;

		case MODE_SLG:

			break;


		default:
			break;
		}
	}
	*/


	while (1) {
		if (ProcessMessage() == -1) {
			break;
		}

		input.update();
		timer.update();

		ClearDrawScreen();
		SetDrawScreen(DX_SCREEN_BACK);

		//sss.DrawSentence(msPerC);
		novel.Render();

		//DrawFormatString(700, 700, GetColor(255, 255, 255), "length = %d", sss.length);
		std::string a = std::to_string(timer.fps());
		DrawString(700, 700, a.c_str(), GetColor(255, 255, 255));

		ScreenFlip();
		
	}

	DxLib_End();

	return 0;
}