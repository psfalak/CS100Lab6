#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "op.hpp"
#include "gtest/gtest.h" 
#include "rand.hpp"
#include <stdlib.h>
#include <string> 
#include "mult.hpp" 
#include "div.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "container.hpp"
#include "vectorContainer.hpp"
#include "sort.hpp" 
#include "listContainer.hpp"
#include <iostream>  
#include "selectionSort.hpp"
#include "bubbleSort.hpp" 

TEST(SortTestSet, BubbleSortTest) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);

    container->set_sort_function(new BubbleSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 28);
}

TEST(SortTestSet, SelectionSortTest) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);

    container->set_sort_function(new SelectionSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 28);
}

TEST(SortTestSet, SelectionSortTestList) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    ListContainer* container = new ListContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);

    container->set_sort_function(new SelectionSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 28);
}

TEST(SortTestSet, BubbleSortTestList) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    ListContainer* container = new ListContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);

    container->set_sort_function(new BubbleSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 28);
}

TEST(OpTest, Container) {
    VectorContainer* test = new VectorContainer();
    Op* mul = new Op(2);
    Op* op2 = new Op(4); 
    Op* op3 = new Op(7); 
    test->add_element(mul);
    test->add_element(op2);
    test->add_element(op3); 
    EXPECT_EQ(2, test->at(0)->evaluate());
    EXPECT_EQ(4, test->at(1)->evaluate());
    test->swap(0,1); 
    EXPECT_EQ(4, test->at(0)->evaluate());
    EXPECT_EQ(2, test->at(1)->evaluate());
    EXPECT_EQ(3, test->size());
    //std::cout << test->print() << std::endl;      
}

TEST(OpTest, ContainerList) {
    ListContainer* test = new ListContainer();
    Op* mul = new Op(2);
    Op* op2 = new Op(4);
    Op* op3 = new Op(7);
    test->add_element(mul);
    test->add_element(op2);
    test->add_element(op3);
    EXPECT_EQ(2, test->at(0)->evaluate());
    EXPECT_EQ(4, test->at(1)->evaluate());
    test->swap(0,2);
    EXPECT_EQ(7, test->at(0)->evaluate());
    EXPECT_EQ(2, test->at(2)->evaluate());
    EXPECT_EQ(3, test->size());
    test->swap(2,0);
    EXPECT_EQ(2, test->at(0)->evaluate());
    EXPECT_EQ(7, test->at(2)->evaluate());
    EXPECT_EQ(3, test->size());
}

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ("8.000000", test->stringify());
    EXPECT_EQ(test->evaluate(), 8); 
}

TEST(OpTest, OpEvaluateNeg) {
    Op* test = new Op(-8);
    EXPECT_EQ("-8.000000", test->stringify());
    EXPECT_EQ(test->evaluate(), -8);
}

TEST(OpTest, OpEvaluateZero) {
    Op* test = new Op(0.0);
    EXPECT_EQ("0.000000", test->stringify());
    EXPECT_EQ(test->evaluate(), 0.0);
}

TEST(OpTest, EvalRand){
    Rand* test = new Rand();
    srand(0);  
    int val = rand() % 100;
    std::string str = std::to_string(val);
    str+= ".000000";
    EXPECT_EQ(str, test->stringify()); 
    EXPECT_EQ(test->evaluate(), val); 
}

TEST(OpTest, EvalMult){
    Op* one = new Op(1); 
    Op* two = new Op(2); 
    Mult* test = new Mult(one, two); 
    EXPECT_EQ(test->evaluate(), 2); 
    EXPECT_EQ("1.000000 * 2.000000", test->stringify());
}

TEST(OpTest, EvalMultNeg){
    Op* one = new Op(-5);
    Op* two = new Op(2);
    Mult* test = new Mult(one, two);
    EXPECT_EQ(test->evaluate(), -10);
    EXPECT_EQ("-5.000000 * 2.000000", test->stringify());
}

TEST(OpTest, EvalMultZero){
    Op* one = new Op(0);
    Op* two = new Op(2);
    Mult* test = new Mult(one, two);
    EXPECT_EQ(test->evaluate(), 0);
    EXPECT_EQ("0.000000 * 2.000000", test->stringify());
}

TEST(OpTest, EvalDivWhole){
    Op* one = new Op(4);
    Op* two = new Op(2);
    Div* test = new Div(one, two);
    EXPECT_EQ(test->evaluate(), 2);
    EXPECT_EQ("4.000000 / 2.000000", test->stringify());
}

