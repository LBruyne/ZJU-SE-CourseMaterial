import java.util.Scanner;
 
class IllegalScoreException extends Exception{
    public IllegalScoreException() {
    }
 
    public IllegalScoreException(String message) {
        super(message);
    }
 
    public IllegalScoreException(String message, Throwable cause) {
        super(message, cause);
    }
 
    public IllegalScoreException(Throwable cause) {
        super(cause);
    }
}

class IllegalNameException extends Exception{
    public IllegalNameException() {
    }
 
    public IllegalNameException(String message) {
        super(message);
    }
 
    public IllegalNameException(String message, Throwable cause) {
        super(message, cause);
    }
 
    public IllegalNameException(Throwable cause) {
        super(cause);
    }
}

class Student{
    private String name;
    private int score;
    //一般情况下，需要注意若程序抛出一个异常后，程序停止执行
    private int flag=0;
    public String getName() {
        return name;
    }
 
    public int getFlag() {
        return flag;
    }
 
    public void setFlag(int flag) {
        this.flag = flag;
    }
 
    public void setName(String name) {
        char c=name.charAt(0);
        if (c>='0'&&c<='9'){
            try {
                flag=1;
                throw new IllegalNameException();
            } catch (IllegalNameException e) {
                System.out.println("IllegalNameException: the first char of name must not be digit, name="+name);
            }
 
            return;
        }
        this.name = name;
    }
 
    public int getScore() {
        return score;
    }
 
    public void setScore(int score)  {
        if (flag==1){
            return;
        }
        if (score<0||score>100){
            try {
                flag=1;
                throw new IllegalScoreException();
            } catch (IllegalScoreException e) {
                System.out.println("IllegalScoreException: score out of range, score="+score);
            }
        }
        this.score = score;
    }
    //如果加分后分数<0 或>100，则抛出IllegalScoreException，加分不成功。
    public int addScore(int score) {
        return 0;
    }
 
    @Override
    public String toString() {
        return "Student [" +
                "name=" + name  +
                ", score=" + score +
                ']';
    }
}

public class Main {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        while (true){
            String str=sc.nextLine();
            if (str.equals("new")){
                String s=sc.nextLine();
                String[] s1 = s.split(" ");
                if (s1.length==2){
                    String name=s1[0];
                    int score=Integer.valueOf(s1[1]);
                    Student student = new Student();
                    student.setName(name);
                    student.setScore(score);
                    if (student.getFlag()==0){
                        System.out.println(student);
                    }
                }else{
                    System.out.println("java.util.NoSuchElementException");
                }
 
            }else {
                break;
            }
        }
        sc.close();
        System.out.println("scanner closed");
    }
}