//����֮��·������
//�ݹ麯���İ���  https://blog.csdn.net/sinat_38052999/article/details/73303111
#include <iostream>  
#include <cmath>  

using namespace std;

int fun(int row, int col, int x, int y) {
	if (row == x&&col == y - 1)
		return 1;
	else if (row == x - 1 && col == y)
		return 1;
	else {
		if (row<x&&col<y)
			return fun(row + 1, col, x, y) + fun(row, col + 1, x, y);
		else if (row<x&&col == y)
			return fun(row + 1, col, x, y);
		else if (row == x&&col<y)
			return fun(row, col + 1, x, y);
	}

}

int main()
{
	int startX, startY, endX, endY;
	cout << "�����������յ�����" << endl;
	cin >> startX >> startY >> endX >> endY;
	cout << "�������Ϊ��" << startX << "," << startY << ")" << endl;
	cout << "�յ�����Ϊ��" << endX << "," << endY << ")" << endl;
	int lenX = abs(startX - endX);
	int lenY = abs(startY - endY);
	cout << fun(0, 0, lenX, lenY);
	return 0;
}
