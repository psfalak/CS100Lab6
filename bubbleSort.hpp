#ifndef __bubbleSort_HPP__
#define __bubbleSort_HPP__

#include "container.hpp"

class Container;

class BubbleSort : Sort {
    public:
        /* Constructors */
        Sort();

        /* Pure Virtual Functions */
        virtual void sort(Container* container){
	   int i;
	   int j;
	   int  size = container.size();
	   
	   for(i = 0; i < size - 1; i++){
	      for(j = 0; j < size - i - 1; j++){
		if(container.at(j) > container.at(j+1)){
		   swap(container.at(j), container.at(j + 1));
		 }
	      }
	   }
	}
};

#endif //__SORT_HPP__
