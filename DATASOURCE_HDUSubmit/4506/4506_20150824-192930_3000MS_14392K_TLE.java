import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String []args){
        BigInteger[] a = new BigInteger[10010];
        BigInteger MOD = new BigInteger("1000000007");
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for(int Case = 0; Case < T; Case++){
            int n = in.nextInt();
            int t = in.nextInt();
            BigInteger k = in.nextBigInteger();
            for(int i = 0; i < n; i++)
                a[i] = in.nextBigInteger();
            t %= n;
            for(int i = 0; i < n - 1; i++){
                System.out.print(a[(i + n - t) % n].multiply(k.pow(t)).mod(MOD) + " ");
            }
            System.out.println(a[(n - 1 + n - t) % n].multiply(k.pow(t)).mod(MOD));
        }
    }
}
