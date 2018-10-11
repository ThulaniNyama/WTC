#!/bin/bash

RANGE=$(seq "$1")
FAILED=0
COUNT=0

print_status () {
	echo "list:"
	echo "$ARG"
	echo "is sorted:"
	echo "$RES"
	echo "line count:"
	echo "$LC"
	echo "failed on $COUNT"
}

trap 'echo; echo "$((COUNT-FAILED))"/"$COUNT"; exit' INT

while [ true ];
do
	ARG=$(echo "$RANGE" | tr " " "\n" | perl -MList::Util=shuffle -e 'print shuffle<STDIN>' | tr "\n" " ")
	INSTR=$(./push_swap "$ARG")
	RES=$(echo "$INSTR" | ./checker "$ARG")
	LC=$(echo "$INSTR" | wc -l | tr -d " ")
	let COUNT++
	if [ "$RES" != "OK" ]
	then
		let FAILED++
		print_status
		break
	fi
	if [ "$LC" -gt $2 ]
	then
		let FAILED++
		if ! [ "$3" ]
		then
			print_status
			break
		fi
	fi
	echo "$LC"
	if [ "$3" ] && [ $COUNT -ge $3 ]
		then break
	fi
done < <(true)

if [ "$3" ]
	then echo "$((COUNT-FAILED))"/"$COUNT"
fi
