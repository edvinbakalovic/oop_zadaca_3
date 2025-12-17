#include <iostream>
#include <functional>
#include <list>
using namespace std;

list<int> map(const list<int>& collection,function<int(int)> callback){
  list<int> mapirana_lista;
  for(auto it=collection.begin();it!=collection.end();++it)
    mapirana_lista.push_back(callback(*it));

  return mapirana_lista;
}

int main(){
  list<int> lista={7, 2, -4, 5, 0, 6, 3};
  auto mapirana_lista=map(lista,[](int n){return n*2+1;});

  for(auto i:mapirana_lista)
    cout<<i<<" ";

  cout<<endl;
  return 0;
}
