package t4;

public class Main {
    public static void main(String[] args) {
        //创建华为手机
        Phone p1 = new Phone();
        p1.setBrand("华为");
        p1.setPrice(1999);
        p1.setColor("蓝色");
        p1.showInfo();
        p1.call("任正非");
        //创建三星手机
        Phone p2 = new Phone("三星", 2999, "黑色");
        p2.showInfo();
        p2.call("三星创始人");

    }
}
