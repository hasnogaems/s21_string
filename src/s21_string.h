#include <stdio.h>
#include <string.h>
void *s21_memchr(const void *str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memcpy(void *dest, const void *src, size_t n);
void *s21_memset(void *str, int c, size_t n);
char *s21_strncat(char *dest, const char *src, size_t n);
int s21_strncmp (const char *str1, const char *str2, size_t n);
char *s21_strncpy(char *dest, const char *src, size_t n);
size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);

#define MAX_ERRORS "d"

#define EPERM           1               /* Operation not permitted */
#define ENOENT          2               /* No such file or directory */
#define ESRCH           3               /* No such process */
#define EINTR           4               /* Interrupted system call */
#define EIO             5               /* Input/output error */
#define ENXIO           6               /* Device not configured */
#define E2BIG           7               /* Argument list too long */
#define ENOEXEC         8               /* Exec format error */
#define EBADF           9               /* Bad file descriptor */
#define ECHILD          10              /* No child processes */
#define EDEADLK         11              /* Resource deadlock avoided */
                                        /* 11 was EAGAIN */
#define ENOMEM          12              /* Cannot allocate memory */
#define EACCES          13              /* Permission denied */
#define EFAULT          14              /* Bad address */
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
#define ENOTBLK         15              /* Block device required */
#endif
#define EBUSY           16              /* Device / Resource busy */
#define EEXIST          17              /* File exists */
#define EXDEV           18              /* Cross-device link */
#define ENODEV          19              /* Operation not supported by device */
#define ENOTDIR         20              /* Not a directory */
#define EISDIR          21              /* Is a directory */
#define EINVAL          22              /* Invalid argument */
#define ENFILE          23              /* Too many open files in system */
#define EMFILE          24              /* Too many open files */
#define ENOTTY          25              /* Inappropriate ioctl for device */
#define ETXTBSY         26              /* Text file busy */
#define EFBIG           27              /* File too large */
#define ENOSPC          28              /* No space left on device */
#define ESPIPE          29              /* Illegal seek */
#define EROFS           30              /* Read-only file system */
#define EMLINK          31              /* Too many links */
#define EPIPE           32              /* Broken pipe */

/* math software */
#define EDOM            33              /* Numerical argument out of domain */
#define ERANGE          34              /* Result too large */

/* non-blocking and interrupt i/o */
#define EAGAIN          35              /* Resource temporarily unavailable */
#define EWOULDBLOCK     EAGAIN          /* Operation would block */
#define EINPROGRESS     36              /* Operation now in progress */
#define EALREADY        37              /* Operation already in progress */

/* ipc/network software -- argument errors */
#define ENOTSOCK        38              /* Socket operation on non-socket */
#define EDESTADDRREQ    39              /* Destination address required */
#define EMSGSIZE        40              /* Message too long */
#define EPROTOTYPE      41              /* Protocol wrong type for socket */
#define ENOPROTOOPT     42              /* Protocol not available */
#define EPROTONOSUPPORT 43              /* Protocol not supported */
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
#define ESOCKTNOSUPPORT 44              /* Socket type not supported */
#endif
#define ENOTSUP         45              /* Operation not supported */
#if !__DARWIN_UNIX03 && !defined(KERNEL)
/*
 * This is the same for binary and source copmpatability, unless compiling
 * the kernel itself, or compiling __DARWIN_UNIX03; if compiling for the
 * kernel, the correct value will be returned.  If compiling non-POSIX
 * source, the kernel return value will be converted by a stub in libc, and
 * if compiling source with __DARWIN_UNIX03, the conversion in libc is not
 * done, and the caller gets the expected (discrete) value.
 */
#define EOPNOTSUPP       ENOTSUP        /* Operation not supported on socket */
#endif /* !__DARWIN_UNIX03 && !KERNEL */

#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
#define EPFNOSUPPORT    46              /* Protocol family not supported */
#endif
#define EAFNOSUPPORT    47              /* Address family not supported by protocol family */
#define EADDRINUSE      48              /* Address already in use */
#define EADDRNOTAVAIL   49              /* Can't assign requested address */

