#include <iostream>
using namespace std;

int main() {
	//C++ 표준 기능의 대부분은 std라는 namespace안에 존재
	//이름이 중복되는 것을 방지해준다
	//cout : console 창에 출력 해준다
	//endl : endline  == \n
	std::cout << "Hello Cpp World" <<std::endl;
	std::cout << "가나다라" << std::endl;

	//using namespace std를 사용하면 std::를 붙이지 않아도된다
	cout << "1234"<<endl;

	//구조적 프로그램은 위에서 아래로
	//같은 줄이면 오른쪽에서 왼쪽으로 실행된다
	return 0;
}