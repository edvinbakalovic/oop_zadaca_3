#include <iostream>
#include <list>
#include <vector>
#include <functional>

using namespace std;

template<typename Container,typename Predicate>
Container my_filter(const Container& collection, Predicate callback){
  Container rezultat;
  for(const auto& e:collection){
    if(callback(e))
      rezultat.push_back(e);
  }
  return rezultat;
}

template<typename Container,typename Predicate>
Container my_map(const Container& collection, Predicate callback){
  Container rezultat;
  for(const auto& e:collection)
    rezultat.push_back(callback(e));
  
  return rezultat;
}

template<typename Container, typename Predicate,typename T>
T my_reduce(const Container& collection, Predicate callback,T acc){
  for(const auto& e: collection)
    acc=callback(e,acc);
  
  return acc;
}


int main(){
  vector<int> vektor = {1,2,3,4,5};
  list<int> lista = {2,4,6,8,10};
  list<double> lista2{5.2,1.5,10.0,12.6};
  list<int> listaReduce={1,2,3,1};
  vector<double> vectorReduce={4.5,2.1,7.2,8.0};


  auto filterVektora = my_filter<vector<int>,function<bool(int)>>(vektor,[](int x){return x%2==0;});
  auto filterListe = my_filter<list<double>,function<bool(int)>>(lista2,[](double x){return x>=6.2;});

  auto mapaVektora=my_map<vector<int>,function<int(int)>>(vektor,[](int x){return x*2;});
  auto mapaListe=my_map<list<int>,function<int(int)>>(lista,[](int x){return x*3;});

  for(const auto& e:filterListe)
    cout<<e<<" ";
  cout<<endl;


  for(const auto& e:mapaVektora)
    cout<<e<<" ";
  cout<<endl;

  
  for(const auto& e:mapaListe)
    cout<<e<<" ";
  cout<<endl;

  cout<<"Suma liste je: "<<my_reduce<list<int>,function<int(int,int)>>(listaReduce,[](int a, int b){return a+b;},0)<<endl;
  cout<<"Suma vektora je:" <<my_reduce<vector<double>,function<double(double,double)>>(vectorReduce,[](double a,double b){return a+b;},0.1)<<endl;
  return 0;
}
