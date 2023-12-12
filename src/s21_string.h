#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>

typedef long unsigned s21_size_t;
#define s21_NULL ((void *)0)

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
typedef struct options{
     bool left_justify ;
     bool force_sign;
     bool space_for_positive ;
     bool alternate_form ;
     bool zero_padding ;
};
#define ERRORS_COUNT 106

#define EPERM_STR "Operation not permitted"
#define ENOENT_STR "No such file or directory"
#define ESRCH_STR "No such process"
#define EINTR_STR "Interrupted system call"
#define EIO_STR "Input/output error"
#define ENXIO_STR "Device not configured"
#define E2BIG_STR "Argument list too long"
#define ENOEXEC_STR "Exec format error"
#define EBADF_STR "Bad file descriptor"
#define ECHILD_STR "No child processes"
#define EDEADLK_STR "Resource deadlock avoided"
#define ENOMEM_STR "Cannot allocate memory"
#define EACCES_STR "Permission denied"
#define EFAULT_STR "Bad address"
#define ENOTBLK_STR "Block device required"
#define EBUSY_STR "Device / Resource busy"
#define EEXIST_STR "File exists"
#define EXDEV_STR "Cross-device link"
#define ENODEV_STR "Operation not supported by device"
#define ENOTDIR_STR "Not a directory"
#define EISDIR_STR "Is a directory"
#define EINVAL_STR "Invalid argument"
#define ENFILE_STR "Too many open files in system"
#define EMFILE_STR "Too many open files"
#define ENOTTY_STR "Inappropriate ioctl for device"
#define ETXTBSY_STR "Text file busy"
#define EFBIG_STR "File too large"
#define ENOSPC_STR "No space left on device"
#define ESPIPE_STR "Illegal seek"
#define EROFS_STR "Read-only file system"
#define EMLINK_STR "Too many links"
#define EPIPE_STR "Broken pipe"
#define EDOM_STR "Numerical argument out of domain"
#define ERANGE_STR "Result too large"
#define EAGAIN_STR "Resource temporarily unavailable"
#define EINPROGRESS_STR "Operation now in progress"
#define EALREADY_STR "Operation already in progress"
#define ENOTSOCK_STR "Socket operation on non-socket"
#define EDESTADDRREQ_STR "Destination address required"
#define EMSGSIZE_STR "Message too long"
#define EPROTOTYPE_STR "Protocol wrong type for socket"
#define ENOPROTOOPT_STR "Protocol not available"
#define EPROTONOSUPPORT_STR "Protocol not supported"
#define ESOCKTNOSUPPORT_STR "Socket type not supported"
#define ENOTSUP_STR "Operation not supported"
#define EPFNOSUPPORT_STR "Protocol family not supported"
#define EAFNOSUPPORT_STR "Address family not supported by protocol family"
#define EADDRINUSE_STR "Address already in use"
#define EADDRNOTAVAIL_STR "Can't assign requested address"
#define ENETDOWN_STR "Network is down"
#define ENETUNREACH_STR "Network is unreachable"
#define ENETRESET_STR "Network dropped connection on reset"
#define ECONNABORTED_STR "Software caused connection abort"
#define ECONNRESET_STR "Connection reset by peer"
#define ENOBUFS_STR "No buffer space available"
#define EISCONN_STR "Socket is already connected"
#define ENOTCONN_STR "Socket is not connected"
#define ESHUTDOWN_STR "Can't send after socket shutdown"
#define ETOOMANYREFS_STR "Too many references: can't splice"
#define ETIMEDOUT_STR "Operation timed out"
#define ECONNREFUSED_STR "Connection refused"
#define ELOOP_STR "Too many levels of symbolic links"
#define ENAMETOOLONG_STR "File name too long"
#define EHOSTDOWN_STR "Host is down"
#define ENOROUTE_STR "No route to host"
#define ENOTEMPTY_STR "Directory not empty"
#define EPROCLIM_STR "Too many processes"
#define EUSERS_STR "Too many users"
#define EDQUOT_STR "Disc quota exceeded"
#define ESTALE_STR "Stale NFS file handle"
#define EREMOTE_STR "Too many levels of remote in path"
#define EBADRPC_STR "RPC struct is bad"
#define ERPCMISMATCH_STR "RPC version wrong"
#define EPROGUNAVAIL_STR "RPC prog. not avail"
#define EPROGMISMATCH_STR "Program version wrong"
#define EPROCUNAVAIL_STR "Bad procedure for program"
#define ENOLCK_STR "No locks available"
#define ENOSYS_STR "Function not implemented"
#define EFTYPE_STR "Inappropriate file type or format"
#define EAUTH_STR "Authentication error"
#define ENEEDAUTH_STR "Need authenticator"
#define EPWROFF_STR "Device power is off"
#define EDEVERR_STR "Device error, e.g. paper out"
#define EOVERFLOW_STR "Value too large to be stored in data type"
#define EBADEXEC_STR "Bad executable"
#define EBADARCH_STR "Bad CPU type in executable"
#define ESHLIBVERS_STR "Shared library version mismatch"
#define EBADMACHO_STR "Malformed Macho file"
#define ECANCELED_STR "Operation canceled"
#define EIDRM_STR "Identifier removed"
#define ENOMSG_STR "No message of desired type"
#define EILSEQ_STR "Illegal byte sequence"
#define ENOATTR_STR "Attribute not found"
#define EBADMSG_STR "Bad message"
#define EMULTIHOP_STR "Reserved"
#define ENODATA_STR "No message available on STREAM"
#define ENOLINK_STR "Reserved"
#define ENOSR_STR "No STREAM resources"
#define ENOSTR_STR "Not a STREAM"
#define EPROTO_STR "Protocol error"
#define ETIME_STR "STREAM ioctl timeout"
#define EOPNOTSUPP_STR "Operation not supported on socket"
#define ENOPOLICY_STR "No such policy registered"
#define ENOTRECOVERABLE_STR "State not recoverable"
#define EOWNERDEAD_STR "Previous owner died"
#define EQFULL_STR "Interface output queue is full"

