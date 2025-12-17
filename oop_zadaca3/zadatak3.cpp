#include <iostream>
#include <functional>
#include <list>

using namespace std;
list<int> my_partition(list<int>::const_iterator pocetak, list<int>::const_iterator kraj, function<bool(int)> callback){
  list<int> rezultat;

  try{
    for(auto it=pocetak;it!=kraj;++it){
     if(callback(*it))
        rezultat.push_back(*it);
   }

    for(auto it=pocetak;it!=kraj;++it){
      if(!(callback(*it)))
       rezultat.push_back(*it);
   }
  }
  catch(...){
    list<int> original;
    for(auto it=pocetak;it!=kraj;++it)
      original.push_back(*it);

    return original;
  } 
   return rezultat;
}

int main(){
  list<int> nums{15,20,25,-10,-75,100,-255,430,200};
  auto result = my_partition(nums.begin(),nums.end(),[](int num){if(num>400) throw "doe"; return num > 0;});
  
  for(auto num : result)
    cout<<num << " ";

  cout<<endl;

  return 0;
}
