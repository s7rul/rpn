/*
 * =====================================================================================
 *
 *       Filename:  stdinput.h
 *
 *    Description:  Header for sstdinputv.c
 *
 *       Compiler:  gcc
 *
 *         Author:  Erik Serrader 
 *
 * =====================================================================================
 */

struct INPUT{
	int c;
	char **v;
}

typedef INPUT;

//funktions in stdinput.c
void freeinputv(INPUT *standard);
INPUT *setstdinput();
