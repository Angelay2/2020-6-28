/*

�����һ�����ж������麯��, �����ж��ٸ��麯��, ��Ͳ����ǿ�����, ���涼����һ�������ĳ�Ա����  -----> �麯����ָ�� 
�麯����ָ��: ָ���麯������׵�ַ(����ָ��, ��Ҫ������,��Ҫ�����ν�����)
�麯����: ������(����Ϊһָ������), ÿһ��Ԫ�ض����麯��ָ��
	1. �����̳и�����麯����,
	2. ���������д�ĸ�����麯��, ��������̳е������, ����д���麯������Ӧ���麯��ָ��ᱻ������麯��ָ�븲��.
	3. ���ֻ����麯��ָ��, ��ͨ����ָ�벻�����������
	4. �����nullptr����, �������nullptrʱ ��֤���麯����������
	5. �麯��ָ��������еĴ��˳���������/�����˳��һ��, �ȶ����Ǹ� �ȷ��Ǹ�ָ��
	6. �����������麯��, ��ָ�밴������/�����˳�����δ��������ĩβ

��̬����: ͨ��ָ��/���õ����麯��      (����ʱ��/��̬��/���ڰ�)
	1. ����ͨ��ʵ��ָ���ʵ���ȡ���ָ�� (�ڶ����д�ŵ����ָ��)
	2. ͨ�����ָ���ҵ����
	3. ��������ҵ�ִ�к�����ʵ�ʵ�ַ
	4. ִ�ж�Ӧ��ַ�ĺ���ָ��, ��ɶ�̬��Ϊ
�Ƕ�̬: ������ (����ʱ��/ǰ�ڰ�/��̬��)

���ָ�����ڶ�����, �����ڴ����(���ڶ�����),            ���ָ��->�����Կ��, ���->���� 
�麯��ָ����������, �麯�����ڴ����                       
�����ֻ����麯����ָ��, ��������麯����ʵ��ָ��, 

��̬��̬: �̳� + �麯��      (����ʱ��)
��̬��̬: ��������, ģ��     (����ʱ��)

��̳����:
	1. ���ĸ�����ֱ�Ӹ���ĸ�����ͬ
	2. ����̳�ÿһ��ֱ�Ӹ�������
	3. ������д���麯��, ���麯��ָ��Ḳ�Ǹ����е��麯��ָ��
	4. �����¶�����麯��, ���麯����ָ��ᰴ������/�����˳�����δ���ڵ�һ��ֱ�Ӹ�������ĩβ
���̳�:
	1. ����̳и�������
	2. ������д���麯��, ���麯��ָ��Ḳ�Ǹ����е��麯��ָ��
	3. �����¶�����麯��, ���麯����ָ��ᰴ������/�����˳�����ڼ̳еĸ�������ĩβ
*/

#include <iostream>
using namespace std;

//class Car
//{
//public:
//	//final�����ĺ������ܱ�������д�� ����ʵ�ּ̳�
//	/*virtual void Drive() final{}*/
//	virtual void Drive(){}
//};
//class Benz :public Car
//{
//public:
//	//override: ����override�������麯��������д�����е�һ���麯����������벻ͨ��
//	//override���ֽӿڼ̳�
//	virtual void Drive() override { cout << "Benz-����" << endl; }
//};

//�����ࣺ �������麯������
//    1.  ����ʵ����
//    2.  �������û����д����Ĵ��麯����������ҲΪ������
//    3.  ���ֽӿڼ̳�

//class Car
//{
//public:
//	//���麯��
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	
//	virtual void Drive(){ cout << "Benz-����" << endl; }
//};

//void test()
//{
//	Car* ptr = new Benz;
//	ptr->Drive();
//	Benz* ptr2 = new Benz;
//	ptr2->Drive();  
//	//ptr2->Car::Drive();
//}

//void test()
//{
//	Car* ptr = new Benz;
//	ptr->Drive();
//}


//class Base
//{
//public:
//	
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Func()" << endl;
//	}
//	virtual void Func3()
//	{
//		cout << "Func1()" << endl;
//	}
//};
//
//class Base2
//{
//public:
//	void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//};
//
//void test()
//{
//	Base b;
//	Base2 b2;
//	cout << sizeof(Base) << endl;
//	cout << sizeof(Base2) << endl;
//}

//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	
//	virtual void Func2()
//	{
//			cout << "Base::Func2()" << endl;
//		}
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//	virtual void Func4()
//	{
//		cout << "Derive::Func4()" << endl;
//	}
//private:
//	int _d = 2;
//};

//void test()
//{
//	Base b;
//	Derive d;
//
//	Base* ptr2 = &d;
//	ptr2->Func1();
//	ptr2->Func2();
//	cout << sizeof(Base) << endl;
//	cout << sizeof(Derive) << endl;
//
//	d.Func1();
//}

//���庯��ָ��
//VfPtr�� ����һ�ຯ����ָ��--> ����ֵΪ�գ�����Ϊ��
typedef void(*VfPtr) ();

void doVF(VfPtr* vftable)
{
	for (int i = 0; vftable[i] != nullptr; ++i)
	{
		//��ȡ���ǰλ�õĺ���ָ��
		VfPtr func = vftable[i];
		func();
	}
}

//void test()
//{
//	Base b;
//	Derive d;
//
//	VfPtr* vftable = (VfPtr*)(*((int*)&b));
//	cout << "Base:" << endl;
//	doVF(vftable);
//
//
//	vftable = (VfPtr*)(*((int*)&d));
//	cout << "Derive:" << endl;
//	doVF(vftable);
//	
//}

class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};

void test()
{
	Base1 b1;
	Base2 b2;
	Derive d;
	cout << "Base1:" << endl;
	VfPtr* vftable = (VfPtr*)(*((int*)&b1));
	doVF(vftable);

	cout << "Base2:" << endl;
	vftable = (VfPtr*)(*((int*)&b2));
	doVF(vftable);

	//cout << sizeof(Derive) << endl;
	cout << "Derive: ��һ�����" << endl;
	cout << "Derive:" << endl;
	vftable = (VfPtr*)(*((int*)&d));
	doVF(vftable);

	//��ַƫ�ƣ��ҵ��ڶ������ָ��Ĵ��λ��
	cout << "Derive: �ڶ������" << endl;
	vftable = (VfPtr*)(*((int*)((char*)&d + sizeof(Base1))));
	doVF(vftable);

}
int main()
{
	test();
	return 0;
}

