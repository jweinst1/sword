#ifndef SWORD_COMPILER_INFO_H
#define SWORD_COMPILER_INFO_H

/**
 * Header that gives info about availabilities in the C
 * distribution.
 */

#if defined(__STDC__)
#  if defined(__STDC_VERSION__)
#    if (__STDC_VERSION__ >= 199409L)
#        if (__STDC_VERSION__ >= 199901L)
#           if (__STDC_VERSION__ >= 201112L)
               // Define both here for c99 and later features.
#              define SWORD_CVERS_11
#              define SWORD_CVERS_99
#           else // !(__STDC_VERSION__ >= 201112L)
#              define SWORD_CVERS_99
#           endif // (__STDC_VERSION__ >= 201112L)
#        else // !(__STDC_VERSION__ >= 199901L)
#           define SWORD_CVERS_94
#        endif // (__STDC_VERSION__ >= 199901L)
#    else // (__STDC_VERSION__ >= 199409L)
#       define SWORD_CVERS_90
#    endif // !(__STDC_VERSION__ >= 199409L)
#  else // defined(__STDC_VERSION__)
#    define SWORD_CVERS_89
#  endif // !defined(__STDC_VERSION__)
#else // defined(__STDC__)
#  ifdef _WIN32
#     pragma message("__STDC__ is not defined, this is a non-standard C version.")
#  else
#     warn "__STDC__ is not defined, this is a non-standard C version."
#  endif
#endif

#include <limits.h>

#if  __STDC_VERSION__ >= 199901L
#    include <stdint.h>
#endif

#ifdef UINT_MAX
#  if UINT_MAX == 0xffffffff
#      define SWORD_INT_IS_32B
#  endif
#endif

#ifdef HAVE_STDBOOL
#  include <stdbool.h>
#else
#   define true 1
#   define false 0
#   define bool int
#endif

// Debugging tools
#include <stdio.h>
#ifdef __GNUC__
#  define  SWORD_DEBUG(msg) fprintf(stderr, \
                "SWORD-DEBUG: %s, line: %u, function: %s, file: %s\n", \
                msg, (unsigned)__LINE__, __FUNCTION__, __FILE__)
#else // __GNUC__
#  ifdef SWORD_CVERS_99
#      define  SWORD_DEBUG(msg) fprintf(stderr, \
                   "SWORD-DEBUG: %s, line: %u, function: %s, file: %s\n", \
                   msg, (unsigned)__LINE__, __func__, __FILE__)
#  else
#     define  SWORD_DEBUG(msg) fprintf(stderr, \
                   "SWORD-DEBUG: %s, line: %u, file: %s\n", \
                   msg, (unsigned)__LINE__, __FILE__)
#  endif
#endif // !__GNUC__

#include <stdlib.h>

// Advancedment of void*
#ifdef __GNUC__
#  define SWORD_ADV_PTR(ptr, off) (ptr + off)
#else // __GNUC__
#  define SWORD_ADV_PTR(ptr, off) ((char*)ptr + off)
#endif // !__GNUC__

#include <stdlib.h> 


#endif // SWORD_COMPILER_INFO_H