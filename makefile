codes = test
 all: $(codes)

 $(codes): %: %.c
	gcc -o $@ $<