/* ipc/network software -- operational errors */
#define ENETDOWN        50              /* Network is down */
#define ENETUNREACH     51              /* Network is unreachable */
#define ENETRESET       52              /* Network dropped connection on reset */
#define ECONNABORTED    53              /* Software caused connection abort */
#define ECONNRESET      54              /* Connection reset by peer */
#define ENOBUFS         55              /* No buffer space available */
#define EISCONN         56              /* Socket is already connected */
#define ENOTCONN        57              /* Socket is not connected */
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
#define ESHUTDOWN       58              /* Can't send after socket shutdown */
#define ETOOMANYREFS    59              /* Too many references: can't splice */
#endif
#define ETIMEDOUT       60              /* Operation timed out */
#define ECONNREFUSED    61              /* Connection refused */

#define ELOOP           62              /* Too many levels of symbolic links */
#define ENAMETOOLONG    63              /* File name too long */

/* should be rearranged */
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
#define EHOSTDOWN       64              /* Host is down */
#endif
#define EHOSTUNREACH    65              /* No route to host */
#define ENOTEMPTY       66              /* Directory not empty */

/* quotas & mush */
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
#define EPROCLIM        67              /* Too many processes */
#define EUSERS          68              /* Too many users */
#endif
#define EDQUOT          69              /* Disc quota exceeded */

/* Network File System */
#define ESTALE          70              /* Stale NFS file handle */
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
#define EREMOTE         71              /* Too many levels of remote in path */
#define EBADRPC         72              /* RPC struct is bad */
#define ERPCMISMATCH    73              /* RPC version wrong */
#define EPROGUNAVAIL    74              /* RPC prog. not avail */
#define EPROGMISMATCH   75              /* Program version wrong */
#define EPROCUNAVAIL    76              /* Bad procedure for program */
#endif

#define ENOLCK          77              /* No locks available */
#define ENOSYS          78              /* Function not implemented */

#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
#define EFTYPE          79              /* Inappropriate file type or format */
#define EAUTH           80              /* Authentication error */
#define ENEEDAUTH       81              /* Need authenticator */

/* Intelligent device errors */
#define EPWROFF         82      /* Device power is off */
#define EDEVERR         83      /* Device error, e.g. paper out */
#endif

#define EOVERFLOW       84              /* Value too large to be stored in data type */

/* Program loading errors */
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
#define EBADEXEC        85      /* Bad executable */
#define EBADARCH        86      /* Bad CPU type in executable */
#define ESHLIBVERS      87      /* Shared library version mismatch */
#define EBADMACHO       88      /* Malformed Macho file */
#endif

#define ECANCELED       89              /* Operation canceled */

#define EIDRM           90              /* Identifier removed */
#define ENOMSG          91              /* No message of desired type */
#define EILSEQ          92              /* Illegal byte sequence */
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
#define ENOATTR         93              /* Attribute not found */
#endif

#define EBADMSG         94              /* Bad message */
#define EMULTIHOP       95              /* Reserved */
#define ENODATA         96              /* No message available on STREAM */
#define ENOLINK         97              /* Reserved */
#define ENOSR           98              /* No STREAM resources */
#define ENOSTR          99              /* Not a STREAM */
#define EPROTO          100             /* Protocol error */
#define ETIME           101             /* STREAM ioctl timeout */

#if __DARWIN_UNIX03 || defined(KERNEL)
/* This value is only discrete when compiling __DARWIN_UNIX03, or KERNEL */
#define EOPNOTSUPP      102             /* Operation not supported on socket */
#endif /* __DARWIN_UNIX03 || KERNEL */

#define ENOPOLICY       103             /* No such policy registered */

#if __DARWIN_C_LEVEL >= 200809L
#define ENOTRECOVERABLE 104             /* State not recoverable */
#define EOWNERDEAD      105             /* Previous owner died */
#endif

#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
#define EQFULL          106             /* Interface output queue is full */
#define ELAST           106             /* Must be equal largest errno */
#endif

