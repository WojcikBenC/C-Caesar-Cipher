main.o: main.c
  g++ -c main.c

caesar.o: caesar.c
  g++ -c caesar.c

out: main.o caesar.o
  g++ -o out main.o caesar.o
