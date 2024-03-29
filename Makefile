# Build and run 
all:
	make build
	make run

build: src/scheduler.c
	gcc -Wall -ansi -lm -o ./build/scheduler.exe ./src/scheduler.c

run: build/scheduler.exe
	clear
	./build/scheduler.exe

int_test: tests/integration_test_driver.c
	gcc -Wall -ansi -lm -o ./tests/integration_test_driver.exe ./tests/unit_tests_runner.c
	clear
	./tests/unit_test_driver.exe

unit_test: tests/unit_test_driver.c
	gcc -Wall -ansi -lm -o ./tests/unit_tests_runner.exe ./tests/unit_test_driver.c
	clear
	./tests/unit_tests_runner.exe

rand_test: tests/rand_tests.c
	gcc -Wall -ansi -lm -o ./tests/rand_test.exe ./tests/rand_tests.c
	clear
	./tests/rand_test.exe


