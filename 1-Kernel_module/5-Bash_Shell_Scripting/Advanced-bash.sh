#Dealing with directories
if [ -d "/path/to/directory" ]; then
    echo "directory \"/path/to/directory\" exists"
fi

# Make sure path ends with /
for directory in '/home/wagdy/Desktop/embedded/'*; do
    if [[ -d "${directory}" && ! -L "${directory}" ]]; then
        echo "${directory}"
    fi
done


#check if the files exists inside a directory
for file in '/home/wagdy/Desktop/embedded/'*; do
    if [[ -f "${file}" && ! -L "${file}" ]]; then
        echo "${file}"
    fi
done




############## Functions ################
#1. Declare funcitons 
function print(){
    echo "$1"
    echo "$#" #print the number of arguments
    echo "$@" #print all the arguments
    echo "$*" #print all the arguments
    echo "$0" #print the name of the script
    echo "$?" #print the exit status of the last command
    echo "$$" #print the process id of the current script
    #tha hash carries integer datatype
    if(($# <3));then
        echo "The number of arguments is less than 3"
    else
        echo "The number of arguments is greater than 3"
    fi

}

#call the function
print "HHHHHHHHHHHHHHHHHi"




#######################################################################################
function sum(){
    declare -i RESULT=$(($1 + $2))
    echo "$RESULT"
    return 0
}
#we take the function return which's echo and store it in the variable

RESULT=$(sum 5 6)
echo "${RESULT}"