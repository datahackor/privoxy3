#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED
/*********************************************************************
 *
 * File        :  $Source: /cvsroot/ijbswa/current/acconfig.h,v $
 *
 * Purpose     :  This file should be the first thing included in every
 *                .c file.  (Before even system headers).  It contains
 *                #define statements for various features.  It was
 *                introduced because the compile command line started
 *                getting ludicrously long with feature defines.
 *
 * Copyright   :  Written by and Copyright (C) 2001-2014 the
 *                Privoxy team. http://www.privoxy.org/
 *
 *                Based on the Internet Junkbuster originally written
 *                by and Copyright (C) 1997 Anonymous Coders and
 *                Junkbusters Corporation.  http://www.junkbusters.com
 *
 *                This program is free software; you can redistribute it
 *                and/or modify it under the terms of the GNU General
 *                Public License as published by the Free Software
 *                Foundation; either version 2 of the License, or (at
 *                your option) any later version.
 *
 *                This program is distributed in the hope that it will
 *                be useful, but WITHOUT ANY WARRANTY; without even the
 *                implied warranty of MERCHANTABILITY or FITNESS FOR A
 *                PARTICULAR PURPOSE.  See the GNU General Public
 *                License for more details.
 *
 *                The GNU General Public License should be included with
 *                this file.  If not, you can view it at
 *                http://www.gnu.org/copyleft/gpl.html
 *                or write to the Free Software Foundation, Inc., 59
 *                Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 *********************************************************************/

//@TOP@

/*
 * Version number - Major (X._._)
 */
#undef VERSION_MAJOR
#define VERSION_MAJOR 3
/*
 * Version number - Minor (_.X._)
 */
#undef VERSION_MINOR
#define VERSION_MINOR 0
/*
 * Version number - Point (_._.X)
 */
#undef VERSION_POINT
#define VERSION_POINT 28
/*
 * Version number, as a string
 */
#undef VERSION
#define VERSION "3.0.28"
/*
 * Status of the code: "alpha", "beta" or "stable".
 */
#undef CODE_STATUS
#define CODE_STATUS "stable"
/*
 * Should pcre be statically built in instead of linkling with libpcre?
 * (This is determined by configure depending on the availiability of
 * libpcre and user preferences).
 * Don't bother to change this here! Use configure instead.
 */
#undef FEATURE_DYNAMIC_PCRE
#define FEATURE_DYNAMIC_PCRE
/*
 * Should pcrs be statically built in instead of linkling with libpcrs?
 * (This is determined by configure depending on the availiability of
 * libpcrs and user preferences).
 * Don't bother to change this here! Use configure instead.
 */
#undef STATIC_PCRS

//#define STATIC_PCRS
/*
 * Allows the use of an ACL to control access to the proxy by IP address.
 */
#undef FEATURE_ACL
#define FEATURE_ACL
/*
 * Allow Privoxy to use accf_http(9) if supported.
 */
#undef FEATURE_ACCEPT_FILTER
#define FEATURE_ACCEPT_FILTER
/*
 * Enables the web-based configuration (actionsfile) editor.  If you
 * have a shared proxy, you might want to turn this off.
 */
#undef FEATURE_CGI_EDIT_ACTIONS
#define FEATURE_CGI_EDIT_ACTIONS
/*
 * Locally redirect remote script-redirect URLs
 */
#undef FEATURE_FAST_REDIRECTS
#define FEATURE_FAST_REDIRECTS
/*
 * Bypass filtering for 1 page only
 */
#undef FEATURE_FORCE_LOAD
#define FEATURE_FORCE_LOAD
/*
 * Allow blocking using images as well as HTML.
 * If you do not define this then everything is blocked as HTML.
 */
#undef FEATURE_IMAGE_BLOCKING
#define FEATURE_IMAGE_BLOCKING
/*
 * Use PNG instead of GIF for built-in images
 */
#undef FEATURE_NO_GIFS

#define FEATURE_NO_GIFS

/*
 * Allow to shutdown Privoxy through the webinterface.
 */
#undef FEATURE_GRACEFUL_TERMINATION
#define FEATURE_GRACEFUL_TERMINATION

/*
 * Allow PCRE syntax in host patterns.
 */
#undef FEATURE_EXTENDED_HOST_PATTERNS

//#define FEATURE_EXTENDED_HOST_PATTERNS

/*
 * Allow filtering with scripts and programs.
 */
#undef FEATURE_EXTERNAL_FILTERS
#define FEATURE_EXTERNAL_FILTERS
/*
 * Keep connections alive if possible.
 */
