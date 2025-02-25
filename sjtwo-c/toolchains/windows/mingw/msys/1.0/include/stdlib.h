/*
 * stdlib.h
 *
 * Definitions for common types, variables, and functions.
 */

#ifndef _STDLIB_H_
#ifdef __cplusplus
extern "C" {
#endif
#define _STDLIB_H_

#include "_ansi.h"

#define __need_size_t
#define __need_wchar_t
#include <stddef.h>

#include <sys/reent.h>

typedef struct 
{
  int quot; /* quotient */
  int rem; /* remainder */
} div_t;

typedef struct 
{
  long quot; /* quotient */
  long rem; /* remainder */
} ldiv_t;

#ifndef NULL
#define NULL 0
#endif

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

#define RAND_MAX __RAND_MAX

extern __IMPORT int __mb_cur_max;

#define MB_CUR_MAX __mb_cur_max

_VOID	_EXFUN(abort,(_VOID) _ATTRIBUTE ((noreturn)));
int	_EXFUN(abs,(int));
int	_EXFUN(atexit,(_VOID (*__func)(_VOID)));
double	_EXFUN(atof,(const char *__nptr));
#ifndef __STRICT_ANSI__
float	_EXFUN(atoff,(const char *__nptr));
#endif
int	_EXFUN(atoi,(const char *__nptr));
long	_EXFUN(atol,(const char *__nptr));
_PTR	_EXFUN(bsearch,(const _PTR __key,
		       const _PTR __base,
		       size_t __nmemb,
		       size_t __size,
		       int _EXPARM(_compar,(const _PTR, const _PTR))));
_PTR	_EXFUN(calloc,(size_t __nmemb, size_t __size));
div_t	_EXFUN(div,(int __numer, int __denom));
_VOID	_EXFUN(exit,(int __status) _ATTRIBUTE ((noreturn)));
_VOID	_EXFUN(free,(_PTR));
char *  _EXFUN(getenv,(const char *__string));
char *	_EXFUN(_getenv_r,(struct _reent *, const char *__string));
char *	_EXFUN(_findenv,(_CONST char *, int *));
char *	_EXFUN(_findenv_r,(struct _reent *, _CONST char *, int *));
long	_EXFUN(labs,(long));
ldiv_t	_EXFUN(ldiv,(long __numer, long __denom));
_PTR	_EXFUN(malloc,(size_t __size));
int	_EXFUN(mblen,(const char *, size_t));
int	_EXFUN(_mblen_r,(struct _reent *, const char *, size_t, int *));
int	_EXFUN(mbtowc,(wchar_t *, const char *, size_t));
int	_EXFUN(_mbtowc_r,(struct _reent *, wchar_t *, const char *, size_t, int *));
int	_EXFUN(wctomb,(char *, wchar_t));
int	_EXFUN(_wctomb_r,(struct _reent *, char *, wchar_t, int *));
size_t	_EXFUN(mbstowcs,(wchar_t *, const char *, size_t));
size_t	_EXFUN(_mbstowcs_r,(struct _reent *, wchar_t *, const char *, size_t, int *));
size_t	_EXFUN(wcstombs,(char *, const wchar_t *, size_t));
size_t	_EXFUN(_wcstombs_r,(struct _reent *, char *, const wchar_t *, size_t, int *));
#ifndef __STRICT_ANSI__
#ifndef _REENT_ONLY
int     _EXFUN(mkstemp,(char *));
char *  _EXFUN(mktemp,(char *));
#endif
#endif
_VOID	_EXFUN(qsort,(_PTR __base, size_t __nmemb, size_t __size, int(*_compar)(const _PTR, const _PTR)));
int	_EXFUN(rand,(_VOID));
_PTR	_EXFUN(realloc,(_PTR __r, size_t __size));
_VOID	_EXFUN(srand,(unsigned __seed));
double	_EXFUN(strtod,(const char *__n, char **_end_PTR));
double	_EXFUN(_strtod_r,(struct _reent *,const char *__n, char **_end_PTR));
#ifndef __STRICT_ANSI__
float	_EXFUN(strtodf,(const char *__n, char **_end_PTR));
#endif
long	_EXFUN(strtol,(const char *__n, char **_end_PTR, int __base));
long	_EXFUN(_strtol_r,(struct _reent *,const char *__n, char **_end_PTR, int __base));
unsigned long _EXFUN(strtoul,(const char *_n_PTR, char **_end_PTR, int __base));
unsigned long _EXFUN(_strtoul_r,(struct _reent *,const char *_n_PTR, char **_end_PTR, int __base));
int	_EXFUN(system,(const char *__string));

#ifndef __STRICT_ANSI__
int	_EXFUN(putenv,(const char *__string));
int	_EXFUN(_putenv_r,(struct _reent *, const char *__string));
int	_EXFUN(setenv,(const char *__string, const char *__value, int __overwrite));
int	_EXFUN(_setenv_r,(struct _reent *, const char *__string, const char *__value, int __overwrite));

char *	_EXFUN(gcvt,(double,int,char *));
char *	_EXFUN(gcvtf,(float,int,char *));
char *	_EXFUN(fcvt,(double,int,int *,int *));
char *	_EXFUN(fcvtf,(float,int,int *,int *));
char *	_EXFUN(ecvt,(double,int,int *,int *));
char *	_EXFUN(ecvtbuf,(double, int, int*, int*, char *));
char *	_EXFUN(fcvtbuf,(double, int, int*, int*, char *));
char *	_EXFUN(ecvtf,(float,int,int *,int *));
char *	_EXFUN(dtoa,(double, int, int, int *, int*, char**));
int	_EXFUN(rand_r,(unsigned *__seed));

double _EXFUN(drand48,(_VOID));
double _EXFUN(_drand48_r,(struct _reent *));
double _EXFUN(erand48,(unsigned short [3]));
double _EXFUN(_erand48_r,(struct _reent *, unsigned short [3]));
long   _EXFUN(jrand48,(unsigned short [3]));
long   _EXFUN(_jrand48_r,(struct _reent *, unsigned short [3]));
_VOID  _EXFUN(lcong48,(unsigned short [7]));
_VOID  _EXFUN(_lcong48_r,(struct _reent *, unsigned short [7]));
long   _EXFUN(lrand48,(_VOID));
long   _EXFUN(_lrand48_r,(struct _reent *));
long   _EXFUN(mrand48,(_VOID));
long   _EXFUN(_mrand48_r,(struct _reent *));
long   _EXFUN(nrand48,(unsigned short [3]));
long   _EXFUN(_nrand48_r,(struct _reent *, unsigned short [3]));
unsigned short *
       _EXFUN(seed48,(unsigned short [3]));
unsigned short *
       _EXFUN(_seed48_r,(struct _reent *, unsigned short [3]));
_VOID  _EXFUN(srand48,(long));
_VOID  _EXFUN(_srand48_r,(struct _reent *, long));

#if !defined (__CYGWIN__) && !defined (__MSYS__)
_VOID	_EXFUN(cfree,(_PTR));
#else
char *	_EXFUN(realpath,(const char *, char *));
void	_EXFUN(unsetenv,(const char *__string));
void	_EXFUN(_unsetenv_r,(struct _reent *, const char *__string));
int	_EXFUN(random,(_VOID));
long	_EXFUN(srandom,(unsigned __seed));
char *  _EXFUN(ptsname, (int));
int     _EXFUN(grantpt, (int));
int     _EXFUN(unlockpt,(int));
#endif

#endif /* ! __STRICT_ANSI__ */

char *	_EXFUN(_dtoa_r,(struct _reent *, double, int, int, int *, int*, char**));
_PTR	_EXFUN(_malloc_r,(struct _reent *, size_t));
_PTR	_EXFUN(_calloc_r,(struct _reent *, size_t, size_t));
_VOID	_EXFUN(_free_r,(struct _reent *, _PTR));
_PTR	_EXFUN(_realloc_r,(struct _reent *, _PTR, size_t));
_VOID	_EXFUN(_mstats_r,(struct _reent *, char *));
int	_EXFUN(_system_r,(struct _reent *, const char *));

_VOID	_EXFUN(__eprintf,(const char *, const char *, unsigned int, const char *));

#ifdef __cplusplus
}
#endif
#endif /* _STDLIB_H_ */
