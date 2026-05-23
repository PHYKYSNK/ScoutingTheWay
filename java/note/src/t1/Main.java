package t1;

public class Main {
    public static void main(String[] args) {
        String name;
        int age;
        double height;
        boolean isStudent;
        double weight;
        name = "Trae";
        age = 1;
        height = 1.2;
        isStudent = false;
        weight = 65;
        System.out.println("十年后的年龄 ： " + (age + 10));

        //计算bmi
        double bmi = weight / (height * height);
        System.out.println("bmi ： " + bmi);

        boolean isAdult = age >= 18 ? true : false;
        System.out.println("是否成年 ： " + isAdult);
    }
}
