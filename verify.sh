#!/bin/bash

msg=$1

if [[ "${msg:0:1}" = [a-zA-Z] ]] ; 
	then
		if grep '^[-0-9a-zA-Z]*$' <<<$msg ; 
			then
				echo "Message is valid";
			else
				echo "Message is invalid";
		fi
	else
		echo "Message is invalid";
fi

