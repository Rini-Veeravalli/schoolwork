.PHONY: test

FLAGS = -std=c99 -Wall

all: codeword.exe

codeword.exe: codewordmain.c
	gcc $(FLAGS) codewordmain.c -o codeword.exe

test:
	test_files/testcodeword.py codeword.exe

clean:
	rm codeword.exe

python:
	python3 test_files/testcodeword.py codeword.exe

tmp:
	./codeword.exe --spellcheck test_files/words.txt try
