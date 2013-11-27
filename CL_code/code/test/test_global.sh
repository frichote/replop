#!/bin/sh

. ./meta.sh

dir="bituint convert createDataSet crossEntropy io LFMM main matrix nnlsm pca sNMF"

sh test_run.sh

sh test_stat.sh
