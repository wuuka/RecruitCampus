//关联数据信息的排序操作

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//使用结构体来确定数据间的关联性
struct JobInformation{
	int Difficult;  //工作难度
	int Reward;  //报酬
};

struct PersonInformation{
	int personCap;  //个人能力
	int index;      //
	int money;      //个人工资
};

//定义sort函数排序的比较变量。
bool cmp_job(JobInformation a, JobInformation b) {
		return a.Difficult < b.Difficult;
}

bool cmp_person(PersonInformation a, PersonInformation b) {
		return a.personCap < b.personCap;
}

bool cmp_person_temp(PersonInformation a, PersonInformation b) {
	return a.index < b.index;
}


int main()
{
	int N, M;
	while (cin >> N >> M) {
		JobInformation *Job = new JobInformation[N];
		for (int i = 0; i < N; i++)
			cin >> Job[i].Difficult >> Job[i].Reward;

		PersonInformation *person = new PersonInformation[M];
		for (int j = 0; j < M; j++) {
			cin >> person[j].personCap;
			person[j].index = j;
		}

		sort(Job, Job + N, cmp_job);  //工作难度排序
		sort(person, person + M, cmp_person);  //个人能力排序

		int s = 0, maxMoney = 0;
		for (int k = 0; k < M; k++) {
			while (s < N) {
				if (person[k].personCap < Job[s].Difficult)
					break;
				maxMoney = max(maxMoney, Job[s].Reward);
				s++;
			}
			person[k].money = maxMoney;
		}

		sort(person, person + M, cmp_person_temp);  //按输入个人顺序输出其工资选择情况
		for (size_t l = 0; l < M; l++)
			cout << person[l].money << endl;

		delete[] Job;
		delete[] person;
	}
	return 0;
}
