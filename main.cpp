#include <iostream>
#include "extra.hpp"


namespace first_namespace {

     struct A {

              int multiple(int a, int b) {  return a*b;  }
              int next(int c) { return c+1; }

     };

}


int main(int argc, char **argv) {



   first_namespace::A  a;

   a.multiple(3,4);


    sec_namespace::B b;
    b.add(3,4);

  return 0;
}
