#ifndef SENTENCE_H
#define SENTENCE_H
#include <string>
#include <DxLib.h>
#include <windows.h>

#include "const.h"
class Sentence {
public:
 	Sentence(std::string s, float inputx, float inputy,
	int sz = DEFAULT_SIZE,
    int lineL = DEFAULT_LINELENGTH,
	std::string font = DEFAULT_FONT,
    unsigned int col = GetColor(255,255,255)
    );
    ~Sentence();

	int strLength(std::string a);//strLength�͕����I�J�E���g��Ԃ�
	int strPointer(std::string a, int charCount);//strPointer��string�I�J�E���g��Ԃ�(charCount�͕����I�J�E���g)

	void changeSentence(std::string s);

    void DrawSentence();
    bool DrawSentence(int mpc, bool isSkip = false);

	int length;

private:
    std::string ss;
    float x,y;

    std::string fontName;
    int size;
    unsigned int color;
    int lineLength;//paragraph�Ŏ��ׂ�
	int countStart;
    int countEnd;
};
#endif
