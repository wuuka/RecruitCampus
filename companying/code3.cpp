
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main() {
       int num;
       double price;
       cin >> num >> price;
       while (num <= 0 || num >= 10000 || price <= 0 || price >= 10000) {
              cin >> num >> price;
       }
       //计算厂商1
       double sum_one = 10;
       if (num >= 3) {
              sum_one = sum_one + num*price*0.7;
              if (sum_one >= 50)
                     sum_one = sum_one - 10;
       }
       else {
              sum_one = sum_one + num*price;
              if (sum_one >= 50)
                     sum_one = sum_one - 10;
       }
       sum_one = ((int)(sum_one * 100 + 0.5)) / 100.0;
       //计算厂商2
       double sum_two = 6;
       sum_two = sum_two + num*price -(int)(sum_two + num*price)/10 *2;
       if (sum_two >= 99)
              sum_two = sum_two - 6;
       sum_two = ((int)(sum_two * 100 + 0.5)) / 100.0;
       //比较
       if (abs(sum_two - sum_one) < 0.01)
              cout << '0' << endl;   //两个厂家一样
       else if (sum_one - sum_two > 0.01)
              cout << '2' << endl;   //厂商一更好
       else
              cout << '1' << endl;
       return 0;
}
