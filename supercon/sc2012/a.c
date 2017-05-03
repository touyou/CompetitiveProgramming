/* SuperCon 2012 予選問題Ｃ用テンプレート（問A，スーパーコン３級認定問題　2012版）
   ・解答プログラムはこのテンプレートに従って作成すること．
　 ・解答プログラムは１つのファイルで，チーム名.c という名前にすること．
　 ・入力の方式は，あらかじめ入力ファイル（例：input_sample.txt）を作っ
　　 ておき，実行時にファイル名を指定する方式です．
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/* ↓以下の範囲は変更可能 */
/* ↑上記の範囲は変更可能 */

int main(int argc, char** argv){
	int answer = -1; /* この変数に答（Vの最大値）を代入してください. */
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

/* ↓以下の範囲は変更可能 */
// N=10
// 1<=|wi|<=10
// 1<=|W|<=100
// -1000000<=vi<=1000000	
    

/* ↑上記の範囲は変更可能 */

	end = clock();
	printf("%s, %f, %d\n", problem_file, (double)(end - start) / CLOCKS_PER_SEC, answer);

	printf("%s, %d\n", problem_file, answer);
	return 0;
}

/* ↓以下の範囲は変更可能 */

/* ↑上記の範囲は変更可能 */
