## Make targets

* `make`/`make all` Compiles the main executable, outputting a `simulation` file in the main folder.
* `make clean` Removes all compilation objects and the executable.
* `make test` Compile outputting a `test` executable in the main folder. It might take a little bit longer to run since it's also compiling the `catch2` library used for the tests.
* `make clean_test` Remove all compilation objects used for compiling the tests and the test executable.


