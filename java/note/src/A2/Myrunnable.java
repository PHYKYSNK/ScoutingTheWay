package A2;

public class Myrunnable implements Runnable{
    private int count = 100;
    private int now = 1;
    @Override
    public void run() {
        String name = Thread.currentThread().getName();
        while(true) {
            synchronized (this) {
                if(now <= count) {

                    System.out.println(name + "售出了第" + now + "张票。");
                    now++;
                } else {
                    break;
                }
            }

            try {
                Thread.sleep(10);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
