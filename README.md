# pdal-test

This illustrates a bad interaction with eigen pdal and conda-build.

## Introduction

Check out this repository.

The test code in `src` consists of a simple do-nothing pdal filter
which optionally, with `--filters.eigentest.eigentest=true`, solves a
simple least squares problem with eigen.  There's also a standalone
program (not involving pdal) which solves the same problem.

Verify the variable settings in
```
scripts/*.sh
```
and adjust if necessary.

## Working build

This uses conda to provide eigen and pdal, but does a "manual" cmake build
using system supplied (Ubuntu 18) compiler.

Run
```
scripts/compile-good.sh
scripts/run-good.sh
```

The eigen solutions from the standalone program and pdal filter are
the same (and are correct).

## Broken build

This uses conda build using the conda approved compiler

Run
```
scripts/compile-good.sh
scripts/run-good.sh
```

The eigen solution from the standalone program is correct.  The eigen
solution from the pdal filter is bogus.
