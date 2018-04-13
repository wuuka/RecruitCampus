//���ױ�����--�����ɫ�����

//�����һ�����ң������������һ����������������û���㹻��ɫ�����ϡ�Ϊ��������򵥣���������������ʾ��ͬ��ɫ�����ϡ���֪���������Ҫ��n����ɫ�����ϣ������ڿ���ȥ�̵깺��һЩ���ϣ������̵겻�ܱ�֤�ܹ�Ӧ������ɫ�����ϣ���������Ҫ�Լ����һЩ���ϡ�������ֲ�һ������ɫA����ɫB���Ͽ��Բ���(A XOR B)������ɫ������(�²���������Ҳ��������������ϲ����µ���ɫ,XOR��ʾ������)�������ڼ��Լ�ľ������빺����ٵ����Ͼ�����Ҫ�����Լ�ְ����Ա������Ҫ����������������Ҫ��������ɫ�����ϣ�

//http://blog.csdn.net/huzhigenlaohu/article/details/52264154

//https://www.nowcoder.com/profile/7109426/codeBookDetail?submissionId=15604075

#include <iostream>  
#include <vector>  
#include <algorithm>  

using namespace std;

// ��һ�����Ķ����Ƶ����λ����λ  
int getHighBit(int num) {
	int highbit = 0;
	while (num) {
		// �������Ķ���������һλ  
		num >>= 1;
		highbit++;
	}
	return highbit;
}

int main() {
	vector < int > colors;
	int n;

	while (cin >> n) {
		colors.clear();
		int result = 0;
		int temp;
		int i = n;
		while (i--) {
			cin >> temp;
			colors.push_back(temp);
		}

		// �� colors ���д�С���������  
		sort(colors.begin(), colors.end());
		int bigger, smaller;
		//bigger �� smaller ʼ��ָ��������һλ�͵����ڶ�λ��  
		bigger = n - 1;
		smaller = bigger - 1;

		while (colors.size() > 2) {
			// ������ߵ����λ��ͬ��˵�����λ����������  
			// ������ xor ������˵��������������������λ  
			if (getHighBit(colors[bigger]) == getHighBit(colors[smaller])) {
				int tem = colors[bigger] ^ colors[smaller];
				//find ����ͷ�ļ��� <algorithm>  
				// �����㷨�� find ���ڷ� string ���͵����������ֱ���ҳ�����Ӧ��Ԫ��  
				// �� vector ��ͷ��ʼһֱ��β���ҵ���һ��ֵΪ temp ��Ԫ�أ����ص���һ��ָ���Ԫ�صĵ����� std::vector<int>::iterator ����  

				// ��Ϊ���� xor �����������������������λ�ѱ����������� xor �õ��Ľ��һ������������С  

				// ��� temp ��� �����������С�� ��û�б��ҵ����� temp �ӵ� colors �����У������ٴ� xor  
				// �Ҳ����Ļ������� colors.end Ӧ���ǹ̶��÷�  
				vector<int>::iterator qq = find(colors.begin(), colors.end(), tem);
				if (qq == colors.end()) {
					colors.push_back(tem);
					sort(colors.begin(), colors.end());
					bigger++; // ��Ϊ colors �ж���һ������������Ҫλ���� 1  
					smaller++;
				}
			}
			else {
				result++;
			}
			// ����������λ��ͬ��˵���Ѿ������������λ�Ѿ�ֻ�������Ǹ����� 1 �ˣ��������Ѿ������ܱ������ˣ������ 1  

			// �����������������λ������������ô����֮��������ѱ�������û������  
			// �����������������λ��������������ô����� 1 �������Ҳû�����ˡ�  
			// ���������  
			colors.pop_back();

			// ��Ϊ������һ���������� bigger �� smaller ��Ҫ��Ӧ�� 1  
			bigger = smaller;
			smaller--;
		}
		cout << result + 2 << endl;
	}
}
