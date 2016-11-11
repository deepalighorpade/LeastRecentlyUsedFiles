***Instruction for execution*******

1)Open the Terminal in Ubuntu.
2)Copy the code in Home directory.
3)Compile the code.
	$gcc leastused.c -oleastused

4)Execute the code
        $./leastused -23d	//list files modified before 23 days
    	$./leastused -11m	//list files modified before 11 months
	$./leastused -01y	//list files modified before 1 year

5)Files generated
	"foutput.txt" stores all files from directory.
	"filelist.txt" stores least used files.
	

Hope you Enjoyed it. 