# PolyRPC

### Purpose of Creation
The purpose of this library is to introduce an easier way to add RPCs to base classes by implementing two Object-Oriented concepts from the S.O.I.L.D Design principles. First is the Single-responsibility principle which states that a class should only have one reason to change and the second is the Liskov Substitution Principle which states that a class should be able to be referred to as it's base class without a change in functionality. Two very common things we see in DayZ scripting are the vanilla example of RPCs and CF's RPC Library.

Let's start with the former, DayZ Vanilla RPCs. In many of the classes in DayZ's base scripts (I.E PlayerBase, DayZGame, etc), we have functions that funnel RPC calls into their respective functions or logic based on an integer value which we pass into the many functions which allow us to send RPCs. The RPC receive functions which are typically are named, "OnRPC", and take in the player's identity, the target game object which the RPC was called to (this must be some sort of game object typically, an integer which dictates the RPC which is being called, and the ParamsReadContext which stores the data being sent over the network.

Inside of these functions, the Bohemia Interactive development team has decided to use a switch statement on the value of the integer; known as, rpc_type. The issue with using a switch statement, or even a bunch of if statements, is you create a dependency on the switch. If someone wishes to go write another RPC for the same class then they too must add another case, or if statement into their function to check whether, or not the rpc_type is the same as the one they expect.

The second example of RPCs is through CF's RPC library. This was the first attempt to making RPCs more simple to implement; however, as time went on we began to see how the framework was more overhead than expected. Some of the issues stem from manipulating the base game ScriptModule to call functions from the instance of the class which manages the RPC. The second issue is that as time went on you'd end up with a class that has 10+ functions that were all functions used for RPCs. Each one of these functions would end up needing to be changed, or tweaked as time progressed; leaving the user to look through hundreds, if not, thousands of lines of code searching for the issue at hand. This violates the Single Responsibility Principle and causes us to write unclear code.

By introducing multiple base classes, inheritance, and multiple Hashmaps we can eliminate the chance for long cluttered switch/if statements which check the rpc_type, bad time complexity, manipulation of the base game ScriptModule, and useless storage of class instances.

### Documentation
- Coming Soon™
