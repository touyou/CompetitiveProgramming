using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

public class BinaryFlips {
    public int minimalMoves(int A, int B, int K)
    {
        for (long i = 0; i <= A + B; i++)
        {
            long rest = i * K - A;
            long use = ((i / 2) * B + ((i - 1) / 2) * A) * 2;
            if (rest >= 0 && rest % 2 == 0 && rest <= use) return (int)i;
        }
        return -1;
    }
}
