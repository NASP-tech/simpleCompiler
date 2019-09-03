rm dist/main
gcc -c main.c backend.c lex.c parser.c error.c
gcc main.o backend.o lex.o parser.o  error.o -o main
rm main.o backend.o lex.o parser.o  error.o
mv main dist/main
./dist/main