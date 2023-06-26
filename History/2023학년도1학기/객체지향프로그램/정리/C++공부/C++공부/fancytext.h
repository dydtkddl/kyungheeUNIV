#pragma once
#include "text.h"
class FancyText : public Text {
	std::string left_bracket;
	std::string right_bracket;
	std::string connector;
public:
	FancyText(const std::string& text, const std::string& left,
		const std::string& right, const std::string& conn);
	std::string get() const override;
	void append(const std::string& extra) override;

};