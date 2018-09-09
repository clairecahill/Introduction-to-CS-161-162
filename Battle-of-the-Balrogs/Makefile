CC = g++
exe_file = a.out
$(exe_file): world.o creature.o demon.o human.o elf.o balrog.o cyberdemon.o driver.o
	$(CC) world.o creature.o demon.o human.o elf.o balrog.o cyberdemon.o driver.o
world.o: world.cpp
	$(CC) -c world.cpp
creature.o: creature.cpp
	$(CC) -c creature.cpp
demon.o: demon.cpp
	$(CC) -c demon.cpp
human.o: human.cpp
	$(CC) -c human.cpp
elf.o: elf.cpp
	$(CC) -c elf.cpp
balrog.o: balrog.cpp
	$(CC) -c balrog.cpp
cyberdemon.o: cyberdemon.cpp
	$(CC) -c cyberdemon.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
clean:
	rm -f *.out *.o $(exe_file)
