/*

如果在一个类中定义了虚函数, 不管有多少个虚函数, 类就不会是空类了, 里面都会有一个隐含的成员变量  -----> 虚函数表指针 
虚函数表指针: 指向虚函数表的首地址(二级指针, 想要拿内容,需要做二次解引用)
虚函数表: 简称虚表(本身为一指针数组), 每一个元素都是虚函数指针
	1. 子类会继承父类的虚函数表,
	2. 如果子类重写的父类的虚函数, 则在子类继承的虚表中, 被重写的虚函数所对应的虚函数指针会被子类的虚函数指针覆盖.
	3. 虚表只存放虚函数指针, 普通函数指针不会存放在虚表中
	4. 虚表以nullptr结束, 访问虚表到nullptr时 则证明虚函数访问完了
	5. 虚函数指针在虚表中的存放顺序和其声明/定义的顺序一致, 先定义那个 先放那个指针
	6. 子类新增的虚函数, 其指针按照声明/定义的顺序依次存放在虚表的末尾

多态过程: 通过指针/引用调用虚函数      (运行时绑定/动态绑定/后期绑定)
	1. 首先通过实际指向的实体获取虚表指针 (在对象中存放的虚表指针)
	2. 通过虚表指针找到虚表
	3. 从虚表中找到执行函数的实际地址
	4. 执行对应地址的函数指令, 完成多态行为
非多态: 看类型 (编译时绑定/前期绑定/静态绑定)

虚表指针存放在对象中, 虚表放在代码段(不在对象中),            虚表指针->宝箱的钥匙, 虚表->宝箱 
虚函数指针放在虚表中, 虚函数放在代码段                       
虚表中只存放虚函数的指针, 并不存放虚函数的实际指令, 

动态多态: 继承 + 虚函数      (运行时绑定)
静态多态: 函数重载, 模板     (编译时绑定)

多继承虚表:
	1. 虚表的个数与直接父类的个数相同
	2. 子类继承每一个直接父类的虚表
	3. 子类重写的虚函数, 其虚函数指针会覆盖父类中的虚函数指针
	4. 子类新定义的虚函数, 其虚函数的指针会按照声明/定义的顺序依次存放在第一个直接父类的虚表末尾
单继承:
	1. 子类继承父类的虚表
	2. 子类重写的虚函数, 其虚函数指针会覆盖父类中的虚函数指针
	3. 子类新定义的虚函数, 其虚函数的指针会按照声明/定义的顺序存放在继承的父类的虚表末尾
*/

#include <iostream>
using namespace std;

//class Car
//{
//public:
//	//final声明的函数不能被子类重写， 体现实现继承
//	/*virtual void Drive() final{}*/
//	virtual void Drive(){}
//};
//class Benz :public Car
//{
//public:
//	//override: 加了override声明的虚函数必须重写父类中的一个虚函数，否则编译不通过
//	//override体现接口继承
//	virtual void Drive() override { cout << "Benz-舒适" << endl; }
//};

//抽象类： 包含纯虚函数的类
//    1.  不能实例化
//    2.  如果子类没有重写父类的纯虚函数，则子类也为抽象类
//    3.  体现接口继承

//class Car
//{
//public:
//	//纯虚函数
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	
//	virtual void Drive(){ cout << "Benz-舒适" << endl; }
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

//定义函数指针
//VfPtr： 代表一类函数的指针--> 返回值为空，参数为空
typedef void(*VfPtr) ();

void doVF(VfPtr* vftable)
{
	for (int i = 0; vftable[i] != nullptr; ++i)
	{
		//获取虚表当前位置的函数指针
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
	cout << "Derive: 第一个虚表：" << endl;
	cout << "Derive:" << endl;
	vftable = (VfPtr*)(*((int*)&d));
	doVF(vftable);

	//地址偏移，找到第二个虚表指针的存放位置
	cout << "Derive: 第二个虚表：" << endl;
	vftable = (VfPtr*)(*((int*)((char*)&d + sizeof(Base1))));
	doVF(vftable);

}
int main()
{
	test();
	return 0;
}

