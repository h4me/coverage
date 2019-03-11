#include <iostream>
#include "extra.hpp"


struct Base {
// void* _vptr;

void *base_vptr;
Base() {
    
    for(int i=0;i<4;i++)
    {    
       std::cout << "Base: " <<  (void*)_vptr << "   " <<  (void*)&_vptr << "====>" <<  (void*)_vptr[i]  << std::endl;
    }
    base_vptr = _vptr;

       std::cout << "-------" << std::endl;
}
virtual ~Base() { std::cout << "~Base()" << std::endl; }
virtual void show() { std::cout << "Base::show()" << std::endl; }

};

struct Child : public Base {
      
       Child() {  
             for(int i=0;i<4;i++)
             {
                 std::cout << "Child: " <<  (void*)_vptr << "   " <<  (void*)&_vptr << "====>" <<  (void*)_vptr[i]  << std::endl;
             }
             std::cout << "-------" << std::endl;

        }
      ~Child() {  }
};


struct ChildNext : Child {

      ChildNext() {  
             for(int i=0;i<4;i++)
             {
                 std::cout << "ChildNext: " << (void*)_vptr << "   " <<  (void*)&_vptr << "====>" <<  (void*)_vptr[i]  << std::endl;
             }
             std::cout << "-------" << std::endl;

        }

        virtual void show()
        { 
       
                 typedef void(Base::*DestFunction)();
               
                 if( static_cast<Base*>(this)->_vptr == base_vptr ) {
                     std::cout << "Takie same" << std::endl;
                  }  else {
                      std::cout << "Nie sa " << (void*) static_cast<Base*>(this)->_vptr << "!="<<  (void*)base_vptr << std::endl;
                  }

                //  DestFunction s = &Base::~Bae;
                   // DestFunction s = reinterpret_cast<DestFunction*>( base_vptr[0] );

                   // (this->*s)();

              // if(   base_vptr[0] == &Child::~Child ) { } 

              std::cout << "dupa" << std::endl;
              typedef unsigned long long U64;
              U64 k =  ( ((U64*)base_vptr) [0]);  
              asm("call *%0" : : "r"(k));  

        }

};

int main(int argc, char **argv) {

  {
   //  Base b;
   //  b.show();

    //  Base *ptr = new Base();
    //  delete ptr;

  }


   ChildNext *c = new ChildNext();
   c->show();
   delete c;
  /* {
   ChildNext k;
   ChildNext& p = k;
   p.show();
   }
  */


  return 0;
}
