#!/bin/bash
git clone https://github.com/nathanweeks/ipcmd.git
where=`pwd`
cd $where/ipcmd
make
make check
