#ifndef __bubbleSort_HPP__
#define __bubbleSort_HPP__

#include "container.hpp"
#include "sort.hpp"

class Container; 

class BubbleSort : public Sort {
    public:
        /* Constructors */
        BubbleSort(){}

        /* Pure Virtual Functions */
        virtual void sort(Container* container){
	   int i;
	   int j;
	   int  size = container->size();
	   
	   for(i = 0; i < size - 1; i++){
	      for(j = 0; j < size - i - 1; j++){
		if(container->at(j)->evaluate() > container->at(j+1)->evaluate()){
		   container->swap(j, j + 1);
		 }
	      }
	   }
	}
};

#endif //__SORT_HPP__
