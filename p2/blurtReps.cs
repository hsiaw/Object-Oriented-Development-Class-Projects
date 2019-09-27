/* Wendy Hsia
 * CPSC 3200
 * January 16, 2018
 * P1
 * 
 * version 2.0
 * 
 * This file contains the blurtReps class definition and all of its
 *      functions.
 *      
 *  blurtReps is an object that holds a private string of <5 characters.
 *  It has an output state that is either plain, terse, or repeat, and a 
 *    repeat count that determines the number of times it is repeated.
 *  It can be pinged upon which it will output depending on the output state.
 *  It can be queried to determine how many times it has been pinged.
 *  After a certain number of pings the object will no longer output upon being pinged.
 *      -if a string larger than the limit is put into a blurtReps object, it is truncated
 *      -the initial output state depends on the string length and then changes each time
 *          it is pinged
 *      -repetition count increments each time the object outputs in repeat state
 */

using System;

namespace blurtRepsClass
{
    public class blurtReps
    {
        const int PLAIN = 0;
        const int REPEAT = 1;
        const int TERSE = 2;
        const int MAXPINGS = 4;
        const int MAXSTRINGLEN = 4;
        const int DEFAULTREPCOUNT = 2;

        //data fields
        private string word;
        private int repCount;
        private int outState;
        private int numPings;
        private bool active;

        //no argument constructor, sets string to 'null'
        public blurtReps()
        {
            word = "null";
            repCount = (MAXSTRINGLEN - word.Length + 1);
            outState = findOutState(word);
            numPings = 0;
            active = true;
        }

        //constructor that takes a string, truncates if over limit
        public blurtReps(string w)
        {
            if (w.Length < 5)
            {
                word = w;
            }
            else
            {
                word = truncWord(w);
            }
            repCount = (MAXSTRINGLEN - word.Length + 1);
            outState = findOutState(word);
            numPings = 0;
            active = true;
        }

        //This function returns the number of times the object has been pinged
        //  -does not change state
        public int query()
        {
            Console.Write("Item has been pinged ");
            Console.Write(numPings);
            Console.Write(" times.");
            Console.WriteLine();
            return numPings;
        }

        /* This function requests output from the blurtReps object
         *      -no output if object is inactive
         *      -output depends on outputState
         *      -if in repeat state, changes repeat count
         *      -number of pings increases if active
         *      -checks if object should deactivate
         *      -changes output state after output
         */
        public void ping()
        {
            if (active)
            {
                if (outState == PLAIN)
                {
                    Console.Write(word);
                }
                else if (outState == REPEAT)
                {
                    for (int i = 0; i < repCount; i++)
                    {
                        Console.Write(word);
                    }
                    repCount++;
                }
                else
                {
                    for (int i = 0; i < (word.Length + 1) / 2; i++)
                    {
                        Console.Write(word[i]);
                    }
                }

                numPings++;
                changeState();

                if (numPings == MAXPINGS)
                {
                    active = false;
                }
            }
        }
        

        //PRIVATE UTILITY METHODS

        //This method shortens a string to the limit
        private string truncWord(string w)
        {
            string newWord = w.Substring(0, MAXSTRINGLEN);
            return newWord;
        }

        //This method changes the state of the object
        private void changeState()
        {
            outState = ((outState + 1) % 3);
        }

        //This method determines the output state of the
        //  object based on the string length
        private int findOutState(string w)
        {
            if (w.Length < MAXSTRINGLEN / 2)
            {
                return REPEAT;
            }
            else if (w.Length == MAXSTRINGLEN / 2)
            {
                return PLAIN;
            }
            else
            {
                return TERSE;
            }
        }
    }
}
