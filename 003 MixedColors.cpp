//网易笔试题--混合颜色（异或）

//你就是一个画家！你现在想绘制一幅画，但是你现在没有足够颜色的颜料。为了让问题简单，我们用正整数表示不同颜色的颜料。你知道这幅画需要的n种颜色的颜料，你现在可以去商店购买一些颜料，但是商店不能保证能供应所有颜色的颜料，所以你需要自己混合一些颜料。混合两种不一样的颜色A和颜色B颜料可以产生(A XOR B)这种颜色的颜料(新产生的颜料也可以用作继续混合产生新的颜色,XOR表示异或操作)。本着勤俭节约的精神，你想购买更少的颜料就满足要求，所以兼职程序员的你需要编程来计算出最少需要购买几种颜色的颜料？

//http://blog.csdn.net/huzhigenlaohu/article/details/52264154

//https://www.nowcoder.com/profile/7109426/codeBookDetail?submissionId=15604075

#include <iostream>  
#include <vector>  
#include <algorithm>  

using namespace std;

// 求一个数的二进制的最高位是哪位  
int getHighBit(int num) {
	int highbit = 0;
	while (num) {
		// 将该数的二进制右移一位  
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

		// 将 colors 进行从小到大的排序  
		sort(colors.begin(), colors.end());
		int bigger, smaller;
		//bigger 和 smaller 始终指向的是最后一位和倒数第二位数  
		bigger = n - 1;
		smaller = bigger - 1;

		while (colors.size() > 2) {
			// 如果两者的最高位相同，说明最高位可以消掉，  
			// 将两者 xor ，或者说将矩阵两行相减消掉最高位  
			if (getHighBit(colors[bigger]) == getHighBit(colors[smaller])) {
				int tem = colors[bigger] ^ colors[smaller];
				//find 函数头文件是 <algorithm>  
				// 泛型算法的 find ，在非 string 类型的容器里，可以直接找出所对应的元素  
				// 从 vector 的头开始一直到尾，找到第一个值为 temp 的元素，返回的是一个指向该元素的迭代器 std::vector<int>::iterator 类型  

				// 因为现在 xor 的是两个最大的数，而且最高位已被消掉，所以 xor 得到的结果一定比这两个数小  

				// 如果 temp 这个 比最大两个数小的 数没有被找到，则将 temp 加到 colors 数组中，进行再次 xor  
				// 找不到的话，返回 colors.end 应该是固定用法  
				vector<int>::iterator qq = find(colors.begin(), colors.end(), tem);
				if (qq == colors.end()) {
					colors.push_back(tem);
					sort(colors.begin(), colors.end());
					bigger++; // 因为 colors 中多了一个数，所以需要位数＋ 1  
					smaller++;
				}
			}
			else {
				result++;
			}
			// 如果两者最高位不同，说明已经所有数的最高位已经只有最大的那个数是 1 了，这样它已经不可能被消掉了，结果＋ 1  

			// 如果两个最大数的最高位可以消掉，那么消除之后，最大数已被消掉，没有用了  
			// 如果两个最大数的最高位不可以消掉，那么结果＋ 1 ，最大数也没有用了。  
			// 弹出最大数  
			colors.pop_back();

			// 因为弹出了一个数，所以 bigger 和 smaller 都要相应－ 1  
			bigger = smaller;
			smaller--;
		}
		cout << result + 2 << endl;
	}
}
