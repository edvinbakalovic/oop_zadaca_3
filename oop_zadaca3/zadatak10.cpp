#include <iostream>
#include <algorithm>
using namespace std;

template<typename IT1, typename IT2>
bool my_equal(IT1 od1, IT1 do1, IT2 od2){
  while(od1!=do1){
    if(*od1!=*od2)
      return false;

    ++od1;
    ++od2;
  }
  return true;
}

int main(){
  string rijec;

  while(cin>>rijec){
    string obrnuti=rijec;
    reverse(obrnuti.begin(),obrnuti.end());
    if(my_equal(rijec.begin(),rijec.end(),obrnuti.begin()))
      cout<<rijec<<": Palindrom"<<endl;
  }
  return 0;
}
