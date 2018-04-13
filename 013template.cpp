//模板用法

//https://blog.csdn.net/qq_35637562/article/details/55194097

#include<iostream>
#include<stdio.h>

using namespace std;

//函数模板
template <typename T> void swap_(T& a, T& b) {  
	//typename关键字告诉编译器把一个特殊的名字解释为一个类型
	T temp;
	temp = b;
	b = a;
	a = temp;
}

//template<class V> void swap_(vector<V>& t1, vector<V>& t2) {
//	t1.swap_(t2);
//}
//template<>前缀表示这是一个专门化,描述时不用      模板参数
//template<> void swap(std::vector<int>& t1, std::vector<int>& t2)
//template<class V> void swap(std::vector<V>& t1, std::vector<V>& t2)


//类模板
template <class T> class Stack {
public:
	Stack() {
		m_maxSize = 100;
		m_pT = new T[m_maxSize];
		m_size = 0;
	};

	~Stack() {
		delete[] m_pT;
	};

	void push(T t) {
		m_size++;
		m_pT[m_size - 1] = t;
	};
	T pop() {
		T t = m_pT[m_size - 1];
		m_size--;
		return t;
	};

	bool isEmpty() {
		return m_size == 0;
	};

	//定义转换代码
	/*template <class T> template <class T2>  Stack<T>::operator Stack<T2>() {
		Stack<T2> StackT2;
		for (int i = 0; i < m_size; i++) {
			StackT2.push((T2)m_pT[m_size - 1]);
		}
		return StackT2;
	}*/

private:
	T *m_pT;
	int m_maxSize;
	int m_size;
};

//template <class T, int maxsize = 100> class Stack {}; 模板参数

int main() {
	//函数模板
	int num1 = 2, num2 = 90;
	swap_<int>(num1, num2);
	cout << num1 << endl << num2 << endl;

	//类模板 栈
	Stack<int> inistack;
	inistack.push(1);
	inistack.push(2);
	inistack.push(3);
	while (!inistack.isEmpty()) {
		cout << inistack.pop() << endl;
	}
	return 0;
}
