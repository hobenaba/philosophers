# Introduction
This project is both fascinating and challenging, where we will be working with threads and learn how to handle them effectively. The core idea of this project is to create a simulation with multiple philosophers of your choice. These philosophers will exist in a simulated world where they eat, sleep, and think. but here's the twist: they can only eat when they have two forks, and the simulation starts all at once, with all philosophers in motion. and here come our job to manage and organize the simulation to ensure that each philosopher can only eat when they have both forks.
# let's start with the beginning
  ## .what is a thread?
  When we run a program, a process takes charge, and this process may utilize multiple cores, depending on the device.Each core handles a single instruction of code at a time. In the context of threads, think of one thread an assignement given to a core. The core processes and executes multiple lines of code instructions associated with that thread.
 ## the problem we would be facing ?
   Since multiple cores can access the same memory, a problem can arise when one thread attempts to change the content of a variable in that process while another thread is doing the same simultaneously (aka data race). This can cause the program to behave improperly.This is where the role of mutexes comes into hand. We got to use them correctly to prevent such conflicts; otherwise, they can work against us.
  ## what is a mutex
  Imagine two people and one room. When one person occupies the room, they lock the door behind them, indicating to the other person that the room is occupied. In this analogy, a mutex acts like a lock, serving as a means to control access to shared resources.
# Plan
  ## .initialization:
  I may have underestimated this aspect, but if you initialize it cleanly, you can build your program seamlessly.First and foremost, we need to parse our arguments, which should 
 exclusively consist of numbers, no characters allowed 👀.
  Next comes the initialization of the variables we will be using.However, while planning, it's crucial to remember the variables that are accessible to all philosophers(threads).For example, all of them have access to the forks, which means our forks must be represented as an array of mutexes, with each mutex representing a fork. Additionally, we must assign each thread its unique characteristics, such as its left fork and right fork...  
  ## .the tasks:
  <
    since I structured the tasks in a strict order eat, sleep,and then think,it made the project more manageable. My primary focus initially was to ensure that all philosophers could eat without any of them dying or any other problem would rise up within 800 ms (t_die) and that each philosopher had a 200 ms time limit to eat. Later in the project, I added the sleeping and thinking components.
  >
 ## .timestamps:
  




