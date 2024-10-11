/**
 * @file unique_ptr.cpp
 * @author Brian Saldana
 * @brief This code will demonstrate the importance of unique pointers and how to work with them. -- note unique pointers got introduced during C++ 14, so to run you might have to do 'g++ -std=c++14 unique_ptr.cpp'
 * @version 1.0
 * @date 2024-10-10
 * @copyright Copyright (c) 2024
 */						\
#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::make_unique;

int main(){
  //Pre C++14 styles of initializating unique pointers
  unique_ptr<double> revenue_ptr_1 {new double {2345.98}};

  //Modern Style of initializing unique pointers -- this function prevents some subtle memory leaks
  unique_ptr<double> revenue_ptr_2 {make_unique<double>(100345.67)};

  //compact modern style of initializing unique pointers
  auto revenue_ptr_3 {make_unique<double>(48572.76)};

  cout << "Revenue 1: " << *revenue_ptr_1 << endl;
  cout << "Revenue 2: " << *revenue_ptr_2 << endl;
  cout << "Revenue 3: " << *revenue_ptr_3 << endl;
}
