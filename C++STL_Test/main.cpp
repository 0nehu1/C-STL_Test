#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

template <typename T>
void print_vector(std::vector<T>& vec)
{
	// ��ü ���͸� ����ϱ�
	std::cout << "[";
	for (typename vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
	{
		cout << *itr<<" ";
	}
	cout << "]"<<endl;
}

template <typename T>
void print_vector_range_based(std::vector<T>& vec) {
	//��ü ���͸� ����ϱ�
	for (const auto& elem : vec) {
		cout << elem << endl;
	}
}

template <typename T>
void print_list(list<T>& lst)
{
	cout << "[";
	// ��ü ����Ʈ�� ����ϱ�
	for (const auto& elem : lst) {
		cout << elem << " ";
	}
	cout << "]" << endl;
}

template <typename T>
void print_deque(deque<T>& dq)
{
	// ��ü ���� ����ϱ�
	cout << "[";
	for (const auto& elem : dq) {
		cout << elem << " ";
	}
	cout << "]" << endl;
}

template <typename T>
void print_set(set<T>& s)
{
	// ���� ��� ���ҵ��� ����ϱ�
	cout << "[";
	for (typename set<T>::iterator itr = s.begin(); itr != s.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << "]" << endl;
}

template <typename K, typename V>
void print_map(std::map<K, V>& m) {
  // ���� ��� ���ҵ��� ����ϱ�
  for (auto itr = m.begin(); itr != m.end(); ++itr) {
    std::cout << itr->first << " " << itr->second << std::endl;
  }
}
template <typename K, typename V>
void print_map(const std::multimap<K, V>& m) {
	// ���� ��� ���ҵ��� ����ϱ�
	for (const auto& kv : m) {
		std::cout << kv.first << " " << kv.second << std::endl;
	}
}

template <typename Iter>
void print(Iter begin, Iter end) {
	while (begin != end) {
		std::cout << "[" << *begin << "] ";
		begin++;
	}
	std::cout << std::endl;
}
class Todo {
	int priority; // �߿䵵, ���� ���� ���� ��
	string job_desc;

public:
	Todo(int priority, string job_desc)
		:priority(priority), job_desc(job_desc){}

	bool operator<(const Todo& t) const {
		if (priority == t.priority) {
			return job_desc < t.job_desc;
		}
		return priority > t.priority;
	}
	friend ostream& operator<<(ostream& o, const Todo& td);	
};
ostream& operator<<(std::ostream& o, const Todo& td) {
	o << "[ �߿䵵: " << td.priority << "] " << td.job_desc<<endl;
	return o;
}
void vector_main()
{
	// ����
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(20);

	cout << " ó�� ���� ����" << endl;
	print_vector(vec);
	//for (vector<int>::size_type i = 0; i < vec.size(); i++) {
	//	cout << "vec�� " << i + 1 << "��° ���� :: " << vec[i] << endl;
	//}

	vector<int>::iterator itr = vec.begin()+2;
	vector<int>::iterator end_itr = vec.end();

	*itr = 50;

	cout << "----------------------" << endl;
	print_vector(vec);
	cout << "----------------------" << endl;

	cout << "������ vec ����ϱ�" << endl;
	vector<int>::reverse_iterator r_iter = vec.rbegin();
	for (; r_iter != vec.rend(); r_iter++){
		cout<< *r_iter <<endl;
	}

	for (int elem : vec)
	{
		cout << "���� : " << elem << endl;
	}

	print_vector_range_based(vec);
}

void list_main()
{
	// ����Ʈ
	list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(20);

	cout << "ó�� ����Ʈ�� ����" << endl;
	print_list(lst);

	for (list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr)
	{
		// ���� ���� ���Ұ� 20�̶��
		// �� �տ� 50�� �ִ´�.
		if (*itr == 20)
		{
			lst.insert(itr, 50);
		}
	}
	print_list(lst);

	for (list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr)
	{
		// ���� 30�� ���Ҹ� �����Ѵ�.
		if (*itr == 30) {
			lst.erase(itr);
			break;
		}
	}
	print_list(lst);
}

void deque_main()
{
	deque<int> dq;
	dq.push_back(10);
	dq.push_back(20);
	dq.push_front(30);
	dq.push_front(40);

	cout << "�ʱ� dq ����" << endl;
	print_deque(dq);

	cout << "�� ���� ���� ����" << endl;
	dq.pop_front();
	print_deque(dq);
}

void set_main()
{
	set<int> s;
	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);
	s.insert(10);

	cout << "������� ���ĵǾ ���´�" << endl;
	print_set(s);

	cout << " 60�� s�� �����ΰ���? :: ";
	auto itr = s.find(60);
	if (itr != s.end())
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	cout << " 20�� s�� �����ΰ���? :: ";
	auto itr1 = s.find(20);
	if (itr1 != s.end())
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

}

void todo_set_main()
{
	set<Todo> todos;

	todos.insert(Todo(1, "basketball"));
	todos.insert(Todo(2, "math"));
	todos.insert(Todo(3, "programming"));
	todos.insert(Todo(4, "friend"));
	todos.insert(Todo(5, "movie"));

	print_set(todos);
}

void map_main()
{
	map<string, double> pitcher_list;

	pitcher_list.insert(pair<string, double>("�ڼ���", 2.23));
	pitcher_list.insert(pair<string, double>("��Ŀ", 2.93));
	pitcher_list.insert(pair<string, double>("�Ǿ���", 2.95));

	// Ÿ���� �������� �ʾƵ� ������ make_pair�Լ���
	// std::pair ��ü�� ���� ���� �ֽ��ϴ�.
	pitcher_list.insert(make_pair("������", 3.04));
	pitcher_list.insert(make_pair("�����", 3.05));
	pitcher_list.insert(make_pair("����", 3.09));

	// Ȥ�� insert �� �Ⱦ����� [] �� �ٷ�
	// ���Ҹ� �߰��� �� �ֽ��ϴ�.
	pitcher_list["����Ʈ"] = 3.56;
	pitcher_list["������"] = 3.76;
	pitcher_list["�̸�"] = 3.90;
	
	print_map(pitcher_list);

	std::cout << "�ڼ��� �������? :: " << pitcher_list["�ڼ���"] << std::endl;
}

void multimap_main()
{
	multimap<int, string> m;
	m.insert(make_pair(1, "hello"));
	m.insert(make_pair(1, "hi"));
	m.insert(make_pair(1, "ahihi"));
	m.insert(make_pair(2, "bye"));
	m.insert(make_pair(2, "baba"));

	print_map(m);

	std::cout << "--------------------" << std::endl;
	std::cout << m.find(1)->second << std::endl;
}


// ������ �� ����ü
struct int_compare {
	bool operator()(const int& a, const int& b)const { return a > b; }
};
// Ȧ�� �� ����ü
struct is_odd {
	bool operator()(const int& i) { return i % 2 == 1; }
};
void sort_main()
{
	vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(6);
	vec.push_back(4);
	vec.push_back(7);
	vec.push_back(2);
	
	/*cout << "���� �� ----" << endl;
	print(vec.begin(), vec.end());

	sort(vec.begin(), vec.end());

	cout << "���� �� ----" << endl;
	print(vec.begin(), vec.end());*/

	cout << "---- ���� �� ----" << endl;
	print(vec.begin(), vec.end());

	//sort(vec.begin(), vec.end(),int_compare());

	partial_sort(vec.begin(), vec.begin() + 5, vec.end());

	// 3�� ���� �� �����
	//vec.erase(remove(vec.begin(), vec.end(), 3), vec.end());

	// ���Ϳ��� Ȧ���� ���� ����
	//vec.erase(remove_if(vec.begin(), vec.end(), is_odd()), vec.end());

	cout << "---- ���� �� ----" << endl;
	print(vec.begin(), vec.end());


}

struct User {
	string name;
	int age;

	User(string name, int age) : name(name), age(age) {}

	bool operator<(const User& u) const { return age < u.age; }
};

ostream& operator<<(ostream& o, const User& u) {
	o << u.name << " , " << u.age;
	return o;
}

void stable_sort_main() // ���Ұ� ���ԵǾ� �ִ� ������ �����ϴ� ���� ���
{
	vector<User> vec;
	for (int i = 0; i < 100; i++)
	{
		string name = "";
		name.push_back('a' + i / 26);
		name.push_back('a' + i % 26);
		vec.push_back(User(name, static_cast<int>(rand() % 10)));
	}

	vector<User> vec2 = vec;

	cout << "---- ���� �� ----" << endl;
	print(vec.begin(), vec.end());

	sort(vec.begin(), vec.end());

	cout << "---- ���� �� ----" << endl;
	print(vec.begin(), vec.end());

	cout << "---- stable_sort �� ��� ----" << endl;
	stable_sort(vec2.begin(), vec2.end());
	print(vec2.begin(), vec2.end());

}

void lambda_main()
{
	vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	cout << "---- ó�� vec ���� ----" << endl;
	print(vec.begin(), vec.end());

	cout << "---- ���Ϳ��� Ȧ���� ���� ���� ----" << endl;
	vec.erase(remove_if(vec.begin(), vec.end(), 
		[](int i)-> bool { return i % 2 == 1; }), // ���� �Լ� �κ� [capture list] (�޴� ����) -> ���� Ÿ�� { �Լ� ��ü } 
		vec.end());
	print(vec.begin(), vec.end());
}



void dynamic_array_main()
{
	cout << "���� �迭 ���� ";
	int length, width;
	cin >> length;

	cout << "���� �迭 ���� ";
	cin >> width;

	//int* array = new int[length](); // �迭 ���� new �����ڸ� ����Ѵ�. �迭���̴� ����� �ƴϿ��� �ȴ�.
	//cout << "���� �迭 ����" << length << "\n";

	//int fixedArray[5] = { 9,7,5,3,1 };
	//int* array1 = new int[5]{ 9,7,5,3,1 };

	//for (int i = 0; i < length; i++)
	//{
	//	cout << array[i]<< fixedArray[i]<< array1[i] << endl;
	//	
	//}
	//delete[] array;

	// 2���� �迭 ���� �Ҵ�
	int** arr = new int* [length]; // �����ϰ��� �ϴ� 2���� �迭�� ���� �� ��ŭ ���� �Ҵ�
	for (int i = 0; i < length; i++)
	{
		arr[i] = new int[width];
	}


	// �����Ҵ��� �޸𸮸� ������� �� �����ϱ�
	for (int j = 0; j < length; j++)
		for (int i = 0; i < width; i++)
		{
			if (j < 1)
				arr[j][i] = i;
			else if (j >= 1)
				arr[j][i] = j * width + i;
		}

	// �����Ҵ��� �޸𸮸� ������� ���
	for(int j = 0; j < length; j++)
	for (int i = 0; i < width; i++)
	{
			cout << "[" << j << "]" << "[" << i << "]" << " = " << arr[j][i] << endl;
	}

	for (int i = 0; i < length; i++)
		delete[] arr[i];

	delete[] arr;

}


int main()
{
	dynamic_array_main();
}
