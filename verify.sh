#!/bin/bash

msg=$1

if [[ "${msg:0:1}" = [a-zA-Z] ]] ; 
then
	if [[ $msg == *[[:ascii:]]* ]]
	then
		check=`echo ${msg} | aspell list -l pl`

		if [[ "${check}" == "" ]] ;
		then
			echo "Przeslane slowo jest poprawne w jezyku polskim";
		else
			echo "Przeslane slowo nie jest poprawne w jezyku polskim";
		fi
	else
		echo "Przeslana wiadomosc nie sklada sie ze znakow ASCII";
	fi
else
	echo "Przeslana wiadomosc nie rozpoczyna sie od litery";
fi
#grep '^[0-9a-zA-Z]*$' <<<$msg ; 
