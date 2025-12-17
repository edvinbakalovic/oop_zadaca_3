#include <iostream>
#include <list>

using namespace std;

struct Klijent{
  string ime;
  int prioritet; // veci prioritet=veci broj=ranije dolazi na red.
};

void printRed(const list<Klijent>& red){
  cout<<"[ ";
  for(const auto& e:red)
    cout<<"{"<<e.ime<<" p: "<<e.prioritet<<"} ";
  cout<<"]"<<endl;
}

int main(){
  string ime;
  int prioritet;
  list<Klijent> red;

  while(true){
    cout<<"Unesite ime: ";
    cin>>ime;

    if(ime=="stop")
      break;

    cout<<"Unesite prioritet: ";
    cin>>prioritet;

    Klijent novi{ime,prioritet};
    auto it=red.begin();
    while(it!=red.end() && it->prioritet>=prioritet)
      ++it;

    red.insert(it,novi);

    cout<<"Trenutni red: ";
    printRed(red);


  }
  return 0;
}

/*
 Napopisati program koji simulira red cekanja u banci, gdje svaki klijent ima:
 ime(string), prioritet(int,veci broj=veci prioritet), vrijeme dolaska(redoslijed unos).
 Koristiti listu za spremanje klijenata. Klijenti se dodaju u listu tako da:
 klijent sa vecum prioritetom ide ispred klijenata sa manjim, ako imaju isti prioritet
 onda ide iza svih postojecih s tim prioritetom(zadrzava se red dolaska)
 :Nakon svakog ubacivanja ispisati cijeli trenutni red.
 * */
