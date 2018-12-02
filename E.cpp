# 1 "gl_main.c"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "gl_main.c"
# 34 "gl_main.c"
# 1 "z_zone.h" 1
# 52 "z_zone.h"
# 1 "/usr/include/stdio.h" 1 3 4
# 27 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 374 "/usr/include/features.h" 3 4
# 1 "/usr/include/sys/cdefs.h" 1 3 4
# 385 "/usr/include/sys/cdefs.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 386 "/usr/include/sys/cdefs.h" 2 3 4
# 375 "/usr/include/features.h" 2 3 4
# 398 "/usr/include/features.h" 3 4
# 1 "/usr/include/gnu/stubs.h" 1 3 4
# 10 "/usr/include/gnu/stubs.h" 3 4
# 1 "/usr/include/gnu/stubs-hard.h" 1 3 4
# 11 "/usr/include/gnu/stubs.h" 2 3 4
# 399 "/usr/include/features.h" 2 3 4
# 28 "/usr/include/stdio.h" 2 3 4





# 1 "/usr/lib/gcc/armv7hl-meego-linux-gnueabi/4.8.3/include/stddef.h" 1 3 4
# 212 "/usr/lib/gcc/armv7hl-meego-linux-gnueabi/4.8.3/include/stddef.h" 3 4
typedef unsigned int size_t;
# 34 "/usr/include/stdio.h" 2 3 4

# 1 "/usr/include/bits/types.h" 1 3 4
# 27 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 28 "/usr/include/bits/types.h" 2 3 4


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;




__extension__ typedef signed long long int __int64_t;
__extension__ typedef unsigned long long int __uint64_t;







__extension__ typedef long long int __quad_t;
__extension__ typedef unsigned long long int __u_quad_t;
# 121 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/typesizes.h" 1 3 4
# 122 "/usr/include/bits/types.h" 2 3 4


__extension__ typedef __u_quad_t __dev_t;
__extension__ typedef unsigned int __uid_t;
__extension__ typedef unsigned int __gid_t;
__extension__ typedef unsigned long int __ino_t;
__extension__ typedef __u_quad_t __ino64_t;
__extension__ typedef unsigned int __mode_t;
__extension__ typedef unsigned int __nlink_t;
__extension__ typedef long int __off_t;
__extension__ typedef __quad_t __off64_t;
__extension__ typedef int __pid_t;
__extension__ typedef struct { int __val[2]; } __fsid_t;
__extension__ typedef long int __clock_t;
__extension__ typedef unsigned long int __rlim_t;
__extension__ typedef __u_quad_t __rlim64_t;
__extension__ typedef unsigned int __id_t;
__extension__ typedef long int __time_t;
__extension__ typedef unsigned int __useconds_t;
__extension__ typedef long int __suseconds_t;

__extension__ typedef int __daddr_t;
__extension__ typedef int __key_t;


__extension__ typedef int __clockid_t;


__extension__ typedef void * __timer_t;


__extension__ typedef long int __blksize_t;




__extension__ typedef long int __blkcnt_t;
__extension__ typedef __quad_t __blkcnt64_t;


__extension__ typedef unsigned long int __fsblkcnt_t;
__extension__ typedef __u_quad_t __fsblkcnt64_t;


__extension__ typedef unsigned long int __fsfilcnt_t;
__extension__ typedef __u_quad_t __fsfilcnt64_t;


__extension__ typedef int __fsword_t;

__extension__ typedef int __ssize_t;


__extension__ typedef long int __syscall_slong_t;

__extension__ typedef unsigned long int __syscall_ulong_t;



typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


__extension__ typedef int __intptr_t;


__extension__ typedef unsigned int __socklen_t;
# 36 "/usr/include/stdio.h" 2 3 4
# 44 "/usr/include/stdio.h" 3 4
struct _IO_FILE;



typedef struct _IO_FILE FILE;





# 64 "/usr/include/stdio.h" 3 4
typedef struct _IO_FILE __FILE;
# 74 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/libio.h" 1 3 4
# 31 "/usr/include/libio.h" 3 4
# 1 "/usr/include/_G_config.h" 1 3 4
# 15 "/usr/include/_G_config.h" 3 4
# 1 "/usr/lib/gcc/armv7hl-meego-linux-gnueabi/4.8.3/include/stddef.h" 1 3 4
# 16 "/usr/include/_G_config.h" 2 3 4




# 1 "/usr/include/wchar.h" 1 3 4
# 82 "/usr/include/wchar.h" 3 4
typedef struct
{
  int __count;
  union
  {

    unsigned int __wch;



    char __wchb[4];
  } __value;
} __mbstate_t;
# 21 "/usr/include/_G_config.h" 2 3 4
typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
# 32 "/usr/include/libio.h" 2 3 4
# 49 "/usr/include/libio.h" 3 4
# 1 "/usr/lib/gcc/armv7hl-meego-linux-gnueabi/4.8.3/include/stdarg.h" 1 3 4
# 40 "/usr/lib/gcc/armv7hl-meego-linux-gnueabi/4.8.3/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 50 "/usr/include/libio.h" 2 3 4
# 144 "/usr/include/libio.h" 3 4
struct _IO_jump_t; struct _IO_FILE;
# 154 "/usr/include/libio.h" 3 4
typedef void _IO_lock_t;





struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;



  int _pos;
# 177 "/usr/include/libio.h" 3 4
};


enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
# 245 "/usr/include/libio.h" 3 4
struct _IO_FILE {
  int _flags;




  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;

  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;



  int _flags2;

  __off_t _old_offset;



  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];



  _IO_lock_t *_lock;
# 293 "/usr/include/libio.h" 3 4
  __off64_t _offset;
# 302 "/usr/include/libio.h" 3 4
  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;

  int _mode;

  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];

};


typedef struct _IO_FILE _IO_FILE;


struct _IO_FILE_plus;

extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
# 338 "/usr/include/libio.h" 3 4
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);







typedef __ssize_t __io_write_fn (void *__cookie, const char *__buf,
     size_t __n);







typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);


typedef int __io_close_fn (void *__cookie);
# 390 "/usr/include/libio.h" 3 4
extern int __underflow (_IO_FILE *);
extern int __uflow (_IO_FILE *);
extern int __overflow (_IO_FILE *, int);
# 434 "/usr/include/libio.h" 3 4
extern int _IO_getc (_IO_FILE *__fp);
extern int _IO_putc (int __c, _IO_FILE *__fp);
extern int _IO_feof (_IO_FILE *__fp) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_ferror (_IO_FILE *__fp) __attribute__ ((__nothrow__ , __leaf__));

extern int _IO_peekc_locked (_IO_FILE *__fp);





extern void _IO_flockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
extern void _IO_funlockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_ftrylockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
# 464 "/usr/include/libio.h" 3 4
extern int _IO_vfscanf (_IO_FILE * __restrict, const char * __restrict,
   __gnuc_va_list, int *__restrict);
extern int _IO_vfprintf (_IO_FILE *__restrict, const char *__restrict,
    __gnuc_va_list);
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t);
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t);

extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int);

extern void _IO_free_backup_area (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
# 75 "/usr/include/stdio.h" 2 3 4




typedef __gnuc_va_list va_list;
# 90 "/usr/include/stdio.h" 3 4
typedef __off_t off_t;
# 102 "/usr/include/stdio.h" 3 4
typedef __ssize_t ssize_t;







typedef _G_fpos_t fpos_t;




# 164 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/bits/stdio_lim.h" 1 3 4
# 165 "/usr/include/stdio.h" 2 3 4



extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;







extern int remove (const char *__filename) __attribute__ ((__nothrow__ , __leaf__));

extern int rename (const char *__old, const char *__new) __attribute__ ((__nothrow__ , __leaf__));




extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) __attribute__ ((__nothrow__ , __leaf__));








extern FILE *tmpfile (void) ;
# 209 "/usr/include/stdio.h" 3 4
extern char *tmpnam (char *__s) __attribute__ ((__nothrow__ , __leaf__)) ;





extern char *tmpnam_r (char *__s) __attribute__ ((__nothrow__ , __leaf__)) ;
# 227 "/usr/include/stdio.h" 3 4
extern char *tempnam (const char *__dir, const char *__pfx)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;








extern int fclose (FILE *__stream);




extern int fflush (FILE *__stream);

# 252 "/usr/include/stdio.h" 3 4
extern int fflush_unlocked (FILE *__stream);
# 266 "/usr/include/stdio.h" 3 4






extern FILE *fopen (const char *__restrict __filename,
      const char *__restrict __modes) ;




extern FILE *freopen (const char *__restrict __filename,
        const char *__restrict __modes,
        FILE *__restrict __stream) ;
# 295 "/usr/include/stdio.h" 3 4

# 306 "/usr/include/stdio.h" 3 4
extern FILE *fdopen (int __fd, const char *__modes) __attribute__ ((__nothrow__ , __leaf__)) ;
# 319 "/usr/include/stdio.h" 3 4
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  __attribute__ ((__nothrow__ , __leaf__)) ;




extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ , __leaf__)) ;






extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));



extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__ , __leaf__));





extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__ , __leaf__));


extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));








extern int fprintf (FILE *__restrict __stream,
      const char *__restrict __format, ...);




extern int printf (const char *__restrict __format, ...);

extern int sprintf (char *__restrict __s,
      const char *__restrict __format, ...) __attribute__ ((__nothrow__));





extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg);




extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf (char *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));





extern int snprintf (char *__restrict __s, size_t __maxlen,
       const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));

# 412 "/usr/include/stdio.h" 3 4
extern int vdprintf (int __fd, const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));








extern int fscanf (FILE *__restrict __stream,
     const char *__restrict __format, ...) ;




extern int scanf (const char *__restrict __format, ...) ;

extern int sscanf (const char *__restrict __s,
     const char *__restrict __format, ...) __attribute__ ((__nothrow__ , __leaf__));
# 443 "/usr/include/stdio.h" 3 4
extern int fscanf (FILE *__restrict __stream, const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf")

                               ;
extern int scanf (const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf")
                              ;
extern int sscanf (const char *__restrict __s, const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__ , __leaf__))

                      ;
# 463 "/usr/include/stdio.h" 3 4








extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;





extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;


extern int vsscanf (const char *__restrict __s,
      const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
# 494 "/usr/include/stdio.h" 3 4
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")



     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")

     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf") __attribute__ ((__nothrow__ , __leaf__))



     __attribute__ ((__format__ (__scanf__, 2, 0)));
# 522 "/usr/include/stdio.h" 3 4









extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);





extern int getchar (void);

# 550 "/usr/include/stdio.h" 3 4
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
# 561 "/usr/include/stdio.h" 3 4
extern int fgetc_unlocked (FILE *__stream);











extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);





extern int putchar (int __c);

# 594 "/usr/include/stdio.h" 3 4
extern int fputc_unlocked (int __c, FILE *__stream);







extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);






extern int getw (FILE *__stream);


extern int putw (int __w, FILE *__stream);








extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     ;
# 638 "/usr/include/stdio.h" 3 4
extern char *gets (char *__s) __attribute__ ((__deprecated__));


# 665 "/usr/include/stdio.h" 3 4
extern __ssize_t __getdelim (char **__restrict __lineptr,
          size_t *__restrict __n, int __delimiter,
          FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
        size_t *__restrict __n, int __delimiter,
        FILE *__restrict __stream) ;







extern __ssize_t getline (char **__restrict __lineptr,
       size_t *__restrict __n,
       FILE *__restrict __stream) ;








extern int fputs (const char *__restrict __s, FILE *__restrict __stream);





extern int puts (const char *__s);






extern int ungetc (int __c, FILE *__stream);






extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;




extern size_t fwrite (const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s);

# 737 "/usr/include/stdio.h" 3 4
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);








extern int fseek (FILE *__stream, long int __off, int __whence);




extern long int ftell (FILE *__stream) ;




extern void rewind (FILE *__stream);

# 773 "/usr/include/stdio.h" 3 4
extern int fseeko (FILE *__stream, __off_t __off, int __whence);




extern __off_t ftello (FILE *__stream) ;
# 792 "/usr/include/stdio.h" 3 4






extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);




extern int fsetpos (FILE *__stream, const fpos_t *__pos);
# 815 "/usr/include/stdio.h" 3 4

# 824 "/usr/include/stdio.h" 3 4


extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));

extern int feof (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;

extern int ferror (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;




extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;








extern void perror (const char *__s);






# 1 "/usr/include/bits/sys_errlist.h" 1 3 4
# 26 "/usr/include/bits/sys_errlist.h" 3 4
extern int sys_nerr;
extern const char *const sys_errlist[];
# 854 "/usr/include/stdio.h" 2 3 4




extern int fileno (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
# 873 "/usr/include/stdio.h" 3 4
extern FILE *popen (const char *__command, const char *__modes) ;





extern int pclose (FILE *__stream);





extern char *ctermid (char *__s) __attribute__ ((__nothrow__ , __leaf__));
# 913 "/usr/include/stdio.h" 3 4
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));



extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;


extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
# 943 "/usr/include/stdio.h" 3 4

# 53 "z_zone.h" 2
# 1 "/usr/include/stdlib.h" 1 3 4
# 32 "/usr/include/stdlib.h" 3 4
# 1 "/usr/lib/gcc/armv7hl-meego-linux-gnueabi/4.8.3/include/stddef.h" 1 3 4
# 324 "/usr/lib/gcc/armv7hl-meego-linux-gnueabi/4.8.3/include/stddef.h" 3 4
typedef unsigned int wchar_t;
# 33 "/usr/include/stdlib.h" 2 3 4








# 1 "/usr/include/bits/waitflags.h" 1 3 4
# 42 "/usr/include/stdlib.h" 2 3 4
# 1 "/usr/include/bits/waitstatus.h" 1 3 4
# 64 "/usr/include/bits/waitstatus.h" 3 4
# 1 "/usr/include/endian.h" 1 3 4
# 36 "/usr/include/endian.h" 3 4
# 1 "/usr/include/bits/endian.h" 1 3 4
# 37 "/usr/include/endian.h" 2 3 4
# 60 "/usr/include/endian.h" 3 4
# 1 "/usr/include/bits/byteswap.h" 1 3 4
# 34 "/usr/include/bits/byteswap.h" 3 4
# 1 "/usr/include/bits/byteswap-16.h" 1 3 4
# 35 "/usr/include/bits/byteswap.h" 2 3 4
# 43 "/usr/include/bits/byteswap.h" 3 4
static __inline unsigned int
__bswap_32 (unsigned int __bsx)
{
  return __builtin_bswap32 (__bsx);
}
# 74 "/usr/include/bits/byteswap.h" 3 4
static __inline __uint64_t
__bswap_64 (__uint64_t __bsx)
{
  return __builtin_bswap64 (__bsx);
}
# 61 "/usr/include/endian.h" 2 3 4
# 65 "/usr/include/bits/waitstatus.h" 2 3 4

union wait
  {
    int w_status;
    struct
      {

 unsigned int __w_termsig:7;
 unsigned int __w_coredump:1;
 unsigned int __w_retcode:8;
 unsigned int:16;







      } __wait_terminated;
    struct
      {

 unsigned int __w_stopval:8;
 unsigned int __w_stopsig:8;
 unsigned int:16;






      } __wait_stopped;
  };
# 43 "/usr/include/stdlib.h" 2 3 4
# 67 "/usr/include/stdlib.h" 3 4
typedef union
  {
    union wait *__uptr;
    int *__iptr;
  } __WAIT_STATUS __attribute__ ((__transparent_union__));
# 95 "/usr/include/stdlib.h" 3 4


typedef struct
  {
    int quot;
    int rem;
  } div_t;



typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;







__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;


# 139 "/usr/include/stdlib.h" 3 4
extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__ , __leaf__)) ;




extern double atof (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern int atoi (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern long int atol (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;





__extension__ extern long long int atoll (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;





extern double strtod (const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern float strtof (const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern long double strtold (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern long int strtol (const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern unsigned long int strtoul (const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));




__extension__
extern long long int strtoq (const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

__extension__
extern unsigned long long int strtouq (const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





__extension__
extern long long int strtoll (const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

__extension__
extern unsigned long long int strtoull (const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

# 305 "/usr/include/stdlib.h" 3 4
extern char *l64a (long int __n) __attribute__ ((__nothrow__ , __leaf__)) ;


extern long int a64l (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;




# 1 "/usr/include/sys/types.h" 1 3 4
# 27 "/usr/include/sys/types.h" 3 4






typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;




typedef __loff_t loff_t;



typedef __ino_t ino_t;
# 60 "/usr/include/sys/types.h" 3 4
typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;
# 98 "/usr/include/sys/types.h" 3 4
typedef __pid_t pid_t;





typedef __id_t id_t;
# 115 "/usr/include/sys/types.h" 3 4
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;
# 132 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/time.h" 1 3 4
# 57 "/usr/include/time.h" 3 4


typedef __clock_t clock_t;



# 73 "/usr/include/time.h" 3 4


typedef __time_t time_t;



# 91 "/usr/include/time.h" 3 4
typedef __clockid_t clockid_t;
# 103 "/usr/include/time.h" 3 4
typedef __timer_t timer_t;
# 133 "/usr/include/sys/types.h" 2 3 4
# 146 "/usr/include/sys/types.h" 3 4
# 1 "/usr/lib/gcc/armv7hl-meego-linux-gnueabi/4.8.3/include/stddef.h" 1 3 4
# 147 "/usr/include/sys/types.h" 2 3 4



typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
# 194 "/usr/include/sys/types.h" 3 4
typedef int int8_t __attribute__ ((__mode__ (__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef int int64_t __attribute__ ((__mode__ (__DI__)));


typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));

typedef int register_t __attribute__ ((__mode__ (__word__)));
# 219 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/sys/select.h" 1 3 4
# 30 "/usr/include/sys/select.h" 3 4
# 1 "/usr/include/bits/select.h" 1 3 4
# 31 "/usr/include/sys/select.h" 2 3 4


# 1 "/usr/include/bits/sigset.h" 1 3 4
# 22 "/usr/include/bits/sigset.h" 3 4
typedef int __sig_atomic_t;




typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;
# 34 "/usr/include/sys/select.h" 2 3 4



typedef __sigset_t sigset_t;





# 1 "/usr/include/time.h" 1 3 4
# 120 "/usr/include/time.h" 3 4
struct timespec
  {
    __time_t tv_sec;
    __syscall_slong_t tv_nsec;
  };
# 44 "/usr/include/sys/select.h" 2 3 4

# 1 "/usr/include/bits/time.h" 1 3 4
# 30 "/usr/include/bits/time.h" 3 4
struct timeval
  {
    __time_t tv_sec;
    __suseconds_t tv_usec;
  };
# 46 "/usr/include/sys/select.h" 2 3 4


typedef __suseconds_t suseconds_t;





typedef long int __fd_mask;
# 64 "/usr/include/sys/select.h" 3 4
typedef struct
  {






    __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];


  } fd_set;






typedef __fd_mask fd_mask;
# 96 "/usr/include/sys/select.h" 3 4

# 106 "/usr/include/sys/select.h" 3 4
extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
# 118 "/usr/include/sys/select.h" 3 4
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);
# 131 "/usr/include/sys/select.h" 3 4

# 220 "/usr/include/sys/types.h" 2 3 4


# 1 "/usr/include/sys/sysmacros.h" 1 3 4
# 24 "/usr/include/sys/sysmacros.h" 3 4


__extension__
extern unsigned int gnu_dev_major (unsigned long long int __dev)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__
extern unsigned int gnu_dev_minor (unsigned long long int __dev)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__
extern unsigned long long int gnu_dev_makedev (unsigned int __major,
            unsigned int __minor)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
# 58 "/usr/include/sys/sysmacros.h" 3 4

# 223 "/usr/include/sys/types.h" 2 3 4





typedef __blksize_t blksize_t;






typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 270 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/bits/pthreadtypes.h" 1 3 4
# 37 "/usr/include/bits/pthreadtypes.h" 3 4
typedef unsigned long int pthread_t;


union pthread_attr_t
{
  char __size[36];
  long int __align;
};

typedef union pthread_attr_t pthread_attr_t;




typedef struct __pthread_internal_slist
{
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;




typedef union
{
  struct __pthread_mutex_s
  {
    int __lock;
    unsigned int __count;
    int __owner;


    int __kind;
    unsigned int __nusers;
    __extension__ union
    {
      int __spins;
      __pthread_slist_t __list;
    };
  } __data;
  char __size[24];
  long int __align;
} pthread_mutex_t;

typedef union
{
  char __size[4];
  long int __align;
} pthread_mutexattr_t;




typedef union
{
  struct
  {
    int __lock;
    unsigned int __futex;
    __extension__ unsigned long long int __total_seq;
    __extension__ unsigned long long int __wakeup_seq;
    __extension__ unsigned long long int __woken_seq;
    void *__mutex;
    unsigned int __nwaiters;
    unsigned int __broadcast_seq;
  } __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;

typedef union
{
  char __size[4];
  long int __align;
} pthread_condattr_t;



typedef unsigned int pthread_key_t;



typedef int pthread_once_t;





typedef union
{
  struct
  {
    int __lock;
    unsigned int __nr_readers;
    unsigned int __readers_wakeup;
    unsigned int __writer_wakeup;
    unsigned int __nr_readers_queued;
    unsigned int __nr_writers_queued;
# 144 "/usr/include/bits/pthreadtypes.h" 3 4
    unsigned char __flags;
    unsigned char __shared;
    unsigned char __pad1;
    unsigned char __pad2;

    int __writer;
  } __data;
  char __size[32];
  long int __align;
} pthread_rwlock_t;

typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;





typedef volatile int pthread_spinlock_t;




typedef union
{
  char __size[20];
  long int __align;
} pthread_barrier_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;
# 271 "/usr/include/sys/types.h" 2 3 4



# 315 "/usr/include/stdlib.h" 2 3 4






extern long int random (void) __attribute__ ((__nothrow__ , __leaf__));


extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));





extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));



extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };

extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));

extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));






extern int rand (void) __attribute__ ((__nothrow__ , __leaf__));

extern void srand (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));




extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__ , __leaf__));







extern double drand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern long int lrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern long int mrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern void srand48 (long int __seedval) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;

  };


extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));









extern void *malloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;

extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;










extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));

extern void free (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));




extern void cfree (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));



# 1 "/usr/include/alloca.h" 1 3 4
# 24 "/usr/include/alloca.h" 3 4
# 1 "/usr/lib/gcc/armv7hl-meego-linux-gnueabi/4.8.3/include/stddef.h" 1 3 4
# 25 "/usr/include/alloca.h" 2 3 4







extern void *alloca (size_t __size) __attribute__ ((__nothrow__ , __leaf__));






# 493 "/usr/include/stdlib.h" 2 3 4





extern void *valloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;




extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 513 "/usr/include/stdlib.h" 3 4


extern void abort (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));



extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 530 "/usr/include/stdlib.h" 3 4





extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));






extern void exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));













extern void _Exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));






extern char *getenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;

# 578 "/usr/include/stdlib.h" 3 4
extern int putenv (char *__string) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern int setenv (const char *__name, const char *__value, int __replace)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));


extern int unsetenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));






extern int clearenv (void) __attribute__ ((__nothrow__ , __leaf__));
# 606 "/usr/include/stdlib.h" 3 4
extern char *mktemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 620 "/usr/include/stdlib.h" 3 4
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
# 642 "/usr/include/stdlib.h" 3 4
extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) ;
# 663 "/usr/include/stdlib.h" 3 4
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 712 "/usr/include/stdlib.h" 3 4





extern int system (const char *__command) ;

# 734 "/usr/include/stdlib.h" 3 4
extern char *realpath (const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__ , __leaf__)) ;






typedef int (*__compar_fn_t) (const void *, const void *);
# 752 "/usr/include/stdlib.h" 3 4



extern void *bsearch (const void *__key, const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;







extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
# 775 "/usr/include/stdlib.h" 3 4
extern int abs (int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;



__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;







extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;




__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;

# 812 "/usr/include/stdlib.h" 3 4
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;




extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;




extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));

extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));






extern int mblen (const char *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));


extern int mbtowc (wchar_t *__restrict __pwc,
     const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));


extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__ , __leaf__));



extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));

extern size_t wcstombs (char *__restrict __s,
   const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__));








extern int rpmatch (const char *__response) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 899 "/usr/include/stdlib.h" 3 4
extern int getsubopt (char **__restrict __optionp,
        char *const *__restrict __tokens,
        char **__restrict __valuep)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3))) ;
# 951 "/usr/include/stdlib.h" 3 4
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


# 1 "/usr/include/bits/stdlib-float.h" 1 3 4
# 956 "/usr/include/stdlib.h" 2 3 4
# 968 "/usr/include/stdlib.h" 3 4

# 54 "z_zone.h" 2
# 1 "/usr/include/string.h" 1 3 4
# 27 "/usr/include/string.h" 3 4





# 1 "/usr/lib/gcc/armv7hl-meego-linux-gnueabi/4.8.3/include/stddef.h" 1 3 4
# 33 "/usr/include/string.h" 2 3 4
# 44 "/usr/include/string.h" 3 4


extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
       size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern void *memmove (void *__dest, const void *__src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));






extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
        int __c, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));





extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 96 "/usr/include/string.h" 3 4
extern void *memchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


# 127 "/usr/include/string.h" 3 4


extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern char *strcat (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncat (char *__restrict __dest, const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcoll (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern size_t strxfrm (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));






# 1 "/usr/include/xlocale.h" 1 3 4
# 27 "/usr/include/xlocale.h" 3 4
typedef struct __locale_struct
{

  struct __locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
} *__locale_t;


typedef __locale_t locale_t;
# 164 "/usr/include/string.h" 2 3 4


extern int strcoll_l (const char *__s1, const char *__s2, __locale_t __l)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));

extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    __locale_t __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));





extern char *strdup (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));






extern char *strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
# 211 "/usr/include/string.h" 3 4

# 236 "/usr/include/string.h" 3 4
extern char *strchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 263 "/usr/include/string.h" 3 4
extern char *strrchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


# 282 "/usr/include/string.h" 3 4



extern size_t strcspn (const char *__s, const char *__reject)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern size_t strspn (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 315 "/usr/include/string.h" 3 4
extern char *strpbrk (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 342 "/usr/include/string.h" 3 4
extern char *strstr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strtok (char *__restrict __s, const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));




extern char *__strtok_r (char *__restrict __s,
    const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));

extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
# 397 "/usr/include/string.h" 3 4


extern size_t strlen (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));





extern size_t strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));





extern char *strerror (int __errnum) __attribute__ ((__nothrow__ , __leaf__));

# 427 "/usr/include/string.h" 3 4
extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__ , __leaf__))

                        __attribute__ ((__nonnull__ (2)));
# 445 "/usr/include/string.h" 3 4
extern char *strerror_l (int __errnum, __locale_t __l) __attribute__ ((__nothrow__ , __leaf__));





extern void __bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern void bcopy (const void *__src, void *__dest, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 489 "/usr/include/string.h" 3 4
extern char *index (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 517 "/usr/include/string.h" 3 4
extern char *rindex (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern int ffs (int __i) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
# 534 "/usr/include/string.h" 3 4
extern int strcasecmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 557 "/usr/include/string.h" 3 4
extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));


extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern char *__stpncpy (char *__restrict __dest,
   const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
# 644 "/usr/include/string.h" 3 4

# 55 "z_zone.h" 2
# 1 "/usr/include/assert.h" 1 3 4
# 66 "/usr/include/assert.h" 3 4



extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));


extern void __assert_perror_fail (int __errnum, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));




extern void __assert (const char *__assertion, const char *__file, int __line)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));



# 56 "z_zone.h" 2




enum {PU_FREE, PU_STATIC, PU_SOUND, PU_MUSIC, PU_LEVEL, PU_LEVSPEC, PU_CACHE,
                                            PU_MAX};
# 73 "z_zone.h"
void *(Z_Malloc)(size_t size, int tag, void **ptr );
void (Z_Free)(void *ptr );
void (Z_FreeTags)(int lowtag, int hightag );
void (Z_ChangeTag)(void *ptr, int tag );
void (Z_Init)(void);
void Z_Close(void);
void *(Z_Calloc)(size_t n, size_t n2, int tag, void **user );
void *(Z_Realloc)(void *p, size_t n, int tag, void **user );
char *(Z_Strdup)(const char *s, int tag, void **user );
void (Z_CheckHeap)();
void Z_DumpHistory(char *);
# 127 "z_zone.h"
void Z_ZoneHistory(char *);
# 35 "gl_main.c" 2
# 44 "gl_main.c"
# 1 "/usr/include/math.h" 1 3 4
# 28 "/usr/include/math.h" 3 4




# 1 "/usr/include/bits/huge_val.h" 1 3 4
# 33 "/usr/include/math.h" 2 3 4

# 1 "/usr/include/bits/huge_valf.h" 1 3 4
# 35 "/usr/include/math.h" 2 3 4
# 1 "/usr/include/bits/huge_vall.h" 1 3 4
# 36 "/usr/include/math.h" 2 3 4


# 1 "/usr/include/bits/inf.h" 1 3 4
# 39 "/usr/include/math.h" 2 3 4


# 1 "/usr/include/bits/nan.h" 1 3 4
# 42 "/usr/include/math.h" 2 3 4



# 1 "/usr/include/bits/mathdef.h" 1 3 4
# 26 "/usr/include/bits/mathdef.h" 3 4
typedef float float_t;

typedef double double_t;
# 46 "/usr/include/math.h" 2 3 4
# 69 "/usr/include/math.h" 3 4
# 1 "/usr/include/bits/mathcalls.h" 1 3 4
# 52 "/usr/include/bits/mathcalls.h" 3 4


