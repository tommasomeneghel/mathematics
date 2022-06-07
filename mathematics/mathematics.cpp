
#include <iostream>

#include "Fraction.h"



int main(int argc, char *argv[])
{
    std::cout << "Hello World!\n";

    std::unique_ptr<tml::Fraction> fraction = std::make_unique <tml::Fraction>();

    std::cout << tml::Fraction::get_fraction_count() << std::endl;

}

