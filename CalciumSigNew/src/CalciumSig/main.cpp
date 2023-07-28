#include "probabilities.h"
#include "reactions.h"
#include "initials.h"
#include <iostream>
#include <cmath>

int main()
{
    initials inits{ };
    Reactions recs{ inits.ini, inits.number_of_rec, inits.number_of_var };
    std::cout << recs.calculate_sigma1(5) << '\n'; //
    return 0;
}