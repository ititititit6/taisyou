#include "Novel.h"

Novel::Novel() {
	initialize();
}

Novel::~Novel() {
	finalize();
}

void Novel::initialize() {
	LoadExFont(FONT_PATH);

	currentFont = "�n���ؖ��� Light";
	ChangeFont(currentFont);
	SetFontSize(64);
	ChangeFontType(DX_FONTTYPE_ANTIALIASING);

	nowParagraph = 0;//���ƂŕύX�ł���get�����o�֐��쐬���Ă�

}

void Novel::finalize() {
	UnloadExFont(FONT_PATH);
}

void Novel::loadScript(std::string fileName) {
	std::ifstream ifs(fileName);
	std::string buf;

	/*while (std::getline(ifs,buf)) {
		if (buf == "#start") {
			std::ostringstream sst;
			ifs >> buf;
			while (buf != "#end") {
				sst << buf << std::endl;
				ifs >> buf;
			}ss
			*/vParagraph.emplace_back(fileName);//����ǂ����悤����
			//�e�L�X�g����t�@�C�������ă��X�g�Əꏊ�|�C���^��n����
			//fstream��Paragraph�ɓǂ�ł��炤
		//}
	//}
}



/*void Novel::changeFont(int fontNo) {
	ChangeFont(fontName.c_str());
}*/

void Novel::Render() {
	vParagraph.at(nowParagraph).Draw();
}

void Novel::drawFont(std::string line,float x, float y) {
	DrawString(x, y, line.c_str(), GetColor(255, 255, 255));
}

void Novel::drawFont(std::string line, float x, float y,int mpc) {

	int numChar = line.length();

	for (int i = 0; i < numChar; i++) {
		std::string buf = line.substr(0, i);

		DrawString(x, y, buf.c_str(), GetColor(255, 255, 255));

		//�����mpc���Ƃɉ�
	}

}