const int errorCodes[] = {
    EPERM, ENOENT, ESRCH, EINTR, EIO, ENXIO, E2BIG, ENOEXEC,
    EBADF, ECHILD, EDEADLK, ENOMEM, EACCES, EFAULT, ENOTBLK,
    EBUSY, EEXIST, EXDEV, ENODEV, ENOTDIR, EISDIR, EINVAL,
    ENFILE, EMFILE, ENOTTY, ETXTBSY, EFBIG, ENOSPC, ESPIPE,
    EROFS, EMLINK, EPIPE, EDOM, ERANGE, EAGAIN, EWOULDBLOCK,
    EINPROGRESS, EALREADY, ENOTSOCK, EDESTADDRREQ, EMSGSIZE,
    EPROTOTYPE, ENOPROTOOPT, EPROTONOSUPPORT, ESOCKTNOSUPPORT,
    ENOTSUP, EOPNOTSUPP, EPFNOSUPPORT, EAFNOSUPPORT, EADDRINUSE,
    EADDRNOTAVAIL, ENETDOWN, ENETUNREACH, ENETRESET, ECONNABORTED,
    ECONNRESET, ENOBUFS, EISCONN, ENOTCONN, ESHUTDOWN, ETOOMANYREFS,
    ETIMEDOUT, ECONNREFUSED, ELOOP, ENAMETOOLONG, EHOSTDOWN,
    EHOSTUNREACH, ENOTEMPTY, EPROCLIM, EUSERS, EDQUOT, ESTALE,
    EREMOTE, EBADRPC, ERPCMISMATCH, EPROGUNAVAIL, EPROGMISMATCH,
    EPROCUNAVAIL, ENOLCK, ENOSYS, EFTYPE, EAUTH, ENEEDAUTH, EPWROFF,
    EDEVERR, EOVERFLOW, EBADEXEC, EBADARCH, ESHLIBVERS, EBADMACHO,
    ECANCELED, EIDRM, ENOMSG, EILSEQ, ENOATTR, EBADMSG, EMULTIHOP,
    ENODATA, ENOLINK, ENOSR, ENOSTR, EPROTO, ETIME, EOPNOTSUPP,
    ENOPOLICY, ENOTRECOVERABLE, EOWNERDEAD, EQFULL, ELAST
};

