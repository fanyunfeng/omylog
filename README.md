# omylog



A sample tool to calcutate the sum()/avg()/count()/var()/min()/max() of values in a log file.


I alwsys print some calling time of critical code block. Like following:

<pre>
function(){
  time_t start = time(NULL);
  
  
  ...
  //do something
  
  
  printf("function foo. time:%d\n", time(NULL)-start);
}
</pre>

This tool automate calculate the avg()/sum()/count()/etc. on the logging time value.


AWK is an alternate tool.

<pre>
Command:
//variable is prefix by time:
omylog -f info.log --v1="time:" -o sum(v1) -i 30

//split the log by ": ," calcuate on the fields
omylog -f info.log -d ": ," -o sum(v1) -o count(v2) -o sum(v1)/count(v2) -i 30

//filter the log file by REG
//grep REG info.log | omylog -d ": ," -o sum($1) -o count($2) -o sum($1)/count($2) -i 30 

omylog REG -f info.log -d ": ," -o sum($1) -o count($2) -o sum($1)/count($2) -i 30


$1
eg.
abc 100 200

$1.1
eg.
abc "100 200"
abc '100 200'


$name
eg.
counter:10 sum:50
counter=10 sum=50
counter 10 sum 50


//show help
omylog -h

</pre>
gplot 
