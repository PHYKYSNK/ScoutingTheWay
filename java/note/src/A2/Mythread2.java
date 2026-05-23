package A2;

public class Mythread2 extends Thread{
    @Override
    public void run() {
        for(int i=0;i<'J'-'A'+1;i++) {
            System.out.println("线程" + getName() + " " + (char)('A'+i));
        }
    }
}
