#include "paragraph.h"

Paragraph::Paragraph(std::string pName) {//csv�ɂ���?

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

  //nowSentence��DrawSentence;
  //�r���œ��͂��ꂽ�������isSkip��true�ɂ���
	charaName->DrawSentence();
	if (vSentence.at(nowSentence).DrawSentence(msPerC) == false) {
		WaitKey();
		if (nowSentence < numSentence - 1) {
			nowSentence++;
			charaName->changeSentence(vCharaName[vCharaNo[nowSentence]]);
		}
	}

  //DrawSentence��false��Ԃ��Ă�����
  //�N���b�N������L�[���͑҂�,���͂������nowSentence++;

	//�����nowSentence�����[�ɒB������
	//Novel�Ɏ��̃p���O���t�ɍs���Ă��炤�悤�w��

}
