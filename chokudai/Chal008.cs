using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

public class FloorBoards {
    public int layout(string[] room)
    {
        //答えをreturnするとテストできます！
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
	private void verify_case(int Case, int Expected, int Received) {
		Console.Write("Test Case #" + Case + "...");
		if (Expected == Received) 
			Console.WriteLine("PASSED"); 
		else { 
			Console.WriteLine("FAILED"); 
			Console.WriteLine("\tExpected: \"" + Expected + '\"');
			Console.WriteLine("\tReceived: \"" + Received + '\"'); } }

    private void test_case_0()
    {
        string[] Arg0 = new string[]
{"....."
,"....."
,"....."
,"....."
,"....."};
        int Arg1 = 5; verify_case(0, Arg1, layout(Arg0));
    }
    private void test_case_1()
    {
        string[] Arg0 = new string[]
{"......."
,".#..##."
,".#....."
,".#####."
,".##..#."
,"....###"};
        int Arg1 = 7; verify_case(1, Arg1, layout(Arg0));
    }
    private void test_case_2()
    {
        string[] Arg0 = new string[]
{"####"
,"####"
,"####"
,"####"};
        int Arg1 = 0; verify_case(2, Arg1, layout(Arg0));
    }
    private void test_case_3()
    {
        string[] Arg0 = new string[]
{"...#.."
,"##...."
,"#.#..."
,".#...."
,"..#..."
,"..#..#"};
        int Arg1 = 9; verify_case(3, Arg1, layout(Arg0));
    }
    private void test_case_4()
    {
        string[] Arg0 = new string[]
{".#...."
,"..#..."
,".....#"
,"..##.."
,"......"
,".#..#."};
        int Arg1 = 9; verify_case(4, Arg1, layout(Arg0));
    }

    private void test_case_5()
    {
        string[] Arg0 = new string[] { ".#.#.#.#.#", "#.#.#.#.#.", ".#.#...#.#", "#.#.#.#.#.", ".#.#.#.#.#", "#...#.#.#.", ".#.#.#...#", "#.#.#.#.#.", ".#.#.#.#.#", "#.#...#.#." };
        int Arg1 = 46; verify_case(5, Arg1, layout(Arg0));
    }

    private void test_case_6()
    {
        string[] Arg0 = new string[] { "..........", "..........", "..........", "..........", "..........", "..........", "..........", "..........", "..........", ".........." };
        int Arg1 = 10; verify_case(6, Arg1, layout(Arg0));
    }

    private void test_case_7()
    {
        string[] Arg0 = new string[] { "......#..#", "..###.....", "......#.#.", "#..#.#...#", "..##..##..", "#.........", ".#.#.###..", "..##.#.#..", ".........#", ".....#..##" };
        int Arg1 = 23; verify_case(7, Arg1, layout(Arg0));
    }

    private void test_case_8()
    {
        string[] Arg0 = new string[] { "..........", "..#.......", "..........", "#......#..", "...#...#..", "...#......", "#.........", "....#.....", "#.........", ".....#...." };
        int Arg1 = 17; verify_case(8, Arg1, layout(Arg0));
    }

    private void test_case_9()
    {
        string[] Arg0 = new string[] { "#.#####.#", "#.......#", "#.#.#.#.#", "....#....", "###.#.###", "....#....", "#.#.#.#.#", "#.......#", "#.#####.#" };
        int Arg1 = 12; verify_case(8, Arg1, layout(Arg0));
    }

    public static void Main()
    {
        try
        {
            FloorBoards ___test = new FloorBoards();
            ___test.run_test(-1);
        }
        catch (Exception e)
        {
            //Console.WriteLine(e.StackTrace);
            Console.WriteLine(e.ToString());
        }
    }
// END CUT HERE
}
