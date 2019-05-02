To be able to compile the project, gcc has to be installed.

To use anoter compiler, change `CC=gcc` to `CC=${compiler}` in the makefile.

### Run main program (train network)

Compile and run the program like this:

```bash
$ make
```
 or
```bash
make main
```

If you get te response `make: 'main' is up to date.`, run the program like this:

```bash
./main`
```

#### Run demo (see future wave height predictions)

Compile and run the program like this:

```
make demo
```

If you get te response `make: 'demo' is up to date.` run the program like this:

```bash
./demo`
```

#### Run test (runs all unit tests)

Compile and run the program like this:

```
make test
```

If you get te response `make: 'test' is up to date.` run the program like this:

```bash
./test`
```