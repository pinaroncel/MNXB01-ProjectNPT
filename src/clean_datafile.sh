#!/bin/bash

########################################################################
#
# Descritpion: This script takes as input
#		- A raw data file that contains first few lines of text and rows of data sets
#		- Creates a temporary file that will copy and process the origianl data file
#		- Copies processed temporary file into a cleaned data file.
#		- Removes temporary file
#
# Example on how to initialise script:
#		./clean_data.sh <Data File Name>.csv
#
########################################################################
# Functions. When error is present, one of these functions is called to explain how to use the script.

missingparam(){
	echo "Missing first parameter"
	echo "Usage:"
	echo "   $0 <Data File Name>.csv”
	echo
	echo "Exiting”
}

manyparam(){
	echo "Too many parameters given."
	echo "Usage:"
	echo "   $0 <Data File Name>.csv”
	echo
	echo "Exiting”
}

directoryfile(){
	echo "Input is a directory and not a file."
	echo "Usage:"
	echo "   $0 <Data File Name>.csv”
	echo
	echo "Exiting”
}

########################################################################

DATAFILEINPUT=$1

if [[ $# == 0 ]]; then
	missingparam
	#exiting with error
	exit 1;
elif [[ $# -ge 2 ]]; then
	manyparam
	#exiting with error
	exit 1;
fi

DATAFILE=$(basename $DATAFILEINPUT)

if [ -f "$DATAFILE" ]; then
	echo "File $DATAFILE found."

elif [ -d "$DATAFILE" ]; then
	directoryfile
	exit 1;
else
	echo "File not found."
	echo "Exiting"
	exit 1;
fi

STARTLINE=$(grep -n 'Datum' $DATAFILE | cut -d ":" -f 1) # Variable {STARTLINE} contains line number before data starts.
STARTDATA=$(($STARTLINE + 1)) # Variable {STARTDATA} contains line number where data starts.

echo
echo "Creating temporary file..."
TMPFILE=$(mktemp ./tmp.XXXXX)

# Copying original file into tmp.XXXXX
cp $DATAFILE $TMPFILE

# Manipulating tmp.XXXXX file data set to the desired state
echo "Cleaning raw data set..."
tail -n -$STARTDATA $DATAFILE | cut -d ";" -f 1-4 | sed 's/;/,/g' > $TMPFILE

#Copying cleaned data file into output file.
cp $TMPFILE clean_$DATAFILE
rm $TMPFILE
echo
echo "Temporary file removed."
echo "Cleaned data is stored in clean_$DATAFILE."

