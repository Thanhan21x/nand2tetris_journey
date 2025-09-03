VMTranslater

# Objective 

* Extend the basic VMTranslater -> full-scale, designed to handle multiple-file programs writen in the VM language.

* Assume -> VM src code -> error free

# Contract

* Complete the construction of a VM-to-hack translator conforming to VM Specification, and to the Standard VM Mapping on the Hack flatform

# Resources

* CPU emulator -> test the generated asm code

* VM emulater -> exec. the supplied test VM prog -> watch the process -> understand the actions that the VM translator must eventually realize in assembly.

# Testing and Implementation sta

* 2 stage: 
    - first: implement the branching commands
    - then: the function commands

## Testing the Handling of the VM Commands 'label', 'if', 'if-goto'

* BasicLoop: tests how the VM translator handles the label and if-goto commands

* FibonaciSeries: a more rigorous test

## Testing the Handling of the VM Cmd 'call', 'function', 'return':

* SimpleFunction: this test entails the handling of a single file consistings of a single function, no Sys.init test function is needed

* FibonacciElement: 2 files -> Main.vm, Sys.vm -> contains a single Sys.init function that call Main.fibonacci with n=4 and then enters an inf. loop

* StaticsTest: three files: Class1.vm and Class2.vm -> functions that set and get the values of several static variables; Sys.vm contains a single Sys.init function that calls these functions.

# Implementation Tips

- Start by figuring out -> asm code -> label, goto, if-goto
- Next, impl. the methods -> writeLabel, writeGoto, writeIf
- Test -> BasicLoop.vm and FibonacciSeries.vm 

* Bootstrapping code:

- for any translated VM program -> start running -> it must include startup code that forces the VM inplementation to start exec. the prog. on the host platform.
- for any VM code -> operate properly -> VM impl. -> store the base address of the stack and the virtual segments in the correct locations in the host RAM. 

- CodeWriter -> 2 stages 
    - 1st: no bootstrapping code
    - 2nd: write the bootstrapping code, as specified in the constructor's API. -> test -> FibonacciElement and StaticsTest.




