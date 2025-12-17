#include <iostream>
#include <list>
#include <functional>
using namespace std;

list<int> filter(const list<int>& collection,function<bool(int)> callback){
  list<int> filtrirana_lista;
  for(auto it=collection.begin();it!=collection.end();++it){
    if(callback(*it))
      filtrirana_lista.push_back(*it);
  }
  return filtrirana_lista;
}

int main(){
  list<int> lista{1, 9, 8, 4, 11, 0, 2, 6, 15, 3, 10};
  auto filter_lista=filter(lista,[](int n){return n%2==0;});

  for(auto it:filter_lista)
    cout<<it<<" ";

  cout<<endl;

return 0;
}