extern double acos (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __acos (double __x) __attribute__ ((__nothrow__ , __leaf__));

extern double asin (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __asin (double __x) __attribute__ ((__nothrow__ , __leaf__));

extern double atan (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atan (double __x) __attribute__ ((__nothrow__ , __leaf__));

extern double atan2 (double __y, double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atan2 (double __y, double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double cos (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cos (double __x) __attribute__ ((__nothrow__ , __leaf__));

extern double sin (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sin (double __x) __attribute__ ((__nothrow__ , __leaf__));

extern double tan (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __tan (double __x) __attribute__ ((__nothrow__ , __leaf__));




extern double cosh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cosh (double __x) __attribute__ ((__nothrow__ , __leaf__));

extern double sinh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sinh (double __x) __attribute__ ((__nothrow__ , __leaf__));

extern double tanh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __tanh (double __x) __attribute__ ((__nothrow__ , __leaf__));

# 86 "/usr/include/bits/mathcalls.h" 3 4


extern double acosh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __acosh (double __x) __attribute__ ((__nothrow__ , __leaf__));

extern double asinh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __asinh (double __x) __attribute__ ((__nothrow__ , __leaf__));

extern double atanh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atanh (double __x) __attribute__ ((__nothrow__ , __leaf__));







extern double exp (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __exp (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double frexp (double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern double __frexp (double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));


extern double ldexp (double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern double __ldexp (double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));


extern double log (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double log10 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log10 (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double modf (double __x, double *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern double __modf (double __x, double *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

# 126 "/usr/include/bits/mathcalls.h" 3 4


extern double expm1 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __expm1 (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double log1p (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log1p (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double logb (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __logb (double __x) __attribute__ ((__nothrow__ , __leaf__));






extern double exp2 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __exp2 (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double log2 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log2 (double __x) __attribute__ ((__nothrow__ , __leaf__));








extern double pow (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __pow (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));


extern double sqrt (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sqrt (double __x) __attribute__ ((__nothrow__ , __leaf__));





extern double hypot (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __hypot (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));






extern double cbrt (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cbrt (double __x) __attribute__ ((__nothrow__ , __leaf__));








extern double ceil (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __ceil (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern double fabs (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fabs (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern double floor (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __floor (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern double fmod (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __fmod (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));




extern int __isinf (double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern int __finite (double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));





extern int isinf (double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern int finite (double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern double drem (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __drem (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));



extern double significand (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __significand (double __x) __attribute__ ((__nothrow__ , __leaf__));





extern double copysign (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __copysign (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));






extern double nan (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __nan (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));





extern int __isnan (double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern int isnan (double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern double j0 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __j0 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double j1 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __j1 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double jn (int, double) __attribute__ ((__nothrow__ , __leaf__)); extern double __jn (int, double) __attribute__ ((__nothrow__ , __leaf__));
extern double y0 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __y0 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double y1 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __y1 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double yn (int, double) __attribute__ ((__nothrow__ , __leaf__)); extern double __yn (int, double) __attribute__ ((__nothrow__ , __leaf__));






extern double erf (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __erf (double) __attribute__ ((__nothrow__ , __leaf__));
extern double erfc (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __erfc (double) __attribute__ ((__nothrow__ , __leaf__));
extern double lgamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __lgamma (double) __attribute__ ((__nothrow__ , __leaf__));






extern double tgamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __tgamma (double) __attribute__ ((__nothrow__ , __leaf__));





extern double gamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __gamma (double) __attribute__ ((__nothrow__ , __leaf__));






extern double lgamma_r (double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern double __lgamma_r (double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));







extern double rint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __rint (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double nextafter (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __nextafter (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

extern double nexttoward (double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __nexttoward (double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern double remainder (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __remainder (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));



extern double scalbn (double __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalbn (double __x, int __n) __attribute__ ((__nothrow__ , __leaf__));



extern int ilogb (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogb (double __x) __attribute__ ((__nothrow__ , __leaf__));




extern double scalbln (double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalbln (double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));



extern double nearbyint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __nearbyint (double __x) __attribute__ ((__nothrow__ , __leaf__));



extern double round (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __round (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern double trunc (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __trunc (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));




extern double remquo (double __x, double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern double __remquo (double __x, double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));






extern long int lrint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrint (double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrint (double __x) __attribute__ ((__nothrow__ , __leaf__));



extern long int lround (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lround (double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llround (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llround (double __x) __attribute__ ((__nothrow__ , __leaf__));



extern double fdim (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __fdim (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));


extern double fmax (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmax (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern double fmin (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmin (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern int __fpclassify (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));


extern int __signbit (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));



extern double fma (double __x, double __y, double __z) __attribute__ ((__nothrow__ , __leaf__)); extern double __fma (double __x, double __y, double __z) __attribute__ ((__nothrow__ , __leaf__));




# 371 "/usr/include/bits/mathcalls.h" 3 4
extern double scalb (double __x, double __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalb (double __x, double __n) __attribute__ ((__nothrow__ , __leaf__));
# 70 "/usr/include/math.h" 2 3 4
# 88 "/usr/include/math.h" 3 4
# 1 "/usr/include/bits/mathcalls.h" 1 3 4
# 52 "/usr/include/bits/mathcalls.h" 3 4


extern float acosf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __acosf (float __x) __attribute__ ((__nothrow__ , __leaf__));

extern float asinf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __asinf (float __x) __attribute__ ((__nothrow__ , __leaf__));

extern float atanf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atanf (float __x) __attribute__ ((__nothrow__ , __leaf__));

extern float atan2f (float __y, float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atan2f (float __y, float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float cosf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __cosf (float __x) __attribute__ ((__nothrow__ , __leaf__));

extern float sinf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sinf (float __x) __attribute__ ((__nothrow__ , __leaf__));

extern float tanf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __tanf (float __x) __attribute__ ((__nothrow__ , __leaf__));




extern float coshf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __coshf (float __x) __attribute__ ((__nothrow__ , __leaf__));

extern float sinhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sinhf (float __x) __attribute__ ((__nothrow__ , __leaf__));

extern float tanhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __tanhf (float __x) __attribute__ ((__nothrow__ , __leaf__));

# 86 "/usr/include/bits/mathcalls.h" 3 4


extern float acoshf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __acoshf (float __x) __attribute__ ((__nothrow__ , __leaf__));

extern float asinhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __asinhf (float __x) __attribute__ ((__nothrow__ , __leaf__));

extern float atanhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atanhf (float __x) __attribute__ ((__nothrow__ , __leaf__));







extern float expf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __expf (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float frexpf (float __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern float __frexpf (float __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));


extern float ldexpf (float __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern float __ldexpf (float __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));


extern float logf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __logf (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float log10f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log10f (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float modff (float __x, float *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern float __modff (float __x, float *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

# 126 "/usr/include/bits/mathcalls.h" 3 4


extern float expm1f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __expm1f (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float log1pf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log1pf (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float logbf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __logbf (float __x) __attribute__ ((__nothrow__ , __leaf__));






extern float exp2f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __exp2f (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float log2f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log2f (float __x) __attribute__ ((__nothrow__ , __leaf__));








extern float powf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __powf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));


extern float sqrtf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sqrtf (float __x) __attribute__ ((__nothrow__ , __leaf__));





extern float hypotf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __hypotf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));






extern float cbrtf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __cbrtf (float __x) __attribute__ ((__nothrow__ , __leaf__));








extern float ceilf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __ceilf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern float fabsf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fabsf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern float floorf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __floorf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern float fmodf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __fmodf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));




extern int __isinff (float __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern int __finitef (float __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));





extern int isinff (float __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern int finitef (float __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern float dremf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __dremf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));



extern float significandf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __significandf (float __x) __attribute__ ((__nothrow__ , __leaf__));





extern float copysignf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __copysignf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));






extern float nanf (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __nanf (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));





extern int __isnanf (float __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern int isnanf (float __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern float j0f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __j0f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float j1f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __j1f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float jnf (int, float) __attribute__ ((__nothrow__ , __leaf__)); extern float __jnf (int, float) __attribute__ ((__nothrow__ , __leaf__));
extern float y0f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __y0f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float y1f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __y1f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float ynf (int, float) __attribute__ ((__nothrow__ , __leaf__)); extern float __ynf (int, float) __attribute__ ((__nothrow__ , __leaf__));






extern float erff (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __erff (float) __attribute__ ((__nothrow__ , __leaf__));
extern float erfcf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __erfcf (float) __attribute__ ((__nothrow__ , __leaf__));
extern float lgammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __lgammaf (float) __attribute__ ((__nothrow__ , __leaf__));






extern float tgammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __tgammaf (float) __attribute__ ((__nothrow__ , __leaf__));





extern float gammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __gammaf (float) __attribute__ ((__nothrow__ , __leaf__));






extern float lgammaf_r (float, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern float __lgammaf_r (float, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));







extern float rintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __rintf (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float nextafterf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __nextafterf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

extern float nexttowardf (float __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __nexttowardf (float __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern float remainderf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __remainderf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));



extern float scalbnf (float __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalbnf (float __x, int __n) __attribute__ ((__nothrow__ , __leaf__));



extern int ilogbf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbf (float __x) __attribute__ ((__nothrow__ , __leaf__));




extern float scalblnf (float __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalblnf (float __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));



extern float nearbyintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __nearbyintf (float __x) __attribute__ ((__nothrow__ , __leaf__));



extern float roundf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __roundf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern float truncf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __truncf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));




extern float remquof (float __x, float __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern float __remquof (float __x, float __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));






extern long int lrintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintf (float __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintf (float __x) __attribute__ ((__nothrow__ , __leaf__));



extern long int lroundf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundf (float __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundf (float __x) __attribute__ ((__nothrow__ , __leaf__));



extern float fdimf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __fdimf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));


extern float fmaxf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fmaxf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern float fminf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fminf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern int __fpclassifyf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));


extern int __signbitf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));



extern float fmaf (float __x, float __y, float __z) __attribute__ ((__nothrow__ , __leaf__)); extern float __fmaf (float __x, float __y, float __z) __attribute__ ((__nothrow__ , __leaf__));




# 371 "/usr/include/bits/mathcalls.h" 3 4
extern float scalbf (float __x, float __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalbf (float __x, float __n) __attribute__ ((__nothrow__ , __leaf__));
# 89 "/usr/include/math.h" 2 3 4
# 132 "/usr/include/math.h" 3 4
# 1 "/usr/include/bits/mathcalls.h" 1 3 4
# 52 "/usr/include/bits/mathcalls.h" 3 4


extern long double acosl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __acosl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

extern long double asinl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __asinl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

extern long double atanl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atanl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

extern long double atan2l (long double __y, long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atan2l (long double __y, long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double cosl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __cosl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

extern long double sinl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sinl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

extern long double tanl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tanl (long double __x) __attribute__ ((__nothrow__ , __leaf__));




extern long double coshl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __coshl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

extern long double sinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

extern long double tanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

# 86 "/usr/include/bits/mathcalls.h" 3 4


extern long double acoshl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __acoshl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

extern long double asinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __asinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

extern long double atanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));







extern long double expl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __expl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double frexpl (long double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern long double __frexpl (long double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));


extern long double ldexpl (long double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern long double __ldexpl (long double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));


extern long double logl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __logl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double log10l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log10l (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double modfl (long double __x, long double *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern long double __modfl (long double __x, long double *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

# 126 "/usr/include/bits/mathcalls.h" 3 4


extern long double expm1l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __expm1l (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double log1pl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log1pl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double logbl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __logbl (long double __x) __attribute__ ((__nothrow__ , __leaf__));






extern long double exp2l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __exp2l (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double log2l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log2l (long double __x) __attribute__ ((__nothrow__ , __leaf__));








extern long double powl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __powl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));


extern long double sqrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sqrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__));





extern long double hypotl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __hypotl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));






extern long double cbrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __cbrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__));








extern long double ceill (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __ceill (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern long double fabsl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fabsl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern long double floorl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __floorl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern long double fmodl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fmodl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));




extern int __isinfl (long double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern int __finitel (long double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));





extern int isinfl (long double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern int finitel (long double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern long double dreml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __dreml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));



extern long double significandl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __significandl (long double __x) __attribute__ ((__nothrow__ , __leaf__));





extern long double copysignl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __copysignl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));






extern long double nanl (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __nanl (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));





extern int __isnanl (long double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern int isnanl (long double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern long double j0l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __j0l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double j1l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __j1l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double jnl (int, long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __jnl (int, long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double y0l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __y0l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double y1l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __y1l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double ynl (int, long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __ynl (int, long double) __attribute__ ((__nothrow__ , __leaf__));






extern long double erfl (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __erfl (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double erfcl (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __erfcl (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double lgammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __lgammal (long double) __attribute__ ((__nothrow__ , __leaf__));






extern long double tgammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tgammal (long double) __attribute__ ((__nothrow__ , __leaf__));





extern long double gammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __gammal (long double) __attribute__ ((__nothrow__ , __leaf__));






extern long double lgammal_r (long double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern long double __lgammal_r (long double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));







extern long double rintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __rintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double nextafterl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __nextafterl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

extern long double nexttowardl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __nexttowardl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern long double remainderl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __remainderl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));



extern long double scalbnl (long double __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalbnl (long double __x, int __n) __attribute__ ((__nothrow__ , __leaf__));



extern int ilogbl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbl (long double __x) __attribute__ ((__nothrow__ , __leaf__));




extern long double scalblnl (long double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalblnl (long double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));



extern long double nearbyintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nearbyintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));



extern long double roundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __roundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern long double truncl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __truncl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));




extern long double remquol (long double __x, long double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern long double __remquol (long double __x, long double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));






extern long int lrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));



extern long int lroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__));



extern long double fdiml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fdiml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));


extern long double fmaxl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fmaxl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern long double fminl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fminl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern int __fpclassifyl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));


extern int __signbitl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));



extern long double fmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__ , __leaf__));




# 371 "/usr/include/bits/mathcalls.h" 3 4
extern long double scalbl (long double __x, long double __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalbl (long double __x, long double __n) __attribute__ ((__nothrow__ , __leaf__));
# 133 "/usr/include/math.h" 2 3 4
# 148 "/usr/include/math.h" 3 4
extern int signgam;
# 189 "/usr/include/math.h" 3 4
enum
  {
    FP_NAN =

      0,
    FP_INFINITE =

      1,
    FP_ZERO =

      2,
    FP_SUBNORMAL =

      3,
    FP_NORMAL =

      4
  };
# 301 "/usr/include/math.h" 3 4
typedef enum
{
  _IEEE_ = -1,
  _SVID_,
  _XOPEN_,
  _POSIX_,
  _ISOC_
} _LIB_VERSION_TYPE;




extern _LIB_VERSION_TYPE _LIB_VERSION;
# 326 "/usr/include/math.h" 3 4
struct exception

  {
    int type;
    char *name;
    double arg1;
    double arg2;
    double retval;
  };




extern int matherr (struct exception *__exc);
# 488 "/usr/include/math.h" 3 4

# 45 "gl_main.c" 2
# 1 "harmattan.h" 1



typedef void (* PFNGLCOLORTABLEEXTPROC) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table);
# 19 "harmattan.h"
typedef GLfloat GLdouble;
# 46 "gl_main.c" 2

extern int tran_filter_pct;



boolean use_fog=false;

int gl_nearclip=5;
char *gl_tex_filter_string;
int gl_tex_filter;
int gl_mipmap_filter;
int gl_drawskys=true;
int gl_sortsprites=true;
int gl_texture_filter_anisotropic = 0;
int gl_use_paletted_texture = 0;
int gl_use_shared_texture_palette = 0;
int gl_paletted_texture = 0;
int gl_shared_texture_palette = 0;
int gl_sprite_offset;

GLuint gld_DisplayList=0;
int fog_density=200;
static float extra_red=0.0f;
static float extra_green=0.0f;
static float extra_blue=0.0f;
static float extra_alpha=0.0f;

GLfloat gl_whitecolor[4]={1.0f,1.0f,1.0f,1.0f};
# 85 "gl_main.c"
static const float lighttable[5][256] =
{
  {
    0.00000f,0.00000f,0.00000f,0.00000f,0.00000f,0.00001f,0.00001f,0.00002f,0.00003f,0.00004f,
    0.00006f,0.00008f,0.00010f,0.00013f,0.00017f,0.00020f,0.00025f,0.00030f,0.00035f,0.00041f,
    0.00048f,0.00056f,0.00064f,0.00073f,0.00083f,0.00094f,0.00106f,0.00119f,0.00132f,0.00147f,
    0.00163f,0.00180f,0.00198f,0.00217f,0.00237f,0.00259f,0.00281f,0.00305f,0.00331f,0.00358f,
    0.00386f,0.00416f,0.00447f,0.00479f,0.00514f,0.00550f,0.00587f,0.00626f,0.00667f,0.00710f,
    0.00754f,0.00800f,0.00848f,0.00898f,0.00950f,0.01003f,0.01059f,0.01117f,0.01177f,0.01239f,
    0.01303f,0.01369f,0.01437f,0.01508f,0.01581f,0.01656f,0.01734f,0.01814f,0.01896f,0.01981f,
    0.02069f,0.02159f,0.02251f,0.02346f,0.02444f,0.02544f,0.02647f,0.02753f,0.02862f,0.02973f,
    0.03088f,0.03205f,0.03325f,0.03448f,0.03575f,0.03704f,0.03836f,0.03971f,0.04110f,0.04252f,
    0.04396f,0.04545f,0.04696f,0.04851f,0.05009f,0.05171f,0.05336f,0.05504f,0.05676f,0.05852f,
    0.06031f,0.06214f,0.06400f,0.06590f,0.06784f,0.06981f,0.07183f,0.07388f,0.07597f,0.07810f,
    0.08027f,0.08248f,0.08473f,0.08702f,0.08935f,0.09172f,0.09414f,0.09659f,0.09909f,0.10163f,
    0.10421f,0.10684f,0.10951f,0.11223f,0.11499f,0.11779f,0.12064f,0.12354f,0.12648f,0.12946f,
    0.13250f,0.13558f,0.13871f,0.14188f,0.14511f,0.14838f,0.15170f,0.15507f,0.15850f,0.16197f,
    0.16549f,0.16906f,0.17268f,0.17635f,0.18008f,0.18386f,0.18769f,0.19157f,0.19551f,0.19950f,
    0.20354f,0.20764f,0.21179f,0.21600f,0.22026f,0.22458f,0.22896f,0.23339f,0.23788f,0.24242f,
    0.24702f,0.25168f,0.25640f,0.26118f,0.26602f,0.27091f,0.27587f,0.28089f,0.28596f,0.29110f,
    0.29630f,0.30156f,0.30688f,0.31226f,0.31771f,0.32322f,0.32879f,0.33443f,0.34013f,0.34589f,
    0.35172f,0.35761f,0.36357f,0.36960f,0.37569f,0.38185f,0.38808f,0.39437f,0.40073f,0.40716f,
    0.41366f,0.42022f,0.42686f,0.43356f,0.44034f,0.44718f,0.45410f,0.46108f,0.46814f,0.47527f,
    0.48247f,0.48974f,0.49709f,0.50451f,0.51200f,0.51957f,0.52721f,0.53492f,0.54271f,0.55058f,
    0.55852f,0.56654f,0.57463f,0.58280f,0.59105f,0.59937f,0.60777f,0.61625f,0.62481f,0.63345f,
    0.64217f,0.65096f,0.65984f,0.66880f,0.67783f,0.68695f,0.69615f,0.70544f,0.71480f,0.72425f,
    0.73378f,0.74339f,0.75308f,0.76286f,0.77273f,0.78268f,0.79271f,0.80283f,0.81304f,0.82333f,
    0.83371f,0.84417f,0.85472f,0.86536f,0.87609f,0.88691f,0.89781f,0.90880f,0.91989f,0.93106f,
    0.94232f,0.95368f,0.96512f,0.97665f,0.98828f,1.00000
  },
  {
    0.00000f,0.00000f,0.00000f,0.00000f,0.00001f,0.00002f,0.00003f,0.00005f,0.00007f,0.00010f,
    0.00014f,0.00019f,0.00024f,0.00031f,0.00038f,0.00047f,0.00057f,0.00069f,0.00081f,0.00096f,
    0.00112f,0.00129f,0.00148f,0.00170f,0.00193f,0.00218f,0.00245f,0.00274f,0.00306f,0.00340f,
    0.00376f,0.00415f,0.00456f,0.00500f,0.00547f,0.00597f,0.00649f,0.00704f,0.00763f,0.00825f,
    0.00889f,0.00957f,0.01029f,0.01104f,0.01182f,0.01264f,0.01350f,0.01439f,0.01532f,0.01630f,
    0.01731f,0.01836f,0.01945f,0.02058f,0.02176f,0.02298f,0.02424f,0.02555f,0.02690f,0.02830f,
    0.02974f,0.03123f,0.03277f,0.03436f,0.03600f,0.03768f,0.03942f,0.04120f,0.04304f,0.04493f,
    0.04687f,0.04886f,0.05091f,0.05301f,0.05517f,0.05738f,0.05964f,0.06196f,0.06434f,0.06677f,
    0.06926f,0.07181f,0.07441f,0.07707f,0.07979f,0.08257f,0.08541f,0.08831f,0.09126f,0.09428f,
    0.09735f,0.10048f,0.10368f,0.10693f,0.11025f,0.11362f,0.11706f,0.12056f,0.12411f,0.12773f,
    0.13141f,0.13515f,0.13895f,0.14281f,0.14673f,0.15072f,0.15476f,0.15886f,0.16303f,0.16725f,
    0.17153f,0.17587f,0.18028f,0.18474f,0.18926f,0.19383f,0.19847f,0.20316f,0.20791f,0.21272f,
    0.21759f,0.22251f,0.22748f,0.23251f,0.23760f,0.24274f,0.24793f,0.25318f,0.25848f,0.26383f,
    0.26923f,0.27468f,0.28018f,0.28573f,0.29133f,0.29697f,0.30266f,0.30840f,0.31418f,0.32001f,
    0.32588f,0.33179f,0.33774f,0.34374f,0.34977f,0.35585f,0.36196f,0.36810f,0.37428f,0.38050f,
    0.38675f,0.39304f,0.39935f,0.40570f,0.41207f,0.41847f,0.42490f,0.43136f,0.43784f,0.44434f,
    0.45087f,0.45741f,0.46398f,0.47057f,0.47717f,0.48379f,0.49042f,0.49707f,0.50373f,0.51041f,
    0.51709f,0.52378f,0.53048f,0.53718f,0.54389f,0.55061f,0.55732f,0.56404f,0.57075f,0.57747f,
    0.58418f,0.59089f,0.59759f,0.60429f,0.61097f,0.61765f,0.62432f,0.63098f,0.63762f,0.64425f,
    0.65086f,0.65746f,0.66404f,0.67060f,0.67714f,0.68365f,0.69015f,0.69662f,0.70307f,0.70948f,
    0.71588f,0.72224f,0.72857f,0.73488f,0.74115f,0.74739f,0.75359f,0.75976f,0.76589f,0.77199f,
    0.77805f,0.78407f,0.79005f,0.79599f,0.80189f,0.80774f,0.81355f,0.81932f,0.82504f,0.83072f,
    0.83635f,0.84194f,0.84747f,0.85296f,0.85840f,0.86378f,0.86912f,0.87441f,0.87964f,0.88482f,
    0.88995f,0.89503f,0.90005f,0.90502f,0.90993f,0.91479f,0.91959f,0.92434f,0.92903f,0.93366f,
    0.93824f,0.94276f,0.94723f,0.95163f,0.95598f,0.96027f,0.96451f,0.96868f,0.97280f,0.97686f,
    0.98086f,0.98481f,0.98869f,0.99252f,0.99629f,1.00000f
  },
  {
    0.00000f,0.00000f,0.00000f,0.00001f,0.00002f,0.00003f,0.00005f,0.00008f,0.00013f,0.00018f,
    0.00025f,0.00033f,0.00042f,0.00054f,0.00067f,0.00083f,0.00101f,0.00121f,0.00143f,0.00168f,
    0.00196f,0.00227f,0.00261f,0.00299f,0.00339f,0.00383f,0.00431f,0.00483f,0.00538f,0.00598f,
    0.00661f,0.00729f,0.00802f,0.00879f,0.00961f,0.01048f,0.01140f,0.01237f,0.01340f,0.01447f,
    0.01561f,0.01680f,0.01804f,0.01935f,0.02072f,0.02215f,0.02364f,0.02520f,0.02682f,0.02850f,
    0.03026f,0.03208f,0.03397f,0.03594f,0.03797f,0.04007f,0.04225f,0.04451f,0.04684f,0.04924f,
    0.05172f,0.05428f,0.05691f,0.05963f,0.06242f,0.06530f,0.06825f,0.07129f,0.07441f,0.07761f,
    0.08089f,0.08426f,0.08771f,0.09125f,0.09487f,0.09857f,0.10236f,0.10623f,0.11019f,0.11423f,
    0.11836f,0.12257f,0.12687f,0.13125f,0.13571f,0.14027f,0.14490f,0.14962f,0.15442f,0.15931f,
    0.16427f,0.16932f,0.17445f,0.17966f,0.18496f,0.19033f,0.19578f,0.20130f,0.20691f,0.21259f,
    0.21834f,0.22417f,0.23007f,0.23605f,0.24209f,0.24820f,0.25438f,0.26063f,0.26694f,0.27332f,
    0.27976f,0.28626f,0.29282f,0.29944f,0.30611f,0.31284f,0.31962f,0.32646f,0.33334f,0.34027f,
    0.34724f,0.35426f,0.36132f,0.36842f,0.37556f,0.38273f,0.38994f,0.39718f,0.40445f,0.41174f,
    0.41907f,0.42641f,0.43378f,0.44116f,0.44856f,0.45598f,0.46340f,0.47084f,0.47828f,0.48573f,
    0.49319f,0.50064f,0.50809f,0.51554f,0.52298f,0.53042f,0.53784f,0.54525f,0.55265f,0.56002f,
    0.56738f,0.57472f,0.58203f,0.58932f,0.59658f,0.60381f,0.61101f,0.61817f,0.62529f,0.63238f,
    0.63943f,0.64643f,0.65339f,0.66031f,0.66717f,0.67399f,0.68075f,0.68746f,0.69412f,0.70072f,
    0.70726f,0.71375f,0.72017f,0.72653f,0.73282f,0.73905f,0.74522f,0.75131f,0.75734f,0.76330f,
    0.76918f,0.77500f,0.78074f,0.78640f,0.79199f,0.79751f,0.80295f,0.80831f,0.81359f,0.81880f,
    0.82393f,0.82898f,0.83394f,0.83883f,0.84364f,0.84836f,0.85301f,0.85758f,0.86206f,0.86646f,
    0.87078f,0.87502f,0.87918f,0.88326f,0.88726f,0.89118f,0.89501f,0.89877f,0.90245f,0.90605f,
    0.90957f,0.91301f,0.91638f,0.91966f,0.92288f,0.92601f,0.92908f,0.93206f,0.93498f,0.93782f,
    0.94059f,0.94329f,0.94592f,0.94848f,0.95097f,0.95339f,0.95575f,0.95804f,0.96027f,0.96244f,
    0.96454f,0.96658f,0.96856f,0.97049f,0.97235f,0.97416f,0.97591f,0.97760f,0.97924f,0.98083f,
    0.98237f,0.98386f,0.98530f,0.98669f,0.98803f,0.98933f,0.99058f,0.99179f,0.99295f,0.99408f,
    0.99516f,0.99620f,0.99721f,0.99817f,0.99910f,1.00000f
  },
  {
    0.00000f,0.00000f,0.00000f,0.00001f,0.00002f,0.00005f,0.00008f,0.00012f,0.00019f,0.00026f,
    0.00036f,0.00048f,0.00063f,0.00080f,0.00099f,0.00122f,0.00148f,0.00178f,0.00211f,0.00249f,
    0.00290f,0.00335f,0.00386f,0.00440f,0.00500f,0.00565f,0.00636f,0.00711f,0.00793f,0.00881f,
    0.00975f,0.01075f,0.01182f,0.01295f,0.01416f,0.01543f,0.01678f,0.01821f,0.01971f,0.02129f,
    0.02295f,0.02469f,0.02652f,0.02843f,0.03043f,0.03252f,0.03469f,0.03696f,0.03933f,0.04178f,
    0.04433f,0.04698f,0.04973f,0.05258f,0.05552f,0.05857f,0.06172f,0.06498f,0.06834f,0.07180f,
    0.07537f,0.07905f,0.08283f,0.08672f,0.09072f,0.09483f,0.09905f,0.10337f,0.10781f,0.11236f,
    0.11701f,0.12178f,0.12665f,0.13163f,0.13673f,0.14193f,0.14724f,0.15265f,0.15817f,0.16380f,
    0.16954f,0.17538f,0.18132f,0.18737f,0.19351f,0.19976f,0.20610f,0.21255f,0.21908f,0.22572f,
    0.23244f,0.23926f,0.24616f,0.25316f,0.26023f,0.26739f,0.27464f,0.28196f,0.28935f,0.29683f,
    0.30437f,0.31198f,0.31966f,0.32740f,0.33521f,0.34307f,0.35099f,0.35896f,0.36699f,0.37506f,
    0.38317f,0.39133f,0.39952f,0.40775f,0.41601f,0.42429f,0.43261f,0.44094f,0.44929f,0.45766f,
    0.46604f,0.47443f,0.48283f,0.49122f,0.49962f,0.50801f,0.51639f,0.52476f,0.53312f,0.54146f,
    0.54978f,0.55807f,0.56633f,0.57457f,0.58277f,0.59093f,0.59905f,0.60713f,0.61516f,0.62314f,
    0.63107f,0.63895f,0.64676f,0.65452f,0.66221f,0.66984f,0.67739f,0.68488f,0.69229f,0.69963f,
    0.70689f,0.71407f,0.72117f,0.72818f,0.73511f,0.74195f,0.74870f,0.75536f,0.76192f,0.76839f,
    0.77477f,0.78105f,0.78723f,0.79331f,0.79930f,0.80518f,0.81096f,0.81664f,0.82221f,0.82768f,
    0.83305f,0.83832f,0.84347f,0.84853f,0.85348f,0.85832f,0.86306f,0.86770f,0.87223f,0.87666f,
    0.88098f,0.88521f,0.88933f,0.89334f,0.89726f,0.90108f,0.90480f,0.90842f,0.91194f,0.91537f,
    0.91870f,0.92193f,0.92508f,0.92813f,0.93109f,0.93396f,0.93675f,0.93945f,0.94206f,0.94459f,
    0.94704f,0.94941f,0.95169f,0.95391f,0.95604f,0.95810f,0.96009f,0.96201f,0.96386f,0.96564f,
    0.96735f,0.96900f,0.97059f,0.97212f,0.97358f,0.97499f,0.97634f,0.97764f,0.97888f,0.98007f,
    0.98122f,0.98231f,0.98336f,0.98436f,0.98531f,0.98623f,0.98710f,0.98793f,0.98873f,0.98949f,
    0.99021f,0.99090f,0.99155f,0.99218f,0.99277f,0.99333f,0.99387f,0.99437f,0.99486f,0.99531f,
    0.99575f,0.99616f,0.99654f,0.99691f,0.99726f,0.99759f,0.99790f,0.99819f,0.99847f,0.99873f,
    0.99897f,0.99920f,0.99942f,0.99963f,0.99982f,1.00000f
  },
  {
    0.00000f,0.00000f,0.00000f,0.00001f,0.00003f,0.00006f,0.00010f,0.00017f,0.00025f,0.00035f,
    0.00048f,0.00064f,0.00083f,0.00106f,0.00132f,0.00163f,0.00197f,0.00237f,0.00281f,0.00330f,
    0.00385f,0.00446f,0.00513f,0.00585f,0.00665f,0.00751f,0.00845f,0.00945f,0.01054f,0.01170f,
    0.01295f,0.01428f,0.01569f,0.01719f,0.01879f,0.02048f,0.02227f,0.02415f,0.02614f,0.02822f,
    0.03042f,0.03272f,0.03513f,0.03765f,0.04028f,0.04303f,0.04589f,0.04887f,0.05198f,0.05520f,
    0.05855f,0.06202f,0.06561f,0.06933f,0.07318f,0.07716f,0.08127f,0.08550f,0.08987f,0.09437f,
    0.09900f,0.10376f,0.10866f,0.11369f,0.11884f,0.12414f,0.12956f,0.13512f,0.14080f,0.14662f,
    0.15257f,0.15865f,0.16485f,0.17118f,0.17764f,0.18423f,0.19093f,0.19776f,0.20471f,0.21177f,
    0.21895f,0.22625f,0.23365f,0.24117f,0.24879f,0.25652f,0.26435f,0.27228f,0.28030f,0.28842f,
    0.29662f,0.30492f,0.31329f,0.32175f,0.33028f,0.33889f,0.34756f,0.35630f,0.36510f,0.37396f,
    0.38287f,0.39183f,0.40084f,0.40989f,0.41897f,0.42809f,0.43723f,0.44640f,0.45559f,0.46479f,
    0.47401f,0.48323f,0.49245f,0.50167f,0.51088f,0.52008f,0.52927f,0.53843f,0.54757f,0.55668f,
    0.56575f,0.57479f,0.58379f,0.59274f,0.60164f,0.61048f,0.61927f,0.62799f,0.63665f,0.64524f,
    0.65376f,0.66220f,0.67056f,0.67883f,0.68702f,0.69511f,0.70312f,0.71103f,0.71884f,0.72655f,
    0.73415f,0.74165f,0.74904f,0.75632f,0.76348f,0.77053f,0.77747f,0.78428f,0.79098f,0.79756f,
    0.80401f,0.81035f,0.81655f,0.82264f,0.82859f,0.83443f,0.84013f,0.84571f,0.85117f,0.85649f,
    0.86169f,0.86677f,0.87172f,0.87654f,0.88124f,0.88581f,0.89026f,0.89459f,0.89880f,0.90289f,
    0.90686f,0.91071f,0.91445f,0.91807f,0.92157f,0.92497f,0.92826f,0.93143f,0.93450f,0.93747f,
    0.94034f,0.94310f,0.94577f,0.94833f,0.95081f,0.95319f,0.95548f,0.95768f,0.95980f,0.96183f,
    0.96378f,0.96565f,0.96744f,0.96916f,0.97081f,0.97238f,0.97388f,0.97532f,0.97669f,0.97801f,
    0.97926f,0.98045f,0.98158f,0.98266f,0.98369f,0.98467f,0.98560f,0.98648f,0.98732f,0.98811f,
    0.98886f,0.98958f,0.99025f,0.99089f,0.99149f,0.99206f,0.99260f,0.99311f,0.99359f,0.99404f,
    0.99446f,0.99486f,0.99523f,0.99559f,0.99592f,0.99623f,0.99652f,0.99679f,0.99705f,0.99729f,
    0.99751f,0.99772f,0.99792f,0.99810f,0.99827f,0.99843f,0.99857f,0.99871f,0.99884f,0.99896f,
    0.99907f,0.99917f,0.99926f,0.99935f,0.99943f,0.99951f,0.99958f,0.99964f,0.99970f,0.99975f,
    0.99980f,0.99985f,0.99989f,0.99993f,0.99997f,1.00000f
  }
};
# 243 "gl_main.c"
static void gld_StaticLightAlpha(float light, float alpha)
{
  player_t *player;
  player = &players[displayplayer];

  if (player->fixedcolormap)
    glColor4f(1.0f, 1.0f, 1.0f, alpha);
  else
    glColor4f(light, light, light, alpha);
}



static void gld_InitExtensions(const char *_extensions)
{
  char *extensions;
  char *extension;
  char *p;

  if (!_extensions)
    return;

  extensions = Z_Malloc(strlen(_extensions) + 1,PU_STATIC,0);
  if (!extensions)
    return;
  memcpy(extensions, _extensions, strlen(_extensions) + 1);

  p = extensions;
  extension = p;

  do {
    while ((*p != ' ') && (*p != '\0'))
      p++;
    if (*p != '\0')
      *p++ = '\0';
    while (*p == ' ')
      p++;

    if (strcasecmp(extension, "GL_EXT_texture_filter_anisotropic") == 0)
      gl_texture_filter_anisotropic = true;
    else if (strcasecmp(extension, "GL_EXT_paletted_texture") == 0) {
      if (gl_use_paletted_texture) {
        gl_paletted_texture = true;
        gld_ColorTableEXT = SDL_GL_GetProcAddress("glColorTableEXT");
 if (gld_ColorTableEXT == ((void *)0))
   gl_paletted_texture = false;
 else
          lprintf(LO_INFO,"using GL_EXT_paletted_texture\n");
      }
    }
    else if (strcasecmp(extension, "GL_EXT_shared_texture_palette") == 0)
      if (gl_use_shared_texture_palette) {
        gl_shared_texture_palette = true;
        gld_ColorTableEXT = SDL_GL_GetProcAddress("glColorTableEXT");
 if (gld_ColorTableEXT == ((void *)0))
   gl_shared_texture_palette = false;
 else
          lprintf(LO_INFO,"using GL_EXT_shared_texture_palette\n");
      }

    extension = p;
  } while (*extension != '\0');

  Z_Free(extensions);
}

void gld_Init(int width, int height)
{
  GLfloat params[4]={0.0f,0.0f,1.0f,0.0f};
  GLfloat BlackFogColor[4] = { 0.0f, 0.0f, 0.0f, 0.0f };

  lprintf(LO_INFO,"GL_VENDOR: %s\n",glGetString(GL_VENDOR));
  lprintf(LO_INFO,"GL_RENDERER: %s\n",glGetString(GL_RENDERER));
  lprintf(LO_INFO,"GL_VERSION: %s\n",glGetString(GL_VERSION));
  lprintf(LO_INFO,"GL_EXTENSIONS:\n");
  {
    char ext_name[256];
    const char *extensions = glGetString(GL_EXTENSIONS);
    const char *rover = extensions;
    const char *p = rover;

    while (*rover)
    {
      p = rover;
      while (*p && *p != ' ')
        p++;
      if (*p)
      {
        int len = MIN(p-rover, sizeof(ext_name)-1);
        memset(ext_name, 0, sizeof(ext_name));
        strncpy(ext_name, rover, len);
        lprintf(LO_INFO,"\t%s\n", ext_name);
      }
      rover = p;
      while (*rover && *rover == ' ')
        rover++;
    }
  }

  gld_InitExtensions(glGetString(GL_EXTENSIONS));

  gld_InitPalettedTextures();

  glViewport(0, 0, SCREENWIDTH, SCREENHEIGHT);

  glClearColor(0.0f, 0.5f, 0.5f, 1.0f);
  glClearDepthf(1.0f);

  glGetIntegerv(GL_MAX_TEXTURE_SIZE,&gld_max_texturesize);

  lprintf(LO_INFO,"GL_MAX_TEXTURE_SIZE=%i\n",gld_max_texturesize);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
  glShadeModel(GL_FLAT);
  glEnable(GL_TEXTURE_2D);
  glDepthFunc(GL_LEQUAL);
  glEnable(GL_ALPHA_TEST);
  glAlphaFunc(GL_GEQUAL,0.5f);
  glDisable(GL_CULL_FACE);
  glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);







  glFogf (GL_FOG_MODE, GL_EXP);
  glFogfv(GL_FOG_COLOR, BlackFogColor);
  glFogf (GL_FOG_DENSITY, (float)fog_density/1000.0f);
  glHint (GL_FOG_HINT, GL_NICEST);
  glFogf (GL_FOG_START, 0.0f);
  glFogf (GL_FOG_END, 1.0f);
  if (!strcasecmp(gl_tex_filter_string,"GL_NEAREST_MIPMAP_NEAREST"))
  {
    use_mipmapping=true;
    gl_shared_texture_palette = false;
    lprintf(LO_INFO,"Using GL_NEAREST for normal textures.\n");
    lprintf(LO_INFO,"Using GL_NEAREST_MIPMAP_NEAREST for mipmap textures.\n");
    gl_tex_filter=GL_NEAREST;
    gl_mipmap_filter=GL_NEAREST_MIPMAP_NEAREST;
  }
  else
  if (!strcasecmp(gl_tex_filter_string,"GL_LINEAR_MIPMAP_NEAREST"))
  {
    use_mipmapping=true;
    gl_shared_texture_palette = false;
    lprintf(LO_INFO,"Using GL_LINEAR for normal textures.\n");
    lprintf(LO_INFO,"Using GL_LINEAR_MIPMAP_NEAREST for mipmap textures.\n");
    gl_tex_filter=GL_LINEAR;
    gl_mipmap_filter=GL_LINEAR_MIPMAP_NEAREST;
  }
  else
  if (!strcasecmp(gl_tex_filter_string,"GL_NEAREST_MIPMAP_LINEAR"))
  {
    use_mipmapping=true;
    gl_shared_texture_palette = false;
    lprintf(LO_INFO,"Using GL_NEAREST for normal textures.\n");
    lprintf(LO_INFO,"Using GL_NEAREST_MIPMAP_LINEAR for mipmap textures.\n");
    gl_tex_filter=GL_NEAREST;
    gl_mipmap_filter=GL_NEAREST_MIPMAP_LINEAR;
  }
  else
  if (!strcasecmp(gl_tex_filter_string,"GL_LINEAR_MIPMAP_LINEAR"))
  {
    use_mipmapping=true;
    gl_shared_texture_palette = false;
    lprintf(LO_INFO,"Using GL_LINEAR for normal textures.\n");
    lprintf(LO_INFO,"Using GL_LINEAR_MIPMAP_LINEAR for mipmap textures.\n");
    gl_tex_filter=GL_LINEAR;
    gl_mipmap_filter=GL_LINEAR_MIPMAP_LINEAR;
  }
  else
  if (!strcasecmp(gl_tex_filter_string,"GL_NEAREST"))
  {
    use_mipmapping=false;
    lprintf(LO_INFO,"Using GL_NEAREST for textures.\n");
    gl_tex_filter=GL_NEAREST;
    gl_mipmap_filter=GL_NEAREST;
  }
  else
  {
    use_mipmapping=false;
    lprintf(LO_INFO,"Using GL_LINEAR for textures.\n");
    gl_tex_filter=GL_LINEAR;
    gl_mipmap_filter=GL_LINEAR;
  }


  use_mipmapping = false;
# 464 "gl_main.c"
  {
    gl_tex_format=GL_RGBA;
    lprintf(LO_INFO,"Using texture format GL_RGBA.\n");
  }
}

void gld_InitCommandLine(void)
{
}




void gld_DrawNumPatch(int x, int y, int lump, int cm, enum patch_translation_e flags)
{
  GLTexture *gltexture;
  float fU1,fU2,fV1,fV2;
  float width,height;
  float xpos, ypos;

  if (flags & VPT_TRANS)
  {
    gltexture=gld_RegisterPatch(lump,cm);
    gld_BindPatch(gltexture, cm);
  }
  else
  {
    gltexture=gld_RegisterPatch(lump,CR_DEFAULT);
    gld_BindPatch(gltexture, CR_DEFAULT);
  }
  if (!gltexture)
    return;
  fV1=0.0f;
  fV2=(float)gltexture->height/(float)gltexture->tex_height;
  if (flags & VPT_FLIP)
  {
    fU1=(float)gltexture->width/(float)gltexture->tex_width;
    fU2=0.0f;
  }
  else
  {
    fU1=0.0f;
    fU2=(float)gltexture->width/(float)gltexture->tex_width;
  }
  xpos=((flags & VPT_STRETCH)?((float)x-gltexture->leftoffset)*(float)SCREENWIDTH/320.0f:(float)x-gltexture->leftoffset);
  ypos=((flags & VPT_STRETCH)?((float)y-gltexture->topoffset)*(float)SCREENHEIGHT/200.0f:(float)y-gltexture->topoffset);
  width=((flags & VPT_STRETCH)?((float)gltexture->realtexwidth)*(float)SCREENWIDTH/320.0f:(float)gltexture->realtexwidth);
  height=((flags & VPT_STRETCH)?((float)gltexture->realtexheight)*(float)SCREENHEIGHT/200.0f:(float)gltexture->realtexheight);
  { GLenum harm_Render_Type = GL_TRIANGLE_STRIP; GLint harm_Vertex_Size = 2; GLsizei harm_Vertex_Stride = 4; GLint harm_TexCoord_Size = 2; GLsizei harm_TexCoord_Stride = 4; GLint harm_Vertex_Count = 4; GLboolean harm_Enable_TexCoord = GL_TRUE;
  GLfloat harm_Data[] = {
    (fU1), (fV1), ((xpos)), ((ypos)),
    (fU1), (fV2), ((xpos)), ((ypos+height)),
    (fU2), (fV1), ((xpos+width)), ((ypos)),
    (fU2), (fV2), ((xpos+width)), ((ypos+height)),
  };
  glEnableClientState(GL_VERTEX_ARRAY); if(harm_Enable_TexCoord) glEnableClientState(GL_TEXTURE_COORD_ARRAY); if(harm_Enable_TexCoord) glTexCoordPointer(harm_TexCoord_Size, GL_FLOAT, harm_TexCoord_Stride * sizeof(GLfloat), harm_Data); glVertexPointer(harm_Vertex_Size, GL_FLOAT, harm_Enable_TexCoord ? harm_Vertex_Stride * sizeof(GLfloat) : 0, harm_Data + (harm_Enable_TexCoord ? harm_TexCoord_Size : 0)); glDrawArrays(harm_Render_Type, 0, harm_Vertex_Count); glDisableClientState(GL_VERTEX_ARRAY); if(harm_Enable_TexCoord) glDisableClientState(GL_TEXTURE_COORD_ARRAY); }
}




void gld_DrawBackground(const char* name)
{
  GLTexture *gltexture;
  float fU1,fU2,fV1,fV2;
  int width,height;

  gltexture=gld_RegisterFlat(R_FlatNumForName(name), false);
  gld_BindFlat(gltexture);
  if (!gltexture)
    return;
  fU1=0;
  fV1=0;
  fU2=(float)SCREENWIDTH/(float)gltexture->realtexwidth;
  fV2=(float)SCREENHEIGHT/(float)gltexture->realtexheight;
  width=SCREENWIDTH;
  height=SCREENHEIGHT;
  { GLenum harm_Render_Type = GL_TRIANGLE_STRIP; GLint harm_Vertex_Size = 2; GLsizei harm_Vertex_Stride = 4; GLint harm_TexCoord_Size = 2; GLsizei harm_TexCoord_Stride = 4; GLint harm_Vertex_Count = 4; GLboolean harm_Enable_TexCoord = GL_TRUE;
  GLfloat harm_Data[] = {
    (fU1), (fV1), ((float)(0)), ((float)(0)),
    (fU1), (fV2), ((float)(0)), ((float)(0+height)),
    (fU2), (fV1), ((float)(0+width)), ((float)(0)),
    (fU2), (fV2), ((float)(0+width)), ((float)(0+height)),
  };
  glEnableClientState(GL_VERTEX_ARRAY); if(harm_Enable_TexCoord) glEnableClientState(GL_TEXTURE_COORD_ARRAY); if(harm_Enable_TexCoord) glTexCoordPointer(harm_TexCoord_Size, GL_FLOAT, harm_TexCoord_Stride * sizeof(GLfloat), harm_Data); glVertexPointer(harm_Vertex_Size, GL_FLOAT, harm_Enable_TexCoord ? harm_Vertex_Stride * sizeof(GLfloat) : 0, harm_Data + (harm_Enable_TexCoord ? harm_TexCoord_Size : 0)); glDrawArrays(harm_Render_Type, 0, harm_Vertex_Count); glDisableClientState(GL_VERTEX_ARRAY); if(harm_Enable_TexCoord) glDisableClientState(GL_TEXTURE_COORD_ARRAY); }
}

void gld_DrawLine(int x0, int y0, int x1, int y1, int BaseColor)
{
  const unsigned char *playpal=W_CacheLumpName("PLAYPAL");

  glBindTexture(GL_TEXTURE_2D, 0);
  last_gltexture = ((void *)0);
  last_cm = -1;
  glColor4f((float)playpal[3*BaseColor]/255.0f, (float)playpal[3*BaseColor+1]/255.0f, (float)playpal[3*BaseColor+2]/255.0f, 1.0)

                                                 ;
  { GLenum harm_Render_Type = GL_LINES; GLint harm_Vertex_Size = 2; GLsizei harm_Vertex_Stride = 4; GLint harm_TexCoord_Size = 2; GLsizei harm_TexCoord_Stride = 4; GLint harm_Vertex_Count = 4; GLboolean harm_Enable_TexCoord = GL_TRUE;
  harm_Enable_TexCoord = GL_FALSE;
  harm_Vertex_Count = 2;
  GLfloat harm_Data[] = {
    (GLfloat)(x0), (GLfloat)(y0),
    (GLfloat)(x1), (GLfloat)(y1),
  };
  glEnableClientState(GL_VERTEX_ARRAY); if(harm_Enable_TexCoord) glEnableClientState(GL_TEXTURE_COORD_ARRAY); if(harm_Enable_TexCoord) glTexCoordPointer(harm_TexCoord_Size, GL_FLOAT, harm_TexCoord_Stride * sizeof(GLfloat), harm_Data); glVertexPointer(harm_Vertex_Size, GL_FLOAT, harm_Enable_TexCoord ? harm_Vertex_Stride * sizeof(GLfloat) : 0, harm_Data + (harm_Enable_TexCoord ? harm_TexCoord_Size : 0)); glDrawArrays(harm_Render_Type, 0, harm_Vertex_Count); glDisableClientState(GL_VERTEX_ARRAY); if(harm_Enable_TexCoord) glDisableClientState(GL_TEXTURE_COORD_ARRAY); }
  W_UnlockLumpName("PLAYPAL");
}

void gld_DrawWeapon(int weaponlump, vissprite_t *vis, int lightlevel)
{
  GLTexture *gltexture;
  float fU1,fU2,fV1,fV2;
  int x1,y1,x2,y2;
  float scale;
  float light;

  gltexture=gld_RegisterPatch(firstspritelump+weaponlump, CR_DEFAULT);
  if (!gltexture)
    return;
  gld_BindPatch(gltexture, CR_DEFAULT);
  fU1=0;
  fV1=0;
  fU2=(float)gltexture->width/(float)gltexture->tex_width;
  fV2=(float)gltexture->height/(float)gltexture->tex_height;
  x1=viewwindowx+vis->x1;
  x2=viewwindowx+vis->x2;
  scale=((float)vis->scale/(float)FRACUNIT);
  y1=viewwindowy+centery-(int)(((float)vis->texturemid/(float)FRACUNIT)*scale);
  y2=y1+(int)((float)gltexture->realtexheight*scale)+1;
  light=(lighttable[usegamma][MAX(MIN((lightlevel),255),0)]);

  if (viewplayer->mo->flags & MF_SHADOW)
  {
    glBlendFunc(GL_DST_COLOR, GL_ONE_MINUS_SRC_ALPHA);
    glAlphaFunc(GL_GEQUAL,0.1f);

    glColor4f(0.2f,0.2f,0.2f,0.33f);
  }
  else
  {
    if (viewplayer->mo->flags & MF_TRANSLUCENT)
      gld_StaticLightAlpha(light,(float)tran_filter_pct/100.0f);
    else
      gld_StaticLightAlpha(light, 1.0f);
  }
  { GLenum harm_Render_Type = GL_TRIANGLE_STRIP; GLint harm_Vertex_Size = 2; GLsizei harm_Vertex_Stride = 4; GLint harm_TexCoord_Size = 2; GLsizei harm_TexCoord_Stride = 4; GLint harm_Vertex_Count = 4; GLboolean harm_Enable_TexCoord = GL_TRUE;
  GLfloat harm_Data[] = {
    (fU1), (fV1), ((float)(x1)), ((float)(y1)),
    (fU1), (fV2), ((float)(x1)), ((float)(y2)),
    (fU2), (fV1), ((float)(x2)), ((float)(y1)),
    (fU2), (fV2), ((float)(x2)), ((float)(y2)),
  };
  glEnableClientState(GL_VERTEX_ARRAY); if(harm_Enable_TexCoord) glEnableClientState(GL_TEXTURE_COORD_ARRAY); if(harm_Enable_TexCoord) glTexCoordPointer(harm_TexCoord_Size, GL_FLOAT, harm_TexCoord_Stride * sizeof(GLfloat), harm_Data); glVertexPointer(harm_Vertex_Size, GL_FLOAT, harm_Enable_TexCoord ? harm_Vertex_Stride * sizeof(GLfloat) : 0, harm_Data + (harm_Enable_TexCoord ? harm_TexCoord_Size : 0)); glDrawArrays(harm_Render_Type, 0, harm_Vertex_Count); glDisableClientState(GL_VERTEX_ARRAY); if(harm_Enable_TexCoord) glDisableClientState(GL_TEXTURE_COORD_ARRAY); }
  if(viewplayer->mo->flags & MF_SHADOW)
  {
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glAlphaFunc(GL_GEQUAL,0.5f);
  }
  glColor4f(1.0f, 1.0f, 1.0f, 1.0);
}

void gld_FillBlock(int x, int y, int width, int height, int col)
{
  const unsigned char *playpal=W_CacheLumpName("PLAYPAL");

  glBindTexture(GL_TEXTURE_2D, 0);
  last_gltexture = ((void *)0);
  last_cm = -1;
  glColor4f((float)playpal[3*col]/255.0f, (float)playpal[3*col+1]/255.0f, (float)playpal[3*col+2]/255.0f, 1.0)

                                           ;
  { GLenum harm_Render_Type = GL_TRIANGLE_STRIP; GLint harm_Vertex_Size = 2; GLsizei harm_Vertex_Stride = 4; GLint harm_TexCoord_Size = 2; GLsizei harm_TexCoord_Stride = 4; GLint harm_Vertex_Count = 4; GLboolean harm_Enable_TexCoord = GL_TRUE;
  harm_Enable_TexCoord = GL_FALSE;
  GLfloat harm_Data[] = {
    (GLfloat)(x), (GLfloat)(y),
    (GLfloat)(x), (GLfloat)(y+height),
    (GLfloat)(x+width), (GLfloat)(y),
    (GLfloat)(x+width), (GLfloat)(y+height),
  };
  glEnableClientState(GL_VERTEX_ARRAY); if(harm_Enable_TexCoord) glEnableClientState(GL_TEXTURE_COORD_ARRAY); if(harm_Enable_TexCoord) glTexCoordPointer(harm_TexCoord_Size, GL_FLOAT, harm_TexCoord_Stride * sizeof(GLfloat), harm_Data); glVertexPointer(harm_Vertex_Size, GL_FLOAT, harm_Enable_TexCoord ? harm_Vertex_Stride * sizeof(GLfloat) : 0, harm_Data + (harm_Enable_TexCoord ? harm_TexCoord_Size : 0)); glDrawArrays(harm_Render_Type, 0, harm_Vertex_Count); glDisableClientState(GL_VERTEX_ARRAY); if(harm_Enable_TexCoord) glDisableClientState(GL_TEXTURE_COORD_ARRAY); }
  glColor4f(1.0f, 1.0f, 1.0f, 1.0);
  W_UnlockLumpName("PLAYPAL");
}

void gld_SetPalette(int palette)
{
  static int last_palette = 0;
  extra_red=0.0f;
  extra_green=0.0f;
  extra_blue=0.0f;
  extra_alpha=0.0f;
  if (palette < 0)
    palette = last_palette;
  last_palette = palette;
  if (gl_shared_texture_palette) {
    const unsigned char *playpal;
    unsigned char pal[1024];
    int i;

    playpal = W_CacheLumpName("PLAYPAL");
    playpal += (768*palette);
    for (i=0; i<256; i++) {
      int col;

      if (fixedcolormap)
        col = fixedcolormap[i];
      else if (fullcolormap)
        col = fullcolormap[i];
      else
        col = i;
      pal[i*4+0] = playpal[col*3+0];
      pal[i*4+1] = playpal[col*3+1];
      pal[i*4+2] = playpal[col*3+2];
      pal[i*4+3] = 255;
    }
    pal[transparent_pal_index*4+0]=0;
    pal[transparent_pal_index*4+1]=0;
    pal[transparent_pal_index*4+2]=0;
    pal[transparent_pal_index*4+3]=0;



    W_UnlockLumpName("PLAYPAL");
  } else {
    if (palette>0)
    {
      if (palette<=8)
      {
        extra_red=(float)palette/2.0f;
        extra_green=0.0f;
        extra_blue=0.0f;
        extra_alpha=(float)palette/10.0f;
      }
      else
        if (palette<=12)
        {
          palette=palette-8;
          extra_red=(float)palette*1.0f;
          extra_green=(float)palette*0.8f;
          extra_blue=(float)palette*0.1f;
          extra_alpha=(float)palette/11.0f;
        }
        else
          if (palette==13)
          {
            extra_red=0.4f;
            extra_green=1.0f;
            extra_blue=0.0f;
            extra_alpha=0.2f;
          }
    }
    if (extra_red>1.0f)
      extra_red=1.0f;
    if (extra_green>1.0f)
      extra_green=1.0f;
    if (extra_blue>1.0f)
      extra_blue=1.0f;
    if (extra_alpha>1.0f)
      extra_alpha=1.0f;
  }
}

unsigned char *gld_ReadScreen(void)
{
  unsigned char *scr;
  unsigned char buffer[MAX_SCREENWIDTH*3];
  int i;

  scr = Z_Malloc(SCREENWIDTH * SCREENHEIGHT * 3,PU_STATIC,0);
  if (scr) {
    glReadPixels(0,0,SCREENWIDTH,SCREENHEIGHT,GL_RGB,GL_UNSIGNED_BYTE,scr);
    for (i=0; i<SCREENHEIGHT/2; i++) {
      memcpy(buffer, &scr[i*SCREENWIDTH*3], SCREENWIDTH*3);
      memcpy(&scr[i*SCREENWIDTH*3],
          &scr[(SCREENHEIGHT-(i+1))*SCREENWIDTH*3], SCREENWIDTH*3);
      memcpy(&scr[(SCREENHEIGHT-(i+1))*SCREENWIDTH*3], buffer, SCREENWIDTH*3);
    }
  }
  return scr;
}

GLvoid gld_Set2DMode(void)
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrthof(
    (GLdouble) 0,
    (GLdouble) SCREENWIDTH,
    (GLdouble) SCREENHEIGHT,
    (GLdouble) 0,
    (GLdouble) -1.0,
    (GLdouble) 1.0
  );
  glDisable(GL_DEPTH_TEST);
}

void gld_InitDrawScene(void)
{
}

void gld_Finish(void)
{
  gld_Set2DMode();
  glFinish();
  SDL_GL_SwapBuffers();
}







typedef struct
{
  GLfloat x;
  GLfloat y;
  GLfloat z;
} GLVertex;

typedef struct
{
  GLfloat u;
  GLfloat v;
} GLTexcoord;

int gld_max_vertexes=0;
int gld_num_vertexes=0;
GLVertex *gld_vertexes=((void *)0);
GLTexcoord *gld_texcoords=((void *)0);

static void gld_AddGlobalVertexes(int count)
{
  if ((gld_num_vertexes+count)>=gld_max_vertexes)
  {
    gld_max_vertexes+=count+1024;
    gld_vertexes=Z_Realloc(gld_vertexes,gld_max_vertexes*sizeof(GLVertex),PU_LEVEL,0);
    gld_texcoords=Z_Realloc(gld_texcoords,gld_max_vertexes*sizeof(GLTexcoord),PU_LEVEL,0);
  }
}





typedef struct
{
  GLenum mode;
  int vertexcount;
  int vertexindex;
} GLLoopDef;



typedef struct
{
  int loopcount;
  GLLoopDef *loops;
} GLSector;

typedef struct
{
  GLLoopDef loop;
} GLSubSector;

typedef struct
{
  float x1,x2;
  float z1,z2;
} GLSeg;

GLSeg *gl_segs=((void *)0);
# 846 "gl_main.c"
typedef struct
{
  GLSeg *glseg;
  float ytop,ybottom;
  float ul,ur,vt,vb;
  float light;
  float alpha;
  float skyymid;
  float skyyaw;
  GLTexture *gltexture;
  byte flag;
} GLWall;

typedef struct
{
  int sectornum;
  float light;
  float uoffs,voffs;
  float z;
  GLTexture *gltexture;
  boolean ceiling;
} GLFlat;

typedef struct
{
  int cm;
  float x,y,z;
  float vt,vb;
  float ul,ur;
  float x1,y1;
  float x2,y2;
  float light;
  fixed_t scale;
  GLTexture *gltexture;
  boolean shadow;
  boolean trans;
} GLSprite;

typedef enum
{
  GLDIT_NONE,
  GLDIT_WALL,
  GLDIT_FLAT,
  GLDIT_SPRITE
} GLDrawItemType;

typedef struct
{
  GLDrawItemType itemtype;
  int itemcount;
  int firstitemindex;
  byte rendermarker;
} GLDrawItem;

typedef struct
{
  GLWall *walls;
  int num_walls;
  int max_walls;
  GLFlat *flats;
  int num_flats;
  int max_flats;
  GLSprite *sprites;
  int num_sprites;
  int max_sprites;
  GLDrawItem *drawitems;
  int num_drawitems;
  int max_drawitems;
} GLDrawInfo;

static GLDrawInfo gld_drawinfo;


static GLSector *sectorloops;

byte rendermarker=0;
static byte *sectorrendered;
static byte *segrendered;

static FILE *levelinfo;
# 941 "gl_main.c"
static boolean gld_PointOnSide(vertex_t *p, divline_t *d)
{

  return ((((double)(d->y))-((double)(p->y)))*((double)(d->dx))-(((double)(d->x))-((double)(p->x)))*((double)(d->dy)) >= 0);
}


static void gld_CalcIntersectionVertex(vertex_t *s, vertex_t *e, divline_t *d, vertex_t *i)
{
  double ax = ((double)(s->x)), ay = ((double)(s->y)), bx = ((double)(e->x)), by = ((double)(e->y));
  double cx = ((double)(d->x)), cy = ((double)(d->y)), dx = cx+((double)(d->dx)), dy = cy+((double)(d->dy));
  double r = ((ay-cy)*(dx-cx)-(ax-cx)*(dy-cy)) / ((bx-ax)*(dy-cy)-(by-ay)*(dx-cx));
  i->x = (fixed_t)((double)s->x + r*((double)e->x-(double)s->x));
  i->y = (fixed_t)((double)s->y + r*((double)e->y-(double)s->y));
}





static vertex_t *gld_FlatEdgeClipper(int *numpoints, vertex_t *points, int numclippers, divline_t *clippers)
{
  unsigned char sidelist[64];
  int i, k, num = *numpoints;



  for(i=0; i<numclippers; i++)
  {
    divline_t *curclip = &clippers[i];



    for(k=0; k<num; k++)
      sidelist[k] = gld_PointOnSide(&points[k], curclip);

    for(k=0; k<num; k++)
    {
      int startIdx = k, endIdx = k+1;

      if(endIdx == num) endIdx = 0;

      if(sidelist[startIdx] != sidelist[endIdx])
      {
        vertex_t newvert;

        gld_CalcIntersectionVertex(&points[startIdx], &points[endIdx], curclip, &newvert);


        points = (vertex_t*)Z_Realloc(points,(++num)*sizeof(vertex_t),PU_LEVEL,0);
        if(num >= 64)
          I_Error("gld_FlatEdgeClipper: Too many points in carver");


        memmove(&points[endIdx+1], &points[endIdx],
          (num - endIdx-1)*sizeof(vertex_t));
        memcpy(&points[endIdx], &newvert, sizeof(newvert));

        memmove(&sidelist[endIdx+1], &sidelist[endIdx], num-endIdx-1);
        sidelist[endIdx] = 1;


        k++;
      }
    }


    for(k=0; k<num; k++)
      if(!sidelist[k])
      {
        memmove(&points[k], &points[k+1], (num - k-1)*sizeof(vertex_t));
        memmove(&sidelist[k], &sidelist[k+1], num - k-1);
        num--;
        k--;
      }
  }

  for(i=0; i<num; i++)
  {
    int previdx = i-1;
    if(previdx < 0) previdx = num - 1;
    if(points[i].x == points[previdx].x
      && points[i].y == points[previdx].y)
    {

      memmove(&points[i], &points[i+1], sizeof(vertex_t)*(num-i-1));
      num--;
      i--;
    }
  }
  *numpoints = num;
  return points;
}

static void gld_FlatConvexCarver(int ssidx, int num, divline_t *list)
{
  subsector_t *ssec=&subsectors[ssidx];
  int numclippers = num+ssec->numlines;
  divline_t *clippers;
  int i, numedgepoints;
  vertex_t *edgepoints;

  clippers=(divline_t*)Z_Malloc(numclippers*sizeof(divline_t),PU_LEVEL,0);
  if (!clippers)
    return;
  for(i=0; i<num; i++)
  {
    clippers[i].x = list[num-i-1].x;
    clippers[i].y = list[num-i-1].y;
    clippers[i].dx = list[num-i-1].dx;
    clippers[i].dy = list[num-i-1].dy;
  }
  for(i=num; i<numclippers; i++)
  {
    seg_t *seg = &segs[ssec->firstline+i-num];
    clippers[i].x = seg->v1->x;
    clippers[i].y = seg->v1->y;
    clippers[i].dx = seg->v2->x-seg->v1->x;
    clippers[i].dy = seg->v2->y-seg->v1->y;
  }


  numedgepoints = 4;
  edgepoints = (vertex_t*)Z_Malloc(numedgepoints*sizeof(vertex_t),PU_LEVEL,0);

  edgepoints[0].x = INT_MIN;
  edgepoints[0].y = INT_MAX;

  edgepoints[1].x = INT_MAX;
  edgepoints[1].y = INT_MAX;

  edgepoints[2].x = INT_MAX;
  edgepoints[2].y = INT_MIN;

  edgepoints[3].x = INT_MIN;
  edgepoints[3].y = INT_MIN;


  edgepoints = gld_FlatEdgeClipper(&numedgepoints, edgepoints, numclippers, clippers);

  if(!numedgepoints)
  {
    if (levelinfo) fprintf(levelinfo, "All carved away: subsector %i - sector %i\n", ssec-subsectors, ssec->sector->iSectorID);
  }
  else
  {
    if(numedgepoints >= 3)
    {
      gld_AddGlobalVertexes(numedgepoints);
      if ((gld_vertexes) && (gld_texcoords))
      {
        int currentsector=ssec->sector->iSectorID;

        sectorloops[ currentsector ].loopcount++;
        sectorloops[ currentsector ].loops=Z_Realloc(sectorloops[currentsector].loops,sizeof(GLLoopDef)*sectorloops[currentsector].loopcount, PU_LEVEL, 0);
        sectorloops[ currentsector ].loops[ sectorloops[currentsector].loopcount-1 ].mode=GL_TRIANGLE_FAN;
        sectorloops[ currentsector ].loops[ sectorloops[currentsector].loopcount-1 ].vertexcount=numedgepoints;
        sectorloops[ currentsector ].loops[ sectorloops[currentsector].loopcount-1 ].vertexindex=gld_num_vertexes;

        for(i = 0; i < numedgepoints; i++)
        {
          gld_texcoords[gld_num_vertexes].u = ( (float)edgepoints[i].x/(float)FRACUNIT)/64.0f;
          gld_texcoords[gld_num_vertexes].v = (-(float)edgepoints[i].y/(float)FRACUNIT)/64.0f;
          gld_vertexes[gld_num_vertexes].x = -(float)edgepoints[i].x/(128.0f*(float)FRACUNIT);
          gld_vertexes[gld_num_vertexes].y = 0.0f;
          gld_vertexes[gld_num_vertexes].z = (float)edgepoints[i].y/(128.0f*(float)FRACUNIT);
          gld_num_vertexes++;
        }
      }
    }
  }

  Z_Free(edgepoints);
  Z_Free(clippers);
}

static void gld_CarveFlats(int bspnode, int numdivlines, divline_t *divlines, boolean *sectorclosed)
{
  node_t *nod;
  divline_t *childlist, *dl;
  int childlistsize = numdivlines+1;



  if(bspnode & NF_SUBSECTOR)
  {



    int ssidx = (numnodes != 0) ? bspnode & (~NF_SUBSECTOR) : 0;

    if (!sectorclosed[subsectors[ssidx].sector->iSectorID])
      gld_FlatConvexCarver(ssidx, numdivlines, divlines);
    return;
  }


  nod = nodes + bspnode;


  childlist = (divline_t*)Z_Malloc(childlistsize*sizeof(divline_t),PU_LEVEL,0);


  if(divlines) memcpy(childlist,divlines,numdivlines*sizeof(divline_t));

  dl = childlist + numdivlines;
  dl->x = nod->x;
  dl->y = nod->y;

  dl->dx = nod->dx;
  dl->dy = nod->dy;
  gld_CarveFlats(nod->children[0],childlistsize,childlist,sectorclosed);



  dl->dx = -nod->dx;
  dl->dy = -nod->dy;
  gld_CarveFlats(nod->children[1],childlistsize,childlist,sectorclosed);


  Z_Free(childlist);
}
# 1510 "gl_main.c"
void gld_GetSubSectorVertices(boolean *sectorclosed)
{
  int i, j;
  int numedgepoints;
  subsector_t* ssector;

  for(i = 0; i < numsubsectors; i++)
  {
    ssector = &subsectors[i];

    if (sectorclosed[ssector->sector->iSectorID])
      continue;

    numedgepoints = ssector->numlines;

    gld_AddGlobalVertexes(numedgepoints);

    if ((gld_vertexes) && (gld_texcoords))
    {
      int currentsector = ssector->sector->iSectorID;

      sectorloops[currentsector].loopcount++;
      sectorloops[currentsector].loops = Z_Realloc(sectorloops[currentsector].loops,sizeof(GLLoopDef)*sectorloops[currentsector].loopcount, PU_LEVEL, 0);
      sectorloops[currentsector].loops[sectorloops[currentsector].loopcount-1].mode = GL_TRIANGLE_FAN;
      sectorloops[currentsector].loops[sectorloops[currentsector].loopcount-1].vertexcount = numedgepoints;
      sectorloops[currentsector].loops[sectorloops[currentsector].loopcount-1].vertexindex = gld_num_vertexes;
      for(j = 0; j < numedgepoints; j++)
      {
        gld_texcoords[gld_num_vertexes].u =( (float)(segs[ssector->firstline + j].v1->x)/FRACUNIT)/64.0f;
        gld_texcoords[gld_num_vertexes].v =(-(float)(segs[ssector->firstline + j].v1->y)/FRACUNIT)/64.0f;
        gld_vertexes[gld_num_vertexes].x = -(float)(segs[ssector->firstline + j].v1->x)/(128.0f*(float)FRACUNIT);
        gld_vertexes[gld_num_vertexes].y = 0.0f;
        gld_vertexes[gld_num_vertexes].z = (float)(segs[ssector->firstline + j].v1->y)/(128.0f*(float)FRACUNIT);
        gld_num_vertexes++;
      }
    }
  }
}

static void gld_PrepareSectorSpecialEffects(int num)
{
  int i;


  sectors[num].no_toptextures=true;
  sectors[num].no_bottomtextures=true;
  for (i=0; i<sectors[num].linecount; i++)
  {
    if ( (sectors[num].lines[i]->sidenum[0]!=NO_INDEX) &&
         (sectors[num].lines[i]->sidenum[1]!=NO_INDEX) )
    {
      if (sides[sectors[num].lines[i]->sidenum[0]].toptexture!=NO_TEXTURE)
        sectors[num].no_toptextures=false;
      if (sides[sectors[num].lines[i]->sidenum[0]].bottomtexture!=NO_TEXTURE)
        sectors[num].no_bottomtextures=false;
      if (sides[sectors[num].lines[i]->sidenum[1]].toptexture!=NO_TEXTURE)
        sectors[num].no_toptextures=false;
      if (sides[sectors[num].lines[i]->sidenum[1]].bottomtexture!=NO_TEXTURE)
        sectors[num].no_bottomtextures=false;
    }
    else
    {
      sectors[num].no_toptextures=false;
      sectors[num].no_bottomtextures=false;
    }
  }






}
# 1606 "gl_main.c"
void gld_PreprocessSectors(void)
{
  boolean *sectorclosed;
  int i;
# 1628 "gl_main.c"
  sectorclosed=Z_Malloc(numsectors*sizeof(boolean),PU_LEVEL,0);
  if (!sectorclosed)
    I_Error("gld_PreprocessSectors: Not enough memory for array sectorclosed");
  memset(sectorclosed, 0, sizeof(boolean)*numsectors);

  sectorloops=Z_Malloc(sizeof(GLSector)*numsectors,PU_LEVEL,0);
  if (!sectorloops)
    I_Error("gld_PreprocessSectors: Not enough memory for array sectorloops");
  memset(sectorloops, 0, sizeof(GLSector)*numsectors);

  sectorrendered=Z_Malloc(numsectors*sizeof(byte),PU_LEVEL,0);
  if (!sectorrendered)
    I_Error("gld_PreprocessSectors: Not enough memory for array sectorrendered");
  memset(sectorrendered, 0, numsectors*sizeof(byte));

  segrendered=Z_Malloc(numsegs*sizeof(byte),PU_LEVEL,0);
  if (!segrendered)
    I_Error("gld_PreprocessSectors: Not enough memory for array segrendered");
  memset(segrendered, 0, numsegs*sizeof(byte));

  gld_vertexes=((void *)0);
  gld_texcoords=((void *)0);
  gld_max_vertexes=0;
  gld_num_vertexes=0;
  gld_AddGlobalVertexes(numvertexes*2);
# 1715 "gl_main.c"
  for (i=0; i<numsectors; i++)
    gld_PrepareSectorSpecialEffects(i);


  if (nodesVersion == 0)
    gld_CarveFlats(numnodes-1, 0, 0, sectorclosed);
  else
    gld_GetSubSectorVertices(sectorclosed);

  if (levelinfo) fclose(levelinfo);
  Z_Free(sectorclosed);
}

static float roll = 0.0f;
static float yaw = 0.0f;
static float inv_yaw = 0.0f;
static float pitch = 0.0f;



static void infinitePerspective(GLdouble fovy, GLdouble aspect, GLdouble znear)
{
 GLdouble left, right, bottom, top;
 GLdouble m[16];

 top = znear * tan(fovy * 3.14159265358979323846 / 360.0);
 bottom = -top;
 left = bottom * aspect;
 right = top * aspect;



 m[ 0] = (2 * znear) / (right - left);
 m[ 4] = 0;
 m[ 8] = (right + left) / (right - left);
 m[12] = 0;

 m[ 1] = 0;
 m[ 5] = (2 * znear) / (top - bottom);
 m[ 9] = (top + bottom) / (top - bottom);
 m[13] = 0;

 m[ 2] = 0;
 m[ 6] = 0;


 m[10] = -1;
 m[14] = -2 * znear;

 m[ 3] = 0;
 m[ 7] = 0;
 m[11] = -1;
 m[15] = 0;

 glMultMatrixf(m);
}

void gld_StartDrawScene(void)
{
  float trY ;
  float xCamera,yCamera;

  extern int screenblocks;
  int height;





  gld_SetPalette(-1);

  if (screenblocks == 11)
    height = SCREENHEIGHT;
  else if (screenblocks == 10)
    height = SCREENHEIGHT;
  else
    height = (screenblocks*SCREENHEIGHT/10) & ~7;

  glViewport(viewwindowx, SCREENHEIGHT-(height+viewwindowy-((height-viewheight)/2)), viewwidth, height);
  glScissor(viewwindowx, SCREENHEIGHT-(viewheight+viewwindowy), viewwidth, viewheight);
  glEnable(GL_SCISSOR_TEST);

  xCamera=-(float)viewx/(128.0f*(float)FRACUNIT);
  yCamera=(float)viewy/(128.0f*(float)FRACUNIT);
  trY=(float)viewz/(128.0f*(float)FRACUNIT);

  yaw=270.0f-(float)(viewangle>>ANGLETOFINESHIFT)*360.0f/FINEANGLES;
  inv_yaw=-90.0f+(float)(viewangle>>ANGLETOFINESHIFT)*360.0f/FINEANGLES;




  glClear(GL_DEPTH_BUFFER_BIT);


  glEnable(GL_DEPTH_TEST);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  infinitePerspective(64.0f, 320.0f/200.0f, (float)gl_nearclip/100.0f);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glRotatef(roll, 0.0f, 0.0f, 1.0f);
  glRotatef(pitch, 1.0f, 0.0f, 0.0f);
  glRotatef(yaw, 0.0f, 1.0f, 0.0f);
  glTranslatef(-xCamera, -trY, -yCamera);

  if (use_fog)
    glEnable(GL_FOG);
  else
    glDisable(GL_FOG);
  rendermarker++;
  gld_drawinfo.num_walls=0;
  gld_drawinfo.num_flats=0;
  gld_drawinfo.num_sprites=0;
  gld_drawinfo.num_drawitems=0;
}

void gld_EndDrawScene(void)
{
  player_t *player = &players[displayplayer];





  glViewport(0, 0, SCREENWIDTH, SCREENHEIGHT);
  glDisable(GL_FOG);
  gld_Set2DMode();

  if (viewangleoffset <= 1024<<ANGLETOFINESHIFT ||
    viewangleoffset >=-1024<<ANGLETOFINESHIFT)
  {
    R_DrawPlayerSprites();
  }
  if (player->fixedcolormap == 32) {
  glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO);
  glColor4f(1,1,1,1);
    glBindTexture(GL_TEXTURE_2D, 0);
    last_gltexture = ((void *)0);
    last_cm = -1;
    { GLenum harm_Render_Type = GL_TRIANGLE_STRIP; GLint harm_Vertex_Size = 2; GLsizei harm_Vertex_Stride = 4; GLint harm_TexCoord_Size = 2; GLsizei harm_TexCoord_Stride = 4; GLint harm_Vertex_Count = 4; GLboolean harm_Enable_TexCoord = GL_TRUE;
   harm_Enable_TexCoord = GL_FALSE;
   GLfloat harm_Data[] = {
    (0.0f), (0.0f),
    (0.0f), ((float)SCREENHEIGHT),
    ((float)SCREENWIDTH), (0.0f),
    ((float)SCREENWIDTH), ((float)SCREENHEIGHT),
   };
    glEnableClientState(GL_VERTEX_ARRAY); if(harm_Enable_TexCoord) glEnableClientState(GL_TEXTURE_COORD_ARRAY); if(harm_Enable_TexCoord) glTexCoordPointer(harm_TexCoord_Size, GL_FLOAT, harm_TexCoord_Stride * sizeof(GLfloat), harm_Data); glVertexPointer(harm_Vertex_Size, GL_FLOAT, harm_Enable_TexCoord ? harm_Vertex_Stride * sizeof(GLfloat) : 0, harm_Data + (harm_Enable_TexCoord ? harm_TexCoord_Size : 0)); glDrawArrays(harm_Render_Type, 0, harm_Vertex_Count); glDisableClientState(GL_VERTEX_ARRAY); if(harm_Enable_TexCoord) glDisableClientState(GL_TEXTURE_COORD_ARRAY); }
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  }
  if (extra_alpha>0.0f)
  {
    glDisable(GL_ALPHA_TEST);
    glColor4f(extra_red, extra_green, extra_blue, extra_alpha);
    glBindTexture(GL_TEXTURE_2D, 0);
    last_gltexture = ((void *)0);
    last_cm = -1;
    { GLenum harm_Render_Type = GL_TRIANGLE_STRIP; GLint harm_Vertex_Size = 2; GLsizei harm_Vertex_Stride = 4; GLint harm_TexCoord_Size = 2; GLsizei harm_TexCoord_Stride = 4; GLint harm_Vertex_Count = 4; GLboolean harm_Enable_TexCoord = GL_TRUE;
   harm_Enable_TexCoord = GL_FALSE;
   GLfloat harm_Data[] = {
      (0.0f), (0.0f),
      (0.0f), ((float)SCREENHEIGHT),
      ((float)SCREENWIDTH), (0.0f),
      ((float)SCREENWIDTH), ((float)SCREENHEIGHT),
   };
    glEnableClientState(GL_VERTEX_ARRAY); if(harm_Enable_TexCoord) glEnableClientState(GL_TEXTURE_COORD_ARRAY); if(harm_Enable_TexCoord) glTexCoordPointer(harm_TexCoord_Size, GL_FLOAT, harm_TexCoord_Stride * sizeof(GLfloat), harm_Data); glVertexPointer(harm_Vertex_Size, GL_FLOAT, harm_Enable_TexCoord ? harm_Vertex_Stride * sizeof(GLfloat) : 0, harm_Data + (harm_Enable_TexCoord ? harm_TexCoord_Size : 0)); glDrawArrays(harm_Render_Type, 0, harm_Vertex_Count); glDisableClientState(GL_VERTEX_ARRAY); if(harm_Enable_TexCoord) glDisableClientState(GL_TEXTURE_COORD_ARRAY); }
    glEnable(GL_ALPHA_TEST);
  }

  glColor4f(1.0f, 1.0f, 1.0f, 1.0);
  glDisable(GL_SCISSOR_TEST);
  if (gl_shared_texture_palette)
    glDisable(GL_SHARED_TEXTURE_PALETTE_EXT);
}

static void gld_AddDrawItem(GLDrawItemType itemtype, int itemindex)
{
  if (gld_drawinfo.num_drawitems>=gld_drawinfo.max_drawitems)
  {
    gld_drawinfo.max_drawitems+=64;
    gld_drawinfo.drawitems=Z_Realloc(gld_drawinfo.drawitems,gld_drawinfo.max_drawitems*sizeof(GLDrawItem),PU_LEVEL,0);
    gld_drawinfo.drawitems[gld_drawinfo.num_drawitems].itemtype=itemtype;
    gld_drawinfo.drawitems[gld_drawinfo.num_drawitems].itemcount=1;
    gld_drawinfo.drawitems[gld_drawinfo.num_drawitems].firstitemindex=itemindex;
    gld_drawinfo.drawitems[gld_drawinfo.num_drawitems].rendermarker=rendermarker;
    return;
  }
  if (gld_drawinfo.drawitems[gld_drawinfo.num_drawitems].rendermarker!=rendermarker)
  {
    gld_drawinfo.drawitems[gld_drawinfo.num_drawitems].itemtype=GLDIT_NONE;
    gld_drawinfo.drawitems[gld_drawinfo.num_drawitems].rendermarker=rendermarker;
  }
  if (gld_drawinfo.drawitems[gld_drawinfo.num_drawitems].itemtype!=itemtype)
  {
    if (gld_drawinfo.drawitems[gld_drawinfo.num_drawitems].itemtype!=GLDIT_NONE)
      gld_drawinfo.num_drawitems++;
    if (gld_drawinfo.num_drawitems>=gld_drawinfo.max_drawitems)
    {
      gld_drawinfo.max_drawitems+=64;
      gld_drawinfo.drawitems=Z_Realloc(gld_drawinfo.drawitems,gld_drawinfo.max_drawitems*sizeof(GLDrawItem),PU_LEVEL,0);
    }
    gld_drawinfo.drawitems[gld_drawinfo.num_drawitems].itemtype=itemtype;
    gld_drawinfo.drawitems[gld_drawinfo.num_drawitems].itemcount=1;
    gld_drawinfo.drawitems[gld_drawinfo.num_drawitems].firstitemindex=itemindex;
    gld_drawinfo.drawitems[gld_drawinfo.num_drawitems].rendermarker=rendermarker;
    return;
  }
  gld_drawinfo.drawitems[gld_drawinfo.num_drawitems].itemcount++;
}







static void gld_DrawWall(GLWall *wall)
{
  if ( (!gl_drawskys) && (wall->flag>=5) )
    wall->gltexture=((void *)0);
  gld_BindTexture(wall->gltexture);
  if (!wall->gltexture)
  {



  }
  if (wall->flag>=5)
  {
    if ( wall->gltexture )
    {
      glMatrixMode(GL_TEXTURE);
      glPushMatrix();
      if ((wall->flag&6)==6)
        glScalef(-128.0f/(float)wall->gltexture->buffer_width,200.0f/320.0f*2.0f,1.0f);
      else
        glScalef(128.0f/(float)wall->gltexture->buffer_width,200.0f/320.0f*2.0f,1.0f);
      glTranslatef(wall->skyyaw,wall->skyymid,0.0f);
    }
    { GLenum harm_Render_Type = GL_TRIANGLE_STRIP; GLint harm_Vertex_Size = 2; GLsizei harm_Vertex_Stride = 4; GLint harm_TexCoord_Size = 2; GLsizei harm_TexCoord_Stride = 4; GLint harm_Vertex_Count = 4; GLboolean harm_Enable_TexCoord = GL_TRUE;
   harm_Enable_TexCoord = GL_FALSE;
   harm_Vertex_Size = 3;
   GLfloat harm_Data[] = {
      (wall->glseg->x1), (wall->ytop), (wall->glseg->z1),
      (wall->glseg->x1), (wall->ybottom), (wall->glseg->z1),
      (wall->glseg->x2), (wall->ytop), (wall->glseg->z2),
      (wall->glseg->x2), (wall->ybottom), (wall->glseg->z2),
   };
    glEnableClientState(GL_VERTEX_ARRAY); if(harm_Enable_TexCoord) glEnableClientState(GL_TEXTURE_COORD_ARRAY); if(harm_Enable_TexCoord) glTexCoordPointer(harm_TexCoord_Size, GL_FLOAT, harm_TexCoord_Stride * sizeof(GLfloat), harm_Data); glVertexPointer(harm_Vertex_Size, GL_FLOAT, harm_Enable_TexCoord ? harm_Vertex_Stride * sizeof(GLfloat) : 0, harm_Data + (harm_Enable_TexCoord ? harm_TexCoord_Size : 0)); glDrawArrays(harm_Render_Type, 0, harm_Vertex_Count); glDisableClientState(GL_VERTEX_ARRAY); if(harm_Enable_TexCoord) glDisableClientState(GL_TEXTURE_COORD_ARRAY); }
    if ( wall->gltexture )
    {
      glPopMatrix();
      glMatrixMode(GL_MODELVIEW);
    }
  }
  else
  {
    gld_StaticLightAlpha(wall->light, wall->alpha);
    { GLenum harm_Render_Type = GL_TRIANGLE_STRIP; GLint harm_Vertex_Size = 2; GLsizei harm_Vertex_Stride = 4; GLint harm_TexCoord_Size = 2; GLsizei harm_TexCoord_Stride = 4; GLint harm_Vertex_Count = 4; GLboolean harm_Enable_TexCoord = GL_TRUE;
   harm_Vertex_Size = 3;
   harm_Vertex_Stride = 5;
   harm_TexCoord_Stride = 5;
   GLfloat harm_Data[] = {
      (wall->ul), (wall->vt), (wall->glseg->x1), (wall->ytop), (wall->glseg->z1),
      (wall->ul), (wall->vb), (wall->glseg->x1), (wall->ybottom), (wall->glseg->z1),
      (wall->ur), (wall->vt), (wall->glseg->x2), (wall->ytop), (wall->glseg->z2),
      (wall->ur), (wall->vb), (wall->glseg->x2), (wall->ybottom), (wall->glseg->z2),
   };
    glEnableClientState(GL_VERTEX_ARRAY); if(harm_Enable_TexCoord) glEnableClientState(GL_TEXTURE_COORD_ARRAY); if(harm_Enable_TexCoord) glTexCoordPointer(harm_TexCoord_Size, GL_FLOAT, harm_TexCoord_Stride * sizeof(GLfloat), harm_Data); glVertexPointer(harm_Vertex_Size, GL_FLOAT, harm_Enable_TexCoord ? harm_Vertex_Stride * sizeof(GLfloat) : 0, harm_Data + (harm_Enable_TexCoord ? harm_TexCoord_Size : 0)); glDrawArrays(harm_Render_Type, 0, harm_Vertex_Count); glDisableClientState(GL_VERTEX_ARRAY); if(harm_Enable_TexCoord) glDisableClientState(GL_TEXTURE_COORD_ARRAY); }
  }
}
# 2095 "gl_main.c"
void gld_AddWall(seg_t *seg)
{
  GLWall wall;
  GLTexture *temptex;
  sector_t *frontsector;
  sector_t *backsector;
  sector_t ftempsec;
  sector_t btempsec;
  float lineheight;
  int rellight = 0;

  if (!segrendered)
    return;
  if (segrendered[seg->iSegID]==rendermarker)
    return;
  segrendered[seg->iSegID]=rendermarker;
  if (!seg->frontsector)
    return;
  frontsector=R_FakeFlat(seg->frontsector, &ftempsec, ((void *)0), ((void *)0), false);
  if (!frontsector)
    return;
  wall.glseg=&gl_segs[seg->iSegID];

  rellight = seg->linedef->dx==0? +8 : seg->linedef->dy==0 ? -8 : 0;
  wall.light=(lighttable[usegamma][MAX(MIN((frontsector->lightlevel+rellight+(extralight<<5)),255),0)]);
  wall.alpha=1.0f;
  wall.gltexture=((void *)0);

  if (!seg->backsector)
  {
    if (frontsector->ceilingpic==skyflatnum)
    {
      wall.ytop=255.0f;
      wall.ybottom=(float)frontsector->ceilingheight/(128.0f*(float)FRACUNIT);
      if ((frontsector->sky) & PL_SKYFLAT) { const line_t *l = &lines[frontsector->sky & ~PL_SKYFLAT]; const side_t *s = *l->sidenum + sides; wall.gltexture=gld_RegisterTexture(texturetranslation[s->toptexture], false, texturetranslation[s->toptexture]==skytexture); wall.skyyaw=-2.0f*((-(float)((viewangle+s->textureoffset)>>ANGLETOFINESHIFT)*360.0f/FINEANGLES)/90.0f); wall.skyymid = 200.0f/319.5f*(((float)s->rowoffset/(float)FRACUNIT - 28.0f)/100.0f); wall.flag = l->special==272 ? 5 : 6; } else if ((frontsector->sky) & PL_SKYFLAT) { const line_t *l = &lines[frontsector->sky & ~PL_SKYFLAT]; const side_t *s = *l->sidenum + sides; wall.gltexture=gld_RegisterTexture(texturetranslation[s->toptexture], false, texturetranslation[s->toptexture]==skytexture); wall.skyyaw=-2.0f*((-(float)((viewangle+s->textureoffset)>>ANGLETOFINESHIFT)*360.0f/FINEANGLES)/90.0f); wall.skyymid = 200.0f/319.5f*(((float)s->rowoffset/(float)FRACUNIT - 28.0f)/100.0f); wall.flag = l->special==272 ? 5 : 6; } else { wall.gltexture=gld_RegisterTexture(skytexture, false, true); wall.skyyaw=-2.0f*((yaw+90.0f)/90.0f); wall.skyymid = 200.0f/319.5f*((100.0f)/100.0f); wall.flag = 5; };;
      { if (gld_drawinfo.num_walls>=gld_drawinfo.max_walls) { gld_drawinfo.max_walls+=128; gld_drawinfo.walls=Z_Realloc(gld_drawinfo.walls,gld_drawinfo.max_walls*sizeof(GLWall),PU_LEVEL,0); } gld_AddDrawItem(GLDIT_WALL, gld_drawinfo.num_walls); gld_drawinfo.walls[gld_drawinfo.num_walls++]=*&wall;};;
    }
    if (frontsector->floorpic==skyflatnum)
    {
      wall.ytop=(float)frontsector->floorheight/(128.0f*(float)FRACUNIT);
      wall.ybottom=-255.0f;
      if ((frontsector->sky) & PL_SKYFLAT) { const line_t *l = &lines[frontsector->sky & ~PL_SKYFLAT]; const side_t *s = *l->sidenum + sides; wall.gltexture=gld_RegisterTexture(texturetranslation[s->toptexture], false, texturetranslation[s->toptexture]==skytexture); wall.skyyaw=-2.0f*((-(float)((viewangle+s->textureoffset)>>ANGLETOFINESHIFT)*360.0f/FINEANGLES)/90.0f); wall.skyymid = 200.0f/319.5f*(((float)s->rowoffset/(float)FRACUNIT - 28.0f)/100.0f); wall.flag = l->special==272 ? 5 : 6; } else if ((frontsector->sky) & PL_SKYFLAT) { const line_t *l = &lines[frontsector->sky & ~PL_SKYFLAT]; const side_t *s = *l->sidenum + sides; wall.gltexture=gld_RegisterTexture(texturetranslation[s->toptexture], false, texturetranslation[s->toptexture]==skytexture); wall.skyyaw=-2.0f*((-(float)((viewangle+s->textureoffset)>>ANGLETOFINESHIFT)*360.0f/FINEANGLES)/90.0f); wall.skyymid = 200.0f/319.5f*(((float)s->rowoffset/(float)FRACUNIT - 28.0f)/100.0f); wall.flag = l->special==272 ? 5 : 6; } else { wall.gltexture=gld_RegisterTexture(skytexture, false, true); wall.skyyaw=-2.0f*((yaw+90.0f)/90.0f); wall.skyymid = 200.0f/319.5f*((100.0f)/100.0f); wall.flag = 5; };;
      { if (gld_drawinfo.num_walls>=gld_drawinfo.max_walls) { gld_drawinfo.max_walls+=128; gld_drawinfo.walls=Z_Realloc(gld_drawinfo.walls,gld_drawinfo.max_walls*sizeof(GLWall),PU_LEVEL,0); } gld_AddDrawItem(GLDIT_WALL, gld_drawinfo.num_walls); gld_drawinfo.walls[gld_drawinfo.num_walls++]=*&wall;};;
    }
    temptex=gld_RegisterTexture(texturetranslation[seg->sidedef->midtexture], true, false);
    if (temptex)
    {
      wall.gltexture=temptex;
      (wall).ytop=((float)(frontsector->ceilingheight)/(float)(128.0f*(float)FRACUNIT))+0.001f; (wall).ybottom=((float)(frontsector->floorheight)/(float)(128.0f*(float)FRACUNIT))-0.001f; lineheight=((float)fabs(((frontsector->ceilingheight)/(float)FRACUNIT)-((frontsector->floorheight)/(float)FRACUNIT)));
      (wall).flag=2; (wall).ul=(((float)(((seg))->sidedef->textureoffset+((seg))->offset)/(float)FRACUNIT)/(float)((wall)).gltexture->buffer_width)+(0.0f); (wall).ur=(((float)(((seg))->sidedef->textureoffset+((seg))->offset)/(float)FRACUNIT)/(float)((wall)).gltexture->buffer_width)+((segs[seg->iSegID].length)/(float)(wall).gltexture->buffer_width); ((seg->linedef->flags & ML_DONTPEGBOTTOM)>0)? ( (wall).vb=(((float)(((seg))->sidedef->rowoffset)/(float)FRACUNIT)/(float)((wall)).gltexture->buffer_height)+((float)(wall).gltexture->height/(float)(wall).gltexture->tex_height), (wall).vt=((wall).vb-((float)(lineheight)/(float)(wall).gltexture->buffer_height)) ):( (wall).vt=(((float)(((seg))->sidedef->rowoffset)/(float)FRACUNIT)/(float)((wall)).gltexture->buffer_height)+(0.0f), (wall).vb=(((float)(((seg))->sidedef->rowoffset)/(float)FRACUNIT)/(float)((wall)).gltexture->buffer_height)+((float)(lineheight)/(float)(wall).gltexture->buffer_height) )


       ;
      { if (gld_drawinfo.num_walls>=gld_drawinfo.max_walls) { gld_drawinfo.max_walls+=128; gld_drawinfo.walls=Z_Realloc(gld_drawinfo.walls,gld_drawinfo.max_walls*sizeof(GLWall),PU_LEVEL,0); } gld_AddDrawItem(GLDIT_WALL, gld_drawinfo.num_walls); gld_drawinfo.walls[gld_drawinfo.num_walls++]=*&wall;};;
    }
  }
  else
  {
    int floor_height,ceiling_height;

    backsector=R_FakeFlat(seg->backsector, &btempsec, ((void *)0), ((void *)0), true);
    if (!backsector)
      return;

    ceiling_height=frontsector->ceilingheight;
    floor_height=backsector->ceilingheight;
    if (frontsector->ceilingpic==skyflatnum)
    {
      wall.ytop=255.0f;
      if (



          (backsector->ceilingheight==backsector->floorheight||(backsector->ceilingheight<=frontsector->floorheight)) &&
          (backsector->ceilingpic==skyflatnum)
         )
      {
        wall.ybottom=(float)backsector->floorheight/(128.0f*(float)FRACUNIT);
        if ((frontsector->sky) & PL_SKYFLAT) { const line_t *l = &lines[frontsector->sky & ~PL_SKYFLAT]; const side_t *s = *l->sidenum + sides; wall.gltexture=gld_RegisterTexture(texturetranslation[s->toptexture], false, texturetranslation[s->toptexture]==skytexture); wall.skyyaw=-2.0f*((-(float)((viewangle+s->textureoffset)>>ANGLETOFINESHIFT)*360.0f/FINEANGLES)/90.0f); wall.skyymid = 200.0f/319.5f*(((float)s->rowoffset/(float)FRACUNIT - 28.0f)/100.0f); wall.flag = l->special==272 ? 5 : 6; } else if ((backsector->sky) & PL_SKYFLAT) { const line_t *l = &lines[backsector->sky & ~PL_SKYFLAT]; const side_t *s = *l->sidenum + sides; wall.gltexture=gld_RegisterTexture(texturetranslation[s->toptexture], false, texturetranslation[s->toptexture]==skytexture); wall.skyyaw=-2.0f*((-(float)((viewangle+s->textureoffset)>>ANGLETOFINESHIFT)*360.0f/FINEANGLES)/90.0f); wall.skyymid = 200.0f/319.5f*(((float)s->rowoffset/(float)FRACUNIT - 28.0f)/100.0f); wall.flag = l->special==272 ? 5 : 6; } else { wall.gltexture=gld_RegisterTexture(skytexture, false, true); wall.skyyaw=-2.0f*((yaw+90.0f)/90.0f); wall.skyymid = 200.0f/319.5f*((100.0f)/100.0f); wall.flag = 5; };;
        { if (gld_drawinfo.num_walls>=gld_drawinfo.max_walls) { gld_drawinfo.max_walls+=128; gld_drawinfo.walls=Z_Realloc(gld_drawinfo.walls,gld_drawinfo.max_walls*sizeof(GLWall),PU_LEVEL,0); } gld_AddDrawItem(GLDIT_WALL, gld_drawinfo.num_walls); gld_drawinfo.walls[gld_drawinfo.num_walls++]=*&wall;};;
      }
      else
      {
        if ( (texturetranslation[seg->sidedef->toptexture]!=NO_TEXTURE) )
        {



          wall.ybottom=(float)MAX(frontsector->ceilingheight,backsector->ceilingheight)/(128.0f*(float)FRACUNIT);

          if ((frontsector->sky) & PL_SKYFLAT) { const line_t *l = &lines[frontsector->sky & ~PL_SKYFLAT]; const side_t *s = *l->sidenum + sides; wall.gltexture=gld_RegisterTexture(texturetranslation[s->toptexture], false, texturetranslation[s->toptexture]==skytexture); wall.skyyaw=-2.0f*((-(float)((viewangle+s->textureoffset)>>ANGLETOFINESHIFT)*360.0f/FINEANGLES)/90.0f); wall.skyymid = 200.0f/319.5f*(((float)s->rowoffset/(float)FRACUNIT - 28.0f)/100.0f); wall.flag = l->special==272 ? 5 : 6; } else if ((backsector->sky) & PL_SKYFLAT) { const line_t *l = &lines[backsector->sky & ~PL_SKYFLAT]; const side_t *s = *l->sidenum + sides; wall.gltexture=gld_RegisterTexture(texturetranslation[s->toptexture], false, texturetranslation[s->toptexture]==skytexture); wall.skyyaw=-2.0f*((-(float)((viewangle+s->textureoffset)>>ANGLETOFINESHIFT)*360.0f/FINEANGLES)/90.0f); wall.skyymid = 200.0f/319.5f*(((float)s->rowoffset/(float)FRACUNIT - 28.0f)/100.0f); wall.flag = l->special==272 ? 5 : 6; } else { wall.gltexture=gld_RegisterTexture(skytexture, false, true); wall.skyyaw=-2.0f*((yaw+90.0f)/90.0f); wall.skyymid = 200.0f/319.5f*((100.0f)/100.0f); wall.flag = 5; };;
          { if (gld_drawinfo.num_walls>=gld_drawinfo.max_walls) { gld_drawinfo.max_walls+=128; gld_drawinfo.walls=Z_Realloc(gld_drawinfo.walls,gld_drawinfo.max_walls*sizeof(GLWall),PU_LEVEL,0); } gld_AddDrawItem(GLDIT_WALL, gld_drawinfo.num_walls); gld_drawinfo.walls[gld_drawinfo.num_walls++]=*&wall;};;
        }
        else
          if ( (backsector->ceilingheight <= frontsector->floorheight) ||
               (backsector->ceilingpic != skyflatnum) )
          {
            wall.ybottom=(float)backsector->ceilingheight/(128.0f*(float)FRACUNIT);
            if ((frontsector->sky) & PL_SKYFLAT) { const line_t *l = &lines[frontsector->sky & ~PL_SKYFLAT]; const side_t *s = *l->sidenum + sides; wall.gltexture=gld_RegisterTexture(texturetranslation[s->toptexture], false, texturetranslation[s->toptexture]==skytexture); wall.skyyaw=-2.0f*((-(float)((viewangle+s->textureoffset)>>ANGLETOFINESHIFT)*360.0f/FINEANGLES)/90.0f); wall.skyymid = 200.0f/319.5f*(((float)s->rowoffset/(float)FRACUNIT - 28.0f)/100.0f); wall.flag = l->special==272 ? 5 : 6; } else if ((backsector->sky) & PL_SKYFLAT) { const line_t *l = &lines[backsector->sky & ~PL_SKYFLAT]; const side_t *s = *l->sidenum + sides; wall.gltexture=gld_RegisterTexture(texturetranslation[s->toptexture], false, texturetranslation[s->toptexture]==skytexture); wall.skyyaw=-2.0f*((-(float)((viewangle+s->textureoffset)>>ANGLETOFINESHIFT)*360.0f/FINEANGLES)/90.0f); wall.skyymid = 200.0f/319.5f*(((float)s->rowoffset/(float)FRACUNIT - 28.0f)/100.0f); wall.flag = l->special==272 ? 5 : 6; } else { wall.gltexture=gld_RegisterTexture(skytexture, false, true); wall.skyyaw=-2.0f*((yaw+90.0f)/90.0f); wall.skyymid = 200.0f/319.5f*((100.0f)/100.0f); wall.flag = 5; };;
            { if (gld_drawinfo.num_walls>=gld_drawinfo.max_walls) { gld_drawinfo.max_walls+=128; gld_drawinfo.walls=Z_Realloc(gld_drawinfo.walls,gld_drawinfo.max_walls*sizeof(GLWall),PU_LEVEL,0); } gld_AddDrawItem(GLDIT_WALL, gld_drawinfo.num_walls); gld_drawinfo.walls[gld_drawinfo.num_walls++]=*&wall;};;
          }
      }
    }
    if (floor_height<ceiling_height)
    {
      if (!((frontsector->ceilingpic==skyflatnum) && (backsector->ceilingpic==skyflatnum)))
      {
        temptex=gld_RegisterTexture(texturetranslation[seg->sidedef->toptexture], true, false);
        if (temptex)
        {
          wall.gltexture=temptex;
          (wall).ytop=((float)(ceiling_height)/(float)(128.0f*(float)FRACUNIT))+0.001f; (wall).ybottom=((float)(floor_height)/(float)(128.0f*(float)FRACUNIT))-0.001f; lineheight=((float)fabs(((ceiling_height)/(float)FRACUNIT)-((floor_height)/(float)FRACUNIT)));
          (wall).flag=1; (wall).ul=(((float)(((seg))->sidedef->textureoffset+((seg))->offset)/(float)FRACUNIT)/(float)((wall)).gltexture->buffer_width)+(0.0f); (wall).ur=(((float)(((seg))->sidedef->textureoffset+((seg))->offset)/(float)FRACUNIT)/(float)((wall)).gltexture->buffer_width)+((segs[seg->iSegID].length)/(float)(wall).gltexture->buffer_width); ((seg->linedef->flags & (ML_DONTPEGBOTTOM | ML_DONTPEGTOP))==0)? ( (wall).vb=(((float)(((seg))->sidedef->rowoffset)/(float)FRACUNIT)/(float)((wall)).gltexture->buffer_height)+((float)(wall).gltexture->height/(float)(wall).gltexture->tex_height), (wall).vt=((wall).vb-((float)(lineheight)/(float)(wall).gltexture->buffer_height)) ):( (wall).vt=(((float)(((seg))->sidedef->rowoffset)/(float)FRACUNIT)/(float)((wall)).gltexture->buffer_height)+(0.0f), (wall).vb=(((float)(((seg))->sidedef->rowoffset)/(float)FRACUNIT)/(float)((wall)).gltexture->buffer_height)+((float)(lineheight)/(float)(wall).gltexture->buffer_height) )


           ;
          { if (gld_drawinfo.num_walls>=gld_drawinfo.max_walls) { gld_drawinfo.max_walls+=128; gld_drawinfo.walls=Z_Realloc(gld_drawinfo.walls,gld_drawinfo.max_walls*sizeof(GLWall),PU_LEVEL,0); } gld_AddDrawItem(GLDIT_WALL, gld_drawinfo.num_walls); gld_drawinfo.walls[gld_drawinfo.num_walls++]=*&wall;};;
        }
      }
    }



    if (comp[comp_maskedanim])
      temptex=gld_RegisterTexture(seg->sidedef->midtexture, true, false);
    else



      temptex=gld_RegisterTexture(texturetranslation[seg->sidedef->midtexture], true, true);

    if (temptex && seg->sidedef->midtexture != NO_TEXTURE)
    {
      wall.gltexture=temptex;
      if ( (seg->linedef->flags & ML_DONTPEGBOTTOM) >0)
      {
        if (seg->backsector->ceilingheight<=seg->frontsector->floorheight)
          goto bottomtexture;
        floor_height=MAX(seg->frontsector->floorheight,seg->backsector->floorheight)+(seg->sidedef->rowoffset);
        ceiling_height=floor_height+(wall.gltexture->realtexheight<<FRACBITS);
      }
      else
      {
        if (seg->backsector->ceilingheight<=seg->frontsector->floorheight)
          goto bottomtexture;
        ceiling_height=MIN(seg->frontsector->ceilingheight,seg->backsector->ceilingheight)+(seg->sidedef->rowoffset);
        floor_height=ceiling_height-(wall.gltexture->realtexheight<<FRACBITS);
      }
# 2252 "gl_main.c"
      {
        int floormax, ceilingmin, linelen;
        float mip;
        mip = (float)wall.gltexture->realtexheight/(float)wall.gltexture->buffer_height;

        if (seg->sidedef->bottomtexture)
          floormax=MAX(seg->frontsector->floorheight,seg->backsector->floorheight);
        else
          floormax=floor_height;
        if (seg->sidedef->toptexture)
          ceilingmin=MIN(seg->frontsector->ceilingheight,seg->backsector->ceilingheight);
        else
          ceilingmin=ceiling_height;
        linelen=abs(ceiling_height-floor_height);
        wall.ytop=((float)MIN(ceilingmin, ceiling_height)/(float)(128.0f*(float)FRACUNIT));
        wall.ybottom=((float)MAX(floormax, floor_height)/(float)(128.0f*(float)FRACUNIT));
        wall.flag=3;
        wall.ul=(((float)(((seg))->sidedef->textureoffset+((seg))->offset)/(float)FRACUNIT)/(float)((wall)).gltexture->buffer_width)+(0.0f);
        wall.ur=(((float)(((seg))->sidedef->textureoffset+((seg))->offset)/(float)FRACUNIT)/(float)(wall).gltexture->buffer_width)+((segs[seg->iSegID].length)/(float)wall.gltexture->buffer_width);
        if (floormax<=floor_height)



          wall.vb=mip*1.0f;

        else
          wall.vb=mip*((float)(ceiling_height - floormax))/linelen;
        if (ceilingmin>=ceiling_height)
          wall.vt=0.0f;
        else
          wall.vt=mip*((float)(ceiling_height - ceilingmin))/linelen;
      }

      if (seg->linedef->tranlump >= 0 && general_translucency)
        wall.alpha=(float)tran_filter_pct/100.0f;
      { if (gld_drawinfo.num_walls>=gld_drawinfo.max_walls) { gld_drawinfo.max_walls+=128; gld_drawinfo.walls=Z_Realloc(gld_drawinfo.walls,gld_drawinfo.max_walls*sizeof(GLWall),PU_LEVEL,0); } gld_AddDrawItem(GLDIT_WALL, gld_drawinfo.num_walls); gld_drawinfo.walls[gld_drawinfo.num_walls++]=*&wall;};;
      wall.alpha=1.0f;
    }
bottomtexture:

    ceiling_height=backsector->floorheight;
    floor_height=frontsector->floorheight;
    if (frontsector->floorpic==skyflatnum)
    {
      wall.ybottom=-255.0f;
      if (
          (backsector->ceilingheight==backsector->floorheight) &&
          (backsector->floorpic==skyflatnum)
         )
      {
        wall.ytop=(float)backsector->floorheight/(128.0f*(float)FRACUNIT);
        if ((frontsector->sky) & PL_SKYFLAT) { const line_t *l = &lines[frontsector->sky & ~PL_SKYFLAT]; const side_t *s = *l->sidenum + sides; wall.gltexture=gld_RegisterTexture(texturetranslation[s->toptexture], false, texturetranslation[s->toptexture]==skytexture); wall.skyyaw=-2.0f*((-(float)((viewangle+s->textureoffset)>>ANGLETOFINESHIFT)*360.0f/FINEANGLES)/90.0f); wall.skyymid = 200.0f/319.5f*(((float)s->rowoffset/(float)FRACUNIT - 28.0f)/100.0f); wall.flag = l->special==272 ? 5 : 6; } else if ((backsector->sky) & PL_SKYFLAT) { const line_t *l = &lines[backsector->sky & ~PL_SKYFLAT]; const side_t *s = *l->sidenum + sides; wall.gltexture=gld_RegisterTexture(texturetranslation[s->toptexture], false, texturetranslation[s->toptexture]==skytexture); wall.skyyaw=-2.0f*((-(float)((viewangle+s->textureoffset)>>ANGLETOFINESHIFT)*360.0f/FINEANGLES)/90.0f); wall.skyymid = 200.0f/319.5f*(((float)s->rowoffset/(float)FRACUNIT - 28.0f)/100.0f); wall.flag = l->special==272 ? 5 : 6; } else { wall.gltexture=gld_RegisterTexture(skytexture, false, true); wall.skyyaw=-2.0f*((yaw+90.0f)/90.0f); wall.skyymid = 200.0f/319.5f*((100.0f)/100.0f); wall.flag = 5; };;
        { if (gld_drawinfo.num_walls>=gld_drawinfo.max_walls) { gld_drawinfo.max_walls+=128; gld_drawinfo.walls=Z_Realloc(gld_drawinfo.walls,gld_drawinfo.max_walls*sizeof(GLWall),PU_LEVEL,0); } gld_AddDrawItem(GLDIT_WALL, gld_drawinfo.num_walls); gld_drawinfo.walls[gld_drawinfo.num_walls++]=*&wall;};;
      }
      else
      {
        if ( (texturetranslation[seg->sidedef->bottomtexture]!=NO_TEXTURE) )
        {
          wall.ytop=(float)frontsector->floorheight/(128.0f*(float)FRACUNIT);
          if ((frontsector->sky) & PL_SKYFLAT) { const line_t *l = &lines[frontsector->sky & ~PL_SKYFLAT]; const side_t *s = *l->sidenum + sides; wall.gltexture=gld_RegisterTexture(texturetranslation[s->toptexture], false, texturetranslation[s->toptexture]==skytexture); wall.skyyaw=-2.0f*((-(float)((viewangle+s->textureoffset)>>ANGLETOFINESHIFT)*360.0f/FINEANGLES)/90.0f); wall.skyymid = 200.0f/319.5f*(((float)s->rowoffset/(float)FRACUNIT - 28.0f)/100.0f); wall.flag = l->special==272 ? 5 : 6; } else if ((backsector->sky) & PL_SKYFLAT) { const line_t *l = &lines[backsector->sky & ~PL_SKYFLAT]; const side_t *s = *l->sidenum + sides; wall.gltexture=gld_RegisterTexture(texturetranslation[s->toptexture], false, texturetranslation[s->toptexture]==skytexture); wall.skyyaw=-2.0f*((-(float)((viewangle+s->textureoffset)>>ANGLETOFINESHIFT)*360.0f/FINEANGLES)/90.0f); wall.skyymid = 200.0f/319.5f*(((float)s->rowoffset/(float)FRACUNIT - 28.0f)/100.0f); wall.flag = l->special==272 ? 5 : 6; } else { wall.gltexture=gld_RegisterTexture(skytexture, false, true); wall.skyyaw=-2.0f*((yaw+90.0f)/90.0f); wall.skyymid = 200.0f/319.5f*((100.0f)/100.0f); wall.flag = 5; };;
          { if (gld_drawinfo.num_walls>=gld_drawinfo.max_walls) { gld_drawinfo.max_walls+=128; gld_drawinfo.walls=Z_Realloc(gld_drawinfo.walls,gld_drawinfo.max_walls*sizeof(GLWall),PU_LEVEL,0); } gld_AddDrawItem(GLDIT_WALL, gld_drawinfo.num_walls); gld_drawinfo.walls[gld_drawinfo.num_walls++]=*&wall;};;
        }
        else
          if ( (backsector->floorheight >= frontsector->ceilingheight) ||
               (backsector->floorpic != skyflatnum) )
          {
            wall.ytop=(float)backsector->floorheight/(128.0f*(float)FRACUNIT);
            if ((frontsector->sky) & PL_SKYFLAT) { const line_t *l = &lines[frontsector->sky & ~PL_SKYFLAT]; const side_t *s = *l->sidenum + sides; wall.gltexture=gld_RegisterTexture(texturetranslation[s->toptexture], false, texturetranslation[s->toptexture]==skytexture); wall.skyyaw=-2.0f*((-(float)((viewangle+s->textureoffset)>>ANGLETOFINESHIFT)*360.0f/FINEANGLES)/90.0f); wall.skyymid = 200.0f/319.5f*(((float)s->rowoffset/(float)FRACUNIT - 28.0f)/100.0f); wall.flag = l->special==272 ? 5 : 6; } else if ((backsector->sky) & PL_SKYFLAT) { const line_t *l = &lines[backsector->sky & ~PL_SKYFLAT]; const side_t *s = *l->sidenum + sides; wall.gltexture=gld_RegisterTexture(texturetranslation[s->toptexture], false, texturetranslation[s->toptexture]==skytexture); wall.skyyaw=-2.0f*((-(float)((viewangle+s->textureoffset)>>ANGLETOFINESHIFT)*360.0f/FINEANGLES)/90.0f); wall.skyymid = 200.0f/319.5f*(((float)s->rowoffset/(float)FRACUNIT - 28.0f)/100.0f); wall.flag = l->special==272 ? 5 : 6; } else { wall.gltexture=gld_RegisterTexture(skytexture, false, true); wall.skyyaw=-2.0f*((yaw+90.0f)/90.0f); wall.skyymid = 200.0f/319.5f*((100.0f)/100.0f); wall.flag = 5; };;
            { if (gld_drawinfo.num_walls>=gld_drawinfo.max_walls) { gld_drawinfo.max_walls+=128; gld_drawinfo.walls=Z_Realloc(gld_drawinfo.walls,gld_drawinfo.max_walls*sizeof(GLWall),PU_LEVEL,0); } gld_AddDrawItem(GLDIT_WALL, gld_drawinfo.num_walls); gld_drawinfo.walls[gld_drawinfo.num_walls++]=*&wall;};;
          }
      }
    }
    if (floor_height<ceiling_height)
    {
      temptex=gld_RegisterTexture(texturetranslation[seg->sidedef->bottomtexture], true, false);
      if (temptex)
      {
        wall.gltexture=temptex;
        (wall).ytop=((float)(ceiling_height)/(float)(128.0f*(float)FRACUNIT))+0.001f; (wall).ybottom=((float)(floor_height)/(float)(128.0f*(float)FRACUNIT))-0.001f; lineheight=((float)fabs(((ceiling_height)/(float)FRACUNIT)-((floor_height)/(float)FRACUNIT)));
        (wall).flag=4; (wall).ul=(((float)(((seg))->sidedef->textureoffset+((seg))->offset)/(float)FRACUNIT)/(float)((wall)).gltexture->buffer_width)+(0.0f); (wall).ur=(((float)(((seg))->sidedef->textureoffset+((seg))->offset)/(float)FRACUNIT)/(float)((wall)).gltexture->buffer_width)+((segs[seg->iSegID].length)/(float)(wall).gltexture->realtexwidth); ((seg->linedef->flags & ML_DONTPEGBOTTOM)>0)? ( (wall).vb=((((float)((((seg)))->sidedef->rowoffset)/(float)FRACUNIT)/(float)(((wall))).gltexture->buffer_height)-(((float)((floor_height-frontsector->ceilingheight))/(float)FRACUNIT)/(float)((wall)).gltexture->buffer_height))+((float)(wall).gltexture->height/(float)(wall).gltexture->tex_height), (wall).vt=((wall).vb-((float)(lineheight)/(float)(wall).gltexture->buffer_height)) ):( (wall).vt=(((float)(((seg))->sidedef->rowoffset)/(float)FRACUNIT)/(float)((wall)).gltexture->buffer_height)+(0.0f), (wall).vb=(((float)(((seg))->sidedef->rowoffset)/(float)FRACUNIT)/(float)((wall)).gltexture->buffer_height)+((float)(lineheight)/(float)(wall).gltexture->buffer_height) )



         ;
        { if (gld_drawinfo.num_walls>=gld_drawinfo.max_walls) { gld_drawinfo.max_walls+=128; gld_drawinfo.walls=Z_Realloc(gld_drawinfo.walls,gld_drawinfo.max_walls*sizeof(GLWall),PU_LEVEL,0); } gld_AddDrawItem(GLDIT_WALL, gld_drawinfo.num_walls); gld_drawinfo.walls[gld_drawinfo.num_walls++]=*&wall;};;
      }
    }
  }
}
# 2354 "gl_main.c"
static void gld_PreprocessSegs(void)
{
  int i;

  gl_segs=Z_Malloc(numsegs*sizeof(GLSeg),PU_LEVEL,0);
  for (i=0; i<numsegs; i++)
  {
    gl_segs[i].x1=-(float)segs[i].v1->x/(float)(128.0f*(float)FRACUNIT);
    gl_segs[i].z1= (float)segs[i].v1->y/(float)(128.0f*(float)FRACUNIT);
    gl_segs[i].x2=-(float)segs[i].v2->x/(float)(128.0f*(float)FRACUNIT);
    gl_segs[i].z2= (float)segs[i].v2->y/(float)(128.0f*(float)FRACUNIT);
  }
}







static void gld_DrawFlat(GLFlat *flat)
{
  int loopnum;
  GLLoopDef *currentloop;




  gld_BindFlat(flat->gltexture);
  gld_StaticLightAlpha(flat->light, 1.0f);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslatef(0.0f,flat->z,0.0f);
  glMatrixMode(GL_TEXTURE);
  glPushMatrix();
  glTranslatef(flat->uoffs/64.0f,flat->voffs/64.0f,0.0f);
  if (flat->sectornum>=0)
  {
# 2423 "gl_main.c"
    for (loopnum=0; loopnum<sectorloops[flat->sectornum].loopcount; loopnum++)
    {

      currentloop=&sectorloops[flat->sectornum].loops[loopnum];
      glDrawArrays(currentloop->mode,currentloop->vertexindex,currentloop->vertexcount);
    }

  }
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
}






static void gld_AddFlat(int sectornum, boolean ceiling, visplane_t *plane)
{
  sector_t *sector;
  sector_t tempsec;
  int floorlightlevel;
  int ceilinglightlevel;
  GLFlat flat;

  if (sectornum<0)
    return;
  flat.sectornum=sectornum;
  sector=&sectors[sectornum];
  sector=R_FakeFlat(sector, &tempsec, &floorlightlevel, &ceilinglightlevel, false);
  flat.ceiling=ceiling;
  if (!ceiling)
  {
    if (sector->floorpic == skyflatnum)
      return;


    flat.gltexture=gld_RegisterFlat(flattranslation[sector->floorpic], true);
    if (!flat.gltexture)
      return;

    flat.light=(lighttable[usegamma][MAX(MIN((floorlightlevel+(extralight<<5)),255),0)]);

    flat.uoffs=(float)sector->floor_xoffs/(float)FRACUNIT;
    flat.voffs=(float)sector->floor_yoffs/(float)FRACUNIT;
  }
  else
  {
    if (sector->ceilingpic == skyflatnum)
      return;


    flat.gltexture=gld_RegisterFlat(flattranslation[sector->ceilingpic], true);
    if (!flat.gltexture)
      return;

    flat.light=(lighttable[usegamma][MAX(MIN((ceilinglightlevel+(extralight<<5)),255),0)]);

    flat.uoffs=(float)sector->ceiling_xoffs/(float)FRACUNIT;
    flat.voffs=(float)sector->ceiling_yoffs/(float)FRACUNIT;
  }


  flat.z=(float)plane->height/(128.0f*(float)FRACUNIT);

  if (gld_drawinfo.num_flats>=gld_drawinfo.max_flats)
  {
    gld_drawinfo.max_flats+=128;
    gld_drawinfo.flats=Z_Realloc(gld_drawinfo.flats,gld_drawinfo.max_flats*sizeof(GLFlat),PU_LEVEL,0);
  }
  gld_AddDrawItem(GLDIT_FLAT, gld_drawinfo.num_flats);
  gld_drawinfo.flats[gld_drawinfo.num_flats++]=flat;
}

void gld_AddPlane(int subsectornum, visplane_t *floor, visplane_t *ceiling)
{
  subsector_t *subsector;


  if (!sectorrendered)
    return;

  subsector = &subsectors[subsectornum];
  if (!subsector)
    return;
  if (sectorrendered[subsector->sector->iSectorID]!=rendermarker)
  {

    if (floor)
      gld_AddFlat(subsector->sector->iSectorID, false, floor);

    if (ceiling)
      gld_AddFlat(subsector->sector->iSectorID, true, ceiling);

    sectorrendered[subsector->sector->iSectorID]=rendermarker;
  }
}







static void gld_DrawSprite(GLSprite *sprite)
{
  gld_BindPatch(sprite->gltexture,sprite->cm);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();

  glTranslatef(sprite->x,sprite->y+ (.01f * (float)gl_sprite_offset),sprite->z);
  glRotatef(inv_yaw,0.0f,1.0f,0.0f);
  if(sprite->shadow)
  {
    glBlendFunc(GL_DST_COLOR, GL_ONE_MINUS_SRC_ALPHA);

    glAlphaFunc(GL_GEQUAL,0.1f);
    glColor4f(0.2f,0.2f,0.2f,0.33f);
  }
  else
  {
    if(sprite->trans)
      gld_StaticLightAlpha(sprite->light,(float)tran_filter_pct/100.0f);
    else
      gld_StaticLightAlpha(sprite->light, 1.0f);
  }
  { GLenum harm_Render_Type = GL_TRIANGLE_STRIP; GLint harm_Vertex_Size = 2; GLsizei harm_Vertex_Stride = 4; GLint harm_TexCoord_Size = 2; GLsizei harm_TexCoord_Stride = 4; GLint harm_Vertex_Count = 4; GLboolean harm_Enable_TexCoord = GL_TRUE;
  harm_Vertex_Size = 3;
  harm_Vertex_Stride = 5;
  harm_TexCoord_Stride = 5;
  GLfloat harm_Data[] = {
    (sprite->ul), (sprite->vt), (sprite->x1), (sprite->y1), (0.0f),
    (sprite->ur), (sprite->vt), (sprite->x2), (sprite->y1), (0.0f),
    (sprite->ul), (sprite->vb), (sprite->x1), (sprite->y2), (0.0f),
    (sprite->ur), (sprite->vb), (sprite->x2), (sprite->y2), (0.0f),
  };
  glEnableClientState(GL_VERTEX_ARRAY); if(harm_Enable_TexCoord) glEnableClientState(GL_TEXTURE_COORD_ARRAY); if(harm_Enable_TexCoord) glTexCoordPointer(harm_TexCoord_Size, GL_FLOAT, harm_TexCoord_Stride * sizeof(GLfloat), harm_Data); glVertexPointer(harm_Vertex_Size, GL_FLOAT, harm_Enable_TexCoord ? harm_Vertex_Stride * sizeof(GLfloat) : 0, harm_Data + (harm_Enable_TexCoord ? harm_TexCoord_Size : 0)); glDrawArrays(harm_Render_Type, 0, harm_Vertex_Count); glDisableClientState(GL_VERTEX_ARRAY); if(harm_Enable_TexCoord) glDisableClientState(GL_TEXTURE_COORD_ARRAY); }

  glPopMatrix();

  if(sprite->shadow)
  {
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glAlphaFunc(GL_GEQUAL,0.5f);
  }
}

void gld_AddSprite(vissprite_t *vspr)
{
  mobj_t *pSpr=vspr->thing;
  GLSprite sprite;
  float voff,hoff;

  sprite.scale=vspr->scale;
  if (pSpr->frame & FF_FULLBRIGHT)
    sprite.light = 1.0f;
  else
    sprite.light = (lighttable[usegamma][MAX(MIN((pSpr->subsector->sector->lightlevel+(extralight<<5)),255),0)]);
  sprite.cm=CR_LIMIT+(int)((pSpr->flags & MF_TRANSLATION) >> (MF_TRANSSHIFT));
  sprite.gltexture=gld_RegisterPatch(vspr->patch+firstspritelump,sprite.cm);
  if (!sprite.gltexture)
    return;
  sprite.shadow = (pSpr->flags & MF_SHADOW) != 0;
  sprite.trans = (pSpr->flags & MF_TRANSLUCENT) != 0;
  if (movement_smooth)
  {
    sprite.x = (float)(-pSpr->PrevX + FixedMul (tic_vars.frac, -pSpr->x - (-pSpr->PrevX)))/(128.0f*(float)FRACUNIT);
    sprite.y = (float)(pSpr->PrevZ + FixedMul (tic_vars.frac, pSpr->z - pSpr->PrevZ))/(128.0f*(float)FRACUNIT);
    sprite.z = (float)(pSpr->PrevY + FixedMul (tic_vars.frac, pSpr->y - pSpr->PrevY))/(128.0f*(float)FRACUNIT);
  }
  else
  {
    sprite.x=-(float)pSpr->x/(128.0f*(float)FRACUNIT);
    sprite.y= (float)pSpr->z/(128.0f*(float)FRACUNIT);
    sprite.z= (float)pSpr->y/(128.0f*(float)FRACUNIT);
  }

  sprite.vt=0.0f;
  sprite.vb=(float)sprite.gltexture->height/(float)sprite.gltexture->tex_height;
  if (vspr->flip)
  {
    sprite.ul=0.0f;
    sprite.ur=(float)sprite.gltexture->width/(float)sprite.gltexture->tex_width;
  }
  else
  {
    sprite.ul=(float)sprite.gltexture->width/(float)sprite.gltexture->tex_width;
    sprite.ur=0.0f;
  }
  hoff=(float)sprite.gltexture->leftoffset/(float)(128.0f);
  voff=(float)sprite.gltexture->topoffset/(float)(128.0f);
  sprite.x1=hoff-((float)sprite.gltexture->realtexwidth/(float)(128.0f));
  sprite.x2=hoff;
  sprite.y1=voff;
  sprite.y2=voff-((float)sprite.gltexture->realtexheight/(float)(128.0f));

  if (gld_drawinfo.num_sprites>=gld_drawinfo.max_sprites)
  {
    gld_drawinfo.max_sprites+=128;
    gld_drawinfo.sprites=Z_Realloc(gld_drawinfo.sprites,gld_drawinfo.max_sprites*sizeof(GLSprite),PU_LEVEL,0);
  }
  gld_AddDrawItem(GLDIT_SPRITE, gld_drawinfo.num_sprites);
  gld_drawinfo.sprites[gld_drawinfo.num_sprites++]=sprite;
}







void gld_DrawScene(player_t *player)
{
  int i,j,k,count;
  fixed_t max_scale;

  glEnableClientState(GL_TEXTURE_COORD_ARRAY);
  glEnableClientState(GL_VERTEX_ARRAY);
  rendered_visplanes = rendered_segs = rendered_vissprites = 0;
  for (i=gld_drawinfo.num_drawitems; i>=0; i--)
  {
    switch (gld_drawinfo.drawitems[i].itemtype)
    {
    case GLDIT_FLAT:

      glEnable(GL_CULL_FACE);

      glCullFace(GL_FRONT);
      for (j=(gld_drawinfo.drawitems[i].itemcount-1); j>=0; j--)
        if (!gld_drawinfo.flats[j+gld_drawinfo.drawitems[i].firstitemindex].ceiling)
        {
          rendered_visplanes++;
          gld_DrawFlat(&gld_drawinfo.flats[j+gld_drawinfo.drawitems[i].firstitemindex]);
        }

      glCullFace(GL_BACK);
      for (j=(gld_drawinfo.drawitems[i].itemcount-1); j>=0; j--)
        if (gld_drawinfo.flats[j+gld_drawinfo.drawitems[i].firstitemindex].ceiling)
        {
          rendered_visplanes++;
          gld_DrawFlat(&gld_drawinfo.flats[j+gld_drawinfo.drawitems[i].firstitemindex]);
        }

      glDisable(GL_CULL_FACE);
      break;
    }
  }
  for (i=gld_drawinfo.num_drawitems; i>=0; i--)
  {
    switch (gld_drawinfo.drawitems[i].itemtype)
    {
    case GLDIT_WALL:
      count=0;
      for (k=1; k<=6; k++)
      {
        if (count>=gld_drawinfo.drawitems[i].itemcount)
          continue;
# 2692 "gl_main.c"
        for (j=(gld_drawinfo.drawitems[i].itemcount-1); j>=0; j--)
          if (gld_drawinfo.walls[j+gld_drawinfo.drawitems[i].firstitemindex].flag==k)
          {
            rendered_segs++;
            count++;
            gld_DrawWall(&gld_drawinfo.walls[j+gld_drawinfo.drawitems[i].firstitemindex]);
          }
# 2710 "gl_main.c"
      break;
    case GLDIT_SPRITE:
      if (gl_sortsprites)
      {
        do
        {
          max_scale=INT_MAX;
          k=-1;
          for (j=(gld_drawinfo.drawitems[i].itemcount-1); j>=0; j--)
            if (gld_drawinfo.sprites[j+gld_drawinfo.drawitems[i].firstitemindex].scale<max_scale)
            {
              max_scale=gld_drawinfo.sprites[j+gld_drawinfo.drawitems[i].firstitemindex].scale;
              k=j+gld_drawinfo.drawitems[i].firstitemindex;
            }
          if (k>=0)
          {
            rendered_vissprites++;
            gld_DrawSprite(&gld_drawinfo.sprites[k]);
            gld_drawinfo.sprites[k].scale=INT_MAX;
          }
        } while (max_scale!=INT_MAX);
      }
      else
      {
        for (j=(gld_drawinfo.drawitems[i].itemcount-1); j>=0; j--,rendered_vissprites++)
          gld_DrawSprite(&gld_drawinfo.sprites[j+gld_drawinfo.drawitems[i].firstitemindex]);
      }
      break;
    }
  }
  glDisableClientState(GL_TEXTURE_COORD_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
}

void gld_PreprocessLevel(void)
{
  if (precache)
    gld_Precache();
  gld_PreprocessSectors();
  gld_PreprocessSegs();
  memset(&gld_drawinfo,0,sizeof(GLDrawInfo));
  glTexCoordPointer(2,GL_FLOAT,0,gld_texcoords);
  glVertexPointer(3,GL_FLOAT,0,gld_vertexes);
}
