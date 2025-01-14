# push_swap

## Overview
**push_swap** is a project that challenges you to sort a stack of integers using a limited set of operations, with the goal of achieving the task in the least number of moves possible. You’ll create an algorithm and use it to solve sorting problems of varying complexity.

This project strengthens your problem-solving skills, algorithm design, and understanding of data structures like stacks.

---

## Features
- Implements a set of sorting operations on two stacks (`a` and `b`).
- Supports handling edge cases such as duplicates and very large inputs.
- Provides efficient sorting solutions for varying stack sizes.

---

## Rules
The program must:
1. Take as input a list of integers (space-separated or as individual arguments).
2. Use two stacks (`a` and `b`).
3. Sort the integers in ascending order within stack `a`.
4. Use only the allowed operations:
   - `sa`, `sb`, `ss`: Swap the top two elements of a stack.
   - `pa`, `pb`: Push the top element of one stack to the other.
   - `ra`, `rb`, `rr`: Rotate a stack upwards.
   - `rra`, `rrb`, `rrr`: Rotate a stack downwards.

The program must output the sequence of operations required to sort the input.

---

## Installation
1. Clone the repository:
   ```bash
   git clone git@github.com:d2iv3r/push_swap.git
   cd push_swap
   ```
2. Build the program:
   ```bash
   make
   ```
   This will generate the push_swap executable.


## Usage

**Running the Program**

To sort a stack of integers, provide them as arguments:
   ```bash
   ./push_swap 4 67 3 87 23
   ```
   The program will output the sequence of operations required to sort the stack.

### Example
**Input:**
   ```bash
   ./push_swap 4 67 3 87 23
```
**Output:**
   ```bash
   pb
   ra
   ra
   pa
   ```
