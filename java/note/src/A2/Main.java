package A2;

public class Main {
    public static void main(String[] args) {
        func1();
        func2();
    }
    public static void func1(){
        try {
            MyThread1 t1 = new MyThread1();t1.start();
            Mythread2 t2 = new Mythread2();t2.start();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static void func2() {
        Myrunnable r = new Myrunnable();
        Thread t1 = new Thread(r,"北京站");
        Thread t2 = new Thread(r,"上海站");
        Thread t3 = new Thread(r,"天津站");
        t1.start();
        t2.start();
        t3.start();

    }
}
