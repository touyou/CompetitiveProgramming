using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

public class NotTwo
{
    public int maxStones(int width, int height)
    {
        //ここにプログラムを記述
    }

    // BEGIN CUT HERE
    public void run_test(int Case) { test_case_0(); test_case_1(); test_case_2(); test_case_3(); test_case_4(); test_case_5(); test_case_6(); test_case_7(); test_case_8(); test_case_9(); }
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
    private void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 4; verify_case(0, Arg2, maxStones(Arg0, Arg1)); }
    private void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 5; verify_case(1, Arg2, maxStones(Arg0, Arg1)); }
    private void test_case_2() { int Arg0 = 8; int Arg1 = 5; int Arg2 = 20; verify_case(2, Arg2, maxStones(Arg0, Arg1)); }
    private void test_case_3() { int Arg0 = 1000; int Arg1 = 1000; int Arg2 = 500000; verify_case(3, Arg2, maxStones(Arg0, Arg1)); }
    private void test_case_4() { int Arg0 = 1000; int Arg1 = 999; int Arg2 = 499500; verify_case(4, Arg2, maxStones(Arg0, Arg1)); }
    private void test_case_5() { int Arg0 = 999; int Arg1 = 1000; int Arg2 = 499500; verify_case(5, Arg2, maxStones(Arg0, Arg1)); }
    private void test_case_6() { int Arg0 = 999; int Arg1 = 999; int Arg2 = 499001; verify_case(6, Arg2, maxStones(Arg0, Arg1)); }
    private void test_case_7() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 4; verify_case(7, Arg2, maxStones(Arg0, Arg1)); }
    private void test_case_8() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; verify_case(8, Arg2, maxStones(Arg0, Arg1)); }
    private void test_case_9() { int Arg0 = 1; int Arg1 = 997; int Arg2 = 499; verify_case(9, Arg2, maxStones(Arg0, Arg1)); }

    public static void Main()
    {
        try
        {
            NotTwo ___test = new NotTwo();
            ___test.run_test(-1);
        }
        catch (Exception e)
        {
            Console.WriteLine(e.ToString());
        }
    }
    //END CUT HERE
}
