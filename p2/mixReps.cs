/* Wendy Hsia
 * CPSC 3200
 * January 25, 2018
 * P2
 * 
 * version 1.0
 * 
 * This file contains the mixReps class definition and all of its
 *      functions.
 *      
 *  mixReps is an object that holds two blurtReps objects. It will ping some
 *      mixture of the two objects depending on its two other data fields:
 *      mixCount and preference. 
 *      
 *      *CLASS INVARIANTS*
 *      -displays a HAS-A relationship: without the two blurtReps objects the 
 *          mixReps object is invalid. There is no way to initialize the 
 *          mixReps object without the blurtReps objects being initialized.
 *      -the mixReps object has complete ownership of the blurtReps objects.
 *      -the blurtReps objects aren't replaceable. 
 *      -once the blurtReps objects age out and deactivate the mixReps object
 *          is essentially aged out and deactivated
 *      -the cardinality of a mixReps object is fixed at 2
 *      
 *      -deep copying is not supported
 *      
 *      *INTERFACE INVARIANTS*
 *      -the mixCount and preference can be toggled with the togglePref and toggleCount
 *          functions
 *      -print function may not result in output if blurtReps objects have aged out      
 */

using System;
using blurtRepsClass;

namespace mixRepsClass
{
    class mixReps
    {
        private blurtReps xBlurt;
        private blurtReps zBlurt;
        private int mixCount;
        private bool prefOdd;

        //no argument constructor
        public mixReps()
        {
            xBlurt = new blurtReps();
            zBlurt = new blurtReps();

            mixCount = 2;
            prefOdd = true;
        }

        //constructor that takes two strings for the two blurtReps objects
        public mixReps(string one, string two)
        {
            xBlurt = new blurtReps(one);
            zBlurt = new blurtReps(two);

            mixCount = 2;
            prefOdd = true;
        }

        //toggles mixCount
        public void toggleCount()
        {
            if(mixCount == 1)
            {
                mixCount = 2;
            }
            else
            {
                mixCount = 1;
            }
        }

        //toggles prefOdd
        public void togglePref()
        {
            prefOdd = !prefOdd;
        }


        //Postcondition: pinging the blurtReps objects may result in them
        //  aging out and not producing output; this would result in the
        //  mixReps object not producing output and being useless
        public void print()
        {
            if(prefOdd)
            {
                if (mixCount == 1)
                {
                    xBlurt.ping();
                }
                else
                {
                    xBlurt.ping();
                    zBlurt.ping();
                }
            }
            else
            {
                if(mixCount == 1)
                {
                    zBlurt.ping();
                }
                else
                {
                    zBlurt.ping();
                    xBlurt.ping();
                }
            }
            Console.WriteLine();
        }
    }
}
