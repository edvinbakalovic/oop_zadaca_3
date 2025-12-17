#include <iostream>
#include <vector>
#include <functional>
using namespace std;

typedef vector<function<bool(int)>> Funkcije;

void default_if_not_all(vector<int>& collection,Funkcije callbacks, int def=-1){
  for(auto& i:collection){
    for(const auto& callback:callbacks){
      if(!callback(i)){
        i=def;
        break;
      }
    }
  }
}

int main(){
  vector<int> collection{1,2,3,4,5};
  Funkcije vektor_funkcija{
  [](int a){return a%2!=0;},
  [](int a){return a>2;}
  };

  default_if_not_all(collection,vektor_funkcija);

  for(auto i:collection)
    cout<<i<< " ";

  cout<<endl;
return 0;
}
