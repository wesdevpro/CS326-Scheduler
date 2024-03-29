unit_test: tests/unit_test_driver.c
	gcc -Wall -ansi -lm -o ./tests/unit_tests_runner.exe ./tests/unit_test_driver.c
	clear
	./tests/unit_tests_runner.exe || echo "what to do if error level ISN'T 0"
