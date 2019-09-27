# Object-Oriented-Development-Class-Projects
The assignments I completed as part of my OO Dev class.

P1:
Design an encapsulated class for
blurtReps.
Each blurtReps object encapsulates a
private, undisclosed string (of < 5 characters) alongside a repetition count and an
output controller. An application programmer may ‘ping’ a
blurtReps
object to generate output. For example, an object with a string of ‘bee’ and a count of 3
would output: ‘bee’ if in state ‘plain’; ‘beebeebee’ if in state ‘repeat’; a truncated
string if ‘terse’. The application programmer may also query an
blurtReps object as
to how many times it had been pinged. A blurtReps
object is initially active but
transitions to inactive once its ping count exceeds a threshold.
Many details are missing (stability of repetition count, state transitions from
inactive, initial state(s)...)
You MUST make and DOCUMENT your design decisions!!
This assignment is an abstract realization of a data sink (store) that yields specific
information upon query but can age and become invalid. With the interface
described above, your design should encapsulate and control state as well as the
release of information.
Part II: Driver (External Perspective of Application Programmer)
Design a driver to demonstrate the program requirements.
Clearly specify the intent and structure of your driver
You should have collections of distinct objects, initialized appropriately, i.e.
random distribution of internal strings, counts, initial states, etc.
Your collection of distinct objects should be sufficiently tested
with random input, and seamless alteration of the state of some
objects.
Do not skimp on your driver’s design: Your run MUST demonstrate the
program requirements.

P2:
Design and implement two classes, each of which encapsulate distinct
blurtReps
objects.
The first type,
mixReps
, has 2
blurtReps
objects (call them x and z), a preference and a
mixCount and
Outputs as only ‘x’ when mixCount == 1 and preference is odd
Outputs as only ‘z’ when mixCount == 1 and preference is even
Outputs as ‘x’ followed by ‘z’ when mixCount ==2 and preference is odd
Outputs as ‘z’ followed by ‘x’ when mixCount ==2 and preference is even
The second type, cohortReps, trackes some number of
blurtReps at a given time.
Outputs the concatenation of all active blurtReps
objects upon demand Adds/Removes
blurtReps objects
Reuse your blurtReps
class from P1, with or without modification: the version number
should increase if you modify your reused code.
Clearly, many details are missing.

Make reasonable design decisions so that your classes satisfy the stated goal,
communicate assumptions and use, and yield clear and maintainable software.

Use ProgrammingByContract to specify pre and post conditions; interface,
implementation and class invariants.

Relationships should be noted in the appropriate invariants.
Part II: Driver
Design a driver to demonstrate the program requirements: clearly specify the intent and
structure of your driver. You should have collections of distinct objects, initialized
appropriately, that is, randomly but distinctly. Do not skimp on your driver’s design.
Use C#. Comments from previous assignment hold, including:
1) Several details in this assignment have been left unspecified.
CLEARLY DOCUMENT all design decision you make.
Design as consistently and cleanly as possible.
2) User interface is essential.
Anyone should be able to use and understand the purpose of your program.
DO NOT assume that the user has read this assignment specification.
Make your output readable but not exceedingly lengthy.
3) Run your program sufficiently to demonstrate its capabilities
Submit results displaying the output.

P3:
P3’s goal is to design C# “gen” classes with a common interface that varies output and state. 

 

Part I: Class design

You are to design a class hierarchy of gen­s, where each gen, if on, outputs an individual integer from its internalized arithmetic sequence* upon request.

An dubGen acts like a gen, except that it doubles every pth value from its sequence. Also, it can be reset to start retrieving values from the beginning of its sequence. 
A skipGen acts like a gen, except that it skips 0, 1 or k values from its sequence. Also, it cannot cycle through on/off states more than k times. 
 

Clearly, many details are missing.  Make reasonable design decisions so that your classes satisfy the stated goal(s), communicate assumptions and use, and yield clear and maintainable software. 

 

Use ProgrammingByContract to specify pre and post conditions; interface, implementation and class invariants.  Relationships should be noted in the appropriate invariants. 

 

Part II: Driver

Design a driver to demonstrate the program requirements. 

            Clearly specify the intent and structure of your driver

Driver should define, and appropriately test type functionality using, a heterogeneous array. 

Test data (objects) should be allocated via a construction routine and should provide a

random distribution of objects with arbitrary initial values (values should be reasonable)

meaningful base values for non-arbitrary initial values

P4:
P4’s goal is to design the C++ classes needed to support the notion of child classes inheriting from gen subtypes (from P3) and a blurtRep type (from P2).  

 

Part I: Class design

gen types are as defined in P3 (that is, a class hierarchy of gen types)
blurtRep type is as defined in P2
blurtGens is-a gen and is-a blurtRep. Hence, the functionality of both parent types should be supported. Your design should address any overlapping notions of state AND accommodate the existence of 3 different gen (sub)types – gen, dubGen and skipGen.
 

Clearly, many details are missing.     You must use multiple inheritance.

Make reasonable design decisions so that your classes satisfy the stated goals, communicate assumptions and use, and yield clear and maintainable software.

 

Use ProgrammingByContract to specify pre and post conditions; interface, implementation and class invariants. Relationships should be noted in the appropriate invariants.

 

Part II: Driver

Design a driver to demonstrate program requirements: Do not skimp on your driver’s design

            Clearly specify the intent and structure of your driver

You should have collections of distinct objects, initialized appropriately. Use of random number generator and/or file IO is appropriate.

P5:
Part I: Class design

Overloaded all appropriate operators for the classes from P1 and P2

blurtReps, mixReps, cohortReps

The goal is for the client to use these types as if they were built-in types. 

 

Comparison should be widely supported for all types.

 

Addition MUST be supported in some manner: you decide.

Consider, for example, if it is reasonable to:

add a blurtReps to a cohortReps? to a mixReps?

add a mixReps to a blurtReps? to a cohortReps?

            add two like objects?

=> then consider short-cut assignment, and ++, and…

Determine the ripple effect(s) of supporting addition

 

Clearly, many, many details are missing.  You must use operator overloading.

 

Make reasonable design decisions so that your classes satisfy the stated goals, communicate assumptions and use, and yield clear and maintainable software. 

 

Use ProgrammingByContract to specify:

pre and post conditions; interface, implementation and class invariants. 

Relationships should be noted in the appropriate invariants. 

 

You MUST reuse your blurt class from P1 and blurtReps, mixReps from P2. 

 

Part II: Driver -- Demonstrate program requirements

 

Clearly specify the intent and structure of your driver, use functional decomposition.

Use collections of distinct objects, initialized appropriately, (random distribution of initial, reasonable values ) to demonstrate the use of the overloaded operators.
