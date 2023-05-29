#include "fancytext.h"
#include <string>

FancyText::FancyText(const std::string& t, 
	const std::string& left,
	const std::string& right,
	const std::string& connector) :
	Text(t), connector(connector), left_bracket(left), right_bracket(right) {};
std::string FancyText::get() const {
	return left_bracket + Text::get() + right_bracket;
	
}
void FancyText::append(const std::string& extra) {
	Text::append(connector + extra);
}