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
        if (A == 0) return 0; //�������K�v�̂Ȃ���
        if (A + B < K) return -1; //�Ђ�����Ԃ��Ȃ���

        array = new int[A + B + 1]; a = A; b = B; k = K;
        for (int i = 0; i <= A + B; i++) array[i] = -1;
        nownode.Add(A);
        array[A] = 0;
        while (nownode.Count > 0)
        {
            foreach (int i in nownode) //i��0�̐�
            {
                check(i, Math.Max(0, K - (A + B - i))); //0���o���邾�����₷
                check(i, Math.Min(i, K)); //1���o���邾�����₷
                check(i, Math.Min(Math.Max((i + 1) / 2, K - ((A + B) - i)), K)); //K�ɏォ��߂Â���
                check(i, Math.Min(Math.Max(i / 2, K - ((A + B) - i)), K)); //K�ɉ�����߂Â���
            }
            //���̃^�[���p��next��now��
            nownode.Clear();
            foreach (int next in nextnode) nownode.Add(next);
            nextnode.Clear();
        }
        return array[0];
    }

    public void check(int nowzero, int usezero)
    {
        int nextzero = nowzero + k - 2 * usezero; //�o���邾��0�𑝂₷���ł��邾���Ђ�����Ԃ�1�𑽂�
        if (array[nextzero] == -1)  //���߂ē��B����n�_�ł���΁A���̒T���ɉ�����
        {
            array[nextzero] = array[nowzero] + 1;
            nextnode.Add(nextzero);
        }
    }
}
