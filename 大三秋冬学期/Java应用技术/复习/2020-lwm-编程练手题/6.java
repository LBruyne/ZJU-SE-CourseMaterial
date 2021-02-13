import java.util.*;
public class Main {
 
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int []a = new int [5];
		while(true)
		{
			String first;
			first = sc.next();
			if(first.equals("other"))
				break;
			if(first.equals("arr"))
			{
				try {
					int secend = sc.nextInt();
					int t = a[secend];
				}catch(Exception e){
					System.out.println(e);
				}
			}
			if(first.equals("null"))
			{
				try {
					String t = null;
					int length = t.length();
				}catch(Exception e) {
					System.out.println(e);
				}
			}
			if(first.equals("cast"))
			{
				try {
					Object ss = new String("string");
					//Integer t = (Integer)ss;
					System.out.println((Integer)ss);
				}catch(Exception e){
					System.out.println(e);
				}
			}
			if(first.equals("num"))
			{
				try {
					String c = sc.next();
					Integer num = Integer.parseInt(c);
					//System.out.println(Integer.parseInt(c));
				}catch(Exception e)
				{
					System.out.println(e);
				}
			}
 
		}
		sc.close();
	}
}
 
 