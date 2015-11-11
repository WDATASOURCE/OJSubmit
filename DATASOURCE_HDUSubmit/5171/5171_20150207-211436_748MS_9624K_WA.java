import java.math.*;
import java.util.*; 
public class Main{
    public static void main(String []args){
        Scanner in = new Scanner(System.in);
        while((in.hasNextInt())){
            int n = in.nextInt();
            int k = in.nextInt();
            int v = 0, t = 0;
            BigInteger c = new BigInteger("0");
            for(int i = 0; i < n; i++){
                t = v;
                v = in.nextInt();
                c = c.add(BigInteger.valueOf(v));
            } 
            BigDecimal t1 = new BigDecimal((1 + Math.sqrt(5)) / 2.0);
            BigDecimal t2 = new BigDecimal((1 - Math.sqrt(5)) / 2.0);
            BigDecimal tt1 = (((BigDecimal.valueOf(1.0 / Math.sqrt(5))).multiply(((t1.pow(k)).add(t1.pow(k + 1))).subtract((t2.pow(k)).add(t2.pow(k + 1))))).subtract(BigDecimal.valueOf(1))).multiply(BigDecimal.valueOf(t));
            BigDecimal tt2 = (((BigDecimal.valueOf(1.0 / Math.sqrt(5))).multiply((((t1.pow(k)).add(t1.pow(k + 1)))).add(t1.pow(k - 1))).subtract(((t2.pow(k)).add(t2.pow(k + 1)))).add(t2.pow(k - 1))).subtract(BigDecimal.valueOf(1))).multiply(BigDecimal.valueOf(t));
            String str = (tt1.add(tt2)).toString();
            String inte = str.split("\\.")[0];
            BigInteger dj = new BigInteger(inte);
            c = (c.add(dj)).mod(BigInteger.valueOf(10000007));
            System.out.println(c);
        }
    }
}    
