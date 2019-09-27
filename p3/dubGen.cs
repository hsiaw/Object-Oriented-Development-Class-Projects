/* Wendy Hsia
 * CPSC 3200
 * February 7, 2018
 * P3
 * 
 * version 1.0
 * 
 * This file contains the class definition of dubGen.
 *      dubGen inherits from gen class. It retains public
 *      functionality such as setting the arithmetic sequence
 *      and inherits the protected data fields difference,
 *      first term, index, threshold, and active.
 *      
 *      A dubGen object is like a gen object except it can be reset
 *          to start at the beginning of the sequence and it doubles
 *          every p'th value.
 *      
 *      CLASS INVARIANTS
 *      The dubGen object will deactivate after a certain number of queries but 
 *          can be reset to reactivate and it will start at the beginning of
 *          the sequence again.
 *      There is no limit to the arithmetic sequence dubGen will generate.
 *      
 *      INTERFACE INVARIANTS
 *      The difference and first term can be changed to get a new 
 *      arithmetic sequence, and the p value can be set.    
 *      dubGen overrides the reset and query functions to implement 
 *          extended functionality.
 */

using System;
using System.Collections.Generic;
using System.Text;
using genClass;

namespace dubGenClass
{
    class dubGen : gen
    {
        const int DEFAULT_P = 3;
        const int DEFAULT_FIRST = 4;
        const int DEFAULT_DIFFERENCE = 2;

        private int p;

        //The constructor for dubGen. Uses base class constructor then also initializes
        //  class specific data.
        public dubGen(int fT = DEFAULT_FIRST, int diff = DEFAULT_DIFFERENCE, int newP = DEFAULT_P) : base(fT, diff)
        {
            p = newP;
        }

        //Sets the p value
        public void setP(int newP)
        {
            p = newP;
        }

        //Overridden parent function to reset object.
        //  Restarts from the beginning of the sequence
        public override void reset()
        {
            base.reset();
            p = DEFAULT_P;
            index = 1;
        }

        //Overridden parent function to retrieve output.
        //  -doubles every p'th value
        //  POSTCONDITION: object may be inactive
        public override int query()
        {
            if(index == threshold)
            {
                active = false;
            }
            if(active)
            {
                int retVal;
                if ((index % p) == 0)
                {
                    retVal = (2 * (firstTerm + (index - 1) * difference));
                }
                else
                {
                    retVal = (firstTerm + (index - 1) * difference);
                }
                index++;
                return retVal;
            }
            else
            {
                return -1;
            }
        }
    }
}
