# Thread Synchronization and Signal Handling in C with Shared Memory and Bash Script Control

This document provides instructions for compiling, running, and managing the Thread Example application, which demonstrates the use of multithreading, shared memory, and signal handling in a POSIX environment. The application includes a C program (threads) and a Bash control script (bash_script.sh).

### Prerequisites

Ensure you have the following installed:

    GCC compiler
    POSIX compatible environment (e.g., Linux)
    Bash shell

### Cloning the Repository

Start by cloning the repository to your local machine:

`git clone https://github.com/UncleWeeds/RISC-V-mentorship-coding-challenge`

`cd RISC-V-mentorship-coding-challenge`

### Compiling the Application

To compile the application and set necessary script permissions, run the following commands in the project directory:

`make`

`make permissions`

This commands compiles the threads C program and sets executable permissions on the bash_script.sh.

### Running the Application

You can run the compiled application directly:

`./threads`

### Using the Bash Script

To control the application execution with the provided script:

`./bash_script.sh <duration_in_seconds>`

For example, to run the application for 10 seconds:

`./bash_script.sh 10`

This script runs the application in the background and sends a SIGINT after the specified duration, allowing you to test the program's response to signal handling.


### Cleaning up

To clean up the compiled files, you can use:

`make clean`

This command removes the compiled application to ensure a clean start for the next build.

### Follow these instructions to set up and test the Thread Example application. This setup is intended to demonstrate advanced C programming techniques in a Linux environment.






























