/* Wendy Hsia
 * CPSC 3200
 * February 7, 2018
 * P3
 * 
 * version 1.0
 * 
 * This file contains the class definition of gen.
 *      A gen object has the definition of an arithmetic
 *      sequence and upon query outputs the next int in
 *      the sequence. It is the parent class to two children:
 *      dubGen and skipGen. It defines the public interface
 *      of a gen object that can reset and query, also change
 *      the sequence definition.
 *      
 *      CLASS INVARIANTS
 *      The gen object will deactivate after a certain number of
 *      queries but can be reactivated with reset.
 *      There is no limit to the arithmetic sequence gen will generate.
 *      
 *      INTERFACE INVARIANTS
 *      The difference and first term can be changed to get a new 
 *      arithmetic sequence, but there is no way to restart a gen obj
 *      to retrieve the beginning of the sequence.
 *      
 *      The functions query and reset are virtual for extension in
 *          descendant classes.
 */

using System;
using System.Collections.Generic;
using System.Text;

namespace genClass
{
    class gen
    {
        const int DEFAULT_FIRST = 4;
        const int DEFAULT_DIFFERENCE = 2;
        const int DEFAULT_THRESHOLD = 5;

        protected int firstTerm;
        protected int difference;
        protected int index;
        protected int threshold;
        protected bool active;

        //Constructor with default parameters
        public gen(int fT = DEFAULT_FIRST, int diff = DEFAULT_DIFFERENCE)
        {
            firstTerm = fT;
            difference = diff;
            index = 1;
            active = true;
            threshold = DEFAULT_THRESHOLD;
        }

        //Sets the difference of the arithmetic sequence
        public void setDiff(int nDiff)
        {
            difference = nDiff;
        }

        //Sets the first term of the arithmetic sequence
        public void setfT(int fT)
        {
            firstTerm = fT;
        }

        //Puts the obj in active state
        public virtual void reset()
        {
            active = true;            
        }

        //Gets output from obj
        //POSTCONDITION: object may be inactive
        public virtual int query()
        {
            if(index == threshold)
            {
                threshold += threshold;
                active = false;
            }
            if(active)
            {
                int nextInt = (firstTerm + (index - 1) * difference);
                index++;
                return nextInt;
            }
            else
            {
                return -1;
            }            
        }
    }
}
