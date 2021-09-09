#include "DoubleLinkedList.hpp"
#include "ArrayList.hpp"

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void ayrac(const string& yazi, ArrayList<string> *liste, char ayirici)
{
    size_t pozisyon = yazi.find(ayirici); 

    size_t pozBaslangic = 0; 

    while (pozisyon != string::npos)
    {
        liste->add(yazi.substr(pozBaslangic, pozisyon - pozBaslangic));
        pozBaslangic = pozisyon + 1; 
        pozisyon = yazi.find(ayirici, pozBaslangic); 
    }
    liste->add((yazi.substr(pozBaslangic, min(pozisyon, yazi.size()) - pozBaslangic + 1)));
}

string DosyaIslemleri(){
	ifstream dosyamiz;
    dosyamiz.open("./doc/Sayilar.txt"); 
    string yazininTamami;  
	char karakter;
	
	int i = 0;
	if ( dosyamiz.is_open() ){
		while ( dosyamiz.get(karakter) ){
			if(karakter == '0' & i == 3){
				// cout<<karakter;
				i = 0;
				karakter = '1';
				yazininTamami.push_back(karakter);
			}  
			else if(karakter == '0' & i == 0){
				i = 0;
				karakter = '1';
				yazininTamami.push_back(karakter);
			}
			else if(karakter == '#'){
				yazininTamami.push_back(karakter);
				i=-1;
			}
			else{
				yazininTamami.push_back(karakter);
				if( i==3 ) i = 0;
			}
			i++;
		}
		dosyamiz.close();
	}
  return yazininTamami;

 }
