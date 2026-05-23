package t5;

public class Teacher extends  Person{
    public Teacher() {
    }

    public Teacher(String name, int age) {
        super(name, age);
    }

    @Override
    public void work() {
        System.out.println("老师在教学");
    }
    public void teach() {
        System.out.println("老师上Python课");
    }
}
