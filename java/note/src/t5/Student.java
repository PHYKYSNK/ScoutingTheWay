package t5;

public class Student extends Person{
    public Student() {
    }

    public Student(String name, int age) {
        super(name, age);
    }

    @Override
    public void work() {
        System.out.println("学生在学习");
    }
    public void study() {
        System.out.println("学生在学习Python");
    }
}