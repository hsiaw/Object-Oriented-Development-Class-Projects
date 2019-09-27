/* Wendy Hsia
 * CPSC 3200
 * February 7, 2018
 * P3
 * 
 * version 1.0
 * 
 * This file contains the class definition of skipGen.
 *      skipGen inherits from gen class. It retains public
 *      functionality such as setting the arithmetic sequence
 *      and inherits the protected data fields difference,
 *      first term, index, threshold, and active.
 *      
 *      A skipGen object is like a gen object except it cannot
 *          be reset more than k times and it skips 0, 1, or k values
 *          in the sequence when queried for output.
 *      
 *      CLASS INVARIANTS
 *      The skipGen object will deactivate after a certain number of queries but 
 *          can be reset to reactivate unless it has already been reactivated
 *          k times.
 *      There is no limit to the arithmetic sequence skipGen will generate.
 *      
 *      INTERFACE INVARIANTS
 *      The difference and first term can be changed to get a new 
 *      arithmetic sequence, and the k value can be set.    
 *      skipGen overrides the reset and query functions to implement 
 *          extended functionality.
 */

using System;
using System.Collections.Generic;
using System.Text;
using genClass;

namespace skipGenClass
{
    class skipGen: gen
    {
        const int DEFAULT_K = 3;
        const int DEFAULT_FIRST = 4;
        const int DEFAULT_DIFFERENCE = 2;

        private int k;
        private int numResets;
        private int skip;

        //The constructor for skipGen. Uses base class constructor then also initializes
        //  class specific data.
        public skipGen(int fT = DEFAULT_FIRST, int diff = DEFAULT_DIFFERENCE, int newK = DEFAULT_K) : base(fT, diff)
        {
            k = newK;
            numResets = 0;
        }

        //Sets k value
        public void setK(int newK)
        {
            k = newK;
        }

        //Overridden function that reactivates object if able to be reset
        //  POSTCONDITION: object may be permanently inactive
        public override void reset()
        {            
            if(numResets != k)
            {
                base.reset();                
                k = DEFAULT_K;
                numResets++;
            }
            else
            {
                return;
            }
        }

        //Overridden parent function to retrieve output.
        //  -skips 0, 1, or k values
        //  POSTCONDITION: object may be inactive
        public override int query()
        {
            int retVal;
            if (active)
            {
                int skipNum = getSkip();                
                retVal = (firstTerm + (index - 1) * difference);
                index += skipNum;
                skip++;
            }
            else
            {
                retVal = -1;
            }
            if (skip == threshold)
            {
                active = false;
                skip = 0;
            }
            return retVal;
        }

        //Private utility function to decide how many values
        //  to skip.
        private int getSkip()
        {
            int retVal = (numResets % 3);
            if(retVal == 2)
            {
                retVal = k;
            }
            return retVal;          
        }
    }
}
