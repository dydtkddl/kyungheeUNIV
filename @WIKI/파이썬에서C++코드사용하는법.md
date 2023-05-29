python의 ctypes를 이용하면 c혹은 c++에서 작성한 코드를 사용가능하다.

a.cpp 에서 작성한 단순 곱셈함수 mul을 python에서 사용해보자.

//a.cpp
#include <cstdio>

extern "C"{
int mul(int a,int b){
return a*b;
}
}


위 파일을 공유라이브러리로 만들어 주어야한다. g++로 a.cpp를 liba.so로 만들어주자.

g++ -shared -fPIC a.cpp -o liba.so

liba.so 파일이 생성되었다. a.py에서 liba.so의 mul을 사용해보자.

#a.py

import ctypes

a = ctypes.CDLL("./liba.so")
mul = a.mul
print(mul(13,43))

a.py를 실행시키면 559가 출력된다.