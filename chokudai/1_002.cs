using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

public class BinaryFlips {
    int[] array;
    int a, b, k;
    List<int> nownode = new List<int>();
    List<int> nextnode = new List<int>();

    public int minimalMoves(int A, int B, int K)
    {
        if (A == 0) return 0; //動かす必要のない時
        if (A + B < K) return -1; //ひっくり返せない時

        array = new int[A + B + 1]; a = A; b = B; k = K;
        for (int i = 0; i <= A + B; i++) array[i] = -1;
        nownode.Add(A);
        array[A] = 0;
        while (nownode.Count > 0)
        {
            foreach (int i in nownode) //iは0の数
            {
                check(i, Math.Max(0, K - (A + B - i))); //0を出来るだけ増やす
                check(i, Math.Min(i, K)); //1を出来るだけ増やす
                check(i, Math.Min(Math.Max((i + 1) / 2, K - ((A + B) - i)), K)); //Kに上から近づける
                check(i, Math.Min(Math.Max(i / 2, K - ((A + B) - i)), K)); //Kに下から近づける
            }
            //次のターン用にnextをnowに
            nownode.Clear();
            foreach (int next in nextnode) nownode.Add(next);
            nextnode.Clear();
        }
        return array[0];
    }

    public void check(int nowzero, int usezero)
    {
        int nextzero = nowzero + k - 2 * usezero; //出来るだけ0を増やす＝できるだけひっくり返す1を多く
        if (array[nextzero] == -1)  //初めて到達する地点であれば、次の探索に加える
        {
            array[nextzero] = array[nowzero] + 1;
            nextnode.Add(nextzero);
        }
    }
}
