#include <iostream>
#include <list>
#include <functional>
using namespace std;

int reduce(const list<int>& collection,function<int(int,int)> callback, int acc){
  
  for(auto value:collection)
    acc=callback(value,acc);

  return acc;
}

int main(){
  list<int> lista={11,4,5,12,6,8,9};
  auto rezultat = reduce(lista,[](int a,int b){return a+b+1;},-12);

  cout<<"Output: "<<rezultat<<endl;
  return 0;
}
