#include <iostream>
#include "extra.hpp"


struct X {

    virtual ~X() { } 
};
/*
X::~X() {

}
*/
struct B : X {

    ~B() {  }
    
};



void usage1(int i);
int main(int argc, char **argv) {
   {
  //  B b;
   }
   //  X* xxxx= new X();
    // delete xxxx;
    B *kk = new B();
   //delete kk;

   First f;
  for(int i=0;i<5;++i)
     usage1(i);


  return 0;
}
