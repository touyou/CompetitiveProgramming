using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

public class BinaryFlips {
    public int minimalMoves(int A, int B, int K)
    {
        if (A == 0) return 0; //動かす必要のない時
        if (A + B < K) return -1; //ひっくり返せない時
        int i = 0;
        int minvalue = A, maxvalue = A; //0の枚数の現在の最大値、最小値を格納。偶数か奇数のみしかないのに注意

        for (i = 0; i <= A + B; i++)
        {
            int nextminvalue, nextmaxvalue;
            //まず可能な限り0を減らす→1をひっくり返すことを考える
            if (minvalue <= K && maxvalue >= K) //最大値と最小値の間にKがある場合
            {
                if (minvalue % 2 == K % 2) return i + 1; //Kとの偶奇が合えば、全て1にすることができる
                else nextminvalue = 1; //そうでないと、どうしても1枚0が残ってしまう
            }
            else nextminvalue = Math.Min(Math.Abs(K - minvalue), Math.Abs(K - maxvalue)); //その他の場合は、端のみ考えれば良い。
            //同様に最大値も求める
            if (minvalue <= (A + B - K) && maxvalue >= (A + B - K))
            {
                if ((A + B - maxvalue) % 2 == K % 2) nextmaxvalue = A + B;
                else nextmaxvalue = A + B - 1;
            }
            else nextmaxvalue = A + B - Math.Min(Math.Abs((A + B - K) - minvalue), Math.Abs((A + B - K) - maxvalue));
            minvalue = nextminvalue;
            maxvalue = nextmaxvalue;
        }
        return -1;
    }
}
