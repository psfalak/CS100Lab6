#include "selectionSort.hpp"
#include "container.hpp" 
#include "sort.hpp"

SelectionSort::SelectionSort(){}

        /* Pure Virtual Functions */
        void SelectionSort::sort(Container* container){
           int i;
           int j;
           int  size = container->size();
           int minIndex;
           for(i = 0; i < size - 1; i++){
              minIndex = i;
              for(j = i + 1; j < size; j++){
                if(container->at(j)->evaluate() < container->at(minIndex)->evaluate()){
                   minIndex = j;
                 }
		container->swap(minIndex, i);
              }
              //container->swap(minIndex, i);
          }
}
