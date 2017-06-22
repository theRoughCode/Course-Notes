CS 246
Office Hours: 3.15 - 4.45pm DC2569A

Linux

cat: prints out the content of a file or combine multiple files to standard output
 - 'cat file1.txt' prints out file1.txt
 - 'cat file1.txt' file2.txt combines both files
 - 'cat' takes in keyboard input and outputs it (ctrl+D ends)
 - 'cat file1.txt - file2.txt' takes in file1.txt, then keyboard (end with ctrl+D), then file2.txt
 - 'man cat' provides info about cat command

 Ctrl-C: kills a process and stops what it is doing by sending an interrupt signal
 Ctrl-D: EOF signal

head: displays first few (10) lines of a file
tail: displays last few (10) lines of a file
  - can specify the number of lines by using '-n[# of lines]' option (e.g. '-n4') or '-[# of lines]'

Secure Shell (SSH)
- allows user to access secure machine
- work in remote environment

ls: lists the contents of the current directory
  - 'ls -a' lists all contents including hidden files (files that start with '.')
  - 'ls -l' lists the contents of a directory in a long listing format
    - 'ls -l [filename]' displays info for a file in long listing format

pwd: shows the current working directory

cd: change directory
  - 'cd'/'cd ~' home directory
  - 'cd [directory]'specified directory
  - 'cd ..' parent directory
  - 'cd /' root directory
  - 'cd -' previous directory
  - Absolute directory begins with '/'
  - Relative directory begins with current './'/parent '../'/home directory '~/'

exit: terminates the shell session
echo: write arguments, separated by spaces and terminated with a newline
  - 'echo ${var}' displays var
rm: remove
  - 'rm -f' force remove
  - 'rm -i' removes interactively by asking first
  - 'rm -r' recursively removes a direectory with all its contents

Standard File Streams
3 standard file streams:
1. stdin with descriptor value of 0 (e.g. keyboard)
2. stdout with descriptor value of 1 (e.g. terminal)
3. stderr with descriptor value of 2 (e.g. logfile)

Input Redirection: stdin is often supplied by directing an input to come from a file or previous output command using Pipe
  - 'doCommand < input_file': e.g. 'cat < file1.txt'
  - 'cat < file1.txt' redirects keyboard input from file1.txt while 'cat file1.txt' opens the file and prints out content

  Output Redirection: stdout is often redirected to a file, sterr is usually printed to terminal but sometimes redirected to a log file
    - 'doCommand > output_file'
    - 'doCommand 2> error_file'  (include 2 to redirect stderr)
    - e.g. Save content of keyboard input to file 'cat > output_file.txt'
    - e.g. Combine file1 and file2 to new file 'cat file1.txt file2.txt > output_file.txt'
    - 'doCommand > output_file 2>&1' redirect the error messages to the sampe location where ouput is (or in bash: 'doCommand >% output_file')
    - 'doCommand >> output_file' appends to start of file

less: loads a text file one page at a time rather than all at once
wc: displays the number of words, bytess, lune a fike
  wc -w word count
  wc -l line count
sort: sort lines of text file (alphabetical)
  - Lines starting with a number will appear before lines starting with a letter.
  - Lines starting with a letter that appears earlier in the alphabet will appear before lines starting with a letter that appears later in the alphabet.
  - Lines starting with a lowercase letter will appear before lines starting with the same letter in uppercase.
  - sort -r: sorts in reverse order
who: lists the currently logged-in users to the system
whoami: lists current user

Wildcards
  - used for pattern matching, can be sused to search for files names with specific characters
  - '?' replaces a single char/digit
  - '*' replaces any string
  - e.g. show the content fo all files that start with the word file then a single character of digit of type.txt
    - 'cat file?.txt'
  - e.g. list all files that has the word file anywhere in its name
    - 'ls *file*.txt'
  - '[set]' matches any character in the set **
    - '[infp]' will match i or n or f or p
    - 'ls [0-9]*.txt' lists the txt files that start with a digit
  - '[!set]' matches any character not in the set
    - 'ls [!0-9]*.txt' lists the txt files that do not start with a digit

