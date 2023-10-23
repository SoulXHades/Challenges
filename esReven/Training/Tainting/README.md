<img src='./images/eshard.png' style='width: 180px; float:right;'>

# Guided exercise: taint playground

---

* **Guided exercise: taint playground**
* Classification: __RESTRICTED__
* _CATEGORY_: Tutorial

---

<img src='./images/header.png' style='height: 200px; display: block; margin-left: auto; margin-right: auto;'>

## 1. Introduction

In this tutorial we will experiment with the tainting engine and understand how to use it effectively. We will be presented with multiple generic situations we might be faced with in out analyses where the taint can be leveraged to get an effective answer.

The aim is to build our mental model of what the tainting engine does, understanding what the tool is capable of, and to build reflexes in how to effectively use it.


## 2. Recording

First, we need to record the playground. In the `binary` directory you will find the `taint_playground` binary:
- Select the binary for your OS
- Using the project manager's GUI, do an automatic binary recording of this binary.

Also open the `taint_playground.c` source file for reference.


## 3. Simple backward taint

1. Locate `simple_case`'s call to `printf`, and point the GUI to this call transition. On Windows, its `value` parameter is in `rdx` at this point - second argument of the `printf` call:
   ```c
   printf("simple_case output: %d\n", value);
   ```
2. Taint this value backward:
    1. Open up the Taint Widget
    2. Click on "From", and select "Current Transition"
    3. Click on "To", and select "First Transition": this sets the "To" field to 0.
    4. In the "Tag0" field, type `rdx`
    5. Click on "Taint"
    6. Check "Symbol" at the bottom of the widget as well.

Look the first 5 to 10 results and take your time to interpret what you see:
1. Do you understand well what the "New" and "Lost" columns are for?
2. Can you track where the value is coming from?
3. Why are there so many results after `init`?

Go to the transition where the global variable is written in memory.


## 4. Memory history vs Taint

Open up the memory history on that global and look at the results:
1. How many results are there - do they highlight all actual uses?

This is a typical case where it's important to understand the difference between when to use the memory history or the tainting engine:
- If we are interested solely on the activity of that memory region, the memory history is the tool to use. Globals, singletons, code pages are examples where most activity will be centered on the memory location itself.
- If on the other hand we want to track where a certain content or value is used, regardless of if its stored in memory, if it is passed along, etc., then the Tainting engin is the tool of choice.

In our case, the memory history highlights that `main` gets the global, and that's it.


## 5. Forward taint

On the other hand, we would prefer to see where that value is actually used now, so instead we will taint this value forward:
1. Make sure the transition where the global variable is written in memory is selected
2. Select the transition right after this one, so there is no confusion if we want to taint the value prior or after the memory write
3. Click on "From", and select "Current Transition"
4. Click on "To", and select "Last Transition".
5. In the memory view pointing to our global, right-click on the global's content and select "Copy current address range"
6. Paste this in the "Tag0" field"
7. Click on Taint

As before, take some time to interpret the results:
- You should quickly find `simple_case`
- Can you find `complex_case_*` functions?
- See how we traverse the `memcpy` easily: successives copies are a not a problem at all.


## 6. Conclusion

In this tutorial we have learned how to start taints in the backward and forward direction. We've also covered the fundamental difference with the memory history.


## 7. To go further: filtering the results

There are many results in the above taint, and that hurts the analysis. Let's use the API to see better.
In the cell below, write code to:
1. Start the same taint as the above section. Use the <b class="jp-MEI-link"><i>/applications/reven/reven-documentation?link=api-cookbook/index.html</i>Cookbook</b> to see how to start a taint quickly.
2. First, print all results: transition number, instruction, and location (binary, symbol)
3. Then, based on the results you see, skip results based on their location: you probably want to skip anything from `ntdll.dll`, and also skip functions that start with a `_` character in `msvcrt.dll`.

Don't hesitate to ask for help.