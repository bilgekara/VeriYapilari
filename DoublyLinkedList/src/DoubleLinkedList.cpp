#include "DoubleLinkedList.hpp"
#include "Node.hpp"

	Node* DoubleLinkedList::FindPrevByPosition(int index){ // konumuna gore bir oncesini buluyoruz
		// en basa eklenirken cagrilmadigi icin index 0 dan farkli bir degerse cagriliyor
		Node *prv = head;
		int i=1;
		// head den basladik, itr->next != NULL(bir oncesine yerlescez cunku
		// i != index esit olursa o index e geldik demektir
		for(Node *itr = head; itr->next != NULL && i != index; itr=itr->next,i++){
			prv = prv->next;
		}
		return prv;
	}
	
	DoubleLinkedList::DoubleLinkedList(){
		head = NULL ; // cunku ortada bir dugum yok
		size = 0; // hic bir veri yok
	}
	
	bool DoubleLinkedList::isEmpty()const{ 
		return size == 0;
	}
	
	int DoubleLinkedList::Count()const{
		return size;
	}
	
	void DoubleLinkedList::add(const int item){ // sona ekleme yapiyor
		insert(size,item);
	}
	
	Node* DoubleLinkedList::FindByHead(){ 
		Node *prv = head;
		return prv;
	}
	
	void DoubleLinkedList::insert(int index,const int item){
		if(index == 0){ // basa eklenecek
			head = new Node(item, head);  // yeni listenin basi -> liste basi yeni dugum olucak
			if(head->next != NULL){ // ilerisi var demek
				head->next->prev = head;
			}
		}
		else{ // araya veya sona
			Node *prv = FindPrevByPosition(index); //bir oncesine yerlestik
			prv->next = new Node(item, prv->next, prv); 
			if(prv->next->next != NULL){ 
				prv->next->next->prev = prv->next;
			}
		}
		size++;	
	}
		
	void DoubleLinkedList::removeAt(int index){ // eklemeye benzer bi oncekine yerlesmeniz lazim
			//if(index<0 || index >= size) throw hata silme yaptigi icin size a esit oluyor
			// ilk dugum mu siliniyor aradan veya sondan mi
			Node *del;
			if(index==0){ 
				head = head->next;
				if(head != NULL) head->prev=NULL;
			}
			else{ //aradan veya sondan silinme
			
				Node *prv = FindPrevByPosition(index);
				
				del = prv->next; // C yi gosteriyor (b nin nexti)
				prv->next = del->next; // artik D yi gosteriyor
				if(del->next!=NULL){
					del->next->prev = prv; 
				}
			}
			size--;
			delete del; // delin gosterdigi dugumu iade ediyoruz
		}
		
	const int DoubleLinkedList::karsilastir(int index)const{
		int i=0;
		// listeyi headden baslayip dolasiyor
		// eger istedigimiz index e gelirse indexin datasini donduruyor
		for(Node *itr=head; itr != NULL;itr=itr->next,i++){
			if(index==i) return itr->data;
		}
	}
	
	void DoubleLinkedList::inverse(){
			int i = 0;
			Node *temp ;
			Node *prev = NULL;
			
			Node *itr=head;
			/* listenin basindan baslaniyor
			* temp de bulundugumuz dugumun next i tutuluyor
			* bulundugumuz dugumun next i yerine previ yaziliyor
			* prev degiskenine suanki iterasyon yaziliyor bir dahaki while dongusunde kullanmak icin
			* bulundugumuz dugum artık bir sonraki dugum
			*/
			while(itr != NULL){
				temp = itr->next;
				itr->next = prev;
				prev = itr;
				itr = temp;
			}
			head = prev;
		}
		
	void DoubleLinkedList::guncelleme(Node *item){ // head i guncelliyor
		head=item;
	}
	
	void DoubleLinkedList::yerDegistir(Node *item, Node *item2, int index){ //detaylar raporda yazilmistir
		if(index==0){ //basa eklencek
			Node* temp=item->next;
			item->next=item2->next;
			item2->next->prev=item;
			item2->next=temp;
			temp->prev=item2;
			
			head = item2;
		}
		else{
			
			int i=1;
			while(i<index){ // hangi dugum degiscekse listeyi oraya kadar ilerletiyoruz
				i++;
				item=item->next;
				item2=item2->next;
			}
		
			if(item->next->next!=NULL){ //aradaki elemanlar değişecek
				Node *temp = item->next;
				Node *temp2 = item2->next->next;
				item->next->next->prev=item2->next;
				item2->next->next=item->next->next;
		
				item->next->next=temp2;
				temp2->prev=item->next->next;
		
				item->next=item2->next;
				item2->next->prev=item;
		
				item2->next=temp;
				temp->prev=item2;
			}
		
			else{ //sondaki elemanlar değişecek
		
				Node *temp = item2->next;
				item->next->prev=item2->next;
				item2->next=item->next;
				item->next=temp;
				item->next->prev=item;
			}
		}
	}

	ostream& operator<<(ostream& screen, DoubleLinkedList &rgt){
		//her uzerinde bulundugumuz dugumu yazicaz
		for(Node *itr=rgt.head; itr != NULL;itr=itr->next){
			screen<<itr->data;
		}
		screen<<endl;
		return screen;
	}
	
	void DoubleLinkedList::clear(){ // liste temizleniyor
		while(!isEmpty()){
			removeAt(0); //sirayla ilk dugumu veriyorum ve liste temizleniyor
		}
	}
	
	DoubleLinkedList::~DoubleLinkedList(){
		clear();
	}
