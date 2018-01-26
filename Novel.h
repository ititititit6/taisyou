#ifndef NOVEL_H
#define NOVEL_H

#include "Font.h"
#include "Paragraph.h"

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <DxLib.h>

class Novel {
public:
	Novel();
	~Novel();

	void initialize();
	void finalize();

	void loadScript(std::string fileName);

	void Render();

	//void changeFont(int fontNo);
	void drawFont(std::string line, float x, float y);

	void drawFont(std::string line, float x, float y,int mpc);

private:
	LPSTR currentFont;
	std::vector<Paragraph> vParagraph;
	//こうではなく,1こだけポインタ作成してchangePで都度読み込む?

	int nowParagraph;

};







#endif // !NOVEL_H
