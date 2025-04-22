#pragma region TestHeader
#include "test_atoi.h"
#include "test_memcpy.h"
#include "test_memmove.h"
#include "test_rchr.h"
#include "test_split.h"
#include "test_strdup.h"
#include "test_striteri.h"
#include "test_strjoin.h"
#include "test_strlcpy.h"
#include "test_strmapi.h"
#include "test_strnstr.h"
#include "test_strtrim.h"
#include "test_substr.h"
#include "test_tochr.h"
#include "test_char.h"
#include "test_cmp.h"
#include "test_memset.h"
#include "test_str.h"
#pragma endregion

#include <stdlib.h>
#include <ctype.h>
#include <bsd/string.h>

#include "libft.h"

#pragma region Structs
typedef struct func
{
	char *name;
	int result;
} t_func;

static t_func create(char *name, int result)
{
	t_func ret;
	ret.name = name;
	ret.result = result; 
}
#pragma endregion

#pragma region Bzero
void *bzero_base(void* ptr,int c,size_t size)
{
	bzero(ptr,size);
	return ptr;
}

void *bzero_mine(void* ptr,int c,size_t size)
{
	ft_bzero(ptr,size);
	return ptr;
}
#pragma endregion

#pragma region Char
int isascii(int c)
{
	return ((c) & ~0x7f) == 0;
}
#pragma endregion

#pragma region rchr
void * strchr_base(const void *ptr,int c, size_t size)
{
	return (strchr((char *)ptr,c));
}

void * strchr_mine(const void *ptr,int c, size_t size)
{
	return (ft_strchr((char *)ptr,c));
}

#pragma endregion

#pragma region cmp
int strncmp_mine(const void * str1,const void * str2, size_t size)
{
	if(str1 == (void *)0 || str2 == (void *)0 )
		return 1;
	else
		return ft_strncmp((char *)str1,(char *)str2, size);
}

int strncmp_base(const void * str1,const void * str2, size_t size)
{
	if(str1 == (void *)0 || str2 == (void *)0 )
		return 1;
	else
		return strncmp((char *)str1,(char *)str2, size);
}
#pragma endregion

int main(int argc, char** agrv)
{
	//atoi
	int(*f_atoi[2])(const char *) = {atoi, ft_atoi};
	//mem
	void * (*f_bzero[2])(void *, int, size_t) = {bzero_base, bzero_mine};
	void * (*f_memset[2])(void *, int, size_t) = {memset, ft_memset};

	//char
	int (*f_isalnum[2])(int) = {isalnum, ft_isalnum};
	int (*f_isalpha[2])(int) = {isalpha, ft_isalpha};
	int (*f_isascii[2])(int) = {isascii, ft_isascii};
	int (*f_isdigit[2])(int) = {isdigit, ft_isdigit};
	int (*f_isprint[2])(int) = {isprint, ft_isprint};

	//rchr
	void *(*f_memchr[2])(const void *, int, size_t) = {memchr,ft_memchr};
	void *(*f_strchr[2])(const void *, int, size_t) = {strchr_base, strchr_mine};


	//cmp
	int(*f_memcmp[2])(const void *, const void *, size_t) = {memcmp, ft_memcmp};
	int(*f_strncmp[2])(const void *, const void *, size_t) = {strncmp_base, strncmp_mine};

	//cpy
	void*(*f_memcpy[2])(void *, const void *, size_t) = {memcpy, ft_memcpy};

	//memmove
	void*(*f_memmove[2])(void *, const void *, size_t ) = {memmove, ft_memmove};

	//strdup
	char *(*f_strdup[2])(const char *) = {strdup, ft_strdup};

	//strlcat
	size_t(*f_strlcat[2])(char *, const char *, size_t) = {strlcat, ft_strlcat};

	//strlcat
	size_t(*f_strlcpy[2])(char *, const char *, size_t) = {strlcpy, ft_strlcpy};

	//strlen
	size_t (*f_strlen[2])(const char *) = {strlen, ft_strlen};

	//strnstr
	char *(*f_strnstr[2])(const char *, const char *, size_t) = {strnstr,ft_strnstr};

	//to..
	int(*f_lower[2])(int) = {tolower, ft_tolower};
	int(*f_upper[2])(int) = {toupper,ft_toupper};

	t_func funcs[] =
	{
		//atoi
		create("Atoi", atoi_logMessages(f_atoi, argc != 1)),

		//mem
		create("Bzero", mem_logMessages(f_bzero, argc != 1)),
		create("Memset", mem_logMessages(f_bzero, argc != 1)),
		
		//char
		create("IsAllNum", char_logMessages(f_isalnum, argc != 1)),
		create("IsAlpha", char_logMessages(f_isalpha, argc != 1)),
		create("IsAscii", char_logMessages(f_isascii, argc != 1)),
		create("IsDigit", char_logMessages(f_isdigit, argc != 1)),
		create("IsPrint", char_logMessages(f_isprint, argc != 1)),
		
		//rchr
		create("MemChr",rchr_logMessages(f_memchr, argc != 1)),
		create("StrChr",rchr_logMessages(f_strchr, argc != 1)),

		//cmp
		create("MemCmp",cmp_logMessages(f_memcmp, argc != 1)),
		create("StrCmp",cmp_logMessages(f_strncmp, argc != 1)),

		//cpy
		create("MemCpy", memcpy_logMessages(f_memcpy, argc != 1)),

		//memmove
		create("MemMove", memmove_logMessages(f_memmove, argc != 1)),

		//split
		create("Split", split_logMessages(ft_split,argc != 1)),

		//strdup
		create("Strdup", strdup_logMessages(f_strdup, argc != 1)),

		//striteri
		create("StrIteri", striteri_logMessages(ft_striteri, argc != 1)),

		//strjoin
		create("StrJoin", strjoin_logMessages(ft_strjoin, argc != 1)),

		//strlcat
		create("StrCat", strlcat_logMessages(f_strlcat, argc != 1)),

		//strlcpy
		create("StrCpy", strlcpy_logMessages(f_strlcpy, argc != 1)),

		//strlen
		create("StrLen", strlen_logMessages(f_strlen, argc != 1)),

		//strmapi
		create("StrMapi",strmapi_logMessages(ft_strmapi, argc != 1)),

		//strnstr
		create("StrnStr", strnstr_logMessages(f_strnstr, argc != 1)),

		//strtrim
		create("StrTrim",strtrim_logMessages(ft_strtrim,argc != 1)),

		//substr
		create("SubStr",substr_logMessages(ft_substr,argc != 1)),

		//to...
		create("ToUpper",tochr_logMessages(f_upper, argc != 1)),
		create("ToLower",tochr_logMessages(f_lower, argc != 1)),

	};
}