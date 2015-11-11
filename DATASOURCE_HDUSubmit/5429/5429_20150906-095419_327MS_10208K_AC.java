/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-09-06 09:08
# Filename:         Main.java
# Description: 
=============================================================================*/
 
import java.math.*;
import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        BigInteger a[] = new BigInteger[110];
        int t = in.nextInt();
        for(int dx = 0; dx < t; dx++){
            int n = in.nextInt();
            boolean f = false;
            for(int i = 0; i < n; i++){
                a[i] = in.nextBigInteger();
                if(a[i].equals(BigInteger.ZERO)) f = true;
            }
            
            boolean flag = true;
            if(n == 1) flag = true;
            else if(n == 2){
                if(!a[0].equals(BigInteger.ZERO) && a[1].equals(BigInteger.ZERO)) flag = false;
                else if(a[0].equals(BigInteger.ZERO) && !a[1].equals(BigInteger.ZERO)) flag = false;
                else flag = true;
            }
            for(int i = 1; i < n - 1; i++)
                if(!(a[i].multiply(a[i]).equals(a[i - 1].multiply(a[i + 1])))) flag = false;

            if(f){
                for(int i = 0; i < n; i++)
                    if(!a[i].equals(BigInteger.ZERO)) flag = false;
            }
            if(flag) System.out.println("Yes");
            else System.out.println("No");
        }
    }
}

