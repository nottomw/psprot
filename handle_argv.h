/*!
	\file handle_argv.h
	\brief Functions used to parse psprot's argv.
*/

#ifndef __HANDLE_ARGV_H__
#define __HANDLE_ARGV_H__

/*!
	\brief Guess what, it prints help.
*/
void print_help( void );

/*!
	\brief Perform specified actions based on argv.
	\param argc Number of elems in argv.
	\param argv Command line arguments array.
	\param options Options array, used to return some data.
*/
void handle_argv( int argc, char **argv, void **options );

#endif
