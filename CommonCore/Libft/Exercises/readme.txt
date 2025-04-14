CHECK FOR THINGS THAT CAN BE SIMPLIFIED
	
	strcpy	-might use- memcpy
	strchr	-might use- memchr

CHAR
	• isalpha	-> DONE
	• isdigit	-> DONE
	• isalnum	-> DONE
	• isascii	-> DONE
	• isprint	-> DONE
STRLEN
	• strlen	-> DONE
MEMSET
	• memset	-> DONE
	• bzero		-> DONE
CMP
	• memcmp	-> DONE
	• strncmp 	-> DONE

TOCHR
	• toupper 	-> needs test header
	• tolower	-> needs test header

CPY
	• memcpy	-> needs test header (CHECK MAN) attention to sobreposition on the same string 
										pay attention to the poisition of pointers
	• strlcpy
	
MEMCHR
	• strchr 	-> needs test header
	• strrchr	-> needs test header
	• memchr

• memmove
• strlcat
• strnstr
• atoi

To implement the two following functions, you will use malloc():
• calloc
• strdup