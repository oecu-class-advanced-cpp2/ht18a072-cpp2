#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>

// 名前空間「cpp2」
namespace cpp2 {
class mcxi {
public:
	// オブジェクトを初期化するクラス（コンストラクタ）
  mcxi(const std::string& s) : value_(0)
  {
    int num = 0;
    for (auto pos = s.begin(); pos != s.end(); ++pos) {
      if (*pos >= '2' && *pos <= '9') {
	num = *pos - '0';
      } else {
	int u = unit(*pos);
	value_ += std::max(num, 1) * u;
	num = 0;
      }
    }
  }

  // 加算用のコンストラクタ
  mcxi() {}


  // 2 つのオブジェクトの加算結果を取得
  mcxi operator+(const mcxi& rhs)
  {

    mcxi ans;
    ans.value_ = value_ + rhs.value_;
    return ans;
  }
  //-------------------------------------------------------------------
  // 現在の値を mcxi 記法に変換
  std::string to_string() const
  {
    std::stringstream ss;

    int m_value = value_;
    int c_value = value_;
    int x_value = value_;
    int i_value = value_;

    int m = 0;
    int c = 0;
    int x = 0;
    int i = 0;
//以下変換
    m = m_value / 1000;
    if (m == 1) {
      ss << 'm';
    } else if (m > 1) {
      ss << m;
      ss << 'm';
    }

    c = c_value % 1000;
    c = c / 100;
    if (c == 1) {
      ss << 'c';
    } else if (c > 1) {
      ss << c;
      ss << 'c';
    }

    x = x_value % 100;
    x = x / 10;
    if (x == 1) {
      ss << 'x';
    } else if (x > 1) {
      ss << x;
      ss << 'x';
    }

    i = i_value % 10;
    if (i == 1) {
      ss << 'i';
    } else if (i > 1) {
      ss << i;
      ss << 'i';
    }

    return ss.str();
  }

private:
	// 単位に対応する値を取得
  int unit(char c)
  {
    switch (c) {
    case 'm': return 1000;
    case 'c': return 100;
    case 'x': return 10;
    case 'i': return 1;
    }
    return -1;
  }
private:
  int value_;
};
}

// 発展課題2
void ans_check(const std::string& s, int i)
{

// 正解の値を格納する配列
  std::vector<std::string> answer = { "3x","x","6cx","5m9c9x9i","m","9m9c9x9i","mi","mi","mx","9m9c9x9i", };

  if (s == answer[i]) {
	  // 正解の値と一致
    std::cout << "正解" << std::endl;
  } else {
	  // 正解の値と一致しない
    std::cout << "不正解" << std::endl;
  }
}

int main()
{
// 1回目の呼び出しと実行
  cpp2::mcxi a0("xi");
  cpp2::mcxi b0("x9i");
  auto result0 = a0 + b0;
  std::cout << "3x" << " " << result0.to_string() << std::endl;

  std::string c0 = result0.to_string();
  ans_check(c0, 0);

  // 2回目
  cpp2::mcxi a1("i");
  cpp2::mcxi b1("9i");
  auto result1 = a1 + b1;
  std::cout << "x" << " " << result1.to_string() << std::endl;

  std::string c1 = result1.to_string();
  ans_check(c1, 1);

  // 3回目
  cpp2::mcxi a2("c2x2i");
  cpp2::mcxi b2("4c8x8i");
  auto result2 = a2 + b2;
  std::cout << "6cx" << " " << result2.to_string() << std::endl;

  std::string c2 = result2.to_string();
  ans_check(c2, 2);

  // 4回目
  cpp2::mcxi a3("m2ci");
  cpp2::mcxi b3("4m7c9x8i");
  auto result3 = a3 + b3;
  std::cout << "5m9c9x9i" << " " << result3.to_string() << std::endl;

  std::string c3 = result3.to_string();
  ans_check(c3, 3);

  // 5回目
  cpp2::mcxi a4("9c9x9i");
  cpp2::mcxi b4("i");
  auto result4 = a4 + b4;
  std::cout << "m" << " " << result4.to_string() << std::endl;

  std::string c4 = result4.to_string();
  ans_check(c4, 4);

  // 6回目
  cpp2::mcxi a5("i");
  cpp2::mcxi b5("9m9c9x8i");
  auto result5 = a5 + b5;
  std::cout << "9m9c9x9i" << " " << result5.to_string() << std::endl;

  std::string c5 = result5.to_string();
  ans_check(c5, 5);

  // 7回目
  cpp2::mcxi a6("m");
  cpp2::mcxi b6("i");
  auto result6 = a6 + b6;
  std::cout << "mi" << " " << result6.to_string() << std::endl;

  std::string c6 = result6.to_string();
  ans_check(c6, 6);

  // 8回目
  cpp2::mcxi a7("i");
  cpp2::mcxi b7("m");
  auto result7 = a7 + b7;
  std::cout << "mi" << " " << result7.to_string() << std::endl;

  std::string c7 = result7.to_string();
  ans_check(c7, 7);

  // 9回目
  cpp2::mcxi a8("m9i");
  cpp2::mcxi b8("i");
  auto result8 = a8 + b8;
  std::cout << "mx" << " " << result8.to_string() << std::endl;

  std::string c8 = result8.to_string();
  ans_check(c8, 8);

  // 10回目
  cpp2::mcxi a9("9m8c7xi");
  cpp2::mcxi b9("c2x8i");
  auto result9 = a9 + b9;
  std::cout << "9m9c9x9i" << " " << result9.to_string() << std::endl;

  std::string c9 = result9.to_string();
  ans_check(c9, 9);

  //11回目(不正解かの確認)
  cpp2::mcxi a10("2x");
  cpp2::mcxi b10("x9i");
  auto result10 = a10 + b10;
  std::cout << "3x9i" << " " << result10.to_string() << std::endl;

  std::string c10 = result10.to_string();
  ans_check(c10, 0);

  return 0;
}