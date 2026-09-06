/* Program to carry out a heuristic search in text input, looking for
   and scoring matches in each line against the strings provided on
   the commandline.

   Skeleton written by Alistair Moffat, ammoffat@unimelb.edu.au,
   August 2026, with the intention that it be modified by students
   to add functionality, as required by the assignment specification.

   Students: You need to have read all of Chapter 7 and before making
   a start on this activity.

   Student Authorship Declaration:

   (1) I certify that except for the code provided in the initial
   skeleton file the program contained in this submission is my
   own work, except where explicitly noted below in connection with
   the use of AI.  I understand that work that has been developed
   by another student, or by me in collaboration with other students,
   or by non-students as a result of request, solicitation, or
   payment, may not be submitted for assessment in this subject.

   (2) I also certify that I have not provided a copy of this work
   in either softcopy or hardcopy or any other form to any other
   student, and nor will I do so until after the marks are released.
   I understand that providing my work to other students, regardless
   of my intention or any undertakings made to me by that other
   student, is also Academic Misconduct.

   (3) I declare that I have used generative AI tools in connection
   with the following aspects of the assignment (please select the
   option that applies best in your case and delete the other three
   choices):

   -- I prompted an AI system with the full assignment specification
   and example input/output files, and requested a complete solution.
   I then reviewed what I was provided with, made further alterations
   to make sure it addressed the specification, including adding
   suitable comments and this Authorship Declaration.

   -- I developed the program structure for myself, and then used
   a sequence of prompts to an AI system to write parts of my design
   as individual functions (including, for example, via GitHub
   copilot), but without including the assignment specification in
   any of the prompts.

   -- I developed my own complete solution to the problem, and then
   used AI to help debug individual functions, find errors, and
   provide other guidance in regard to structure and so on.

   -- I made zero use of AI, and the program is wholly the result
   my own knowledge and development.

   (4) The AI system(s) that I used are:

   [Type a type a list of the AI systems that you used while doing
   this assignment, or "None"]

   (5) I understand that submitting for assessment work developed
   in collaboration with other people constitutes Academic Misconduct,
   and may be penalized by mark deductions, or by other penalties
   determined via the University of Melbourne Academic Honesty
   Policy, as described at https://academicintegrity.unimelb.edu.au.

   Signed by: [Enter your full name and student number here before submission]
   Dated:     [Enter the date that you "signed" the declaration]

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

/**********************************************************************/

// this constant controls whether or not extra output is generated,
// make sure is set to 0 for your final submission
#define DEBUG 1

#define MAX_LINES 999           // max number of input lines
#define MAX_CHARS  80           // max number of characters per line

#define TOP_SCORES  5           // number of top-scoring lines to keep
#define MAX_MATCH  10           // maximum match length permitted

// add in any further #defines that you want here

/**********************************************************************/

typedef char line_t[MAX_CHARS+1];

// add in any further typedefs that you want here

/**********************************************************************/

int  read_one_line(line_t line, int max);
void  print_stage(int stg);
void  tadaa(void);

// add in any further function prototypes that you want here

/**********************************************************************/

int
main(int argc, char *argv[]) {
	
	// you have to write the body of the main function, but don't
	// make it too long, it should control the traffic flow and use
	// functions to do the actual work

	line_t line;
	int len;
	int nlines=0;

	// this first loop is here to show you how to access the strings
	// provided on the commandline, and will only generate output
	// when DEBUG is non-zero
	if (DEBUG) {
		for (int argnum=1; argnum < argc; argnum++) {
			printf("argv[%d]: %s\n", argnum, argv[argnum]);
		}
		printf("\n");

	}

	// this is where your solution starts, reading the input lines
	// one by one; your task is to decide what processing must happen
	// on each line after it has been read, and then implement added
	// functionality to achieve that outcome, you can choose
	// whether to retain, modify, or replace this indicative loop,
	// but I'll give you a hint to think about functions and arrays!
	while ((len = read_one_line(line, MAX_CHARS)) != EOF) {

		// successfully read another line, now process it

		// this printf is also for debugging purposes and the
		// output it generates should NOT be showing when you
		// submit your final program
		if (DEBUG) {
			printf("%3d: %s\n", nlines, line);
		}
		nlines += 1;
	}

	// and at the end, a traditional comp10002 sign-off...
	tadaa();

	return 0;
}

/**********************************************************************/

// here are a couple of free gifts
//

void
print_stage(int stg) {
	printf("\n");
	printf("Stage %d\n", stg);
	printf("-------\n");
}

void
tadaa(void) {
	printf("\n");
	printf("tadaa!\n");
}

/**********************************************************************/

// function to read one line from stdin into character array, see Section
// 7.8 and 7.9 of the textbook to understand how this works
// returns either EOF or the length of the string placed into line[], up
// to a maximum of "max" characters

int
read_one_line(line_t line, int max) {

	int len=0, c;

	// read input characters one by one
	while ( (c = getchar()) != EOF) {

		if (c == '\n') {
			// newline marks end of line, stop here
			line[len] = '\0';
			return len;
		}

		// check to see if still safe to store character
		if (len < max) {
			// yes, still safe
			line[len] = c;
			len += 1;
		} else {
			// nope, have reached maximum, silently discard
		}

	}

	// if here, have reached EOF, but could still be a partial line
	if (len > 0) {
		// yes, there is, close it off and send it back
		line[len] = '\0';
		return len;
	} else {
		// nah, we really are at the end of the input
		return EOF;
	}

}

/**********************************************************************/

