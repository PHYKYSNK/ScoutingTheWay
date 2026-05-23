package t6;

public abstract class Pet {
    private String name;
    private int age;

    public Pet() {
    }
    public Pet(String name, int age) {
        this.name = name;
        this.age = age;
    }
    //定义抽象方法eat
    public abstract void eat();

    public void sleep() {
        System.out.println("正在睡觉~~~");
    }


}
