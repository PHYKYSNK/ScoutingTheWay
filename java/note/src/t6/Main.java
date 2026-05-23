package t6;

public class Main {
    public static void main(String[] args) {
        Pet p1 = new Cat("哈基米",3);
        Pet p2 = new Dog("哈基汪",2);

        p1.eat();
        p1.sleep();
        //p1调用play方法
        ((Playable)p1).play();
        if(p1 instanceof Playable) {
            ((Cat)p1).play();
        }
        p2.eat();
        p2.sleep();
        ((Playable)p2).play();
    }
}
