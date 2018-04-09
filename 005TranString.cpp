//�����������߱�� �����ִ�ת�������ٲ��衿

//������������Ϊ n ( 0 < n <= 8 ) �� ���ִ� (��1��9����)  ������ϣ���Ե�һ�����ִ���һϵ�����²�����
//1�������ִ���ĳһλ��1
//2�������ִ���ĳһλ��1
//3���������ִ��������������ֵ�λ��
//����ʹ�õ�һ�����ִ���ɵڶ������ִ��� ����������Ҫ���ٲ�����

//http://blog.csdn.net/libin_vincent/article/details/79601786

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main() {
	char str_[8], std_[8];  //�������ִ�
	cin >> str_;
	cin >> std_;

	int temp[8][8];  //�������
	int num = strlen(str_);
	for (int i = 0; i<num ; ++i) {//�������ַ�����ͬλ��ı�ʾ����
		for (int j = 0; j<num; ++j) {
			temp[i][j] = abs((int)str_[i] - (int)std_[j]);
		}
	}

	int stepNum = 0;  //��������
	for (int i = 0; i<num; ++i) {
		for (int j = 0; j<num; ++j) {
			if (i == j)
				continue;

			//��������ɼ��ٲ���ʱ���н�������
			if ((temp[i][j] == 0 || temp[i][j] == 1) &&
			(temp[j][j] + temp[i][i]) > (temp[j][i] + 1)) {
				for (size_t k = 0; k < num ; ++k) {
					swap(temp[i][k], temp[j][k]);
				}
				stepNum = stepNum + 1;
			}
		}
	}
	//����Խ����ϵĺ�
	for (int p = 0; p < num; ++p)
		stepNum  += temp[p][p];
	cout << stepNum << endl;
}