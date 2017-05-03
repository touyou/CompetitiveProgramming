import java.io.*;
import java.util.*;
import java.math.*;
public class Main {
    public static void main(String args[]) throws IOExcenption {
        BufferedReader br =  new BufferedReader(InputStreamReader(System.in));
        String in;
    }
    private static BigInteger solve(BigInteger a0, BigInteger a1, BigInteger a2) {
        for (int i=3; i<=99; i++) {
            BigInteger tmp = a0.add(a1).add(a2);
            a0 = a1;
            a1 = a2;
            a2 = tmp;
        }
        return a2;
    }
}
