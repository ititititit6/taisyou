#include "paragraph.h"

Paragraph::Paragraph(std::string pName) {//csvにする?

	std::string buf;
	int count = 0;
	//std::istringstream iss(ss);
	std::ifstream iss(pName,std::ios::binary);

	while (std::getline(iss,buf)) {
		std::stringstream oss(buf);
		std::string buff;
		std::getline(oss, buff, ',');
		vSentence.emplace_back(buff, TEXTAREA_X, TEXTAREA_Y);
		std::getline(oss, buff, ',');
		int chara = atoi(buff.c_str());
		vCharaNo.push_back(chara);
		count++;
	}

	numSentence = count;
	nowSentence = 0;

	charaName = new Sentence(vCharaName[vCharaNo[0]], 700, 500, 12, 4);
  
}

void Paragraph::Draw() {

  //nowSentenceをDrawSentence;
  //途中で入力されたら引数のisSkipをtrueにする
	charaName->DrawSentence();
	if (vSentence.at(nowSentence).DrawSentence(msPerC) == false) {
		WaitKey();
		if (nowSentence < numSentence - 1) {
			nowSentence++;
			charaName->changeSentence(vCharaName[vCharaNo[nowSentence]]);
		}
	}

  //DrawSentenceがfalseを返してきたら
  //クリックか決定キー入力待ち,入力があればnowSentence++;

	//さらにnowSentenceが末端に達したら
	//Novelに次のパラグラフに行ってもらうよう指示

}
