package t6;

public class Cat extends Pet implements Playable{
    public Cat() {
        super();
    }
    public Cat(String name, int age) {
        super(name, age);
    }
    @Override
    public void eat() {
        System.out.println("猫吃猫粮");
    }

    @Override
    public void play() {
        System.out.println("猫玩毛线球");
    }
}
