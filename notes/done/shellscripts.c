Benefits:
- Automate tasks
- Simple commands
- Users are given a controlle dinterface
- combination of utilities to forma  new commands
- Quick protoyping of functionalities wthout compiling codes

First Line
#!/bin/bash -> path of interpreter
save file with ".sh" extension (shell)

e.g. Write a hello world shell script
#!/bin/bash
echo "Hello World"

Make Executable
 - change permissions to make the file executable
 - cmod u+x[fileName].sh

'#': comment

Interactive script
e.g. Write a script that will read your name and student id and display to output
#!/bin/bash
echo "What is your name?"
read name
echo "Enter your student ID"
read id
echo your name is $name and your id is $id

Return
- can use Exit command to set return value
- '$?' to view return value of most recent command

\: used at end of line command
  - indicate continuation in the next line/split line into multiple lines
';': interpret what is next as new command
  - separate the commands
  - execute one after the other
  - chaining commands, merge commands
  - '&&' abort subsequent commands if one fails
  - '||' proceed until success

e.g. Go to home dir -> ls using long listing -> Go to cs246 folder -> list files  (on same line)
#!/bin/bash
cd~; ls -l; cd cs246; ls

Script Parameters
$0 script name
$1, $2, ... First, Second, ... Parameters
$* all parameters
$# number of parameters

e.g. Write a program that takes 2 files names as input. Take the first 3 lines of a first input file1 and the last 3 lines of second input file, all lines reversed.  It should save the output in merge3rev.out
#!/bin/bash
head -3 $1 > temp
tail -3 $2 >> temp
tac temp > merge3rev.out
rm temp

Command Substitution
- store result of a command
- Enclose inner command with backticks '``' or enclose with '$()'
- innermost command is executed first and its standard output is inserted where substitution is done
- '$()' allows nesting

'expr': evaluate an expression
  - arithmetics
  - comparison
  - logical
  - '$(())' or '$(expr ...)'
  - e.g. Add two inputs and print both summation
  #!/bin/bash
  result=$(expr $1 + $2)
  echo $1 + $2 = $result

'export': makes variable availble to child processes
  - 'export VAR=value'
  - 'export' list of env vars

Functions
  - execute procedures by building code blocks that implements a set of operations
  - function(){}
  - to read arguments from function, use $1, $2

Single vs Double Quotes
- echo "$HOME" -> /home/rcykoh
- echo '$HOME' -> $HOME

Conditionals
'if [condition]
then
  statements
elif [condition]
then
  statements
else
  statements
fi'


File Testing
- use of square brackets
- '-f' check if regular file exists
- '-e' check if file exists
- '-d' checks if directory
- '-r -w -x' check if readable, writable, executable
Number Testing
- 'eq' equals '-ne' not equals
- '-gt -lt -ge -le' greater, less, greater or equal, less or requal

Boolean Expression
- '&&' and
- '||' or
- '!' not
-  '==' if two strings are equal
e.g. Read the total points the student collected and display 'Pass' if grade >= 50 and "Fail" if grade < 50
'#!/bin/bash
echo "What is your grade?"
read grade
if [ grade -ge 50]; then
  echo "Pass"
else
  echo "Fail"
fi'

Case statements
- compare variable against different values
- e.g. Write a function that takes 3 inputs from user.  First number is add or subtract, the other are numbers to add/subtract.  Write a program that implements the addition/subtraction
'#!/bin/bash
add(){
  result=$(($1 + $2))
}
subtract(){
  result=$(($1 - $2))
}
if [$# -ne 3] || !([$1 == "add"] || [$1 == 'sub']); then
  echo "Please input 3 arguments: (add or subtract), number1, number2"
  exit 1
else
  $1 $2 $3
fi
echo result is $result'
  - e.g. Convert grade to letter format
  '#!/bin/bash
  if [$1 -gt 100]; then echo "error"
  elif [$1 -ge 95]; then echo "A+"
  elif [$1 -ge 85]; then echo "A"
  .
  .
  .
  else echo "Error"
  fi'

String Manipulation
 - ${#string} returns length of string
 - ${string:s:n} returns usbstring from start to length n
 - ${string#*.} extract chars after .
 - ${string%txt} extract string before txt

For loops
  - 'for var in list
    do
      commands
    done'
  -e.g. Search for c files in the system, create dir CFolder, move the files to that dir, create a header file for each c file
  '#!/bin/bash
  mkdir CFolder
  for filename in *.c
  do
    mv $filename CFolder
    touch CFolder/${filename%.c}.h
  done'
  - e.g. Write a shell that reads a filename and returns how many distinct words exists
  '#!/bin/bash
  for word in $(cat $1); do
    echo $word >> tmp
  done
  distinctwords = $(sort tmp | uniq | wc -l)
  echo "The total number of distinct words is $distinctwords"'
  - e.g. Count the number of articles in file (a, the, The)
  '#!/bin/bash
  articleCount=0
  for word in $(cat $1); do
    if [$word == "The"]
    then articleCount=$((articleCount + 1))
    fi
  done
  echo articleCount'

While Loops
- e.g. Write a function that calculates the factorial
'#!/bin/bash
num=$1
fact=1
while [num -gt 0]; do
fact=$(($fact * num))
num=$(($num - 1))
done
echo fact'

Until
 - until condition is false
