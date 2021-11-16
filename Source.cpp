#include <iostream>
using namespace std;
#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。

/* --------------------------------------------------------------- */
/* is_prime
* 
* 与えられた正整数 x に対して素数かどうか判定する
*/
/* -------------------------------------------------------------- */
bool is_prime(unsigned int x)
{
  if (x == 1) {
    return false;
  }
  for (int i = 2; i < x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  //2からx-1までの数がxで割れるかチェックする
  //もし割れたら即falseを返す
  return true;
}
/* --------------------------------------------------------------- */
/*
* n
*
* 与えられた正整数 a と d と n に対して、この等差数列に含まれる n 番目の
* 素数を返す。
*
* TODO: この nth_prime 関数を実装せよ。必要であれば他に関数や
* ファイルを作成せよ。
*/
/* -------------------------------------------------------------- */
int nth_prime(unsigned int a, unsigned int d, unsigned int n)
{

  int count_N = 0;  
  int num;
  for (int i = 0;; i++) {
    num = i * d + a;
    if (is_prime(num) == true) {
      count_N++;
      if (count_N == n) return num;
    }

  }
}

int main()
{
  cout << nth_prime(259, 170, 40) << endl;
  cout << nth_prime(367, 186, 151) << endl;
  cout << nth_prime(179, 10, 203)  <<  endl;
  cout << nth_prime(103, 230, 1) << endl;
  cout << nth_prime(27, 104, 185) << endl;
  cout << nth_prime(253, 50, 85) << endl;
  cout << nth_prime(1, 1, 1) << endl;
  cout << nth_prime(9075, 337, 210) << endl;
  cout << nth_prime(307, 24, 79) << endl;
  cout << nth_prime(331, 221, 177) << endl;
  cout << nth_prime(259, 170, 40) << endl;
  cout << nth_prime(269, 58, 102) << endl;

  //std::cout << nth_prime(367, 186, 151) << std::endl;
  // 以下、同様に、入出力例通りになるか確認せよ。
  
  return 0;
}