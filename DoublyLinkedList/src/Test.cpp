#include "Sayi.cpp"

int main(int argc, char* argv[]){ 
	
	ArrayList<string> *isimler = new ArrayList<string>(); //dosyadaki sayilarin # karakterine gore bolundugu dizi
	ArrayList<string> *listeTemp = new ArrayList<string>(); // sayilaarin 3 lu olarak gecici sekilde tutuldugu dizi
	
	DoubleLinkedList *sayi1 = new DoubleLinkedList();
	DoubleLinkedList *sayi2 = new DoubleLinkedList();

	ayrac(DosyaIslemleri(), isimler, '#');
	
	// diziyi uc uc ayirmak icin kullanılacak substr fonksiyonu icin baslangic ve bitis sayilari belirlendi
	int baslangic = 0; 
	int boyut=0;
	int count = 0;

	for (int i = 0; i < isimler->size() ; i++) {
		/* listede '#' karakteriyle ayrilmis ne kadar sayi varsa o kadar donucek
		* sirasiyla sayilar 3 er 3 er bolunup bir diziye atancak
		* 3 e bolunen sayılar  listeTemp e atanacak ve liste sayi pointerina listeyi ekliyecek
		* distaki for basa donucek listeTemp temizleencek ve yeni sayi icin ayni islemler uygulanacak
		*/
		listeTemp->clear();
		for(int k=0;isimler->elementAt(i)[k]!='\0';k++)
		{
			count++;
		}
		int kacboyutlu = count / 3;
		for(int j=0; j < kacboyutlu ; j++){
			listeTemp->add(isimler->elementAt(i).substr(baslangic,3));
			baslangic = baslangic + 3;
			if(i==0){ // ilk sayiysa sayi1 bagli listesine ekliyor
				int tmp=stoi(listeTemp->elementAt(j));
				sayi1->add(tmp);
			}
			if(i==1){
				int tmp=stoi(listeTemp->elementAt(j));
				sayi2->add(tmp);
			}
		}
		count = 0;
		baslangic = 0;
	}
	
	for(int i=0 ; i< sayi1->Count() ; i++){
		if(sayi1->karsilastir(i) > sayi2->karsilastir(i))
		{
			sayi1->inverse();
		}
		else if(sayi1->karsilastir(i) == sayi2->karsilastir(i))
		{
			sayi2->inverse();
		}
		else if(sayi1->karsilastir(i) < sayi2->karsilastir(i))
		{
			if(i==0){
				/* sayi1 in head i temp de tutuluyor
				* dugumler yer degistiriyor
				* sayi2 nin head i guncelleniyor
				*/
				Node *temp=sayi1->FindByHead();
				sayi1->yerDegistir(sayi1->FindByHead(), sayi2->FindByHead(),i);
				sayi2->guncelleme(temp);
			}
			else{
				sayi1->yerDegistir(sayi1->FindByHead(), sayi2->FindByHead(),i);
			}
		}
	}
	cout<<"Sayi 1 : "<<*sayi1<<endl;
	cout<<"Sayi 2 : "<<*sayi2;
	
	delete sayi1; // new le olusturulan yerler iade ediliyor
	delete sayi2;

	
	return 0;
}