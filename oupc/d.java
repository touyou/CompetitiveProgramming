import java.util.*;
import java.math.*;
public class Main {
    public static void main(String[] args) {
        Scanner stdIn=new Scanner(System.in);
        int n=stdIn.nextInt();
        BigInteger x=BigInteger.valueOf(0);
        BigInteger bunbo=BigInteger.valueOf(1);
        for (int i=0; i<n; i++) {
            int o=stdIn.nextInt(), y=stdIn.nextInt();
            BigInteger j=BigInteger.valueOf(y);
            if (o==1) x=x.add(j.multiply(bunbo));
            if (o==2) x=x.subtract(j.multiply(bunbo));
            if (o==3) x=x.multiply(j);
            if (o==4) bunbo=bunbo.multiply(j);
        }
//        System.out.println(x);
//        System.out.println(bunbo);
        System.out.println(x.divide(bunbo));
    }
};
