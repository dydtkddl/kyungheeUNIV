//�迭���� 03
// C��Ÿ�� strings
// ���ڿ� string���� ���ڿ��� ���ڵ��� �������� �����̶�� �����ߴ�.
// ���ڿ��� C++���� �ؽ�Ʈ�� �۾��ϴ� �⺻ ����̸� std::string�� C++���� ���ڿ���
// �۾��ϴ� ���� ���Ը����.
// Modern C++�� std::string�� C-style���ڿ� �ΰ����� �����Ѵ�.
// 
// C-style String;
// 
// 01.
//#include <iostream>
//int main() {
//	char myString[] = "string"; // �����Ϸ��� ���̸� ���.
//	int length = sizeof(myString) / sizeof(myString[0]);
//	std::cout << "��Ʈ�� " << myString << "�� ���̴� " << length << std::endl;
//	for (int i = 0; i < length; i++) {
//		std::cout << static_cast<int>(myString[i]) << " ";
//	}
//	return 0;
//}
//
//
// 02. �迭ó�� ��� ����
//#include <iostream>
//int main() {
//	char myString[] = "string";
//	myString[3] = 'p';
//	std::cout << myString;
//	return 0;
//}
//
//
//
// 03. std::cout �� �׳� �ᵵ ���ڿ��� ��� ��Ұ� ���ʷ� ��µȴ�.
//#include <iostream>
//int main() {
//	char name[] = "�ȿ��"; // �ѱ��� �� ���ڴ� 2����Ʈ�� ����
//	int length = sizeof(name) / sizeof(name[0]);
//	std::cout << length << ','<<name << std::endl;
//}

//04. C style string�� �ʱ�ȭ�� �������� char������ cin���� ���ڿ��� �޾� ���尡��
//#include <iostream>
//int main() {
//	char name[200];
//	std::cin >> name;
//	std::cout << name;
//}

//05 CstyleString���� cin���� ���ڿ��� ���� ��, �̸� �������� char�� ���̺���
// ū ���ڿ��� ������ �ȵȴ�.
// �̶� ������ getline�̶�� �Լ��� �ִ�.
//std::cin.getline()
//#include <iostream>
//int main() {
//	char text[324];
//	std::cin.getline(text, 324);
//	std::cout << "you entered : " << text << std::endl;
//}

//06 Cstyle String�� �����ϴ� cstring ��������� �Լ���
// strcpy(), strcmp(), strlen()���� �ִ�
//#include <iostream>
//#include <cstring>
//int main()
//{
//    char source[] = "Copy this!";
//    char dest[50];
//    //strcpy(dest, source); 
//    //�̷��� �ϸ�, dest�� ���̰� �� �۾Ƽ� ���ۿ����÷ο찡 �Ͼ.
//    strcpy_s(dest,sizeof(dest), source);
//    std::cout << dest; // prints "Copy this!"
//
//    std::cout << strlen(dest); // ������ \0�� ������ ���̸� ��ȯ
//    return 0;
//}

//����. ���ڿ��� cin���� �޾Ƽ�, ������ ������ ���� ���α׷��� �ۼ��Ͻÿ�
//#include <iostream>
//int main() {
//	int count = 0;
//	char text[255];
//	std::cin.getline(text, 255);
//	for (int i = 0; i < 255; i++) {
//		if (static_cast<char>(text[i]) == ' ') {
//			count++;
//		}
//	}
//	std::cout << count << std::endl << text;
//}

/* �����ϸ鼭 
C++�� ����ҋ� C style string�� �����ϴ� ���� ����
�ֳ��ϸ� Ư���� ������ ���ٸ� std::string�� ���°��� �� ���� �����ϸ� �����ϱ� �����̴�
�׷��� �� �۵������� �˰��ִ� ���� ����.*/