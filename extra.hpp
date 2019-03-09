
#include <iostream>
struct Temple {
         void next(int a); 
         void kupa(int k) {  std::cout << "To jest kupa" << std::endl;  }
};


namespace sec_namespace {

     struct B {

              int add(int a, int b); 

     };

}




namespace first_namespace {

     struct A {

              int multiple(int a, int b) {  return a*b;  }
              int next(int c) { return c+1; }

     };

}

