#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
template <typename T>
void print(T value) {
	std::cout << value << std::endl;
};
template <typename T>
void print(const std::vector<T>& v) {
	int size = v.size();
	for (int i = 0; i < size; i++) {
		std::cout << v[i] << ", ";
	};
};
int main() {
	std::vector<int> list;
	bool done = false;
	char command;
	std::string name;
	std::ofstream fout;
	std::ifstream fin;
	while (!done) {
		std::cout << "I)nsert <item> P)rint "
			<< "S)ave <filename> L)oad <filename> "
			<< "E)rase Q)uit: ";
		std::cin >> command;
		int value;

		switch (command) {
			case 'I':
			case 'i':
				std::cin >> value;
				list.push_back(value);
				break;
			case 'P':
			case 'p':
				print(list);
				break;
			case 'S':
			case 's':
				std::cin >> name;
				if (name.length()<5 or name.substr(name.length() - 4) != ".txt")
					name += ".txt";
				fout.open(name);

				if (fout.good()) {
					for (int i = 0; i < list.size(); i++) {
						fout << list[i] << " ";
					}
					fout.close();
				}
				print("you save!");
				break;
			case 'L':
			case 'l':
				std::cin >> name;
				if (name.length()<5 or name.substr(name.length() - 4) != ".txt") {
					name += ".txt";
				}
				fin.open(name);

				if (fin.fail()) {
					print("error");
					break;
				}
				else {
					int v;
					while (fin >> v) {
						print(v);
					}
				}
		}
	}
};
