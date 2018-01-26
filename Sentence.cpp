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

//文字的カウントがstringカウントで何文字に相当するか調べたい
int Sentence::strPointer(std::string a, int charCount) {
	int c = 0;//文字カウント
	int i = 0;//stringカウント
	while (c < charCount) {
		if (a[i] != '\n') {
			if (IsDBCSLeadByte(a[i]) == 0) {//半角なら
				c++;
				i++;//文字カウントに1足してstringも1進める
			}
			else {//全角なら
				c++;
				i += 2;//文字カウントに1足してstringは2進める
			}
		}
		else {//改行なら
			i++;//文字カウント0,string1
		}
	}
	if (c == charCount) return i;
	else return -1;
}

void Sentence::DrawSentence() {
	DrawString(x, y, ss.c_str(), color);
	//UI部品とか、Label上の描画はUIとともに生成、破棄?
};

bool Sentence::DrawSentence(int mpc,bool isSkip) {
	int now = GetNowCount();

	if (countStart == 0) {
		countStart = now;
		countEnd = countStart + ((length + 1) * mpc);
		return true;
	}

	//不透明どもフェードするなら
	/*
	int alpha;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	DrawString();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
	*/

	//nowCharは普通の文字カウント
	//substrはstringカウントで代入する必要あり

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


	if (now >= countEnd || isSkip == true) return false;//描画終了,入力待ち->廃棄をManagerクラスに依頼
	else return true;
	//描画続行
}
