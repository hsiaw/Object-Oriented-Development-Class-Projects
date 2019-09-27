/* Wendy Hsia
 * CPSC 3200
 * February 7, 2018
 * P3
 * 
 * version 1.0
 * 
 * This file contains the driver to test P3.
 *      It first generates a random collection of heterogeneous 
 *      gen objects all typed to a gen reference. Then it querys
 *      each object a set number of times to demonstrate how each 
 *      type of object responds to a query. If the object ages out
 *      it is reset unless it cannot be reset any more.
 * 
 */

using System;
using genClass;
using dubGenClass;
using skipGenClass;

namespace program
{
    class P3
    {
        //Function to generate gen objects
        static gen getGen(int which, int fT, int diff)
        {
            switch (which)
            {
                case 0:
                    return new gen(fT, diff);
                case 1:
                    return new dubGen(fT, diff);
                case 2:                    
                    return new skipGen(fT, diff);
                default:
                    Console.WriteLine("invalid entry");
                    return null;                
            }
        }

        //Function to test a gen object
        static void testGen(gen toTest, int numTest)
        {
            Console.Write("Testing ");
            Console.Write(toTest);
            Console.WriteLine(" object");
            int outPut;
            for(int i = 0; i < numTest; i++)
            {
                outPut = toTest.query();
                if(outPut == -1)
                {
                    toTest.reset();
                }
                Console.Write(outPut);
                Console.Write(" ");
            }
            Console.WriteLine();
            Console.WriteLine();
        }

        //Main 
        static void Main(string[] args)
        {
            const int NUMOBJS = 10;
            const int NUMTESTS = 50;

            Random r = new Random();

            gen[] array = new gen[NUMOBJS];

            Console.WriteLine("Generating random heterogeneous collection of gen objs");
            for(int i = 0; i < NUMOBJS; i++)
            {
                array[i] = getGen((r.Next() % 3), (r.Next() % 10), (r.Next() % 10));
            }

            Console.Write("Querying each obj ");
            Console.Write(NUMTESTS);
            Console.WriteLine(" times");
            for(int i = 0; i < NUMOBJS; i++)
            {
                testGen(array[i], NUMTESTS);
            }

            return;
        }
    }
}
