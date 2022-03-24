#! /bin/bash -e
CONDAENV=run2
BUILDENV=compile2
LASIN=/tmp/in.las
LASOUT=/tmp/out2.las
VERSION=1.0.dev4
. $HOME/miniconda3/etc/profile.d/conda.sh
conda create -y -n $CONDAENV
conda activate $CONDAENV
conda install -y conda-build conda-verify conda-forge-pinning
conda install -y pdal=2.3
PACKAGE=$HOME/miniconda3/envs/${BUILDENV}/conda-bld/linux-64/eigentest-$VERSION-*tar.bz2
echo install $PACKAGE
conda install $PACKAGE
bare_eigentest
pdal translate \
     -f filters.eigentest --filters.eigentest.eigentest=true \
     $LASIN $LASOUT