TEST(OpTest, EvalDivNeg){
    Op* one = new Op(-4);
    Op* two = new Op(2);
    Div* test = new Div(one, two);
    EXPECT_EQ(test->evaluate(), -2);
    EXPECT_EQ("-4.000000 / 2.000000", test->stringify());
}

TEST(OpTest, EvalDivZero){
    Op* one = new Op(-4);
    Op* two = new Op(0);
    Div* test = new Div(one, two);
    EXPECT_EQ(test->evaluate(), 0);
    EXPECT_EQ("-4.000000 / 0.000000", test->stringify());
}

TEST(OpTest, EvalDivMult){
    Op* num1 = new Op(2); 
    Op* num2 = new Op(8); 
    Op* num3 = new Op(4); 
    Mult* two = new Mult(num1, num2);
    Div* test = new Div(two, num3);
    EXPECT_EQ(test->evaluate(), 4);
    EXPECT_EQ("2.000000 * 8.000000 / 4.000000", test->stringify());
}

TEST(OpTest, EvalDivMultNeg){
    Op* num1 = new Op(2);
    Op* num2 = new Op(-8);
    Op* num3 = new Op(4);
    Mult* two = new Mult(num1, num2);
    Div* test = new Div(two, num3);
    EXPECT_EQ(test->evaluate(), -4);
    EXPECT_EQ("2.000000 * -8.000000 / 4.000000", test->stringify());
}

TEST(addTest, simpleAddition) {
  Op* val1 = new Op(1);  
  Op* val2 = new Op(5);
  Add* test = new Add(val1, val2);
  EXPECT_EQ(test->evaluate(), 6);
  EXPECT_EQ(test->stringify(), "1.000000+5.000000");
}

TEST(addTest, OneZero) {
  Op* val1 = new Op(0);
  Op* val2 = new Op(3);
  Add* test = new Add(val1, val2);
  EXPECT_EQ(test->evaluate(), 3);
  EXPECT_EQ(test->stringify(), "0.000000+3.000000");
}

TEST(addTest, LargeNums) {
  Op* val1 = new Op(100);
  Op* val2 = new Op(300);
  Add* test = new Add(val1, val2);
  EXPECT_EQ(test->evaluate(), 400);
  EXPECT_EQ(test->stringify(), "100.000000+300.000000");
}

TEST(subTest, simpleSubtraction) {
  Op* val1 = new Op(5);
  Op* val2 = new Op(1);
  Sub* test = new Sub(val1, val2);
  EXPECT_EQ(test->evaluate(), 4);
  EXPECT_EQ(test->stringify(), "5.000000-1.000000");
}

TEST(subTest, negativeAnswer) {
  Op* val1 = new Op(1);
  Op* val2 = new Op(5);
  Sub* test = new Sub(val1, val2);
  EXPECT_EQ(test->evaluate(), -4);
  EXPECT_EQ(test->stringify(), "1.000000-5.000000");
}

TEST(subTest, largeNums) {
  Op* val1 = new Op(300);
  Op* val2 = new Op(299);
  Sub* test = new Sub(val1, val2);
  EXPECT_EQ(test->evaluate(), 1);
  EXPECT_EQ(test->stringify(), "300.000000-299.000000");
}

TEST(powTest, oneZero) {
  Op* val1 = new Op(5);
  Op* val2 = new Op(0);
  Pow* test = new Pow(val1, val2);
  EXPECT_EQ(test->evaluate(), 1);
  EXPECT_EQ(test->stringify(), "5.000000**0.000000");
}

TEST(powTest, simpleExponent) {
  Op* val1 = new Op(5);
  Op* val2 = new Op(2);
  Pow* test = new Pow(val1, val2);
  EXPECT_EQ(test->evaluate(), 25);
  EXPECT_EQ(test->stringify(), "5.000000**2.000000");
}

TEST(powTest, doubleZero) {
  Op* val1 = new Op(0);
  Op* val2 = new Op(1);
  Pow* test = new Pow(val1, val2);
  EXPECT_EQ(test->evaluate(), 0);
  EXPECT_EQ(test->stringify(), "0.000000**1.000000");
}

TEST(powTest, negativeNums) {
  Op* val1 = new Op(-5);
  Op* val2 = new Op(2);
  Pow* test = new Pow(val1, val2);
  EXPECT_EQ(test->evaluate(), 25);
  EXPECT_EQ(test->stringify(), "-5.000000**2.000000");
}

TEST(powTest, largeNums) {
  Op* val1 = new Op(10);
  Op* val2 = new Op(5);
  Pow* test = new Pow(val1, val2);
  EXPECT_EQ(test->evaluate(), 100000);
  EXPECT_EQ(test->stringify(), "10.000000**5.000000");
}

#endif //__OP_TEST_HPP__
