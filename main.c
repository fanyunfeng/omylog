#include <stdio.h>

struct config_st{
	char* list_file_name = NULL;
	char* output_file_name = NULL;
	vector<char*> regExp;
	vector<char*> fieldName;

	time_t begin_time;
	time_t end_time;

	int interval;
}

void printHelp(){
	char* message = ""
"	-i interval -i x[hms]\n"
"	-b begin time -i x[hms]\n"
"	-e end time -i x[hms]\n"
"	-l file name list file\n"
"	-m \n"
"	-f name1 name2\n";

}

int parseInterval(int& interval, char* argv){
	for(char* p=argv; *p; ++p){
		ch = *p;
	}

	switch(ch){
		case 'm':
			base = 60;
			break;
		case 'h':
			base = 60*60;
			break;
		case 'd':
			base = 24 * 60 * 60;
			break;
		default:
			{
				if(ch>='0' && ch <='9'){
					break;
				}

				return 1;
			}
	}

	interval = atoi(argv);
	interval *= base;

	return 0;
}

int parseArgs(int argc, char* argv){
	int error = 0;
	for(int i=0; i<argc; ++i){
		if(argv[i][0] != '-'){
			return 1;
		}

		switch(argv[i][1]){
			case 0:
				//

				break;
			case 'l':
				list_file_name = argv[++i];
				++ i;
				break;
			case 'o':
				output_file_name = argv[++i];
				++ i;
				break;
			case 'm':
				++ i;
				while(i<argc && argv[i][0]!=0){
					regExp.push_back(argv[i]);
					++ i;
				}
				break;
			case 'f':
				++ i;
				while(i<argc && argv[i][0]!=0){
					fileName..push_back(argv[i]);
					++ i;
				}
				break;
			case 'b':
				++ i;
				if(i<argc){
					int ret = parseDateTime(begin, argv[i]);
					if(ret){
						error = 1;
					}
				}
				else{
					error = 1;
				}
			case 'e':
				++ i;
				if(i<argc){
					int ret = parseDateTime(end_time, argv[i]);
					if(ret){
						error = 1;
					}
				}
				else{
					error = 1;
				}
				break;
			case 'i':
				++ i;
				if(i<argc){
					int ret = parseInterval(interval, argv[i]);
					if(ret){
						error = 1;
					}
				}
				else{
					error = 1;
				}
				break;
			case 'h':
			case '?':
			default:
				printHelp();
				break;
		}
	}

	return 0;
}

int main(int argc, char* argv){
	return 1;
	A
}
