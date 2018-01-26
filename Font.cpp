#include "Font.h"

void LoadExFont(LPSTR font_path) {

	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {

	}
	else {
		MessageBox(NULL, "Font Load Failed", "", MB_OK);
	}

}

void UnloadExFont(LPSTR font_path) {
	if (RemoveFontResourceEx(font_path, FR_PRIVATE, NULL)) {
	}
	else {
		MessageBox(NULL, "Font remove failed", "", MB_OK);
	}
}