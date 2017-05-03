using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

public class BinaryFlips {
    public int minimalMoves(int A, int B, int K)
    {
        if (A == 0) return 0; //動かす必要のない時
        if (A + B < K) return -1; //ひっくり返せない時

        int[] array = new int[A + B + 1];
        for (int i = 0; i <= A + B; i++) array[i] = -1;
        List<int> nownode = new List<int>();
        List<int> nextnode = new List<int>();
        nownode.Add(A);
        array[A] = 0;
        while (nownode.Count > 0)
        {
            foreach (int i in nownode) //iは0の数
            {
                for (int j = Math.Max(0, K - (A + B - i)); j <= Math.Min(i, K); j++) //jは0をひっくり返す数
                {
                    int nextzero = i + (K - 2 * j); //遷移する次の状態の0の数
                    if (array[nextzero] == -1)  //初めて到達する地点であれば、次の探索に加える
                    {
                        if (nextzero == 0) return array[i] + 1; //答えが見つかれば、それを返す
                        array[nextzero] = array[i] + 1;
                        nextnode.Add(nextzero);
                    }
                }
            }
            //次のターン用にnextをnowに
            nownode.Clear();
            foreach (int k in nextnode) nownode.Add(k);
            nextnode.Clear();
        }
        return -1;
    }
}
