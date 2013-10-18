#include <iostream>
#include <vector>
#include <string>
using namespace std;


void multiply(const vector<int>& a, const vector<int>& b, vector<int>& result);

int main(void)
{
  int i;

  string s;
  vector<int> a, b;
  cout << "please input two big integers: \n";
  cin >> s;

  a.reserve(s.size());

  for (i = 0; i < s.size(); ++i)
  {
    a.push_back(s[i] - '0');
  }

  cin >> s;
  b.reserve(s.size());
  {
    b.push_back(s[i] - '0');
  }

  vector<int> c(a.size() + b.size() - 1, 0);

  multiply(a, b, c);

  for (i = 0; i < c.size(); ++i)  
  {
    cout << c[i];
  }
  cout <<endl;
  return 0;
}

void multiply(const vector<int>& a, const vector<int>& b, vector<int>& result)
{
  int i, j, k;
  int tmp;

  for (i = 0; i < a.size(); ++i) 
  {
    k = i;
    for (j = 0; j < b.size(); ++j)
    {
      result[k++] += a[i] * b[j];
    }
  }

  for (i = 0; i < result.size(); ++i)  
  {
    cout << result[i]<<endl;
  }
  for(k = 0;k<result.size()-1;k++)
  {
    if(result[k] > 9){
      result[k+1] += result[k]/10;
      result[k] = result[k]%10;
    }
  }
}
