#include <iostream>
#include <functional>
#include <list>

using namespace std;
list<int> my_partition(list<int>::const_iterator pocetak, list<int>::const_iterator kraj, function<bool(int)> callback){
  list<int> rezultat;

  for(auto it=pocetak;it!=kraj;++it){
    if(callback(*it))
      rezultat.push_back(*it);
  }

  for(auto it=pocetak;it!=kraj;++it){
    if(!(callback(*it)))
      rezultat.push_back(*it);
  }

  return rezultat;
}

int main(){
  list<int> nums{15,20,25,-10,-75,100,-255,430,200};
  auto result = my_partition(nums.begin(),nums.end(),[](int num){return std::abs(num)>99;});
  
  for(auto num : result)
    cout<<num << " ";

  cout<<endl;

  return 0;
}
