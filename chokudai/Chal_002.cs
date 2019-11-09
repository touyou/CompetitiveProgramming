using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

public class BinaryFlips {
public int minimalMoves(int A, int B, int K) {
	//ここに処理を記載してください。
}




	//ここより先はテスト用となります。TopCoderへの提出時は、下の「ここまで」まで選択して削除してください。
	public void run_test(int Case) {
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

	private void test_case_0() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 3; int Arg3 = 1; verify_case(0, Arg3, minimalMoves(Arg0, Arg1, Arg2)); }
	private void test_case_1() { int Arg0 = 4; int Arg1 = 0; int Arg2 = 3; int Arg3 = 4; verify_case(1, Arg3, minimalMoves(Arg0, Arg1, Arg2)); }
	private void test_case_2() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 3; int Arg3 = 2; verify_case(2, Arg3, minimalMoves(Arg0, Arg1, Arg2)); }
	private void test_case_3() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 5; int Arg3 = -1; verify_case(3, Arg3, minimalMoves(Arg0, Arg1, Arg2)); }
	private void test_case_4() { int Arg0 = 100000; int Arg1 = 100000; int Arg2 = 578; int Arg3 = 174; verify_case(4, Arg3, minimalMoves(Arg0, Arg1, Arg2)); }
	private void test_case_5() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 1; int Arg3 = 0; verify_case(5, Arg3, minimalMoves(Arg0, Arg1, Arg2)); }
	private void test_case_6() { int Arg0 = 4; int Arg1 = 44; int Arg2 = 50; int Arg3 = -1; verify_case(6, Arg3, minimalMoves(Arg0, Arg1, Arg2)); }
	private void test_case_7() { int Arg0 = 99200; int Arg1 = 0; int Arg2 = 99101; int Arg3 = 1004; verify_case(7, Arg3, minimalMoves(Arg0, Arg1, Arg2)); }
	private void test_case_8() { int Arg0 = 99999; int Arg1 = 100000; int Arg2 = 50000; int Arg3 = -1; verify_case(8, Arg3, minimalMoves(Arg0, Arg1, Arg2)); }
	private void test_case_9() { int Arg0 = 1; int Arg1 = 99999; int Arg2 = 99999; int Arg3 = 99999; verify_case(9, Arg3, minimalMoves(Arg0, Arg1, Arg2)); }

public static void Main() {
	try{
		BinaryFlips ___test = new BinaryFlips();
		___test.run_test(-1);
	} catch(Exception e) {
		//Console.WriteLine(e.StackTrace);
		Console.WriteLine(e.ToString());
	}
}
	// ここまで
}
