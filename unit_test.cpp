#include "gtest/gtest.h"

#include "op_test.hpp"
#include "vectorContainer.hpp"
#include <iostream>

int main(int argc, char **argv) {
  VectorContainer* test = new VectorContainer();
  Op* mul = new Op(2);
  Op* op2 = new Op(4);
  Op* op3 = new Op(7);
  test->add_element(mul);
  test->add_element(op2);
  test->add_element(op3);
  test->print();
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
