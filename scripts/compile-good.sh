#! /bin/bash -exv
CONDAENV=compile1
INSTALLDIR=/tmp/eigentest
. $HOME/miniconda3/etc/profile.d/conda.sh
conda create -y -n $CONDAENV
conda activate $CONDAENV
conda install -y conda-build conda-verify conda-forge-pinning
conda install -y pdal=2.3
mkdir -p BUILD
cd BUILD
rm -rf *
cmake -D CMAKE_INSTALL_PREFIX=$INSTALLDIR ..
make -j10 all install
