// 배열공부 02
// 배열과 루프 & 배열 정렬
// 배열인덱스는 변수여도 되지만 배열 초기화 길이지정은 반드시 컴파일 상수로 해야한다.
// 혹은 리터럴상수나 매크로 상수여야한다.

// array01 for 루프를 사용해서 배열의 모든 요소에 접근하는 예제;
//#include <iostream>
//int main() {
//	int scores[]{ 84,92,66,77,98 };
//	const int numstudents = sizeof(scores) / sizeof(scores[0]);
//	int total_score = 0;
//	int best_score = 0;
//	for (int i = 0; i < numstudents; i++) {
//		total_score += scores[i];
//		best_score = (scores[i] > best_score) ? scores[i] : best_score;
//	}
//
//	double average_score = static_cast<double>(total_score) / numstudents;
//	
//	
//	std::cout << "학생수는 : " << numstudents << std::endl;
//	std::cout << "전체학생 점수 합은 : " << total_score<< std::endl;
//	std::cout << "최고점수는 : " << best_score << std::endl;
//	std::cout << "평균점수는 : " << average_score << std::endl;
//
//}

/*
루프는 일반적으로 다음 작업중 하나를 수행하기 위해 배열과 함께 사용된다
1. 평균이나 합계를 계산.
2. 값을 검색. 최고값이나 최저값
3. 배열을 재구성 . 오름차순 내림차순
*/

//array02 .swap함수.
//#include <iostream>
//#include <algorithm>
//int main() {
//	int x = 123;
//	int y = 999;
//	std::cout << x << ',' << y << std::endl;
//	std::swap(x, y);
//	std::cout << "스왑후" << std::endl;
//	std::cout << x << ',' << y << std::endl;
//
//}

//array03 스왑함수를 이용해서 배열 선택정렬
/* 배열 인덱스 0에서 시작해서 가장 작은 값을 찾는다
그리고 그 값을 0번인덱스 값과 swap한다
1번 인덱스부터 다시 반복한다.*/
//#include <iostream>
//#include <algorithm>
//#include <cstdlib>
//void print(int* arr, int size) {
//	for (int i = 0; i < size; i++) {
//		std::cout << arr[i] << ',';
//		if (i % 10 == 9) {
//			std::cout << std::endl;
//		}
//	}
//	std::cout << std::endl;
//}
//int main() {
//	srand(1);
//	const int length = 112;
//	int arr[length]{};//uniform initialization
//	for (int i = 0; i < length; i++) {
//		arr[i] = rand();
//	};
//	print(arr, length);
//	int iters = length;
//	int min_index = 0;
//	while (iters > 1) {
//		int start_index = (length - iters);
//		for (int i = 0; i < iters; i++) {
//			if (i == 0) {
//				min_index = start_index;
//			}
//			else {
//				min_index = (arr[min_index] < arr[start_index + i]) ? min_index : (start_index + i);
//			}
//		}
//		std::swap(arr[length - iters], arr[min_index]);
//		iters -= 1;
//	}
//	print(arr,length);
//}

// arr04다차원 배열.
//#include <iostream>
//
//int main() {
//	int arra[3][5]{ {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
//	//int array2[][]; 는 안됌.
//	//int array2[][2]{ {1,2,3},{4,5,6}}은 됌.
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 5; j++) {
//			std::cout << arra[i][j] << ',';
//		};
//		std::cout << std::endl;
//	}
//}