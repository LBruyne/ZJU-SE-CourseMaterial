import java.util.ArrayList;
import java.util.Scanner;
 
interface GeneralStack<T>{
    public T push(T item);          //如item为null，则不入栈直接返回null。
    public T pop();                 //出栈，如为栈为空，则返回null。
    public T peek();                //获得栈顶元素，如为空，则返回null.
    public boolean empty();         //如为空返回true
    public int size();              //返回栈中元素数量
}

class ArrayListGeneralStack implements GeneralStack{
    ArrayList list=new ArrayList();
    @Override
    public String toString() {
        return  list.toString();
    }
 
    @Override
    public Object push(Object item) {
        if (list.add(item)){
            return item;
        }else {
            return false;
        }
    }
 
    @Override
    public Object pop() {
        if (list.size()==0){
            return null;
        }
        return list.remove(list.size()-1);
    }
 
    @Override
    public Object peek() {
        return list.get(list.size()-1);
    }
 
    @Override
    public boolean empty() {
        if (list.size()==0){
            return true;
        }else {
            return false;
        }
    }
 
    @Override
    public int size() {
        return list.size();
    }
}
class Car{
    private int id;
    private String name;
 
    @Override
    public String toString() {
        return "Car [" +
                "id=" + id +
                ", name=" + name  +
                ']';
    }
 
    public int getId() {
        return id;
    }
 
    public void setId(int id) {
        this.id = id;
    }
 
    public String getName() {
        return name;
    }
 
    public void setName(String name) {
        this.name = name;
    }
 
    public Car(int id, String name) {
        this.id = id;
        this.name = name;
    }
}
public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        while (true){
            String s=sc.nextLine();
            if (s.equals("Double")){
                System.out.println("Double Test");
                int count=sc.nextInt();
                int pop_time=sc.nextInt();
                ArrayListGeneralStack arrayListGeneralStack = new ArrayListGeneralStack();
                for (int i=0;i<count;i++){
                    System.out.println("push:"+arrayListGeneralStack.push(sc.nextDouble()));
                }
                for (int i=0;i<pop_time;i++){
                    System.out.println("pop:"+arrayListGeneralStack.pop());
                }
                System.out.println(arrayListGeneralStack.toString());
                double sum=0;
                int size=arrayListGeneralStack.size();
                for (int i=0;i<size;i++){
                    sum+=(double)arrayListGeneralStack.pop();
                }
                System.out.println("sum="+sum);
                System.out.println("interface GeneralStack");
            }else if (s.equals("Integer")){
                System.out.println("Integer Test");
                int count=sc.nextInt();
                int pop_time=sc.nextInt();
                ArrayListGeneralStack arrayListGeneralStack = new ArrayListGeneralStack();
                for (int i=0;i<count;i++){
                    System.out.println("push:"+arrayListGeneralStack.push(sc.nextInt()));
                }
                for (int i=0;i<pop_time;i++){
                    System.out.println("pop:"+arrayListGeneralStack.pop());
                }
                System.out.println(arrayListGeneralStack.toString());
                int sum=0;
                int size=arrayListGeneralStack.size();
                for (int i=0;i<size;i++){
                    sum+=(int)arrayListGeneralStack.pop();
                }
                System.out.println("sum="+sum);
                System.out.println("interface GeneralStack");
            }else if (s.equals("Car")){
                System.out.println("Car Test");
                int count=sc.nextInt();
                int pop_time=sc.nextInt();
                ArrayListGeneralStack arrayListGeneralStack = new ArrayListGeneralStack();
                for (int i=0;i<count;i++){
                    int id=sc.nextInt();
                    String name=sc.next();
                    Car car = new Car(id,name);
                    System.out.println("push:"+arrayListGeneralStack.push(car));
                }
                for (int i=0;i<pop_time;i++){
                    System.out.println("pop:"+arrayListGeneralStack.pop());
                }
                System.out.println(arrayListGeneralStack.toString());
                if (arrayListGeneralStack.size()>0){
                    int size=arrayListGeneralStack.size();
                    for (int i=0;i<size;i++){
                        Car car=(Car) arrayListGeneralStack.pop();
                        System.out.println(car.getName());
                    }
                }
                System.out.println("interface GeneralStack");
            }else if (s.equals("quit")){
                break;
            }
        }
 
    }
}
 