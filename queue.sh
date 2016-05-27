#!/bin/bash

make -s
echo "-----"
echo "Ready to start!"
echo "Now you can send a message!"
echo "-----"
./send
echo "-----"
echo "You get: "
echo "----"
./receive
