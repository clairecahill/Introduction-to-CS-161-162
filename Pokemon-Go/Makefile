CC = g++
exe_file = a.out
$(exe_file): cave.o driver.o event.o flying.o location.o pokemon.o pokestop.o psychic.o rock.o trainer.o
	$(CC) -g cave.o driver.o event.o flying.o location.o pokemon.o pokestop.o psychic.o rock.o trainer.o
cave.o: cave.cpp
	$(CC) -c cave.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
event.o: event.cpp
	$(CC) -c event.cpp
flying.o: flying.cpp
	$(CC) -c flying.cpp
location.o: location.cpp
	$(CC) -c location.cpp
pokemon.o: pokemon.cpp
	$(CC) -c pokemon.cpp
pokestop.o: pokestop.cpp
	$(CC) -c pokestop.cpp
psychic.o: psychic.cpp
	$(CC) -c psychic.cpp
rock.o: rock.cpp
	$(CC) -c rock.cpp
trainer.o: trainer.cpp
	$(CC) -c trainer.cpp
clean:
	rm -f *.out *.o $(exe_file)
debug: cave.o driver.o event.o flying.o location.o pokemon.o pokestop.o psychic.o rock.o trainer.o
	$(CC) -g cave.o driver.o event.o flying.o location.o pokemon.o pokestop.o psychic.o rock.o trainer.o
