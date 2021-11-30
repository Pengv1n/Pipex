all:
	gcc *.c libft/*.c -o pipex
	./pipex a "grep a" "wc -c" b
clean:
	rm -f pipex
