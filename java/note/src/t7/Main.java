package t7;

public class Main {
    public static void main(String[] args) {
        Calculator c = new Calculator();
        try {
            System.out.println(c.divide(10,0));
        } catch (ArithmeticException e) {
            e.printStackTrace();
        }
        Student s2 = new Student();
        s2.setAge(20);
        int age2 = s2.getAge();
        System.out.println(age2);

        Student s1 = new Student();
        try {
            s1.setAge(-5);
            int age1 = s1.getAge();
            System.out.println(age1);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}