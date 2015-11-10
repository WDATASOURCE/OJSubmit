import java.math.*;
import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        BigDecimal one = new BigDecimal(1);
        BigDecimal eight = new BigDecimal(8);
        String str;
        while(in.hasNext()){
            BigDecimal ans = new BigDecimal(0);
            BigDecimal a = one.divide(eight);
            str = in.next();
            for(int i = 2; i < str.length(); i++){
                ans = ans.add(a.multiply(new BigDecimal(str.charAt(i) - 48)));
                a = a.divide(eight);
            }
            System.out.println(str +" [8]" + " = " + ans.toString() + " [10]");
        }

    }
}
