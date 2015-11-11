import java.util.*;

public class Main {
    public static void main(String []args){
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for(int Case = 1; Case <= T; Case++){
            int n = in.nextInt();
            Calendar l = Calendar.getInstance();
            l.set(2013, 2, 24);
            Calendar r = Calendar.getInstance();
            r.set(2013, 2, 24);
            
            l.add(Calendar.DATE, n);
            r.add(Calendar.DATE, -n);
            
            int ly = l.get(Calendar.YEAR);
            int lm = l.get(Calendar.MONTH) + 1;
            int ld = l.get(Calendar.DATE);
            
            int ry = r.get(Calendar.YEAR);
            int rm = r.get(Calendar.MONTH) + 1;
            int rd = r.get(Calendar.DATE);
            
            System.out.printf("%d/%02d/%02d %d/%02d/%02d", ly, lm, ld, ry, rm, rd);
            System.out.println();
        }
    }
}
