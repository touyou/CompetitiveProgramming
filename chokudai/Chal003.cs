using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

public class CantorDust {

    public int occurrencesNumber(string[] pattern, int time)
    {
        //ここに自分のプログラムを記入！
    }


// BEGIN CUT HERE
    public void run_test(int Case)
    {
        if ((Case == -1) || (Case == 0)) test_case_0();
        if ((Case == -1) || (Case == 1)) test_case_1();
        if ((Case == -1) || (Case == 2)) test_case_2();
        if ((Case == -1) || (Case == 3)) test_case_3();
        if ((Case == -1) || (Case == 4)) test_case_4();
        if ((Case == -1) || (Case == 5)) test_case_5();
        if ((Case == -1) || (Case == 6)) test_case_6();
        if ((Case == -1) || (Case == 7)) test_case_7();
        if ((Case == -1) || (Case == 8)) test_case_8();
        if ((Case == -1) || (Case == 9)) test_case_9();
    }
    private void verify_case(int Case, int Expected, int Received)
    {
        Console.Write("Test Case #" + Case + "...");
        if (Expected == Received)
            Console.WriteLine("PASSED");
        else
        {
            Console.WriteLine("FAILED");
            Console.WriteLine("\tExpected: \"" + Expected + '\"');
            Console.WriteLine("\tReceived: \"" + Received + '\"');
        }
    }
	private void test_case_0() { string[] Arg0 = new string[]{".X",".."}; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, occurrencesNumber(Arg0, Arg1)); }
	private void test_case_1() { string[] Arg0 = new string[]{".."}; int Arg1 = 1; int Arg2 = 2; verify_case(1, Arg2, occurrencesNumber(Arg0, Arg1)); }
	private void test_case_2() { string[] Arg0 = new string[]{"."}; int Arg1 = 2; int Arg2 = 65; verify_case(2, Arg2, occurrencesNumber(Arg0, Arg1)); }
	private void test_case_3() { string[] Arg0 = new string[]{"X...X"}; int Arg1 = 2; int Arg2 = 4; verify_case(3, Arg2, occurrencesNumber(Arg0, Arg1)); }
	private void test_case_4() { string[] Arg0 = new string[]{"X"}; int Arg1 = 9; int Arg2 = 262144; verify_case(4, Arg2, occurrencesNumber(Arg0, Arg1)); }
    private void test_case_5() { string[] Arg0 = new string[] { "....", "....", "...." }; int Arg1 = 9; int Arg2 = 385369800; verify_case(5, Arg2, occurrencesNumber(Arg0, Arg1)); }
    private void test_case_6() { string[] Arg0 = new string[] { "...........................", "...........................", "...........................", "...........................", "...........................", "...........................", "..........................." }; int Arg1 = 3; int Arg2 = 3; verify_case(6, Arg2, occurrencesNumber(Arg0, Arg1)); }
    private void test_case_7() { string[] Arg0 = new string[] { ".......X.X...X.X........", "........................" }; int Arg1 = 5; int Arg2 = 186; verify_case(7, Arg2, occurrencesNumber(Arg0, Arg1)); }
    private void test_case_8() { string[] Arg0 = new string[] { "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", ".X...X.X.........X.X...X.X.....................", "...............................................", ".X...X.X.........X.X...X.X.....................", "...............................................", "...............................................", "...............................................", ".X...X.X.........X.X...X.X.....................", "...............................................", ".X...X.X.........X.X...X.X.....................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", ".X...X.X.........X.X...X.X.....................", "..............................................." }; int Arg1 = 8; int Arg2 = 496; verify_case(8, Arg2, occurrencesNumber(Arg0, Arg1)); }
    private void test_case_9() { string[] Arg0 = new string[] { "X.X...X.X.........X.X..", ".......................", "X.X...X.X.........X.X..", ".......................", ".......................", ".......................", "X.X...X.X.........X.X..", ".......................", "X.X...X.X.........X.X..", ".......................", ".......................", ".......................", ".......................", ".......................", ".......................", ".......................", ".......................", ".......................", "X.X...X.X.........X.X..", ".......................", "X.X...X.X.........X.X..", ".......................", ".......................", ".......................", "X.X...X.X.........X.X..", ".......................", "X.X...X.X.........X.X.." }; int Arg1 = 9; int Arg2 = 4096; verify_case(9, Arg2, occurrencesNumber(Arg0, Arg1)); }

// END CUT HERE
// BEGIN CUT HERE
public static void Main() {
try {
CantorDust ___test = new CantorDust();
___test.run_test(-1);
} catch(Exception e) {
//Console.WriteLine(e.StackTrace);
Console.WriteLine(e.ToString());
}
}
// END CUT HERE
}
