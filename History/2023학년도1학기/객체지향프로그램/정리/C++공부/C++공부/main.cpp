#include <iostream>
#include <string>
class Text {
	std::string text;
public:
	virtual ~Text() {
		std::cout << "destrot Text" << std::endl;
	}
	Text(const std::string& t) :text(t) {};
	virtual std::string get() const {
		return text;
	}
	void append(const std::string& str) {
		text += str;
	}
};
class NewText : public Text {
	std::string left;
	std::string right;
public:
	~NewText() override {
		std::cout << "destroy newText" << std::endl;
	}
	NewText(const std::string& t,
		const std::string& left,
		const std::string& right)
		:Text(t), left(left), right(right) {};
	std::string get() const override {
		return left + Text::get() + right;
	}
};
int main() {
	Text t("하이");
	NewText nt("하이하이", "ㅋㅋ구", "구ㅋㅋ");
	std::cout << nt.get() << std::endl;
	std::cout << t.get() << std::endl;
}