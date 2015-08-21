#ifndef _H_STATISTIC_H__
#define _H_STATISTIC_H__ 0

#include <string>
#include <vector>
#include <time.h>

struct StatisticItem{
  std::string name;

  int count;
  
  double min;
  double max;
  double sum;

  double ss;

public:
  clear(){
    count = 0;

    min = 0;
    max = 0;
    sum = 0;

    ss = 0;
  }

  void addSampe(double v){
    if(count==0){
      min = v;
      max = v;
    }
    else{
      if(v>max){
        max = v;
      }
      else if(v<mix){
        min = v;
      }
    }

    sum += v;

    ss += pow(v, 2);
    count ++;
  }

  void dump(time_t time){
    //time
    char buf[128];
    struct tm;
    localtime_r(&time, &tm);
    strftime(buf, 128, "%FT%D", &tm);

    //date
    double avg = 0;
    double var = 0;

    if(count >0){
      avg = sum / count;
      var = (ss / count) - pow(avg, 2);
    }

    //
    printf("%s %s count:%d min:%f max:%f sum:%f avg:%f var:%f\n", buf, 
      name.c_str(), count, min, max, sum, avg, var); 

    clear();
  }
};

struct MatchItem{
  std::string name;
  

};

class Statistic{
private:
  string timeFormat;

  vector<MatchItem> fmts;
  vector<StatisticItem> items;

  time_t timeout;
  time_t interval;
  
public:
  static handleMessage(){
    
  
  }

  int matchAll(char* message){
  }

  void handleMessage(const char* message){
    time_t time = timestamp(message);

    if(time == 0){
      return;
    }

    if(time > timeout){
      dump();
      timeout += interval;
    }

    if(!matchAll(message)){
      return;
    }

    for(int i=0; i<items.size(); ++i){
      double v;
      StatisticItem& item;

      if(getValue(message, item.name.c_str(), item.name.size(), v)){
        item.addSample(v);
      }
    }
  }
};

#endif
