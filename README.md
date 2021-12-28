# COMP2140_A2Q2_Train_Cpp

## Purpose
Model a train with a linked list, where each node in the linked list will
represent one car on the train.

• Model the train with a **_Doubly-linked list_**, where each node has a reference (pointer) to
both the node ahead of it and the node behind it.

• Program should ask the user to enter the name of an input file.

• Program will process the input file, performing the requested operations as it goes.
The input file will consist of lines of commands, with a command possibly followed by
lines of data. See the input description below. Echo each command to the console,
perform the operation, and print a summary of the actions performed. Please see the
sample output below.

• Create at least four classes: a TrainCar class (which stores the information about
one train car), a Node class (which stores links to neighbouring nodes and one TrainCar
object), a Train class (the linked list class), and an application/main class (to process the
input file).

• The TrainCar class should store the type of cargo (a String), and the value of the cargo.

• The Train class constructor will create a train consisting of one car (an engine, where the
type of cargo is set to “engine” and the value is set to $0)