char *errorStrings[] = {EPERM_STR,
                        ENOENT_STR,
                        ESRCH_STR,
                        EINTR_STR,
                        EIO_STR,
                        ENXIO_STR,
                        E2BIG_STR,
                        ENOEXEC_STR,
                        EBADF_STR,
                        ECHILD_STR,
                        EDEADLK_STR,
                        ENOMEM_STR,
                        EACCES_STR,
                        EFAULT_STR,
                        ENOTBLK_STR,
                        EBUSY_STR,
                        EEXIST_STR,
                        EXDEV_STR,
                        ENODEV_STR,
                        ENOTDIR_STR,
                        EISDIR_STR,
                        EINVAL_STR,
                        ENFILE_STR,
                        EMFILE_STR,
                        ENOTTY_STR,
                        ETXTBSY_STR,
                        EFBIG_STR,
                        ENOSPC_STR,
                        ESPIPE_STR,
                        EROFS_STR,
                        EMLINK_STR,
                        EPIPE_STR,
                        EDOM_STR,
                        ERANGE_STR,
                        EAGAIN_STR,
                        EINPROGRESS_STR,
                        EALREADY_STR,
                        ENOTSOCK_STR,
                        EDESTADDRREQ_STR,
                        EMSGSIZE_STR,
                        EPROTOTYPE_STR,
                        ENOPROTOOPT_STR,
                        EPROTONOSUPPORT_STR,
                        ESOCKTNOSUPPORT_STR,
                        ENOTSUP_STR,
                        EPFNOSUPPORT_STR,
                        EAFNOSUPPORT_STR,
                        EADDRINUSE_STR,
                        EADDRNOTAVAIL_STR,
                        ENETDOWN_STR,
                        ENETUNREACH_STR,
                        ENETRESET_STR,
                        ECONNABORTED_STR,
                        ECONNRESET_STR,
                        ENOBUFS_STR,
                        EISCONN_STR,
                        ENOTCONN_STR,
                        ESHUTDOWN_STR,
                        ETOOMANYREFS_STR,
                        ETIMEDOUT_STR,
                        ECONNREFUSED_STR,
                        ELOOP_STR,
                        ENAMETOOLONG_STR,
                        EHOSTDOWN_STR,
                        ENOROUTE_STR,
                        ENOTEMPTY_STR,
                        EPROCLIM_STR,
                        EUSERS_STR,
                        EDQUOT_STR,
                        ESTALE_STR,
                        EREMOTE_STR,
                        EBADRPC_STR,
                        ERPCMISMATCH_STR,
                        EPROGUNAVAIL_STR,
                        EPROGMISMATCH_STR,
                        EPROCUNAVAIL_STR,
                        ENOLCK_STR,
                        ENOSYS_STR,
                        EFTYPE_STR,
                        EAUTH_STR,
                        ENEEDAUTH_STR,
                        EPWROFF_STR,
                        EDEVERR_STR,
                        EOVERFLOW_STR,
                        EBADEXEC_STR,
                        EBADARCH_STR,
                        ESHLIBVERS_STR,
                        EBADMACHO_STR,
                        ECANCELED_STR,
                        EIDRM_STR,
                        ENOMSG_STR,
                        EILSEQ_STR,
                        ENOATTR_STR,
                        EBADMSG_STR,
                        EMULTIHOP_STR,
                        ENODATA_STR,
                        ENOLINK_STR,
                        ENOSR_STR,
                        ENOSTR_STR,
                        EPROTO_STR,
                        ETIME_STR,
                        EOPNOTSUPP_STR,
                        ENOPOLICY_STR,
                        ENOTRECOVERABLE_STR,
                        EOWNERDEAD_STR,
                        EQFULL_STR};