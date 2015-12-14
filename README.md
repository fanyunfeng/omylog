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
omylog -f info.log --v1="time:" -o sum($1) -i 30

//split the log by ": ," calcuate on the fields
omylog -f info.log -d ": ," -o sum($1) -o count($2) -o sum($1)/count($2) -i 30

//filter the log file by REG
//grep REG info.log | omylog -d ": ," -o sum($1) -o count($2) -o sum($1)/count($2) -i 30 

omylog REG -f info.log -d ": ," -o sum($1) -o count($2) -o sum($1)/count($2) -i 30


eg.
abc 100 200

$2=100
$3=200

eg.
abc "100 200"
abc '100 200'

$2.1=100
$2.2=200

eg.
counter:10 sum:50
counter=10 sum=50
counter 10 sum 50

$count=10
$sum=50


if()
eg.
if($1>100)

sum()
count()
max()
min()
avg()

print()
eg.
print($1)



//show help
omylog -h

</pre>
gplot 
