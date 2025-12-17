#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

list<int> parni_neparni(list<int>::const_iterator pocetak, list<int>::const_iterator kraj){
  list<int> rezultat;
  for(auto it=pocetak;it!=kraj;++it){
    if(*it%2==0)
      rezultat.push_back(*it);
  }

  for(auto it=pocetak;it!=kraj;++it){
    if(*it%2!=0)
      rezultat.push_back(*it);
  }
  return rezultat;
}



int main(){
  list<int> lista={5,2,6,7,1,30};
  auto rezultat=parni_neparni(lista.begin(),lista.end());

  for(auto it:rezultat)
    cout<<it<< " ";

  cout<<endl;



  return 0;
}
