import java.util.*;
import java.math.*;
class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        BigInteger a,b,m;
        a=sc.nextBigInteger();
        b=sc.nextBigInteger();
        m=sc.nextBigInteger();

	if(m.compareTo(BigInteger.ONE)==0){
            int len=b.toString().length()-1;
            int dpa[][]=new int[len][10];
            int dpb[][]=new int[len][10];
            for(int i=0;i<10;i++){
                dpa[0][i]=1;
            }
            for(int i=0;i<10;i++){
                dpb[0][i]=1;
            }
            for(int i=1;i<len;i++){
                for(int j=0;j<10;j++){
                    dpa[i][j]=0;
                    if(i%2==0){
                        for(int k=j+1;k<10;k++){
                            dpa[i][j]+=dpa[i-1][k];
                            dpa[i][j]%=10000;
                        }
                    }else{
                        for(int k=0;k<j;k++){
                            dpa[i][j]+=dpa[i-1][k];
                            dpa[i][j]%=10000;
                        }
                    }
                }
            }
            for(int i=1;i<len;i++){
                for(int j=0;j<10;j++){
                    dpb[i][j]=0;
                    if(i%2==1){
                        for(int k=j+1;k<10;k++){
                            dpb[i][j]+=dpb[i-1][k];
                            dpb[i][j]%=10000;
                        }
                    }else{
                        for(int k=0;k<j;k++){
                            dpb[i][j]+=dpb[i-1][k];
                            dpb[i][j]%=10000;
                        }
                    }
                }
            }
            int ret=0;
            for(int i=0;i<len;i++){
                for(int j=1;j<10;j++){
                    ret+=dpa[i][j]+dpb[i][j];
                    ret%=10000;
                }
            }
            System.out.println(ret);
        }else{
            int ret=0;
            for(BigInteger ii=a;ii.compareTo(b)<=0;ii=ii.add(BigInteger.ONE)){
                if(ii.remainder(m)==BigInteger.ZERO){
                    String s=ii.toString();
                    Boolean isa=true,isb=true;
                    for(int i=1;i<s.length();i++){
                        if(i%2==0){
                            if(!(s.charAt(i)>s.charAt(i-1))) isa=false;
                            if(!(s.charAt(i)<s.charAt(i-1))) isb=false;
                        }else{
                            if(!(s.charAt(i)<s.charAt(i-1))) isa=false;
                            if(!(s.charAt(i)>s.charAt(i-1))) isb=false;
                        }
                    }
                    if(isa||isb){
                        ret++;
                        ret%=10000;
                    }
                }
            }
            System.out.println(ret);
        }
    }
}
