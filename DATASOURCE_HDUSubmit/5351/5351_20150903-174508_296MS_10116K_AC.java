/*
ID: LinKArftc
PROG: Main.java
LANG: C++
*/
import java.math.BigInteger;
import java.util.Scanner;
public class Main{
    public static BigInteger[] fib;
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        fib = new BigInteger[1500];
        BigInteger a, b;
        a = new BigInteger("1");
        b = new BigInteger("1");
        fib[1] = a;
        fib[2] = a;
        fib[0] = new BigInteger("1");
        for(int i=3; i<=1000; i++){
            fib[i] = fib[i-1].add(fib[i-2]);
        }
        int t;
        t = cin.nextInt();
        int n;
        BigInteger m;
        BigInteger p = new BigInteger("258280327");
        while(t-->0){
            n = cin.nextInt();
            m = cin.nextBigInteger();
            if(m.add(BigInteger.valueOf(1)).compareTo(fib[n]) >=0){
                while(m.add(BigInteger.valueOf(1)).compareTo(fib[n]) >= 0){
                    n++;
                }
            } else {
                while(m.add(BigInteger.valueOf(1)).compareTo(fib[n]) < 0){
                    n--;
                }
                n++;
            }
            System.out.println(m.subtract(fib[n-2]).mod(p));
        }
    }
}