#undef FEATURE_CONNECTION_KEEP_ALIVE

/*
 * Allow to share outgoing connections between incoming connections.
 */
#undef FEATURE_CONNECTION_SHARING
#define FEATURE_CONNECTION_SHARING

/*
 * Use POSIX threads instead of native threads.
 */
#undef FEATURE_PTHREAD

/*
 * Enables statistics function.
 */
#undef FEATURE_STATISTICS
#define FEATURE_STATISTICS

/*
 * Enable strptime() sanity checks.
 */
#undef FEATURE_STRPTIME_SANITY_CHECKS
#define FEATURE_STRPTIME_SANITY_CHECKS

/*
 * Allow Privoxy to be "disabled" so it is just a normal non-blocking
 * non-anonymizing proxy.  This is useful if you're trying to access a
 * blocked or broken site - just change the setting in the config file,
 * or use the handy "Disable" menu option in the Windows GUI.
 */
#undef FEATURE_TOGGLE
#define FEATURE_TOGGLE 1

/*
 * Allows the use of trust files.
 */
#undef FEATURE_TRUST
#define FEATURE_TRUST
/*
 * Defined on Solaris only.  Makes the system libraries thread safe.
 */
#undef _REENTRANT

/*
 * Defined on Solaris only.  Without this, many important functions are not
 * defined in the system headers.
 */
#undef __EXTENSIONS__

/*
 * Defined always.
 * FIXME: Don't know what it does or why we need it.
 * (presumably something to do with MultiThreading?)
 */
#undef __MT__

/* If the (nonstandard and thread-safe) function gethostbyname_r
 * is available, select which signature to use
 */
#undef HAVE_GETHOSTBYNAME_R_6_ARGS
#undef HAVE_GETHOSTBYNAME_R_5_ARGS
#undef HAVE_GETHOSTBYNAME_R_3_ARGS

/* If the (nonstandard and thread-safe) function gethostbyaddr_r
 * is available, select which signature to use
 */
#undef HAVE_GETHOSTBYADDR_R_8_ARGS
#undef HAVE_GETHOSTBYADDR_R_7_ARGS
#undef HAVE_GETHOSTBYADDR_R_5_ARGS

/* Defined if you have gmtime_r and localtime_r with a signature
 * of (struct time *, struct tm *)
 */
#undef HAVE_GMTIME_R
#undef HAVE_LOCALTIME_R

/* Define to 'int' if <sys/socket.h> doesn't have it.
 */
#undef socklen_t

/* Define if pcre.h must be included as <pcre/pcre.h>
 */
#undef PCRE_H_IN_SUBDIR

/* Define if pcreposix.h must be included as <pcre/pcreposix.h>
 */
#undef PCREPOSIX_H_IN_SUBDIR


#define FEATURE_CLIENT_TAGS
#define HAVE_CALLOC
#define HAVE_SNPRINTF
#define FEATURE_CONNECTION_KEEP_ALIVE
#define SIZEOF_LONG_LONG 8

#ifndef EBCDIC
#define EBCDIC 0
#endif
#undef const
#undef size_t
#define HAVE_STRERROR 1
#define HAVE_MEMMOVE  1
#define HAVE_BCOPY    0


#ifndef LINK_SIZE
#define LINK_SIZE   2
#endif

#ifndef POSIX_MALLOC_THRESHOLD
#define POSIX_MALLOC_THRESHOLD 10
#endif

#ifndef MATCH_LIMIT
#define MATCH_LIMIT 10000000
#endif

#ifndef MATCH_LIMIT_RECURSION
#define MATCH_LIMIT_RECURSION MATCH_LIMIT
#endif

#define NEWLINE			10

#define HAVE_SYS_STAT_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_WINDOWS_H 1
#define HAVE_STDINT_H 1                                                   
#define HAVE_INTTYPES_H 1   

#define HAVE_STRTOLL 1
#define HAVE__STRTOI64 1

#define PCRE_STATIC 1

#define SUPPORT_PCRE8 1
#define PARENS_NEST_LIMIT       250
#define HAVE_LONG_LONG 1
#define HAVE_UNSIGNED_LONG_LONG 1

#define PCREGREP_BUFSIZE        20480

#ifndef MAX_NAME_SIZE
#define MAX_NAME_SIZE 32
#endif

#ifndef MAX_NAME_COUNT
#define MAX_NAME_COUNT 10000
#endif

#ifndef MAX_DUPLENGTH
#define MAX_DUPLENGTH 30000
#endif


#define PUMODEBUG 1

//@BOTTOM@



#endif /* CONFIG_H_INCLUDED */
