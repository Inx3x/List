#include <iostream>
#include <list>

using namespace std;

//** ����ü
typedef struct tagInfo
{
	int iNumber;
}INFO;


class Object
{
	//** ��Ӱ��� ��� ����.
protected:
	INFO Info;
public:
	//** ���߾� �Լ�. �ڽ� Ŭ�������� ���. (���� ���� �Լ�)
	virtual Object* Clone() = 0;

public:
	//** Getter
	INFO GetInfo() { return Info; }

	//** Setter
	void SetInfo(int _number) { Info.iNumber = _number; }

public:
	//** ������.
	Object() {}

	//** ���� ������
	//Object(const INFO& _Info) : Info(_Info) {}

	//** �Ҹ���.
	virtual ~Object() {}
};



//** Bullet Ŭ����  Object ���
class Bullet : public Object
{
public:
	//** ���� �Լ�.
	Object* Clone() override { return new Bullet(*this); }

public:
	//** ������
	Bullet() {}

	//** ��������� 
	//Bullet(const INFO& _Info) : Object(_Info){}

	//** �Ҹ���
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


	//** ������ �����Ͽ� �ش� ������ ���� ������ int i �� ����� ���� ����.
	{
		int i = 0;

		for (list<Object*>::iterator iter = NumberList.begin();
			iter != NumberList.end(); ++iter)
		{
			//** �� �ʱ�ȭ.
			(*iter)->SetInfo(i++);
		}
	}

	//** ���
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