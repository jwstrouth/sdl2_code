#include "jwsRandomNumber.h"

jwsRandomNumber::jwsRandomNumber()
{
    SetSeed();
}

jwsRandomNumber::~jwsRandomNumber()
{
    //dtor
}

void jwsRandomNumber::SetSeed()
{
    unsigned int seed = arc4random();
    srand(seed);
}

void jwsRandomNumber::Generate()
{
    m_number = rand();
}

int jwsRandomNumber::RandNum(int range)
{
    Generate();
    return m_number%range;
}
