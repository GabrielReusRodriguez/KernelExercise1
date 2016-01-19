# KernelExercise1
Kernel Excercise 1

http://rikiji.it/2011/04/17/Linux-kernel-programming-exercises-1.html

Task

The first proposed task is to develop a kernel module aimed to check the ARP table to detect when something fishy is going on. Requisites:

  *  Solution has to be a kernel module, as it can be done without harming the kernel tree. ARP checking can be easily done in user space reading /proc/net/arp but that won’t help in undestanding how the linux kernel works.
  *  Run checks at regular intervals of time without any busy waiting.
  *  Checks should detect duplicated entries in the ARP table. That’s an acceptable approssimation to detect arp spoofing.
