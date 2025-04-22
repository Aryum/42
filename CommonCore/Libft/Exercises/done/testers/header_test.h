#include <stddef.h>

int atoi_logMessages(int(*func[2])(const char *), int printAll);

int char_logMessages(int (*func[2])(int), int printAll);

int cmp_logMessages(int(*func[2])(const void *, const void *, size_t), int printAll);

int memcpy_logMessages(void*(*func[2])(void *, const void *, size_t), int printAll);

int memmove_logMessages(void*(*funcs[2])(void *, const void *, size_t ), int printAll);

int mem_logMessages(void * (*func[2])(void *, int, size_t), int printAll);

int rchr_logMessages(void *(*func[2])(const void *, int, size_t), int printAll);

int split_logMessages(char **(*func)(char const *s, char c), int printAll);

int  strlen_logMessages(size_t (*func[2])(const char *), int printAll);

int strdup_logMessages(char *(*func[2])(const char *), int printAll);

int striteri_logMessages(void(*func)(char *s, void (*f)(unsigned int, char*)), int printAll);

int strjoin_logMessages(char	*(*func)(char const *, char const *), int printAll);

int strlcat_logMessages(size_t(*func[2])(char *, const char *, size_t), int printAll);

int strlcpy_logMessages(size_t(*func[2])(char *, const char *, size_t), int printAll);

int strmapi_logMessages(char	*(*func)(char const *s, char (*f)(unsigned int, char)), int printAll);

int strnstr_logMessages(char *(*func[2])(const char *, const char *, size_t), int printAll);

int strtrim_logMessages(char	*(*func)(char const *, char const *), int printAll);

int substr_logMessages(char	*(*func)(char const *, unsigned int, size_t), int printAll);

int tochr_logMessages(int(*func[2])(int), int printAll);

















