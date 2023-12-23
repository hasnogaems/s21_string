#ifndef S21_STRING_H
#define S21_STRING_H
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>

typedef long unsigned s21_size_t;
#define S21_NULL ((void *)0)

struct flag_type {
  int plus;
  int minus;
  int space;
  int is_short;
  int is_long;
  int precision;
  int width;
};

typedef struct flag_type flag_t;

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

void reset_flags(flag_t *flags);
char *print_char(char *str, flag_t *flags, char type, va_list *input);
char *print_string(char *str, flag_t *flags, va_list *input);
char *print_wide_string(char *str, flag_t *flags, va_list *input);
char *print_number(char *str, flag_t *flags, char type, va_list *input);
void s21_itos(char *str, long long int num, flag_t *flags);
void s21_ftos(char *str, double num, flag_t *flags);
void s21_uitos(char *str, unsigned long num, flag_t *flags);
int s21_sprintf(char *str, const char *format, ...);

#define S21EPERM_STR "Operation not permitted"
#define S21ENOENT_STR "No such file or directory"
#define S21ESRCH_STR "No such process"
#define S21EINTR_STR "Interrupted system call"
#define S21EIO_STR "Input/output error"
#define S21ENXIO_STR "Device not configured"
#define S21E2BIG_STR "Argument list too long"
#define S21ENOEXEC_STR "Exec format error"
#define S21EBADF_STR "Bad file descriptor"
#define S21ECHILD_STR "No child processes"
#define S21EDEADLK_STR "Resource deadlock avoided"
#define S21ENOMEM_STR "Cannot allocate memory"
#define S21EACCES_STR "Permission denied"
#define S21EFAULT_STR "Bad address"
#define S21ENOTBLK_STR "Block device required"
#define S21EBUSY_STR "Resource busy"
#define S21EEXIST_STR "File exists"
#define S21EXDEV_STR "Cross-device link"
#define S21ENODEV_STR "Operation not supported by device"
#define S21ENOTDIR_STR "Not a directory"
#define S21EISDIR_STR "Is a directory"
#define S21EINVAL_STR "Invalid argument"
#define S21ENFILE_STR "Too many open files in system"
#define S21EMFILE_STR "Too many open files"
#define S21ENOTTY_STR "Inappropriate ioctl for device"
#define S21ETXTBSY_STR "Text file busy"
#define S21EFBIG_STR "File too large"
#define S21ENOSPC_STR "No space left on device"
#define S21ESPIPE_STR "Illegal seek"
#define S21EROFS_STR "Read-only file system"
#define S21EMLINK_STR "Too many links"
#define S21EPIPE_STR "Broken pipe"
#define S21EDOM_STR "Numerical argument out of domain"
#define S21ERANGE_STR "Result too large"
#define S21EAGAIN_STR "Resource temporarily unavailable"
#define S21EINPROGRESS_STR "Operation now in progress"
#define S21EALREADY_STR "Operation already in progress"
#define S21ENOTSOCK_STR "Socket operation on non-socket"
#define S21EDESTADDRREQ_STR "Destination address required"
#define S21EMSGSIZE_STR "Message too long"
#define S21EPROTOTYPE_STR "Protocol wrong type for socket"
#define S21ENOPROTOOPT_STR "Protocol not available"
#define S21EPROTONOSUPPORT_STR "Protocol not supported"
#define S21ESOCKTNOSUPPORT_STR "Socket type not supported"
#define S21ENOTSUP_STR "Operation not supported"
#define S21EPFNOSUPPORT_STR "Protocol family not supported"
#define S21EAFNOSUPPORT_STR "Address family not supported by protocol family"
#define S21EADDRINUSE_STR "Address already in use"
#define S21EADDRNOTAVAIL_STR "Can't assign requested address"
#define S21ENETDOWN_STR "Network is down"
#define S21ENETUNREACH_STR "Network is unreachable"
#define S21ENETRESET_STR "Network dropped connection on reset"
#define S21ECONNABORTED_STR "Software caused connection abort"
#define S21ECONNRESET_STR "Connection reset by peer"
#define S21ENOBUFS_STR "No buffer space available"
#define S21EISCONN_STR "Socket is already connected"
#define S21ENOTCONN_STR "Socket is not connected"
#define S21ESHUTDOWN_STR "Can't send after socket shutdown"
#define S21ETOOMANYREFS_STR "Too many references: can't splice"
#define S21ETIMEDOUT_STR "Operation timed out"
#define S21ECONNREFUSED_STR "Connection refused"
#define S21ELOOP_STR "Too many levels of symbolic links"
#define S21ENAMETOOLONG_STR "File name too long"
#define S21EHOSTDOWN_STR "Host is down"
#define S21ENOROUTE_STR "No route to host"
#define S21ENOTEMPTY_STR "Directory not empty"
#define S21EPROCLIM_STR "Too many processes"
#define S21EUSERS_STR "Too many users"
#define S21EDQUOT_STR "Disc quota exceeded"
#define S21ESTALE_STR "Stale NFS file handle"
#define S21EREMOTE_STR "Too many levels of remote in path"
#define S21EBADRPC_STR "RPC struct is bad"
#define S21ERPCMISMATCH_STR "RPC version wrong"
#define S21EPROGUNAVAIL_STR "RPC prog. not avail"
#define S21EPROGMISMATCH_STR "Program version wrong"
#define S21EPROCUNAVAIL_STR "Bad procedure for program"
#define S21ENOLCK_STR "No locks available"
#define S21ENOSYS_STR "Function not implemented"
#define S21EFTYPE_STR "Inappropriate file type or format"
#define S21EAUTH_STR "Authentication error"
#define S21ENEEDAUTH_STR "Need authenticator"
#define S21EPWROFF_STR "Device power is off"
#define S21EDEVERR_STR "Device error"
#define S21EOVERFLOW_STR "Value too large to be stored in data type"
#define S21EBADEXEC_STR "Bad executable (or shared library)"
#define S21EBADARCH_STR "Bad CPU type in executable"
#define S21ESHLIBVERS_STR "Shared library version mismatch"
#define S21EBADMACHO_STR "Malformed Mach-o file"
#define S21ECANCELED_STR "Operation canceled"
#define S21EIDRM_STR "Identifier removed"
#define S21ENOMSG_STR "No message of desired type"
#define S21EILSEQ_STR "Illegal byte sequence"
#define S21ENOATTR_STR "Attribute not found"
#define S21EBADMSG_STR "Bad message"
#define S21EMULTIHOP_STR "EMULTIHOP (Reserved)"
#define S21ENODATA_STR "No message available on STREAM"
#define S21ENOLINK_STR "ENOLINK (Reserved)"
#define S21ENOSR_STR "No STREAM resources"
#define S21ENOSTR_STR "Not a STREAM"
#define S21EPROTO_STR "Protocol error"
#define S21ETIME_STR "STREAM ioctl timeout"
#define S21EOPNOTSUPP_STR "Operation not supported on socket"
#define S21ENOPOLICY_STR "Policy not found"
#define S21ENOTRECOVERABLE_STR "State not recoverable"
#define S21EOWNERDEAD_STR "Previous owner died"
#define S21EQFULL_STR "Interface output queue is full"

#define ERRORS_COUNT 106

typedef struct {
  const char *stringErrors[ERRORS_COUNT];
} errors;

#endif  // S21_STRING_H