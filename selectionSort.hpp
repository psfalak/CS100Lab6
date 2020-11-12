


















[pfala001@hammer lab-06---strategy-pattern-pfala001-akris023-lab6]$ clear




[pfala001@hammer lab-06---strategy-pattern-pfala001-akris023-lab6]$ vim selectionSort.hpp
[pfala001@hammer lab-06---strategy-pattern-pfala001-akris023-lab6]$ vim bubbleSort.hpp 




















#ifndef __SelectionSort_HPP__
#define __SelectionSort_HPP__

#include "container.hpp"

class SelectionSort : Sort {
    public:
        /* Constructors */
        Sort();

        /* Pure Virtual Functions */
        virtual void sort(Container* container){
           int i;
           int j;
           int  size = container.size();
	   int minIndex;
           for(i = 0; i < size - 1; i++){
	      minIndex = i;
              for(j = i + 1; j < size; j++){
                if(container.at(j) < container.at(minIndex)){
                   minIndex = j;
                 }
              }
	      swap(minIndex, container.at(i));
           }

        }
};

#endif //__SORT_HPP__
                                                             30,15         Bot

