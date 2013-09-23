#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MT.h"
void Usage(){
	fprintf(stderr, "Usage: run .. SEED .. NUMITER .. DIMENSION\n");
}
int main(int argc, char **argv){

	/* 引数チェック */
	if( argc != 4 ) {
		fprintf(stderr, "Too few arguments.\n");
		Usage();
		return -1;
	}
	int seed = atoi(argv[1]);
	int num_iter = atoi(argv[2]);
	int NBOX = atoi(argv[3]);
	if( NBOX < 3 ){
		fprintf(stderr, "DIMENSION must be larger than 2.\n");
		return -1;
	}
	char box[NBOX];
	int hit_index;
	int select_index;
	init_genrand(seed);
	int nochange=0, change=0;
	int i;
	int tmp_index;
	memset(box, 0, sizeof(box));

	/* ここで試行 */
	for( i=0; i<num_iter; i++){
		hit_index = genrand_int32() % NBOX;
		select_index = genrand_int32() % NBOX;
		box[hit_index] = 1;
		if( hit_index == select_index ){
			nochange ++;
		}
		else {
			if( NBOX == 3 ){
				change ++;
			}
			else {
					while ( (tmp_index=genrand_int32() % NBOX) == select_index);
					if( tmp_index == hit_index ){
						change++;
					}
				}
		}
		box[hit_index] = 0;
	}

	fprintf(stdout, "Change: %d %3.2f%%  Nochange: %d %3.2f%%\n", change, (double)change/num_iter*100, nochange, (double)nochange/num_iter*100);	
	return 0;
}
	
	
		
