<div align="center">

# 42_pipex

<h5>
  This project will let you discover in detail a UNIX mechanism that you already know by using it in your program. 
</h5>

<img src="https://github.com/pedromelocf/utilities/blob/master/pipexe.png" />

![](https://komarev.com/ghpvc/?username=pedromelocf)

 I am glad to share that I have just finished the first step in the 42 journey: Finishing the first phase, delivering 6 projects along this process and now I am heading to the second one.

 In pipex, the last project in phase one, we have to create a program that reproduces the behavior of the bash terminal when dealing with redirection and pipes.

 To do this, you need to deeply understand these major topics:
  
• Pipe concept;

• Fork and process identification;

• File descriptors redirection.

</br>

Basically, our program will be executed as follows:

./pipex file1 cmd1 cmd2 file2

</br>

It must take 4 arguments:

• file1 and file2 are file names.

• cmd1 and cmd2 are shell commands with their parameters.

</br>

It must behave exactly the same as the shell command below:

$> < file1 cmd1 | cmd2 > file2

</br>

Examples:

$> ./pipex infile "ls -l" "wc -l" outfile

Should behave like: < infile ls -l | wc -l > outfile

</br>

$> ./pipex infile "grep a1" "wc -w" outfile

Should behave like: < infile grep a1 | wc -w > outfile

</br>

</div>

<div align="center">

<h2> Grade </h2>

<img src="https://github.com/pedromelocf/utilities/blob/master/100_grade.png" />

</div>
