/* @file jwsRandomNumber.h
 *
 * @brief random number class
 *
 * @author James Strouth
 * Contact: jamesstrouth@gmail.com
 *
 * Reference: https://man7.org/linux/man-pages/man3/srand.3.html

       The rand() function returns a pseudo-random integer in the range
       0 to RAND_MAX inclusive (i.e., the mathematical range
       [0, RAND_MAX]).

       The srand() function sets its argument as the seed for a new
       sequence of pseudo-random integers to be returned by rand().
       These sequences are repeatable by calling srand() with the same
       seed value.

       If no seed value is provided, the rand() function is
       automatically seeded with a value of 1.

       The function rand() is not reentrant, since it uses hidden state
       that is modified on each call.  This might just be the seed value
       to be used by the next call, or it might be something more
       elaborate.  In order to get reproducible behavior in a threaded
       application, this state must be made explicit; this can be done
       using the reentrant function rand_r().

       Like rand(), rand_r() returns a pseudo-random integer in the
       range [0, RAND_MAX].  The seedp argument is a pointer to an
       unsigned int that is used to store state between calls.  If
       rand_r() is called with the same initial value for the integer
       pointed to by seedp, and that value is not modified between
       calls, then the same pseudo-random sequence will result.

       The value pointed to by the seedp argument of rand_r() provides
       only a very small amount of state, so this function will be a
       weak pseudo-random generator.  Try drand48_r(3) instead.
*/

#ifndef JWSRANDOMNUMBER_H
#define JWSRANDOMNUMBER_H

#include <iostream>
using namespace std;

class jwsRandomNumber
{
    public:
        jwsRandomNumber();
        virtual ~jwsRandomNumber();

        int RandNum(int range);

    protected:

    private:
        void SetSeed();
        void Generate();

        int     m_number;
};

#endif // JWSRANDOMNUMBER_H