#define EPERM_STR "Operation not permitted",
#define ENOENT_STR "No such file or directory",
#define ESRCH_STR "No such process",
#define EINTR_STR "Interrupted system call",
#define EIO_STR "Input/output error",
#define ENXIO_STR "Device not configured",
#define E2BIG_STR "Argument list too long",
#define ENOEXEC_STR "Exec format error",
#define EBADF_STR "Bad file descriptor",
#define ECHILD_STR "No child processes",
#define EDEADLK_STR "Resource deadlock avoided",
#define ENOMEM_STR "Cannot allocate memory",
#define EACCES_STR "Permission denied",
#define EFAULT_STR "Bad address",
#define ENOTBLK_STR "Block device required",
#define EBUSY_STR "Device / Resource busy",
#define EEXIST_STR "File exists",
#define EXDEV_STR "Cross-device link",
#define ENODEV_STR "Operation not supported by device",
#define ENOTDIR_STR "Not a directory",
#define EISDIR_STR "Is a directory",
#define EINVAL_STR "Invalid argument",
#define ENFILE_STR "Too many open files in system",
#define EMFILE_STR "Too many open files",
#define ENOTTY_STR "Inappropriate ioctl for device",
#define ETXTBSY_STR "Text file busy",
#define EFBIG_STR "File too large",
#define ENOSPC_STR "No space left on device",
#define ESPIPE_STR "Illegal seek",
#define EROFS_STR "Read-only file system",
#define EMLINK_STR "Too many links",
#define EPIPE_STR "Broken pipe",
#define EDOM_STR "Numerical argument out of domain",
#define ERANGE_STR "Result too large",
#define EAGAIN_STR "Resource temporarily unavailable",
#define EINPROGRESS_STR "Operation now in progress",
#define EALREADY_STR "Operation already in progress",
#define ENOTSOCK_STR "Socket operation on non-socket",
#define EDESTADDRREQ_STR "Destination address required",
#define EMSGSIZE_STR "Message too long",
#define EPROTOTYPE_STR "Protocol wrong type for socket",
#define ENOPROTOOPT_STR "Protocol not available",
#define EPROTONOSUPPORT_STR "Protocol not supported",
#define ESOCKTNOSUPPORT_STR "Socket type not supported",
#define ENOTSUP_STR "Operation not supported",
#define EPFNOSUPPORT_STR "Protocol family not supported",
#define EAFNOSUPPORT_STR "Address family not supported by protocol family",
#define EADDRINUSE_STR "Address already in use",
#define EADDRNOTAVAIL_STR "Can't assign requested address",
#define ENETDOWN_STR "Network is down",
#define ENETUNREACH_STR "Network is unreachable",
#define ENETRESET_STR "Network dropped connection on reset",
#define ECONNABORTED_STR "Software caused connection abort",
#define ECONNRESET_STR "Connection reset by peer",
#define ENOBUFS_STR "No buffer space available",
#define EISCONN_STR "Socket is already connected",
#define ENOTCONN_STR "Socket is not connected",
#define ESHUTDOWN_STR "Can't send after socket shutdown",
#define ETOOMANYREFS_STR "Too many references: can't splice",
#define ETIMEDOUT_STR "Operation timed out",
#define ECONNREFUSED_STR "Connection refused",
#define ELOOP_STR "Too many levels of symbolic links",
#define ENAMETOOLONG_STR "File name too long",
#define EHOSTDOWN_STR "Host is down",
#define ENOROUTE_STR "No route to host",
#define ENOTEMPTY_STR "Directory not empty",
#define EPROCLIM_STR "Too many processes",
#define EUSERS_STR "Too many users",
#define EDQUOT_STR "Disc quota exceeded",
#define ESTALE_STR "Stale NFS file handle",
#define EREMOTE_STR "Too many levels of remote in path",
#define EBADRPC_STR "RPC struct is bad",
#define ERPCMISMATCH_STR "RPC version wrong",
#define EPROGUNAVAIL_STR "RPC prog. not avail",
#define EPROGMISMATCH_STR "Program version wrong",
#define EPROCUNAVAIL_STR "Bad procedure for program",
#define ENOLCK_STR "No locks available",
#define ENOSYS_STR "Function not implemented",
#define EFTYPE_STR "Inappropriate file type or format",
#define EAUTH_STR "Authentication error",
#define ENEEDAUTH_STR "Need authenticator",
#define EPWROFF_STR "Device power is off",
#define EDEVERR_STR "Device error, e.g. paper out",
#define EOVERFLOW_STR "Value too large to be stored in data type",
#define EBADEXEC_STR "Bad executable",
#define EBADARCH_STR "Bad CPU type in executable",
#define ESHLIBVERS_STR "Shared library version mismatch",
#define EBADMACHO_STR "Malformed Macho file",
#define ECANCELED_STR "Operation canceled",
#define EIDRM_STR "Identifier removed",
#define ENOMSG_STR "No message of desired type",
#define EILSEQ_STR "Illegal byte sequence",
#define ENOATTR_STR "Attribute not found",
#define EBADMSG_STR "Bad message",
#define EMULTIHOP_STR "Reserved",
#define ENODATA_STR "No message available on STREAM",
#define ENOLINK_STR "Reserved",
#define ENOSR_STR "No STREAM resources",
#define ENOSTR_STR "Not a STREAM",
#define EPROTO_STR "Protocol error",
#define ETIME_STR "STREAM ioctl timeout",
#define EOPNOTSUPP_STR "Operation not supported on socket",
#define ENOPOLICY_STR "No such policy registered",
#define ENOTRECOVERABLE_STR "State not recoverable",
#define EOWNERDEAD_STR "Previous owner died",
#define EQFULL_STR "Interface output queue is full"