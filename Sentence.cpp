#include "Sentence.h"


Sentence::Sentence(std::string s, float inputx, float inputy,
	int sz,
	int lineL,
	std::string font,
	unsigned int col) {
	ss = s;
	fontName = font;
	size = sz;
	color = col;
	lineLength = lineL;
	length = strLength(ss);
	countStart = 0;
	x = inputx;
	y = inputy;
}

Sentence::~Sentence() {
}

void Sentence::changeSentence(std::string s) {
	ss = s;
	length = strLength(s);
	countStart = 0;
}

int Sentence::strLength(std::string a) {
	int l = a.length();
	int c = 0;
	for (int i = 0; i < l; i++) {
		if (a[i] != '\n') {
			if (IsDBCSLeadByte(a[i]) == 0) {
				c++;
			}
			else {
				c++;
				i++;
			}
		}
	}

	return c;
}

//�����I�J�E���g��string�J�E���g�ŉ������ɑ������邩���ׂ���
int Sentence::strPointer(std::string a, int charCount) {
	int c = 0;//�����J�E���g
	int i = 0;//string�J�E���g
	while (c < charCount) {
		if (a[i] != '\n') {
			if (IsDBCSLeadByte(a[i]) == 0) {//���p�Ȃ�
				c++;
				i++;//�����J�E���g��1������string��1�i�߂�
			}
			else {//�S�p�Ȃ�
				c++;
				i += 2;//�����J�E���g��1������string��2�i�߂�
			}
		}
		else {//���s�Ȃ�
			i++;//�����J�E���g0,string1
		}
	}
	if (c == charCount) return i;
	else return -1;
}

void Sentence::DrawSentence() {
	DrawString(x, y, ss.c_str(), color);
	//UI���i�Ƃ��ALabel��̕`���UI�ƂƂ��ɐ����A�j��?
};

bool Sentence::DrawSentence(int mpc,bool isSkip) {
	int now = GetNowCount();

	if (countStart == 0) {
		countStart = now;
		countEnd = countStart + ((length + 1) * mpc);
		return true;
	}

	//�s�����ǂ��t�F�[�h����Ȃ�
	/*
	int alpha;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	DrawString();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
	*/

	//nowChar�͕��ʂ̕����J�E���g
	//substr��string�J�E���g�ő������K�v����

	int nowChar = 0;
	int nowChar_str = 0;
	if (now < countEnd && isSkip == false) {
		nowChar = (now - countStart) / mpc;
		nowChar_str = strPointer(ss, nowChar);
	}
	else {
		nowChar = length;
		nowChar_str = ss.length();
	}


	int line = (nowChar - 1) / lineLength;

	std::string buf;

	if (line == 0) {
		buf = ss.substr(0, nowChar_str);
		DrawString(x, y, buf.c_str(), color);
	}
	else {
		std::string buff = ss.substr(0,nowChar_str);

		while (1) {
			if (line != 0) {
				buf += buff.substr(0,strPointer(buff,lineLength));
				buff.erase(buff.begin(), buff.begin() + strPointer(buff, lineLength));
				buf += "\n";
				line--;
			} else {
				buf += buff;
				break;
			}
		}
		DrawString(x, y, buf.c_str(), color);
		}

	/*
	if (line == 0) {
		buf = ss.substr(0, nowChar_str);
	}
	else {
		for (int nline = 1; nline <= line; nline++) {
			if (nline = line) {
				buf += ss.substr(strPointer(ss,lineLength*nline), nowChar_str);
			}
			else {
				buf += ss.substr(strPointer(ss, lineLength*nline), strPointer(ss, lineLength*(nline + 1)));
				buf += '\n';
			}
		}
	}
	*/


	if (now >= countEnd || isSkip == true) return false;//�`��I��,���͑҂�->�p����Manager�N���X�Ɉ˗�
	else return true;
	//�`�摱�s
}
