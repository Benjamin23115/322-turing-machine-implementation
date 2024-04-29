BINS = TuringMachine

CC = g++
CFLAGS = -g -Wall 

LDFLAGS = -lm -lrt -lstdc++

.PHONY: default
default: $(BINS)

turing_machine.o: turing_machine.cpp turing_machine.h
	$(CC) $(CFLAGS) -c $< -o $@

crash.o: crash.cpp crash.h
	$(CC) $(CFLAGS) -c $< -o $@

final_states.o: final_states.cpp final_states.h
	$(CC) $(CFLAGS) -c $< -o $@

states.o: states.cpp states.h
	$(CC) $(CFLAGS) -c $< -o $@

tape.o: tape.cpp tape.h 
	$(CC) $(CFLAGS) -c $< -o $@

uppercase.o: uppercase.cpp uppercase.h 
	$(CC) $(CFLAGS) -c $< -o $@

input_alphabet.o: input_alphabet.cpp input_alphabet.h
	$(CC) $(CFLAGS) -c $< -o $@

transition.o: transition.cpp transition.h
	$(CC) $(CFLAGS) -c $< -o $@

transition_function.o: transition_function.cpp transition_function.h
	$(CC) $(CFLAGS) -c $< -o $@

tape_alphabet.o: tape_alphabet.cpp tape_alphabet.h
	$(CC) $(CFLAGS) -c $< -o $@	

input_strings.o: input_strings.cpp input_strings.h
	$(CC) $(CFLAGS) -c $< -o $@	

main.o: main.cpp turing_machine.h
	$(CC) $(CFLAGS) -c $< -o $@	

.PHONY: clean
clean:
	rm -f core* *.o *~

# TuringMachine: main.o
# 	$(CC) $(LDFLAGS) $^ $(LIBRARIES) -o $@

TuringMachine: main.o turing_machine.o input_strings.o crash.o input_alphabet.o final_states.o states.o tape.o transition.o uppercase.o transition_function.o tape_alphabet.o
	$(CC) $(LDFLAGS) $^ $(LIBRARIES) -o $@

.PHONY: immaculate
immaculate: clean
	rm -f $(PROGRAM)

