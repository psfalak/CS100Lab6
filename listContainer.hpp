#ifndef __LISTCONTAINER_HPP__
#define __LISTCONTAINER_HPP__


#include <list>
#include "sort.hpp"
#include "base.hpp"
using namespace std;


class Sort;
class Base;

class ListContainer : public Container{
    private:
        list<Base*> myList;

    public:
        /* Constructors */
        ListContainer();
        ListContainer(Sort* function);

        /* Pure Virtual Functions */ 
        // push the top pointer of the tree into container
        void add_element(Base* element);
        // iterate through trees and output the expressions (use stringify())
        void print();
        // calls on the previously set sorting-algorithm. Checks if sort_function is not null, throw exception if otherwise
        void sort();
                                                          
        /*Essentially the only functions needed to sort*/
        //switch tree locations
        void swap(int i, int j);
        // get top ptr of tree at index i
        Base* at(int i);
        // return container size
        int size();
};

#endif 