Pipes
- can pipe the output of certain commands into the input of another command
- 'commandA | commandB | commandC'
- e.g. display lines 10 and 11 of file3.txt
  - 'head -n11 file3.txt | tail -n2'

**
Users and Groups
 - Each user is assigned a userid
 - /etc/groups

File Permissions
 - 'd' = directory
 - files have 3 different types of permissions:
  - read (r)
  - write (w)
  - execute (x)

  - user (u)
  - group (g)
  - others (o)
  - all (a)

  - e.g. 'drwxr-xr-x'
    - 'd' directory
    - 'rwx' user has rwx access
    - 'r-x' group has r and x access
    - 'r-x' others have r and x access
  - chmod: change permissions of a file
    - '+' add permission
    - '-' remove perssion
    - '=' set permission
    - e.g. 'chmod u-r file' remove read permission from user for file
    - e.g. 'chmod o+x file' add execute permission to others
    - e.g. 'chmod a=rwx file' give everybody full control

which: search where an application resides
  - 'which ls' finds out where the ls command resides
whereis: search broader range of directories and locate the source and man packages of the application
  - 'whereis man'

tree: displays tree view of file system
  - 'tree cs246' displays tree view of cs246 folder
tac: start from last line of a file and displays its contents backwards
  - 'tac file1.txt' displays the contents of file1.txt backwards
  - 'tac file1.txt file2.txt file3.txt' flips each file in order
touch: update the file timestamp to match the current time
  - can be used to update the access, change and modify time
  - if file doesnt exist, it creates an empty file
  - 'touch -t' sets time
    - 'touch tomato' creates a file called tomato
    - 'touch -t 0606060606 tomato' sets time stamp  of tomato to June 6, 2006, 6:06am
    - 'touch tomato' updates timestamp of tomato
stat: displays the detailed status of a particular file or file system
mkdir: create new directory
  - 'mkdir A A/B1 A/B2 A/B1/C1 A/B1/C2 A/B1/C1/D1' creates a tree
rmdir: remove empty directory
  - 'rmdir A/B1/C2' removes the C2 directory
mv: move or/and rename a file
  - 'mv alice.txt cs246/alicewonderland.txt' moves alice.txt into cs246 and rename to alicewonderland.txt
sudo: run a program by the use of security privilege of another user often the root or super user
locate: search through a previously created database of files and directory to find a match of your entry
  - 'locate alicewonderland' locates previously created alicewonderland
  - 'updatedb' updates database (when creating new files)
find:
  - 'find [dir] -name file_name'
  - 'find / -name ubunto > ubuntofiles.txt 2> logfile.txt less ubuntofiles.txt less logfile.txt' finds file names ubunto in the root dir and save results into a file, save errors into log file and display the first page of the result
  - '-delete'
  - 'exec[command]'
  -'size'
uniq: removes repeated, adjacent lines in a file
  - 'sort file3.txt file4.txt | uniq' sorts file3 and file4 and removes duplicates
  - 'sort file3.txt file4.txt | uniq | wc -l' counts number of lines in unique combination of file3 and file4
grep: searches for a pttern in a file name and prints all matching lines
  - 'grep [pattern] directory'
  - '-v' print line NOT matched by the pattern
  - '-egrep'/'grep -E' uses regular expressions
  - e.g. 'egrep "(T|t)he" 1001nights.txt | wc -l' counts the number of lines where the word the or The appeared in 1001night.txt
shutdown: halts the machine
  - 'shutdown -h'schedule shutdown at current time
    - 'shutdown -h 10:00' shuts down at 10am
  - 'shutdown -r' restarts machine
**
awk: extract and print specific content of file
  - e.g. 'awk ${ print 1 }' fileCol.txt =>'1\n5\n9\n13'
cal: deisplay calendar and date of easter

Regular Expression (RegEx)
 - '.' used to match any single character
 - '|' match either or
 - '$' match end of string
 - '^' match beginning of string
 - '*' match preceding item 0 or more times
 - '?' matches preceding item 0 or 1 times
 - '{n}' matches preceding item exactly n occurences
 - '[...]' matches any character in set
 - e.g. '(W|w)onderland' matches Wonderland or wonderland
 - e.g. '[C|c][S|s][0-9]{3}' matches any CS course
