# LEAKS = leaks -atExit -- 

# EXCEPTION CHECKING
exception:
	g++ throw_exception_experiment.cc
	$(LEAKS) ./a.out

# CREATE AND PRINT ARRAY OF MATRICES
array:
	g++ matrix_array.cc ../src/*
	$(LEAKS) ./a.out

# POINTER(*) VS REFERENCE(&)
ptrref:
	g++ -O1 -g0 -S ptrref.cc

# TESTS ENVIRONMENT
env1:
	gcc -lstdc++ -lgtest -pthread environment_stackoverflow.cc
	./a.out
	make clean   

env2:
	gcc -lstdc++ -lgtest -pthread environment_stackoverflow_changed.cc
	./a.out
	make clean   

# SERVICE
clean:
	rm a.out
