#ifndef __SelectionSort_HPP__
#define __SelectionSort_HPP__

#include "container.hpp"
//#include "sort.hpp"
//class Container; 

class SelectionSort : public Sort {
    public:
        /* Constructors */
        SelectionSort();//{}

        /* Pure Virtual Functions */
        virtual void sort(Container* container);/*{
           int i;
           int j;
           int  size = container->size();
	   int minIndex;
           for(i = 0; i < size - 1; i++){
	      minIndex = i;
              for(j = i + 1; j < size; j++){
                if(container->at(j) < container->at(minIndex)){
                   minIndex = j;
                 }
              }
	      container->swap(minIndex, i);
           }

        }*/
};

#endif //__SORT_HPP__
//                                                             30,15         Bot

