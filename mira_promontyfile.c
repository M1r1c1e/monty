#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>

/**
 * to_openfile - Open file.
 * @Fname: PROstring with the name of the file.
 */
void to_openfile(char *Fname)
{
	int chekfile;
	FILE *KF;

	if (Fname == NULL)
	{
		error_mes(2, Fname);
		return;
	}

	chekfile = access(Fname, R_OK);

	if (chekfile == -1)
	{
		error_mes(2, Fname);
		return;
	}

	KF = fopen(Fname, "r");

	if (!KF)
	{
		error_mes(2, Fname);
		return;
	}

	readprogfile(KF);
	fclose(KF);
}

/**
 * readprogfile - Read the content.
 * @KF: Pointer 2 a file descriptor
 */
void readprogfile(FILE *KF)
{
	int line_counter = 1, fomat_spercifer = 0;
	char *F_line = NULL;
	size_t Slen = 0;

	if (!KF)
	{
		error_mes(2, "file_name");
		return;
	}

	while (getline(&F_line, &Slen, KF) != -1)
	{
		fomat_spercifer = int_line
			(F_line, line_counter, fomat_spercifer);
		line_counter++;
	}

	free(F_line);
}

/**
 * int_line - Interpret each line by separating it one by one.
 * @PROstring: string on the line 2 be read.
 * @line_counter: Line number 4 the opcode.
 * @fomat_spercifer: fomart specifier is 0 for Stack 1 for Queue
 * Return: Returns 0 if the opcode is stack or 1 if Queue.
 */
int int_line(char *PROstring, int line_counter, int fomat_spercifer)
{
	const char *p_delim = "\n ";
	char *op_tok;
	char *comd;

	if (PROstring == NULL)
	{
		error_mes(4);
		return (fomat_spercifer);
	}

	op_tok = strtok(PROstring, p_delim);

	if (op_tok == NULL)
		return (fomat_spercifer);

	comd = strtok(NULL, p_delim);

	if (strcmp(op_tok, "queue") == 0)
		return (1);
	else if (strcmp(op_tok, "stack") == 0)
		return (0);

	progfunction(op_tok, comd, line_counter, fomat_spercifer);
	return (fomat_spercifer);
}

