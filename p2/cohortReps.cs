/* Wendy Hsia
 * CPSC 3200
 * January 25, 2018
 * P2
 * 
 * version 1.0
 * 
 * This file contains the cohortReps class definition and all of its
 *      functions.
 *      
 *  cohortReps is an object that can hold any number of blurtReps objects.
 *      It has a stack structure and will loop through all blurtReps objects
 *      curently in the cohortReps object and ping them to concatenate all
 *      active blurtReps output.
 *      
 *      *CLASS INVARIANTS*
 *      -displays a HOLDS-A relationship: a cohortReps object is valid with
 *          or without blurtReps objects. It is just a container for the blurtReps
 *          objects and can also create output from all the contained blurtReps objects.
 *      -the cohortReps object has temporary ownership of the blurtReps objects; it can
 *          have new objects pushed into it and can release ownership of objects with pop.
 *      -the blurtReps objects are replaceable. 
 *      -once the blurtReps objects age out and deactivate they no longer output when pinged
 *          so they become trash in the cohortReps object.
 *      -the cardinality of a cohortReps object is boundless; resizes upon filling up
 *      
 *      -deep copying is not supported
 *      
 *      *INTERFACE INVARIANTS*
 *      -the cohortReps object has these functions: push, pop, clear, isEmpty, and print
 *      -the client has no responsibility when pushing because the object is boundless,
 *          but must check if the cohortReps object is empty before popping. 
 */

using System;
using blurtRepsClass;


namespace cohortRepsClass
{
    public class cohortReps
    {
        const int DEFAULT_CAPACITY = 5;

        private blurtReps[] array;
        private int count;
        private int capacity;

        //no argument constructor
        public cohortReps()
        {
            capacity = DEFAULT_CAPACITY;
            array = new blurtReps[capacity];
            count = 0;
        }

        //Postcondition: may result in cohortReps capacity doubling,
        //  cohortReps object becomes temporarily responsible
        //  for a newly initiated blurtReps object
        public void push(string word)
        {
            if(count == capacity)
            {
                resize();
            }
            blurtReps newBlurt = new blurtReps(word);
            array[count] = newBlurt;
            count++;
        }

        //PRECONDITION: cohortReps object must NOT be empty;
        //  client is responsible for using isEmpty before popping
        //  to avoids bounds errors.
        public void pop()
        {
            count--;
            array[count] = null;
        }

        //fully empties cohortReps object
        public void clear()
        {
            for(int i = (count-1); i >=0; i--)
            {
                array[i] = null;
            }
            count = 0;
        }

        //checks if cohortReps object is empty
        public bool isEmpty()
        {
            return (count == 0);
        }

        //produces output
        public void print()
        {
            for(int i = 0; i < count; i++)
            {
                array[i].ping();
            }
            Console.WriteLine();
        }
        
        //PRIVATE UTILITY FUNCTIONS

        //resizes cohortReps array so it is functionally boundless to the client
        private void resize()
        {
            blurtReps[] newArray = new blurtReps[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                newArray[i] = array[i];
                array[i] = null;
            }

            capacity *= 2;
            array = newArray;
        }
    }
}
