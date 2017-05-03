using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

public class BinaryFlips {
    public int minimalMoves(int A, int B, int K)
    {
        if (A == 0) return 0; //�������K�v�̂Ȃ���
        if (A + B < K) return -1; //�Ђ�����Ԃ��Ȃ���
        int i = 0;
        int minvalue = A, maxvalue = A; //0�̖����̌��݂̍ő�l�A�ŏ��l���i�[�B��������݂̂����Ȃ��̂ɒ���

        for (i = 0; i <= A + B; i++)
        {
            int nextminvalue, nextmaxvalue;
            //�܂��\�Ȍ���0�����炷��1���Ђ�����Ԃ����Ƃ��l����
            if (minvalue <= K && maxvalue >= K) //�ő�l�ƍŏ��l�̊Ԃ�K������ꍇ
            {
                if (minvalue % 2 == K % 2) return i + 1; //K�Ƃ̋������΁A�S��1�ɂ��邱�Ƃ��ł���
                else nextminvalue = 1; //�����łȂ��ƁA�ǂ����Ă�1��0���c���Ă��܂�
            }
            else nextminvalue = Math.Min(Math.Abs(K - minvalue), Math.Abs(K - maxvalue)); //���̑��̏ꍇ�́A�[�̂ݍl����Ηǂ��B
            //���l�ɍő�l�����߂�
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
