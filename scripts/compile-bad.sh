#! /bin/bash -e
CONDAENV=compile2
. $HOME/miniconda3/etc/profile.d/conda.sh
conda create -y -n $CONDAENV
conda activate $CONDAENV
conda install -y conda-build conda-verify conda-forge-pinning
conda build recipe --variant-config-file $CONDA_PREFIX/conda_build_config.yaml
