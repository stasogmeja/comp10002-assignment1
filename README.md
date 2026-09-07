# COMP10002 Assignment 1

Heuristic text search and scoring system implemented in C.

## Description

This program reads query terms from the command line and text lines
from standard input. Each line is assigned a score based on partial
matches against the query terms, and the highest-scoring lines are
reported.

## Files

- ass1.c          : main program
- ass1-skel.c     : original skeleton provided by the subject
- test1.txt       : sample test data
- test2.txt       : sample test data
- test3.txt       : sample test data

## Compilation

```bash
gcc -Wall -o ass1 ass1.c
```

## Example Usage

```bash
ass1 fully fun < test1.txt
```
