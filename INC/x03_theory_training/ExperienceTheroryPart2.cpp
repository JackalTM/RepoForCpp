#include "ExperienceTheroryPart2.h"

void BaseClass::Print(void) {std::cout << "BASE CLASS!!" << std::endl;}
void Derived22::Print(void) {std::cout << "Derived11 CLASS!!" << std::endl;}
void Derived22::Print(void) {std::cout << "Derived22 CLASS!!" << std::endl;}

void CallDynamicCast(void)
{
    Derived11   myDerived11;
    Derived11*  pDerived11;
    BaseClass*  pBaseClass;

    pBaseClass = dynamic_cast<BaseClass*>(&myDerived11);

    pDerived11 = dynamic_cast<Derived11*>(pBaseClass);

    if(pBaseClass == nullptr)
        std::cout << "pBaseClass == NULL" << std::endl;
    else
        std::cout << "pBaseClass is valid" << std::endl;

    if(pDerived11 == nullptr)
        std::cout << "pDerived11 == NULL" << std::endl;
    else
        std::cout << "pDerived11 is valid" << std::endl;
}