# omylog
A sample tool to calcutate the sum avg()/count()/var()/min()/max() of values in a log file.


I alwsys print some calling time of critical code block. Like following:


function(){
  time_t start = time(NULL);
  
  ...
  //do something
  
  
  printf("function foo. time:%d\n", time(NULL)-start);
}


This tool automate calculate the avg()/sum()/count()/etc. on the logging time value.


AWK is an alternate tool.


