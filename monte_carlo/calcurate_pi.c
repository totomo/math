#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct coord{
	double x;
	double y;
}coord;

void usage(){
	fprintf(stderr, "Usage: estpi ... NumberOfIteration\n");
	fprintf(stderr, "Options:\n");
	fprintf(stderr, "--help, -h: show the usage.\n");
}

char isContainCircle(coord p){
	p.x =(double) rand() / RAND_MAX;
	p.y =(double) rand() / RAND_MAX;
	if( pow(p.x, 2) + pow(p.y, 2) <= 1.0 ){
		return 1;
	}
	else {
		return 0;
	}
}

long extractFromArguments(char **argv){
	int i=1;
	while( argv[i] != NULL ){	
		if( strcmp(argv[i], "--help") * strcmp(argv[i], "-h") ==0 ){
			usage();
			exit(EXIT_FAILURE);
		}
		else{
			return atoi(argv[i]);
		}
		i++;
	}
}

void verifyArguments(int argc){
	if(argc!=2 && argc!=3){
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char **argv){
	coord p;
	long number;
	int i;
	int count = 0;
	// 引数のチェック
	verifyArguments(argc);
	number = extractFromArguments(argv);
	for( i=0; i<number; i++ ){
		count += isContainCircle(p);
	}
	fprintf(stdout, "result: %3.7f\n", (double)count / number * 4.0);
	return 0;
}

