import java.math.*;
import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        while(in.hasNext()){
            int b = in.nextInt();
            if(b == 0) break;
            BigInteger p = in.nextBigInteger(b);
            BigInteger m = in.nextBigInteger(b);
            p = p.mod(m);
            System.out.println(p.toString(b));
        }
    }
}
