int j, k;
    /* flag[i][j]:=
    wiとWのj文字目から|wi|文字の比較でwiが大きいなら1、小さいなら0、等しいなら2
    */
    static int flag[1000][10001], wg[1000];
    int len=strlen(W);
    for (i=0; i<N; i++) {
        wg[i]=strlen(w[i]);
        for (j=0; j<len; j++) {
            int n=2;
            for (k=j; k<len&&k<j+wg[i]&&!flag[i][j]; k++) {
                if (w[i][k-j]!=W[j]) n=0;
                if (w[i][k-j]>W[j]) flag[i][j]=1;
            }
            if (n==2) flag[i][j]=2;
        }
    }
    /*
    前から確定していく
    dp[i][j][k]:=
    i番目の文字列をj文字目から使うとして
    k=0なら先頭が必ず小さい
    k=1なら先頭から今までが等しい
    ⇔k=1のときflag[i][j]=1のものは使えない
    */
    static ll dp[1001][10001][2];
    for (i=0; i<N; i++) {
        for (j=0; j<=10000; j++) {
            if (j<wg[i]) {
                dp[i+1][j][0]=dp[i][j][0];
                dp[i+1][j][1]=dp[i][j][1];
            } else if (flag[i][j]==2) {
                dp[i+1][j][0]=max(dp[i][j][0], dp[i][j-wg[i]][0]+v[i]);
                dp[i+1][j][1]=max(dp[i][j][1], dp[i][j-wg[i]][1]+v[i]);
            } else if (flag[i][j]==0) {
                dp[i+1][j][0]=max(dp[i][j][0], max_element(dp[i][j-wg[i]], 2)+v[i]);
                dp[i+1][j][1]=dp[i][j][1];
            }
            answer=max(answer, max_element(dp[i][j], 2));
        }
    }