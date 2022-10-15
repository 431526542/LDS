#include <iostream>
#include <vector> //가변배열에 해당하는 기준 라이브러리
#include <list> //연결형리스트에 해당하는 기준 라이브러리

using std::vector;
using std::list;


int main()
{
	//표준라이브러리의 벡터와 리스트 즉.가변배열과 연결형리스트
	vector<int> vecInt;
	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt[0] = 100;
	vecInt.at(1); //특정 인덱스로 접근해서 그값을 참조자로 반환해주는것 vecInt[1]와 똑같다.
	vecInt[1];
	vecInt.data(); //데이터 시작주소 반환
	vecInt.size(); //데이터를 몇개 집어 넣었는지
	vecInt.capacity(); //현재 기준으로 몇칸까지 허용범위인지

	//리스트안에 내가넣은 데이터 싹다 순회하고싶다(벡터는 이런식으로도 할 수 있다.)
	for (size_t i = 0; i < vecInt.size(); ++i)
	{
		std::cout << vecInt[i] << std::endl; // vecInt[i]이 아니면 vecInt.at(i)이다.
	}
	vector<int>::iterator viter = vecInt.begin();
	*viter = 100; //vecInt의 처음데이터를 100으로 넣는다.
	++viter; // vecInt의 처음값에서 두번째값으로 가르킴

	list<int> listInt;
	listInt.push_back(111);
	listInt.push_back(222);
	listInt.size();
	//기본적으로 순회할수 있는 반복자iterator를 재공한다.
	//iterator는 클래스이다. 리스트 안쪽에 있는 클래스이다. 클래스안에 클래스가 구현되어있다(inner class)
	list<int>::iterator iter = listInt.begin(); //listInt의 첫번째 노드를 가르킨다
	int idata = *iter; //이렇게하면 listInt의 첫번째 데이터 10이라는 숫자를 가르킨다.포인터가 아니다(중요).
					   //iterator클래스 내부에 *오퍼레이터가구현되어있음.*의기능은 데이터파트만 꺼내오겠다.
	for (iter = listInt.begin(); iter != listInt.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}



	return 0;
}