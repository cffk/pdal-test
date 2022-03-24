#! /bin/bash -e
CONDAENV=run1
INSTALLDIR=/tmp/eigentest
LASIN=/tmp/in.las
LASOUT=/tmp/out1.las
. $HOME/miniconda3/etc/profile.d/conda.sh
conda create -y -n $CONDAENV
conda activate $CONDAENV
conda install -y conda-build conda-verify conda-forge-pinning
conda install -y pdal=2.3
$INSTALLDIR/bin/bare_eigentest
PDAL_DRIVER_PATH=$INSTALLDIR/lib:$PDAL_DRIVER_PATH \
		pdal translate \
		-f filters.eigentest --filters.eigentest.eigentest=true \
		$LASIN $LASOUT

