#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP


#include <iostream>
using namespace std;

template <typename Object>
class ArrayList{
	private: 
		Object *items;
		int length;
		int capacity;
		
		void reserve(int newCapacity){
			Object *tmp = new Object[newCapacity];
			for(int i=0;i<length;i++){
				tmp[i] = items[i];
				delete [] items;
				items = tmp;
				capacity = newCapacity;
			}
		}
	public:
		ArrayList(){
			length=0;
			capacity=100;
			items =new Object[capacity];
		}
		int size()const{
			return length;
		}
		bool isEmpty()const{
			return size() == 0;
		}
		void add(const Object& item){ //sona ekleme
			insert(length,item);
		}
		void insert(int index, const Object& item){
			// if(index<0 || index >length) hata
			if(length == capacity) reserve(2*capacity);
			for(int i = length-1;i >= index;i--){
				items[i+1] =items[i];
			}
			items[index] = item;
			length++;
		}
		int indexOf(const Object& item){
			for(int i=0; i<length;i++){
				if(items[i] == item) return i;
			}
			throw "HATA";
		}
		const Object& first()const{
			if(isEmpty()) throw "HATA";
			return items[0];
		}
		const Object& last()const{
			if(isEmpty()) throw "HATA";
			return items[length-1];
		}
		void clear(){
			length = 0;
		}
		void remove(const Object& item){
			int index = indexOf(item);
			removeAt(index);
		}
		void removeAt(int index){
			// if(index < 0 || index >= length
			for(int i=index+1;i<length;i++){
				items[i-1]=items[i];
			}
			length--;
		}
		bool find(const Object& item){
			for(int i=0;i<length;i++){
				if(items[i]== item) return true;
			}
			return false;
		}
		const Object& elementAt(int index){ //index ini veriyosun elemanı döndürüyor
		// if(index<0 || index>=length) throw "HATA"
			return items[index];
		}
		friend ostream& operator<<(ostream& screen, ArrayList<Object>& right){
			screen<<endl;
			for(int i=0;i<right.length;i++){
				screen<<right.items[i]<<" ";
			}
			screen<<endl;
			return screen;
		}
		~ArrayList(){
			delete [] items;
		}
};
#endif