#include <iostream>
using namespace std;
#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。
#define GET_ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
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
int ao[13];//比較
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
  int count = 0;
  for (int i = a; i < CPP2_PRIME_UPPER_LIMIT; i++) {
    if (is_prime(a)) count++;
    if (count == n) {
      break;
    } else {
      a += d;
    }
  }
  for (int j = 0; j < GET_ARRAY_SIZE(ao); j++) {
    ao[j] = a;
  }	
  return a;
}




void rep2_2(unsigned int i)
{
  int ans[] =
  {92809,6709,12037,103,93523,
   14503,2,899429,5107,412717,
   22699,25673,2525};

  
  if (ao[i] == ans[i]) {
    cout << "正解" << endl;
  } else {
    cout << "不正解" << endl;
  }

  
}

int main()
{

  cout << nth_prime(367, 186, 151) << endl;
  rep2_2(0);
  cout << nth_prime(179, 10, 203) << endl;
  rep2_2(1);
  cout << nth_prime(271, 37, 39) << endl;
  rep2_2(2);
  cout << nth_prime(103, 230, 1) << endl;
  rep2_2(3);
  cout << nth_prime(27, 104, 185) << endl;
  rep2_2(4);
  cout << nth_prime(253, 50, 85) << endl;
  rep2_2(5);
  cout << nth_prime(1, 1, 1) << endl;
  rep2_2(6);
  cout << nth_prime(9075, 337, 210) << endl;
  rep2_2(7);
  cout << nth_prime(307, 24, 79) << endl;
  rep2_2(8);
  cout << nth_prime(331, 221, 177) << endl;
  rep2_2(9);
  cout << nth_prime(259, 170, 40) << endl;
  rep2_2(10);
  cout << nth_prime(269, 58, 102) << endl;
  rep2_2(11);
  cout << nth_prime(59, 59, 59) << endl;
  rep2_2(12);
  //std::cout << nth_prime(367, 186, 151) << std::endl;
  // 以下、同様に、入出力例通りになるか確認せよ。

  return 0;
}