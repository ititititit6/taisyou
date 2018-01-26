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

	int strLength(std::string a);//strLengthは文字的カウントを返す
	int strPointer(std::string a, int charCount);//strPointerはstring的カウントを返す(charCountは文字的カウント)

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
    int lineLength;//paragraphで持つべき
	int countStart;
    int countEnd;
};
#endif
