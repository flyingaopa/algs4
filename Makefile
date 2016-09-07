all: shellsort insertsort mergesort quicksort
shellsort: shellsort.c
	gcc -Wall -g $< -o $@

insertsort: insertsort.c
	gcc -Wall -g $< -o $@

mergesort: mergesort.c
	gcc -Wall -g $< -o $@

quicksort: quicksort.c
	gcc -Wall -g $< -o $@
