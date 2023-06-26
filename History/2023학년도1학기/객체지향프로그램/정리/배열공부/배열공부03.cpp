//배열공부 03
// C스타일 strings
// 문자열 string에서 문자열은 문자들의 연속적인 모음이라고 정의했다.
// 문자열은 C++에서 텍스트로 작업하는 기본 방법이며 std::string은 C++에서 문자열로
// 작업하는 것을 쉽게만든다.
// Modern C++은 std::string과 C-style문자열 두가지를 지원한다.
// 
// C-style String;
// 
// 01.
//#include <iostream>
//int main() {
//	char myString[] = "string"; // 컴파일러가 길이를 계산.
//	int length = sizeof(myString) / sizeof(myString[0]);
//	std::cout << "스트링 " << myString << "의 길이는 " << length << std::endl;
//	for (int i = 0; i < length; i++) {
//		std::cout << static_cast<int>(myString[i]) << " ";
//	}
//	return 0;
//}
//
//
// 02. 배열처럼 요소 접근
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
// 03. std::cout 을 그냥 써도 문자열의 모든 요소가 차례로 출력된다.
//#include <iostream>
//int main() {
//	char name[] = "안용상"; // 한글의 한 글자는 2바이트를 차지
//	int length = sizeof(name) / sizeof(name[0]);
//	std::cout << length << ','<<name << std::endl;
//}

//04. C style string은 초기화를 하지않은 char변수에 cin으로 문자열을 받아 저장가능
//#include <iostream>
//int main() {
//	char name[200];
//	std::cin >> name;
//	std::cout << name;
//}

//05 CstyleString에서 cin으로 문자열을 받을 떄, 미리 지정해준 char의 길이보다
// 큰 문자열을 받으면 안된다.
// 이때 유용한 getline이라는 함수가 있다.
//std::cin.getline()
//#include <iostream>
//int main() {
//	char text[324];
//	std::cin.getline(text, 324);
//	std::cout << "you entered : " << text << std::endl;
//}

//06 Cstyle String을 제어하는 cstring 헤더파일의 함수들
// strcpy(), strcmp(), strlen()등이 있다
//#include <iostream>
//#include <cstring>
//int main()
//{
//    char source[] = "Copy this!";
//    char dest[50];
//    //strcpy(dest, source); 
//    //이렇게 하면, dest의 길이가 더 작아서 버퍼오버플로우가 일어남.
//    strcpy_s(dest,sizeof(dest), source);
//    std::cout << dest; // prints "Copy this!"
//
//    std::cout << strlen(dest); // 종결자 \0을 제외한 길이를 반환
//    return 0;
//}

//예제. 문자열을 cin으로 받아서, 공백의 개수를 세는 프로그램을 작성하시오
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

/* 정리하면서 
C++을 사용할떈 C style string을 지양하는 것이 좋다
왜냐하면 특별한 이유가 없다면 std::string을 쓰는것이 더 쉽고 안전하며 유연하기 떄문이다
그러나 그 작동원리를 알고있는 것은 좋다.*/