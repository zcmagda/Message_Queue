#!/bin/bash

word=$1
lg=`echo ${#word}`
if [[ "${word:0:1}" = [a-zA-Z] ]] ; then
	#if [[ "$word" = [a-zA-Z0-9]{1,${lg}} ]] ; then
		echo "$lg"
	#fi
fi
