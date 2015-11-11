import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();        
        for(int i = 1; i <= n; ++i){
            BigInteger a = in.nextBigInteger();
            BigInteger b = in.nextBigInteger();
            BigInteger ans = a.add(b);
            System.out.println("Case " + i+ ":");
            System.out.println(a + " + " + b + " = " +ans);
            if(i != n)
                System.out.println();
        }
    }
}
