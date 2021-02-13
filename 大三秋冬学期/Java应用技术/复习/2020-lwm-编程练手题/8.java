import java.util.Scanner;

class Person{          //定义一个person类
    private String name = null;
    private int age = 0;
    private boolean gender = false;
    private int id = 0;
    
    public Person() {
        System.out.println("This is constructor");
        System.out.println(name+","+age+","+gender+","+id);
        System.out.println("Person [name="+name+", age="+age+", gender="+gender+", id="+id+"]");
    }
    
    public Person(String n, int a, boolean g) {      //编写有构造参数，赋值
        this.name = n;
        this.age = a;
        this.gender = g;
    }
    
    public String toString() {       //使用tostring方法
        System.out.println("Person [name="+this.name+", age="+this.age+", gender="+this.gender+", id="+0+"]");
        return name;
    }
}

public class Main {

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        int number = reader.nextInt();
        Person[] per = new Person[number];    //初始化对象数组
        for(int i=0; i<per.length; i++) {    //通过循环输入
            String name = reader.next();
            int age = reader.nextInt();
            boolean genter = reader.nextBoolean();
            per[i] = new Person(name,age,genter);
        }
        for(int x=per.length-1; x>=0;x--){    
            per[x].toString();
        }
        
        per.toString();
        Person s = new Person();
    }

}
