#include <list>
#include "sort.hpp"
#include "base.hpp"
#include "listContainer.hpp"
#include <iostream>
using namespace std;

/* Constructors */
ListContainer::ListContainer() : Container(nullptr) {}
ListContainer::ListContainer(Sort* function) : Container(function) {}

/* Pure Virtual Functions */
// push the top pointer of the tree into container
void ListContainer::add_element(Base* element){
	myList.push_back(element); 
}
           
// iterate through trees and output the expressions (use stringify())                          
void ListContainer::print(){
	for(auto val : myList){
		cout << val->stringify() << endl;
	}
}
                                         
// calls on the previously set sorting-algorithm. Checks if sort_function is not null, throw exception if otherwise                                                
void ListContainer::sort(){
	sort_function->sort(this);
}
        
                                                         
/*Essentially the only functions needed to sort*/
//switch tree locations
void ListContainer::swap(int i, int j){
	list<Base*>::iterator it = myList.begin(); 
	list<Base*>::iterator it2;

	if(i<j){
	
	   int difference = j - i;
 	   int iTwo = i; 

	   while(iTwo){
	     ++it; 
	     --iTwo; 
	   }	
	   
	   Base* temp = *it; 
	   it2 = it; 

	   while(difference){
	     ++it2; 
	     --difference; 
	   }
	    
           Base* temp2 = *it2;  
           myList.insert(it2, temp); 
	   myList.erase(it2);  
  	   myList.insert(it, temp2); 
	   myList.erase(it); 
	   
	}

	else{

       	   int difference = i - j;
           int iTwo = j;  

           while(iTwo){
             ++it; 
             --iTwo; 
           }    
               
           Base* temp = *it; 
           it2 = it; 

           while(difference){
             ++it2; 
             --difference; 
           }   
                
           Base* temp2 = *it2;  
           myList.insert(it2, temp); 
           myList.erase(it2);  
           myList.insert(it, temp2);
           myList.erase(it);
	}	
}
// get top ptr of tree at index i
Base* ListContainer::at(int i){
	list<Base*>::iterator it = myList.begin(); 

	while(i){
	  ++it;
   	  --i; 
	}

	return *it; 	
}
// return container size
int ListContainer::size(){
	list<Base*>::iterator it = myList.begin();
	list<Base*>::iterator itEnd = myList.end(); 
	int size = 0; 
	while(it != itEnd){
	     ++it; 
	     ++size;  
	}

	return size; 
}
