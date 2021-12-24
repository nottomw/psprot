/*!
	\file signal_handlers.h
	\brief psprot signal handlers.
*/

#ifndef __SIGNAL_HANDLERS_H__
#define __SIGNAL_HANDLERS_H__

/*!
	\brief SIGINT, SIGQUIT and SIGTERM handler. Initializes psprot cleanup & exit.
*/
void set_superloop_exitflag( int sigid );

/*!
	\brief SIGUSR1 handler. Rereads config file, and reloads psprot config.
*/
void reload_conf( int sigid );

#endif
