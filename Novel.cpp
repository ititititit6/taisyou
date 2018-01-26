#include "Novel.h"

Novel::Novel() {
	initialize();
}

Novel::~Novel() {
	finalize();
}

void Novel::initialize() {
	LoadExFont(FONT_PATH);

	currentFont = "馬酔木明朝 Light";
	ChangeFont(currentFont);
	SetFontSize(64);
	ChangeFontType(DX_FONTTYPE_ANTIALIASING);

	nowParagraph = 0;//あとで変更できるgetメンバ関数作成してね

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
			*/vParagraph.emplace_back(fileName);//これどうしようかね
			//テキスト巨大ファイルつくってリストと場所ポインタを渡して
			//fstreamでParagraphに読んでもらう
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

		//これをmpcごとに回す
	}

}
