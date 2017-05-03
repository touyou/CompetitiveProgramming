/* SuperCon 2012 �\�I���b�p�e���v���[�g�i��A�C�X�[�p�[�R���R���F����@2012�Łj
   �E�𓚃v���O�����͂��̃e���v���[�g�ɏ]���č쐬���邱�ƁD
�@ �E�𓚃v���O�����͂P�̃t�@�C���ŁC�`�[����.c �Ƃ������O�ɂ��邱�ƁD
�@ �E���͂̕����́C���炩���ߓ��̓t�@�C���i��Finput_sample.txt�j�����
�@�@ �Ă����C���s���Ƀt�@�C�������w�肷������ł��D
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/* ���ȉ��͈͕̔͂ύX�\ */
/* ����L�͈͕̔͂ύX�\ */

int main(int argc, char** argv){
	int answer = -1; /* ���̕ϐ��ɓ��iV�̍ő�l�j�������Ă�������. */
	int N;
	static int v[10];
	static char w[10][10+1];
	static char W[100+1];
	char* problem_file;
	clock_t start, end;
	FILE* fp;

	int i;
	char buf[0xffff];
	char* p;

	if(argc <= 1){
		fprintf(stderr, "Enter the input file.\n");
		exit(EXIT_FAILURE);
	}

	problem_file = argv[1];
	fp = fopen(problem_file, "r");
	if(fp == NULL){
		fprintf(stderr, "Cannot open %s.\n", problem_file);
		exit(EXIT_FAILURE);
	}

	p = fgets(buf, 0xffff, fp);
	assert(p != 0);

	N = atoi(strtok(buf, " \n"));
	assert( N == 10 );

	p = fgets(buf, 0xffff, fp);
	assert(p != 0);
	p = strtok(buf, " \n");
	strcpy(W, p);
	assert(1 <= strlen(W) && strlen(W) <= 100);
	for(p = W; *p; ++p){
		assert( islower(*p) );
	}

	for(i = 0; i < N; ++i){
		p = fgets(buf, 0xffff, fp);
		assert(p != 0);
		v[i] = atoi(strtok(buf, " "));
		assert(-1000000 <= v[i] && v[i] <= 1000000);
		p = strtok(NULL, " \n");
		strcpy(w[i], p);
		assert(1 <= strlen(w[i]) && strlen(w[i]) <= 10);
		for(p = w[i]; *p; ++p){
			assert( islower(*p) );
		}
	}

	fclose(fp);

	start = clock();

/* ���ȉ��͈͕̔͂ύX�\ */
// N=10
// 1<=|wi|<=10
// 1<=|W|<=100
// -1000000<=vi<=1000000	
    

/* ����L�͈͕̔͂ύX�\ */

	end = clock();
	printf("%s, %f, %d\n", problem_file, (double)(end - start) / CLOCKS_PER_SEC, answer);

	printf("%s, %d\n", problem_file, answer);
	return 0;
}

/* ���ȉ��͈͕̔͂ύX�\ */

/* ����L�͈͕̔͂ύX�\ */
