using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

public class BinaryFlips {
    public int minimalMoves(int A, int B, int K)
    {
        if (A == 0) return 0; //�������K�v�̂Ȃ���
        if (A + B < K) return -1; //�Ђ�����Ԃ��Ȃ���

        int[] array = new int[A + B + 1];
        for (int i = 0; i <= A + B; i++) array[i] = -1;
        List<int> nownode = new List<int>();
        List<int> nextnode = new List<int>();
        nownode.Add(A);
        array[A] = 0;
        while (nownode.Count > 0)
        {
            foreach (int i in nownode) //i��0�̐�
            {
                for (int j = Math.Max(0, K - (A + B - i)); j <= Math.Min(i, K); j++) //j��0���Ђ�����Ԃ���
                {
                    int nextzero = i + (K - 2 * j); //�J�ڂ��鎟�̏�Ԃ�0�̐�
                    if (array[nextzero] == -1)  //���߂ē��B����n�_�ł���΁A���̒T���ɉ�����
                    {
                        if (nextzero == 0) return array[i] + 1; //������������΁A�����Ԃ�
                        array[nextzero] = array[i] + 1;
                        nextnode.Add(nextzero);
                    }
                }
            }
            //���̃^�[���p��next��now��
            nownode.Clear();
            foreach (int k in nextnode) nownode.Add(k);
            nextnode.Clear();
        }
        return -1;
    }
}
