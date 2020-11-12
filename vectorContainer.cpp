#include <vector>
#include "sort.hpp"
#include "base.hpp"
#include "vectorContainer.hpp" 
#include <iostream>
using namespace std; 

       
 /* Constructors */
VectorContainer::VectorContainer() : Container(nullptr) {}
VectorContainer::VectorContainer(Sort* function) : Container(function) {} 

/* Non Virtual Functions */
//void VectorContainer::set_sort_function(Sort* sort_function){   // set the type of sorting algorithm
//	Container::sort_function = sort_function; //does "this" work in a concrete class?	
//}

/* Pure Virtual Functions */
// push the top pointer of the tree into container
void VectorContainer::add_element(Base* element){
	vect.push_back(element); 
}
        
// iterate through trees and output the expressions (use stringify())      
void VectorContainer::print(){
	for(auto var : vect)
	{
	   cout <<  var->stringify() << endl;   
	}
}
       
// calls on the previously set sorting-algorithm. Checks if sort_function is not null, throw exception if otherwise       
void VectorContainer::sort(){
	sort_function->sort(this); // not sure about passing this? 
}
                                                         
        
/* Essentially the only functions needed to sort */        
//switch tree locations
void VectorContainer::swap(int i, int j){
	Base* temp = vect.at(i); 
	vect.at(i) = vect.at(j); 
	vect.at(j) = temp; // where do we dealocate temp or does our destructor do that? 
}
        
// get top ptr of tree at index i
Base* VectorContainer::at(int i){
	return vect.at(i); 
}
        
// return container size
int VectorContainer::size(){
	return vect.size(); 
}
