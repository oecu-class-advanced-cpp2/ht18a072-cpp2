#include <iostream>
using namespace std;
#define CPP2_PRIME_UPPER_LIMIT 1000000 //�T������l�̏���l�B

/* --------------------------------------------------------------- */
/* is_prime
* 
* �^����ꂽ������ x �ɑ΂��đf�����ǂ������肷��
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
  //2����x-1�܂ł̐���x�Ŋ���邩�`�F�b�N����
  //�������ꂽ�瑦false��Ԃ�
  return true;
}
/* --------------------------------------------------------------- */
/*
* n
*
* �^����ꂽ������ a �� d �� n �ɑ΂��āA���̓�������Ɋ܂܂�� n �Ԗڂ�
* �f����Ԃ��B
*
* TODO: ���� nth_prime �֐�����������B�K�v�ł���Α��Ɋ֐���
* �t�@�C�����쐬����B
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
  // �ȉ��A���l�ɁA���o�͗�ʂ�ɂȂ邩�m�F����B
  
  return 0;
}