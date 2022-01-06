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
	// 전체 벡터를 출력하기
	std::cout << "[";
	for (typename vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
	{
		cout << *itr<<" ";
	}
	cout << "]"<<endl;
}

template <typename T>
void print_vector_range_based(std::vector<T>& vec) {
	//전체 벡터를 출력하기
	for (const auto& elem : vec) {
		cout << elem << endl;
	}
}

template <typename T>
void print_list(list<T>& lst)
{
	cout << "[";
	// 전체 리스트를 출력하기
	for (const auto& elem : lst) {
		cout << elem << " ";
	}
	cout << "]" << endl;
}

template <typename T>
void print_deque(deque<T>& dq)
{
	// 전체 덱을 출력하기
	cout << "[";
	for (const auto& elem : dq) {
		cout << elem << " ";
	}
	cout << "]" << endl;
}

template <typename T>
void print_set(set<T>& s)
{
	// 셋의 모든 원소들을 출력하기
	cout << "[";
	for (typename set<T>::iterator itr = s.begin(); itr != s.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << "]" << endl;
}

template <typename K, typename V>
void print_map(std::map<K, V>& m) {
  // 맵의 모든 원소들을 출력하기
  for (auto itr = m.begin(); itr != m.end(); ++itr) {
    std::cout << itr->first << " " << itr->second << std::endl;
  }
}
template <typename K, typename V>
void print_map(const std::multimap<K, V>& m) {
	// 맵의 모든 원소들을 출력하기
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
	int priority; // 중요도, 높을 수록 급한 것
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
	o << "[ 중요도: " << td.priority << "] " << td.job_desc<<endl;
	return o;
}
void vector_main()
{
	// 벡터
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(20);

	cout << " 처음 벡터 상태" << endl;
	print_vector(vec);
	//for (vector<int>::size_type i = 0; i < vec.size(); i++) {
	//	cout << "vec의 " << i + 1 << "번째 원소 :: " << vec[i] << endl;
	//}

	vector<int>::iterator itr = vec.begin()+2;
	vector<int>::iterator end_itr = vec.end();

	*itr = 50;

	cout << "----------------------" << endl;
	print_vector(vec);
	cout << "----------------------" << endl;

	cout << "역으로 vec 출력하기" << endl;
	vector<int>::reverse_iterator r_iter = vec.rbegin();
	for (; r_iter != vec.rend(); r_iter++){
		cout<< *r_iter <<endl;
	}

	for (int elem : vec)
	{
		cout << "원소 : " << elem << endl;
	}

	print_vector_range_based(vec);
}

void list_main()
{
	// 리스트
	list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(20);

	cout << "처음 리스트의 상태" << endl;
	print_list(lst);

	for (list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr)
	{
		// 만일 현재 원소가 20이라면
		// 그 앞에 50을 넣는다.
		if (*itr == 20)
		{
			lst.insert(itr, 50);
		}
	}
	print_list(lst);

	for (list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr)
	{
		// 값이 30인 원소를 삭제한다.
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

	cout << "초기 dq 상태" << endl;
	print_deque(dq);

	cout << "맨 앞의 원소 제거" << endl;
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

	cout << "순서대로 정렬되어서 나온다" << endl;
	print_set(s);

	cout << " 60이 s의 원소인가요? :: ";
	auto itr = s.find(60);
	if (itr != s.end())
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	cout << " 20이 s의 원소인가요? :: ";
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

	pitcher_list.insert(pair<string, double>("박세웅", 2.23));
	pitcher_list.insert(pair<string, double>("해커", 2.93));
	pitcher_list.insert(pair<string, double>("피어밴드", 2.95));

	// 타입을 지정하지 않아도 간단히 make_pair함수로
	// std::pair 객체를 만들 수도 있습니다.
	pitcher_list.insert(make_pair("차우찬", 3.04));
	pitcher_list.insert(make_pair("장원준", 3.05));
	pitcher_list.insert(make_pair("헥터", 3.09));

	// 혹은 insert 를 안쓰더라도 [] 로 바로
	// 원소를 추가할 수 있습니다.
	pitcher_list["니퍼트"] = 3.56;
	pitcher_list["박종훈"] = 3.76;
	pitcher_list["켈리"] = 3.90;
	
	print_map(pitcher_list);

	std::cout << "박세웅 방어율은? :: " << pitcher_list["박세웅"] << std::endl;
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


// 역정렬 비교 구조체
struct int_compare {
	bool operator()(const int& a, const int& b)const { return a > b; }
};
// 홀수 비교 구조체
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
	
	/*cout << "정렬 전 ----" << endl;
	print(vec.begin(), vec.end());

	sort(vec.begin(), vec.end());

	cout << "정렬 후 ----" << endl;
	print(vec.begin(), vec.end());*/

	cout << "---- 정렬 전 ----" << endl;
	print(vec.begin(), vec.end());

	//sort(vec.begin(), vec.end(),int_compare());

	partial_sort(vec.begin(), vec.begin() + 5, vec.end());

	// 3인 벡터 값 지우기
	//vec.erase(remove(vec.begin(), vec.end(), 3), vec.end());

	// 벡터에서 홀수인 원소 제거
	//vec.erase(remove_if(vec.begin(), vec.end(), is_odd()), vec.end());

	cout << "---- 정렬 후 ----" << endl;
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

void stable_sort_main() // 원소가 삽입되어 있는 순서를 보존하는 정렬 방식
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

	cout << "---- 정렬 전 ----" << endl;
	print(vec.begin(), vec.end());

	sort(vec.begin(), vec.end());

	cout << "---- 정렬 후 ----" << endl;
	print(vec.begin(), vec.end());

	cout << "---- stable_sort 의 경우 ----" << endl;
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

	cout << "---- 처음 vec 상태 ----" << endl;
	print(vec.begin(), vec.end());

	cout << "---- 벡터에서 홀수인 원소 제거 ----" << endl;
	vec.erase(remove_if(vec.begin(), vec.end(), 
		[](int i)-> bool { return i % 2 == 1; }), // 람다 함수 부분 [capture list] (받는 인자) -> 리턴 타입 { 함수 본체 } 
		vec.end());
	print(vec.begin(), vec.end());
}



void dynamic_array_main()
{
	cout << "가로 배열 길이 ";
	int length, width;
	cin >> length;

	cout << "세로 배열 길이 ";
	cin >> width;

	//int* array = new int[length](); // 배열 버전 new 연산자를 사용한다. 배열길이는 상수가 아니여도 된다.
	//cout << "가로 배열 길이" << length << "\n";

	//int fixedArray[5] = { 9,7,5,3,1 };
	//int* array1 = new int[5]{ 9,7,5,3,1 };

	//for (int i = 0; i < length; i++)
	//{
	//	cout << array[i]<< fixedArray[i]<< array1[i] << endl;
	//	
	//}
	//delete[] array;

	// 2차원 배열 동적 할당
	int** arr = new int* [length]; // 선언하고자 하는 2차원 배열의 행의 수 만큼 동적 할당
	for (int i = 0; i < length; i++)
	{
		arr[i] = new int[width];
	}


	// 동적할당한 메모리를 순서대로 값 기입하기
	for (int j = 0; j < length; j++)
		for (int i = 0; i < width; i++)
		{
			if (j < 1)
				arr[j][i] = i;
			else if (j >= 1)
				arr[j][i] = j * width + i;
		}

	// 동적할당한 메모리를 순서대로 출력
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
