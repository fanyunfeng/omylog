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
//grep REG info.log | omylog -d ": ," -o sum(v1) -o count(v2) -o sum(v1)/count(v2) -i 30 

omylog REG -f info.log -d ": ," -o sum(v1) -o count(v2) -o sum(v1)/count(v2) -i 30


//show help
omylog -h

</pre>
gplot 
