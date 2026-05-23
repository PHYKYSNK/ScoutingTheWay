package t6;

public class Dog extends Pet implements Playable{
    public Dog() {
    }
    public Dog(String name, int age) {
        super(name, age);
    }
    @Override
    public void eat() {
        System.out.println("狗吃骨头");
    }
    @Override
    public void play() {
        System.out.println("狗玩飞盘");
    }
}
