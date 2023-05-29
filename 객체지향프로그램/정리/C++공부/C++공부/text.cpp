#include "text.h"

Text::Text(const std::string &str):text(str){}
void Text::append(const std::string& str) {
	text += str;
}
std::string Text::get() const {
	return text;
}
