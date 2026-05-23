package t4;

public class Phone {
    private String brand;
    private double price;
    private String color;

    public void call(String name) {
        System.out.println("正在用手机给" + name + "打电话");
    }

    public void sendMessage(String content) {
        System.out.println("正在给发短信，内容 ： " + content);
    }
    public void showInfo() {
        System.out.println("手机品牌是：" + brand +
                "，价格是：" + price
                + "，颜色是：" + color);
    }

    public Phone(String brand, double price, String color) {
        this.brand = brand;
        this.price = price;
        this.color = color;
    }

    public Phone() {
    }

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }
}
