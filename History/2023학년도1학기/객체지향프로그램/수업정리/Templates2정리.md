리스트와 벡터
    std::list
    형식
        template<
            class T,
            class Allocator = std::allocator<T> // 기본할당자, 성능 좋음, default로 설정
        >class list;
    특징 
        이전 요소와 다음 요소로 연결
        장점 : 중간에 요소 삽입 삭제 빠름
        단점 : 임의로 요소에 접근하기에 느림.
        
    std::vector 
    형식
        template<
            class T,
            class Allocator = std::allocator<t> // 기본할당자, 성능 좋음, default로 설정
        >class vector;
    특징
        동적 배열로 구현되어있음
        데이터를 연속적인 메모리 공간에 저장
        요소의 접근과 임의 위치에서 삽입 및 삭제 작업이 빠르게 수행
        그러나 중간에 삽입 삭제하는 경우 해당위치 이후의
        모든 요소들을 이동시켜야해서 비용이 높아짐.

리스트의 Non멤버함수 
1. std::begin(list) 
2. std::end(list)
리스트의 멤버함수
1. begin() ex. listname.begin()
2. end() ex. listname.end()
std:list<std::string> lst{ "zero" , "one", "two", "three", "four"};
for (auto i : lst)
    std::cout << i << ", ";
std::cout << std:endl;
for (auto iter = std::begin(lst); iter !=std::end(lst);iter ++)
    std::cout << *iter << ", ";

세트
    형식
        template<
            class Key,
            class Compare = std::less<key>
            class Allocator = std::allocator<key>
        >class set;
        데이터 타입을 key로 받고
        Allocator로 받은 할당자로 할당을 하고
        Compare로 받은 비교자로 비교를 해서 정렬
    예시
    int main(){
        std::set<int> x;
        x.insert(10);
        x.insert(10);
        x.insert(11);
        x.insert(9);

        for (auto i : x)
            std::cout << i << ", ";
        std::cout << std::endl;
        
        for (auto it = x.begin(); it != x.end(); ++it)
            std::cout << *it << ", ";
        std::cout << std::endl;
    }

맵Map
    형식
        template<
            class Key,
            class T,
            class Compare = std::less<key>,
            class Allocator = std::allocator<std::pair< const key, T>>
        > class map;
    std::pair구조체의 형식
        //std::pair클래스의 멤버. first, second
        template <class T1, class T2>
            struct pair {
                T1 first;
                T2 second;
                
                // 생성자, 비교 연산자 등의 멤버 함수들...
            };
    맵 예시
    int main(){
        std::map<std::string , int > y;
        y.insert(std::pair<std::string, int>("+", 10));
        y.insert(std::pair<std::string, int>("--", 20));
        y.insert(std::pair<std::string, int>("!!", 30));
        y.insert(std::pair<std::string, int>("<<", 40));
        y.insert(std::pair<std::string, int>(">>", 50));
        y["*"] = 0;
        for (auto i : y ){
            std::cout << i.first << ", " << i.second << ", ";
            //std::cout << y[i.first]<< ", ";
        }
        std::cout << std::endl;
        
        for (auto it = y.begin(); it != y.end; ++it)
            std::cout << it->first << ", " << it->second << ", ";
    }


Priority_queue
    형식
        template<
            class T, 
            class Container = std::vector<T>,
            class Compare = std::less<typename Container::value_type> //std::less<T>써도댐.
            >class priority_queue 
        >
        //std::priority_queue는 C++ 표준 라이브러리에서 제공되는 클래스 템플릿입니다. 이 클래스는 우선순위 큐(priority queue)를 구현하는 데 사용됩니다. 우선순위 큐는 값을 저장하고 검색하는 동안 우선순위가 가장 높은 요소에 빠르게 접근할 수 있는 데이터 구조입니다.

    예시
        int main(){
            std::priority_queue<int> queue; // container : vector, compare : less
            queue.push(11); 
            queue.push(2); 
            queue.push(4); 
            queue.push(5); 
            queue.push(6); 

        }