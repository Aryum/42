find . -type f -name "*.c" -exec cc -c -Wall -Wextra -Werror {} \;
ar -r libft.a *.o
ranlib libft.a