import java.util.*;
public class BinaryFlips {
    public int minimalMoves(int A, int B, int K) {
        int res;
	// 毎回ここが呼び出されますので、ここに答えを返す関数の中身を記載してください。

        return res;
    }

// ここから、一番下の「ここまで」という部分まではテスト用となりますので、
// 提出時は削除をしてください。
    public static void main(String[] args) {
        try {
            eq(0,(new BinaryFlips()).minimalMoves(3, 0, 3),1);
            eq(1,(new BinaryFlips()).minimalMoves(4, 0, 3),4);
            eq(2,(new BinaryFlips()).minimalMoves(4, 1, 3),2);
            eq(3,(new BinaryFlips()).minimalMoves(3, 2, 5),-1);
            eq(4,(new BinaryFlips()).minimalMoves(100000, 100000, 578),174);
            eq(5,(new BinaryFlips()).minimalMoves(0, 0, 1),0);
            eq(6,(new BinaryFlips()).minimalMoves(4, 44, 50),-1);
            eq(7,(new BinaryFlips()).minimalMoves(99200, 0, 99101),1004);
            eq(8,(new BinaryFlips()).minimalMoves(99999, 100000, 50000),-1);
            eq(9,(new BinaryFlips()).minimalMoves(1, 99999, 99999),99999);
        } catch( Exception exx) {
            System.err.println(exx);
            exx.printStackTrace(System.err);
        }
    }
    private static void eq( int n, int a, int b ) {
        if ( a==b )
            System.err.println("Case "+n+" passed.");
        else
            System.err.println("Case "+n+" failed: expected "+b+", received "+a+".");
    }
// ここまで
}
