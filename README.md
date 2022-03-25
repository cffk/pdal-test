# pdal-test

This illustrates a bad interaction with eigen pdal and conda-build.

*UPDATE*: this bug has been fixed by specifying the conda build
 dependency `eigen=3.3.9` compatible with what was used for pdal.

## Introduction

The test code in `src` consists of a simple do-nothing pdal filter
(copied from the `pdal.io` site) which optionally, with
`--filters.eigentest.eigentest=true`, solves a simple least squares
problem with eigen.  There's also a standalone program (not involving
pdal) which solves the same problem using the same block of code.

The code can be compiled in two ways:

1. doing `conda install pdal=2.3`, and building the code with cmake.
   In this case the two methods of solving the least squares problem
   (with the standalone code and by running the pdal filter) give the
   same (correct) result.

2. using `conda build`, relying on the recipe in the `recipe`
   directory.  In this case, the standalone code give the correct
   result for the least squares problem; the result from the pdal
   filter is garbage.

## Prerequisites

1. A miniconda environment (testing done on an Ubuntu 18 system).

2. The scripts create environments `{compile,run}{1,2}`.  These should
   not exist ahead of time.

3. The scripts expect to install into `/tmp/eigentest`.

4. `/tmp/in.las` should be a valid (smallish) las file.  The scripts
   expect to write output to `/tmp/out{1,2}.las`.

This behavior can be configured by the variables set at the top of the
scripts.

## Compiling with cmake

Run

```
scripts/compile-good.sh > compile-good.log 2>&1
scripts/run-good.sh > run-good.log 2>&1
```

The end `run-good.log` is

```
z = A\B (standalone eigen) =
 -0.146455
  -1.74294
   6.27609
 -0.655561
-0.0612884
 -0.183508
z = A\B (pdal eigen) =
 -0.146455
  -1.74294
   6.27609
 -0.655561
-0.0612884
 -0.183508
```

showing the same (correct) output with the standalone and pdal filter
solutions.


## Compiling with conda build

Run

```
scripts/compile-bad.sh > compile-bad.log 2>&1
scripts/run-bad.sh > run-bad.log 2>&1
```

The end `run-bad.log` is

```
z = A\B (standalone eigen) =
 -0.146455
  -1.74294
   6.27609
 -0.655561
-0.0612884
 -0.183508
z = A\B (pdal eigen) =
 2.34287e-309
 3.57307e-309
-1.02527e-309
-2.84016e-309
 2.50931e-309
-5.23097e-306
```

The standalon eigen solution is correct.  The eigen solution from the
pdal filter is bogus.
