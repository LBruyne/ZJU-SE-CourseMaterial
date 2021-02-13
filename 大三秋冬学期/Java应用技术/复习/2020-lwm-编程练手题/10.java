import java.util.Scanner;
 
class Student{
    private String name;
    private String sex;
    private int age;
 
    @Override
    public String toString() {
        String str="Student [name='"+name+"', sex='"+sex+"', age="+age+"]";
        return str;
    }
 
    public Student(String name, String sex, int age) {
        this.name = name;
        this.sex = sex;
        this.age = age;
    }
 
    public Student() {
    }
 
    public String getName() {
        return name;
    }
 
    public void setName(String name) {
        this.name = name;
    }
 
    public String getSex() {
        return sex;
    }
 
    public void setSex(String sex) {
        this.sex = sex;
    }
 
    public int getAge() {
        return age;
    }
 
    public void setAge(int age) {
        this.age = age;
    }
}
public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String name=sc.next();
        int age=Integer.valueOf(sc.next());
        String sx=sc.next();
        Student student = new Student(name, sx, age);
        System.out.println(student);
    }
}