#include <iostream>
#include <list>

using namespace std;

//** 구조체
typedef struct tagInfo
{
	int iNumber;
}INFO;


class Object
{
	//** 상속간의 사용 가능.
protected:
	INFO Info;
public:
	//** 버추얼 함수. 자식 클레스에서 사용. (순수 가상 함수)
	virtual Object* Clone() = 0;

public:
	//** Getter
	INFO GetInfo() { return Info; }

	//** Setter
	void SetInfo(int _number) { Info.iNumber = _number; }

public:
	//** 생성자.
	Object() {}

	//** 복사 생성자
	//Object(const INFO& _Info) : Info(_Info) {}

	//** 소멸자.
	virtual ~Object() {}
};



//** Bullet 클레스  Object 상속
class Bullet : public Object
{
public:
	//** 복제 함수.
	Object* Clone() override { return new Bullet(*this); }

public:
	//** 생성자
	Bullet() {}

	//** 복사생성자 
	//Bullet(const INFO& _Info) : Object(_Info){}

	//** 소멸자
	virtual ~Bullet() {}
};



int main(void)
{
	list<Object*> NumberList;

	NumberList.push_back((new Bullet)->Clone());
	NumberList.push_back((new Bullet)->Clone());
	NumberList.push_back((new Bullet)->Clone());
	NumberList.push_back((new Bullet)->Clone());
	NumberList.push_back((new Bullet)->Clone());
	NumberList.push_back((new Bullet)->Clone());


	//** 지역을 생성하여 해당 영역을 빠저 나갈떄 int i 가 선언된 스텍 삭제.
	{
		int i = 0;

		for (list<Object*>::iterator iter = NumberList.begin();
			iter != NumberList.end(); ++iter)
		{
			//** 값 초기화.
			(*iter)->SetInfo(i++);
		}
	}

	//** 출력
	for (auto iter = NumberList.begin();
		iter != NumberList.end(); ++iter)
	{
		cout << (*iter)->GetInfo().iNumber << endl;
	}





	/*
	list<char*> NumberList;

	NumberList.push_back((char*)"Hello World!!");

	for (list<char*>::iterator iter = NumberList.begin();
		iter != NumberList.end(); ++iter)
	{
		cout << (*iter);
	}
	*/


	/*
	for (auto iter = NumberList.begin();
			iter != NumberList.end(); ++iter)
	{
		cout << (*iter) << endl;
	}
	*/

	return 0;
}