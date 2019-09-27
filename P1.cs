/* Wendy Hsia
 * CPSC 3200
 * January 16, 2018
 * P1
 * 
 * This file is the driver to demonstrate the capabilities of the blurtReps class.
 *  -it has a main function that creates and uses blurtReps objects
 *  -a secondary utility function creates random strings to be used in
 *   demonstrating the blurtReps ability to handle random input
 */
using System;
using blurtRepsClass;

 class P1
 {
    static void Main(string[] args)
    {
       const int NUMTESTS = 5;

       blurtReps defaultIsNull = new blurtReps();
       blurtReps tooLong = new blurtReps("sidney crosby");
       blurtReps shortWord = new blurtReps("x");
       blurtReps myWord = new blurtReps("it");

       Console.WriteLine("Demonstrating basic utility of blurtReps:");

       for (int i = 0; i < NUMTESTS; i++)
       {
           defaultIsNull.ping();
           tooLong.ping();
           shortWord.ping();
           myWord.ping(); 
       }

       Console.WriteLine("Demonstrating capacity to handle random input:");
       int prePing;
       int postPing;

        //This will test the blurtReps objects by pinging them until they deactivate

       for (int i = 0; i <NUMTESTS; i++)
       {
            blurtReps testObj = new blurtReps(randStringGen());
            bool active = true;
            while(active)
            {
                prePing = testObj.query();
                testObj.ping();
                postPing = testObj.query();
                if(prePing == postPing)
                {
                    active = false;
                }
            }
       }
       return;
    }

    //This function creates a random string of the same character repeated
    //      -for use to test blurtReps objects
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

