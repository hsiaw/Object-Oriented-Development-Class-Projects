/* Wendy Hsia
 * CPSC 3200
 * January 25, 2018
 * P2
 * 
 * version 1.0
 * 
 * This file is the driver to demonstrate the capabilities of the mixReps and cohortReps
 *      class. It uses randomly generated strings to use in the classes to show their 
 *      functionality
 *  -it has a main function that creates and uses blurtReps objects
 *  -a secondary utility function creates random strings to be used in
 *   demonstrating the blurtReps ability to handle random input
 */

using System;
using cohortRepsClass;
using mixRepsClass;

namespace P2
{
    public class P2
    {
        static void Main(string[] args)
        {
            const int NUM_COHORT_TESTS = 15;
            const int NUM_MIX_TESTS = 5;

            Console.WriteLine("Demonstrating the use of cohortReps:");
            cohortReps testCohort = new cohortReps();
            
            for(int i = 0; i < NUM_COHORT_TESTS; i++)
            {
                testCohort.push(randStringGen());
                testCohort.print();
            }

            Console.WriteLine();
            Console.WriteLine("Demonstrating the use of mixReps:");
            mixReps[] testArray = new mixReps[NUM_MIX_TESTS];

            for(int i = 0; i < NUM_MIX_TESTS; i++)
            {
                testArray[i] = new mixReps(randStringGen(), randStringGen());
            }

            //Some objects will age out and not print anything
            for(int i = 0; i < NUM_MIX_TESTS; i++)
            {
                for(int j = 0; j < NUM_MIX_TESTS; j++)
                {
                    testArray[j].print();
                    if ((j % 2) == 0)
                    {
                        testArray[j].toggleCount();
                    }
                    else
                    {
                        testArray[j].togglePref();
                    }
                }
            }

            return;
        }

        //This function creates a random string of the same character repeated
        //      -for use to test mixReps and cohortReps objects
        //      -returns a randomly generated string 
        static string randStringGen()
        {
            Random rand = new Random();
            char randChar = (char)((rand.Next() % 26) + 97);

            int size = (rand.Next() % 5) + 1;
            char[] randString = new char[size];
            for (int i = 0; i < size; i++)
            {
                randString[i] = randChar;
            }

            return new string(randString);
        }
    }
}