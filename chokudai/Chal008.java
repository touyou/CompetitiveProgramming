import java.util.*;

public class FloorBoards {
    public int layout(String room[])
    {
        //答えをreturnするとテストできます！
        return 0;
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
		System.out.println("Test Case #" + Case + "...");
		if (Expected == Received) 
			System.out.println("PASSED"); 
		else { 
			System.out.println("FAILED"); 
			System.out.println("\tExpected: \"" + Expected + '\"');
			System.out.println("\tReceived: \"" + Received + '\"'); } }

    private void test_case_0()
    {
        String[] Arg0 = new String[]
{"....."
,"....."
,"....."
,"....."
,"....."};
        int Arg1 = 5; verify_case(0, Arg1, layout(Arg0));
    }
    private void test_case_1()
    {
        String[] Arg0 = new String[]
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
        String[] Arg0 = new String[]
{"####"
,"####"
,"####"
,"####"};
        int Arg1 = 0; verify_case(2, Arg1, layout(Arg0));
    }
    private void test_case_3()
    {
        String[] Arg0 = new String[]
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
        String[] Arg0 = new String[]
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
        String[] Arg0 = new String[] { ".#.#.#.#.#", "#.#.#.#.#.", ".#.#...#.#", "#.#.#.#.#.", ".#.#.#.#.#", "#...#.#.#.", ".#.#.#...#", "#.#.#.#.#.", ".#.#.#.#.#", "#.#...#.#." };
        int Arg1 = 46; verify_case(5, Arg1, layout(Arg0));
    }

    private void test_case_6()
    {
        String[] Arg0 = new String[] { "..........", "..........", "..........", "..........", "..........", "..........", "..........", "..........", "..........", ".........." };
        int Arg1 = 10; verify_case(6, Arg1, layout(Arg0));
    }

    private void test_case_7()
    {
        String[] Arg0 = new String[] { "......#..#", "..###.....", "......#.#.", "#..#.#...#", "..##..##..", "#.........", ".#.#.###..", "..##.#.#..", ".........#", ".....#..##" };
        int Arg1 = 23; verify_case(7, Arg1, layout(Arg0));
    }

    private void test_case_8()
    {
        String[] Arg0 = new String[] { "..........", "..#.......", "..........", "#......#..", "...#...#..", "...#......", "#.........", "....#.....", "#.........", ".....#...." };
        int Arg1 = 17; verify_case(8, Arg1, layout(Arg0));
    }

    private void test_case_9()
    {
        String[] Arg0 = new String[] { "#.#####.#", "#.......#", "#.#.#.#.#", "....#....", "###.#.###", "....#....", "#.#.#.#.#", "#.......#", "#.#####.#" };
        int Arg1 = 12; verify_case(8, Arg1, layout(Arg0));
    }

    public static void main(String[] args)
    {
        new FloorBoards().run_test(-1);
    }
// END CUT HERE
}
